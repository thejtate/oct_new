<?php

/**
 * @file
 * Checkout form
 */

function fnl_store_checkout_form($form, &$form_state) {

  //TODO: split to common store part and oct specific part
  //attach user cart to form_state
  $form_state['order'] = fnl_store_order_load(fnl_store_cart_order_id_load());

  $oid = !empty($form_state['order']->oid) ? $form_state['order']->oid : NULL;
  $form_state['cart'] = fnl_store_cart_load($oid);

  if(empty($form_state['cart']) || empty($form_state['order'])) {

    $form['empty_message'] = array(
      '#markup' => '<div>' . t('Cart is empty.') . '</div>',
    );

    return $form;
  }

  //recalculate order to check any changes before checkout.
  fnl_store_cart_attach_calculation($form_state['order']);

  $form['cart'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => '',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $cart = views_embed_view('cart', 'checkout');
  $form['cart']['content'] = array(
    '#markup' => '<div>'
      . $cart
      . '</div>',
  );

  $form['user'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => t('User Information'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['user']['purchaser'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Purchaser'),
  );

  $form['user']['first_name'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Parent or Guardian First name'),
  );

  $form['user']['last_name'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Parent or Guardian Last name'),
  );

  $form['user']['second_first_name'] = array(
    '#type' => 'textfield',
    '#required' => FALSE,
    '#title' => t('Another Parent or Guardian First name'),
  );

  $form['user']['second_last_name'] = array(
    '#type' => 'textfield',
    '#required' => FALSE,
    '#title' => t('Another Parent or Guardian Last name'),
  );

  $form['user']['phone'] = array(
    '#type' => 'masked_input',
    '#mask' => '(999)999-9999',
    '#required' => TRUE,
    '#title' => t('Phone Number'),
  );

  $form['user']['address'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Address'),
  );

  $form['user']['city'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('City'),
  );

  $form['user']['state'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#title' => t('State'),
    '#default_value' => 'OK',
    '#options' => fnl_store_usa_states_options(),
  );

  $form['user']['zip'] = array(
    '#type' => 'masked_input',
    '#mask' => '99999',
    '#required' => TRUE,
    '#title' => t('Zip'),
  );

  $form['user']['email'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Email'),
    '#element_validate' => array('fnl_store_element_validate_email'),
  );

  $form['user']['email_confirm'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Re-enter email address'),
    '#element_validate' => array('fnl_store_element_validate_email'),
  );

  $form['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#name' => 'cancel',
    '#limit_validation_errors' => array(),//don`t validate form
    '#submit' => array('fnl_store_checkout_form_cancel_submit'),
    '#weight' => 99,
    // ra__ajax
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit Order'),
    '#name' => 'submit',
    '#weight' => 100,
    // ra__ajax
  );

  return $form;
}

function fnl_store_checkout_form_cancel_submit($form, &$form_state) {
  drupal_goto(FNL_STORE_CART_PAGE);
}

function fnl_store_checkout_form_validate($form, &$form_state) {

  if(!empty($form_state['values']['user']['email']) && !empty($form_state['values']['user']['email_confirm'])
  && ($form_state['values']['user']['email'] !== $form_state['values']['user']['email_confirm'])) {
    form_error($form['user']['email'], t('Email entries do not match.'));
  }
}

function fnl_store_checkout_form_submit($form, &$form_state) {

  $order = &$form_state['order'];
  $ignore_values_keys = drupal_map_assoc(array('cancel', 'submit', 'form_build_id', 'form_id', 'form_token'));

  $order->data['checkout_values'] = array_diff_key($form_state['values'], $ignore_values_keys);

  fnl_store_checkout_start($order);
}

function fnl_store_checkout_start(&$order) {

  $order->status = FNL_ORDER_STATUS_ON_CHECKOUT;
  if(function_exists('fnl_store_cart_attach_calculation')) {
    //recalculate and save, to check any changes before payment start
    fnl_store_cart_attach_calculation($order);
  } else {
    fnl_store_order_save($order);
  }
}


function fnl_store_usa_states_options() {
  return array(
    'AL' => t('Alabama'),
    'AK' => t('Alaska'),
    'AS' => t('American Samoa'),
    'AZ' => t('Arizona'),
    'AR' => t('Arkansas'),
    'CA' => t('California'),
    'CO' => t('Colorado'),
    'CT' => t('Connecticut'),
    'DE' => t('Delaware'),
    'DC' => t('District of Columbia'),
    'FL' => t('Florida'),
    'GA' => t('Georgia'),
    'GU' => t('Guam'),
    'HI' => t('Hawaii'),
    'ID' => t('Idaho'),
    'IL' => t('Illinois'),
    'IN' => t('Indiana'),
    'IA' => t('Iowa'),
    'KS' => t('Kansas'),
    'KY' => t('Kentucky'),
    'LA' => t('Louisiana'),
    'ME' => t('Maine'),
    'MH' => t('Marshall Islands'),
    'MD' => t('Maryland'),
    'MA' => t('Massachusetts'),
    'MI' => t('Michigan'),
    'MN' => t('Minnesota'),
    'MS' => t('Mississippi'),
    'MO' => t('Missouri'),
    'MT' => t('Montana'),
    'NE' => t('Nebraska'),
    'NV' => t('Nevada'),
    'NH' => t('New Hampshire'),
    'NJ' => t('New Jersey'),
    'NM' => t('New Mexico'),
    'NY' => t('New York'),
    'NC' => t('North Carolina'),
    'ND' => t('North Dakota'),
    'MP' => t('Northern Marianas Islands'),
    'OH' => t('Ohio'),
    'OK' => t('Oklahoma'),
    'OR' => t('Oregon'),
    'PW' => t('Palau'),
    'PA' => t('Pennsylvania'),
    'PR' => t('Puerto Rico'),
    'RI' => t('Rhode Island'),
    'SC' => t('South Carolina'),
    'SD' => t('South Dakota'),
    'TN' => t('Tennessee'),
    'TX' => t('Texas'),
    'UT' => t('Utah'),
    'VT' => t('Vermont'),
    'VI' => t('Virgin Islands'),
    'VA' => t('Virginia'),
    'WA' => t('Washington'),
    'WV' => t('West Virginia'),
    'WI' => t('Wisconsin'),
    'WY' => t('Wyoming'),
  );
}

/**
 * Form element validation handler for email elements.
 */
function fnl_store_element_validate_email($element, &$form_state) {
  $value = $element['#value'];
  if ($value != '' && !valid_email_address($value)) {
    form_error($element, t('%name must be a valid email address.', array('%name' => $element['#title'])));
  }
}