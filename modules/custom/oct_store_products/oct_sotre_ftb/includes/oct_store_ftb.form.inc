<?php

/**
 * @file
 * Purchise form.
 */

function oct_store_ftb_form($form, &$form_state, $node) {


  list($tickets_info, $bottom_note, $fees) = oct_store_ftb_form_get_info($node);

  $form_state['node'] = $node;
  $form_state['tickets_info'] = $tickets_info;

  $form['company_name'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Your Name / Company Name'),
  );

  $tickets_wrapper_id = drupal_html_id('oct-store-ftb-table');
  $form['tickets'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => '',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#theme_wrappers' => array('oct_store_ftb_form_table'),
    '#prefix' => '<div id="' . $tickets_wrapper_id . '">',
    '#suffix' => '</div>',
    //custom attributes
    '#bottom_note' => $bottom_note,
    '#fees' => $fees,
  );

  $form['tickets']['names_lists'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => '',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  foreach ($tickets_info as $key => $info) {
    $qty_options = array(0 => 0) + drupal_map_assoc(range($info['qty_min'], $info['qty_max']));

    $form['tickets'][$key] = array(
      '#type' => 'select',
      '#required' => FALSE,
      '#title' => $info['label'],
      '#default_value' => 0,
      '#options' => $qty_options,
      '#title_display' => 'invisible',
      '#attributes' => array('data-price' => $info['price'], 'class' => array('ticket')),
      //custom attributes
      '#price' => $info['price'],
      '#ticket_description' => $info['description'],
    );

    if(!empty($info['names_label'])) {
      $form['tickets']['names_lists'][$key] = array(
        '#type' => 'fieldset',
        '#tree' => TRUE,
        '#title' => '',
        '#collapsible' => FALSE,
        '#collapsed' => FALSE,
        '#attributes' => array('class' => array('guest-names-fieldset'))
      );

      for ($i = 0; $i < $info['qty_max']; $i++) {
        $form['tickets']['names_lists'][$key][$i] = array(
          '#type' => 'textfield',
          '#required' => FALSE,
          '#title' => ($i == 0) ? $info['names_label'] : '',
          '#attributes' => array('class' => array('guest-names'))
        );

        if($i == 0) {
          $form['tickets']['names_lists'][$key][$i]['#after_build'][] = 'oct_store_ftb_form_element_afterbuild_required_labels';
        }

      }
    }

  }

  $form['guests_seated'] = array(
    '#type' => 'textarea',
    '#required' => FALSE,
    '#title' => t(
      'List the names of other guests with whom you would like to be seated:'
    ),
    '#cols' => 60,
    '#rows' => 5,
  );

  $form['#attributes']['class'][] = 'ftb-calculation-form';
  $form['#attached']['js'][] = drupal_get_path('module', 'oct_store_ftb') . '/js/oct_store_ftb.js';

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add to cart'),
    '#name' => 'add',
  );

  return $form;
}

function oct_store_ftb_form_validate($form, &$form_state) {
  if(!oct_store_production_tickets_total_amount($form_state)) {
    form_set_error('', t('Please select at least one ticket. Total price cannot be 0'));
  }

  $values = $form_state['values'];

  $selected_tickets = array_filter($values['tickets']);
  unset($selected_tickets['names_lists']);

  foreach ($selected_tickets as $ticket_key =>  $selected_ticket_count) {
    if(!empty($values['tickets']['names_lists'][$ticket_key])) {

      $required_names = array_splice($values['tickets']['names_lists'][$ticket_key], 0, $selected_ticket_count);

      foreach ($required_names as $name_key =>  $name_value) {
        if(empty(trim($name_value))) {
          form_set_error('tickets][names_lists][' . $ticket_key , $form_state['tickets_info'][$ticket_key]['names_label'] . ' are required.');
          break;
        }
      }

    }
  }

}

