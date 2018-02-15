<?php
/**
 * @file
 * Form for finishing payment.
 */

function oct_store_partial_pay_finish($form, &$form_state, $order) {

  $payed = oct_store_partial_pay_get_payed_amount_from_all_transactions($order->oid);
  $is_transactions_limit_reached = oct_store_partial_pay_is_transaction_limit_reached($order);
  $form_state['amount_due'] = $order->amount - $payed;


  $form_state['order'] = $order;
  $form['cart'] = array(
    '#markup' => theme('oct_store_partial_pay_order_totals', array('order' => $order)),
  );

  $form['cart_details'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => t('Order details'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['cart_details']['content'] = array(
    '#markup' => views_embed_view('order_finishing_payment', 'order', $order->oid) . theme('fnl_store_order_totals', array('order' => $order)),
  );

  $options = array(
    'due' => t(
      'Amount due !amount',
      array('!amount' => fnl_store_format_amount($form_state['amount_due']))
    ),
  );

  if(!$is_transactions_limit_reached) {
    $options['part'] = t('Pay');
  }

  $form['type'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#title' => t(''),
    '#title_display' => 'invisible',
    '#default_value' => 'due',
    '#options' => $options,
  );

  if(!$is_transactions_limit_reached) {
    $form['amount'] = array(
      '#type' => 'numberfield',
      '#step' => '0.01',
      '#min' => 0,
      '#max' => $form_state['amount_due'],
      '#required' => FALSE,
      '#title' => t('$'),
      '#default_value' => '0',
      '#states' => array(
        'enabled' => array(
          ':input[name="type"]' => array('value' => 'part'),
        ),
      ),
    );
  } else {
    $form['description'] = array(
      '#markup' => t('- Parts limit reached. Pay full due Amount.'),
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Pay now'),
  );

  return $form;
}

function oct_store_partial_pay_finish_validate($form, &$form_state) {

  $order = $form_state['order'];
  $values = $form_state['values'];

  if($values['type'] == 'part') {
    if($values['amount'] > $form_state['amount_due'] ) {
      form_set_error('amount', t('The Amount must be less than or equal to !max', array('!max' => fnl_store_format_amount($form_state['amount_due']))));
    } else if($values['amount'] <= 0) {
      form_set_error('amount', t('The Amount must be greater than !max', array('!max' => fnl_store_format_amount(0))));
    }
  }


  if(oct_store_partial_pay_is_due_date_outdated($order)) {
    form_set_error('', t('You cant finish payment. Because order due date is outdated.'));
  }

}

function oct_store_partial_pay_finish_submit($form, &$form_state) {
  $order = &$form_state['order'];
  $values = $form_state['values'];


  if($values['type'] == 'due') {
    $order->data['partial_payment']['to_pay_amount'] = $form_state['amount_due'];
    $order->data['partial_payment']['last_payed_amount'] = $form_state['amount_due'];
  } else {
    $order->data['partial_payment']['to_pay_amount'] = $values['amount'];
    $order->data['partial_payment']['last_payed_amount'] = $values['amount'];
  }


  fnl_store_payment_pay($order->data['checkout_values']['payment']['method'], $order);
}

/**
 * Check order limit for partial transactions count.
 */
function oct_store_partial_pay_is_transaction_limit_reached($order) {

  if(!empty($order->data['partial_payment']['transactions_count'])
  && $order->data['partial_payment']['transactions_count'] >= (OCT_STORE_PARTIAL_PAYMENTS_LIMIT - 1)) {
    return TRUE;
  } else {
    return FALSE;
  }
}