function oct_store_ftb_form_submit($form, &$form_state) {

  $values = $form_state['values'];
  $node = $form_state['node'];

  $selected_tickets = array_filter($values['tickets']);
  unset($selected_tickets['names_lists']);
  $product = new stdClass();
  $product->nid = $node->nid;
  $product->qty = 1;
  $product->name = $node->title;
  $product->type = 'product_ftb';
  $product->sku = 'product_ftb_' . $node->nid;
  $product->amount = oct_store_production_tickets_total_amount($form_state);

  $product->data['full_info']['nid'] = $node->nid;
  $product->data['full_info']['company_name'] = $values['company_name'];
  $product->data['full_info']['guests_seated'] = $values['guests_seated'];

  $selected_tickets_info = array();
  foreach ($selected_tickets as $key => $ticket_count) {

    //save only selected tickets names
    if(!empty($values['tickets']['names_lists'][$key])) {
      $names = array_splice($values['tickets']['names_lists'][$key], 0, $ticket_count);
      $names = array_filter($names);
    } else {
      $names = array();
    }


    //full ticket info
    $selected_tickets_info[$key] = array(
      'count' => $ticket_count,
      'price' => $form_state['tickets_info'][$key]['price'],
      'label' => $form_state['tickets_info'][$key]['label'],
      'names' => $names,
    );
  }


  $product->data['selected_tickets'] = $selected_tickets_info;

  fnl_store_cart_add_product($product);

  drupal_set_message(
    t(
      '%name added to !cart',
      array(
        '%name' => $product->name,
        '!cart' => l(t('your shopping cart'), FNL_STORE_CART_PAGE)
      )
    )
  );

  $form_state['redirect'] = FNL_STORE_CART_PAGE;
}

/**
 * Calculate total tickets price.
 */
function oct_store_production_tickets_total_amount($form_state) {

  $total = 0;

  $selected_tickets = array_filter($form_state['values']['tickets']);

  foreach ($selected_tickets as $id => $value) {
    if(!empty($form_state['tickets_info'][$id]['price'])) {
      $total += $value * $form_state['tickets_info'][$id]['price'];
    }
  }

  return $total;
}

/**
 * Get tickets information from the ftb node for the tickets purchase form.
 *
 * @param $node
 * @return array
 *  $tickets_info - All information about ticket prices
 *  $bottom_note - Form bottom text
 *  $ftb_fees - Product Fees array.
 */
function oct_store_ftb_form_get_info($node) {

  $tickets_info = array();
  $bottom_note = '';

  $fees = oct_store_fees_load_product_fees('product_ftb');

  try {
    $wrap = entity_metadata_wrapper('node', $node);

    $bottom_note = $wrap->field_ftbf_notification->value();

    //iterate field collection
    foreach ($wrap->field_ftbf_base_items->getIterator() as $delta =>  $fc_item_wrap) {
      /**  @var $fc_item_wrap EntityMetadataWrapper **/
      $field_collection_id = $fc_item_wrap->getIdentifier();

      $tickets_info[$field_collection_id] = array(
        'label' => check_plain($fc_item_wrap->field_ftbf_base_items_title->value()),
        'description' => $fc_item_wrap->field_ftbf_base_items_desc->value(),
        'price' => $fc_item_wrap->field_ftbf_base_items_cost->value(),
        'collection_id' => $field_collection_id,
        'qty_min' => 0,
        'qty_max' => $fc_item_wrap->field_ftbf_base_items_max_qty->value(),
        'names_label' => $fc_item_wrap->field_ftbf_base_items_names->value(),
      );
    }

  } catch (EntityMetadataWrapperException $exc) {
    watchdog('oct_store_ftb', __FUNCTION__ . '() <pre>' .  $exc->getTraceAsString() . '</pre>', NULL, WATCHDOG_ERROR);
    drupal_set_message($exc->getMessage(), 'error');
  }

  return array($tickets_info, $bottom_note, $fees);
}

/**
 * Wrap title in strong tag, exclude string in brackets ().
 */
function oct_store_ftb_form_element_afterbuild_required_labels($element) {

  $element['#title'] = $element['#title'] . theme('form_required_marker');
  return $element;
}