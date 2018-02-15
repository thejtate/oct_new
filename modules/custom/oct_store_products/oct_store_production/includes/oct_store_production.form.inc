<?php

/**
 * @file
 * Production ticket purchase.
 */

function oct_store_production_form($form, &$form_state) {

  $production_wrapper_id = drupal_html_id('oct-store-produtions');

  $form['#prefix'] = '<div id="' . $production_wrapper_id . '" class="left-part">';
  $form['#suffix'] = '</div>';

  $productions = oct_store_production_load_productions();

  $production_default = NULL;
  if(!empty($form_state['values']['production'])) {
    $node = node_load($form_state['values']['production']);
  } elseif(!empty($_GET['id']) && isset($productions[(int) $_GET['id']])) {
    $production_default = (int) $_GET['id'];
    $node = node_load($production_default);
  }

  $form['production'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#title' => t('Production'),
    '#default_value' => $production_default,
    '#empty_option' => t('- Select -'),
    '#options' => $productions,
    '#ajax' => array(
      'callback' => 'oct_store_production_select_ajax',
      'wrapper' => $production_wrapper_id,

    ),
  );

  if(!empty($node)) {

    list($date_options, $tickets_info, $fees, $not_avail_date_options, $not_avail_message) = oct_store_production_form_get_info($node);

    $date_select = array(
      '#type' => 'select',
      '#required' => TRUE,
      '#title' => t('Date and time'),
      '#empty_option' => t('Please select...'),
      '#options' => $date_options,
      '#ajax' => array(
        'callback' => 'oct_store_production_select_ajax',
        'wrapper' => $production_wrapper_id,
      ),
    );;

    if (empty($date_options)) {
      $form['message'] = array(
        '#markup' => '<h3>' . t('No available dates. Please choose another production.') . '</h3>',
      );

      //if selected date that not available online
    } elseif(!empty($form_state['values']['datetime']) && isset($not_avail_date_options[$form_state['values']['datetime']])) {
      $form['datetime'] = $date_select;

      $form['message'] = array(
        '#markup' => '<h3>' .$not_avail_message . '</h3>',
      );

    }
    else {
      $form_state['node'] = $node;
      $form_state['tickets_info'] = $tickets_info;
      $form_state['date_options'] = $date_options;


      $form['datetime'] = $date_select;

      $tickets_wrapper_id = drupal_html_id('oct-store-products-table');
      $form['tickets'] = array(
        '#type' => 'fieldset',
        '#tree' => TRUE,
        '#title' => '',
        '#collapsible' => FALSE,
        '#collapsed' => FALSE,
        '#ticket_groups' => array(),
        '#theme_wrappers' => array('oct_store_production_form_table'),
        '#prefix' => '<div id="' . $tickets_wrapper_id . '">',
        '#suffix' => '</div>',
        //custom attributes
        '#fees' => $fees,
      );

      foreach ($tickets_info as $key => $info) {
        $qty_options = array(0 => 0) + drupal_map_assoc(
            range($info['qty_min'], $info['qty_max'])
          );

        $form['tickets'][$key] = array(
          '#type' => 'select',
          '#required' => FALSE,
          '#title' => $info['label'],
          '#default_value' => 0,
          '#options' => $qty_options,
          '#title_display' => 'invisible',
          '#attributes' => array(
            'data-price' => $info['price'],
            'class' => array('ticket')
          ),
          //custom attributes
          '#price' => $info['price']
        );
      }


      $form['tickets']['complimentary_adult'] = array(
        '#type' => 'item',
        '#markup' => '<div class="complimentary-calculation-result">0</div>',
        '#title' => t('Complimentary adult'),
        '#title_display' => 'invisible',
        //custom attributes
        '#price' => '0',
      );

      //classes for js calculation of complimentary adults
      if(!empty($form['tickets']['child_tickets'])) {
        $form['tickets']['child_tickets']['#attributes']['class'][] = 'complimentary-calculation';
      }
      if(!empty($form['tickets']['child_groups'])) {
        $form['tickets']['child_groups']['#attributes']['class'][] = 'complimentary-calculation';
      }
      if(!empty($form['tickets']['child_50_plus_group_tickets'])) {
        $form['tickets']['child_50_plus_group_tickets']['#attributes']['class'][] = 'complimentary-calculation';
      }

      $form['#attributes']['class'][] = 'complimentary-calculation-form';
      $form['#attached']['js'][] = drupal_get_path(
          'module',
          'oct_store_production'
        ) . '/js/oct_store_production.js';

      $form['#attached']['js'][] = array(
        'data' => array('children_count_for_free_ticket' => OCT_STORE_PRODUCTION_CHILDREN_COUNT_FOR_FREE_TICKET),
        'type' => 'setting'
      );

      $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Add to cart'),
        '#name' => 'submit',
      );
    }
  }

  return $form;
}

function oct_store_production_form_validate($form, &$form_state) {

  $errors = form_get_errors();
  if(!empty($errors)) {
    return;
  }

  $selected_tickets = array_filter($form_state['values']['tickets']);
  if(empty($selected_tickets)) {
    form_set_error('tickets', t('Please select at least one ticket.'));
    return;
  }


  $values = $form_state['values'];
  $node = $form_state['node'];

  $collection_id = $values['datetime'];//datetime field has time keyed by collection id

  $selected_tickets = array_filter($values['tickets']);

  $product = new stdClass();
  $product->nid = $node->nid;
  $product->qty = 1;
  $product->name = $node->title;
  $product->type = 'product_production';
  $product->sku = 'product_production_' . $collection_id;
  $product->amount = oct_store_production_tickets_total_amount($selected_tickets, $form_state['tickets_info']);

  //production related data

  $product->data['full_info']['collection_id'] = $collection_id;
  $product->data['full_info']['datetime'] = $form_state['date_options'][$collection_id];

  $selected_tickets_info = array();
  $total_tickets_count = 0;

  foreach ($selected_tickets as $key => $ticket_count) {
    $total_tickets_count += $ticket_count;
    $selected_tickets_info[$key] = array(
      'count' => $ticket_count,
      'price' => $form_state['tickets_info'][$key]['price'],
      'label' => $form_state['tickets_info'][$key]['label'],
    );
  }


  $complimentary_adult_count = oct_store_production_calculate_complimentary_tickets($values);
  if(!empty($complimentary_adult_count)) {
    $selected_tickets_info['complimentary_adult'] = array(
      'count' => $complimentary_adult_count,
      'price' => 0,
      'label' => t('Complimentary Adult'),
    );
    $total_tickets_count += $complimentary_adult_count;
  }

  $product->data['selected_tickets'] = $selected_tickets_info;
  $product->data['total_tickets_count'] = $total_tickets_count;


  $form_state['add_product'] = $product;

  $cart_qty = oct_store_stock_cart_product_qty($product->sku);
  $store_qty = oct_store_stock_get_quantity($product);

  $available_qty = (($store_qty - $cart_qty) <= 0) ? 0 : ($store_qty - $cart_qty);

  if(($available_qty - $total_tickets_count) < 0) {
    form_set_error('tickets', t('The maximum quantity for @product that can be ordered is @number', array('@product' => $product->name, '@number' => $available_qty)));
  }

}

function oct_store_production_form_submit($form, &$form_state) {

  fnl_store_cart_add_product($form_state['add_product']);

  drupal_set_message(
    t(
      '%name added to !cart',
      array(
        '%name' => $form_state['add_product']->name,
        '!cart' => l(t('your shopping cart'), FNL_STORE_CART_PAGE)
      )
    )
  );

  $form_state['redirect'] = FNL_STORE_CART_PAGE;
}

function oct_store_production_select_ajax($form, $form_state) {
  return $form;
}

/**
 * Calculate total tickets price.
 */
function oct_store_production_tickets_total_amount($selected_tickets, $tickets_info) {
  $total = 0;
  foreach ($selected_tickets as $name => $count) {
    $total += $count * $tickets_info[$name]['price'];
  }

  return $total;
}

/**
 * Calculate free complimentary tickets
 *
 * @param $form_values
 * @return int
 */
function oct_store_production_calculate_complimentary_tickets($form_values) {

  $children = !empty($form_values['tickets']['child_tickets']) ? $form_values['tickets']['child_tickets'] : 0;
  $children += !empty($form_values['tickets']['child_groups']) ? $form_values['tickets']['child_groups'] : 0;
  $children += !empty($form_values['tickets']['child_50_plus_group_tickets']) ? $form_values['tickets']['child_50_plus_group_tickets'] : 0;

  $free_tickets = floor($children / OCT_STORE_PRODUCTION_CHILDREN_COUNT_FOR_FREE_TICKET);

  return $free_tickets;
}

/**
 * Get tickets information from the production node for the tickets purchase form.
 *
 * @param $node
 * @return array
 *  $date_options - Node dates keyed by field collection ID
 *  $tickets_info - All information about ticket prices
 *  $fees - Product Fees array.
 *  $not_availe_date_options - Node dates that not available online.
 *  $not_avail_message - Message text for not available online dates.
 */
function oct_store_production_form_get_info($node) {

  $date_options = array();
  $not_avail_date_options = array();
  $tickets_info = array();

  $fees = oct_store_fees_load_product_fees('product_production');
  $not_avail_message = t('Sorry, no online ticket purchases are available for this showing. Please purchase the tickets at the door.');

  try {
    $wrap = entity_metadata_wrapper('node', $node);
    //$fields_info = $wrap->getPropertyInfo();
    if(!empty($wrap->field_product_unvaliable_message->value)) {
      $not_avail_message = $wrap->field_product_unvaliable_message->value->value();
    }

    //iterate field collection
    $now = new DateObject();
    foreach ($wrap->field_production_time->getIterator() as $delta => $fc_item_wrap) {

      $field_collection_id = $fc_item_wrap->getIdentifier();
      $start_date_obj = new DateObject($fc_item_wrap->field_production_time_date->value->value());

      if($start_date_obj > $now) {
        /** @var EntityDrupalWrapper $fc_item_wrap **/
        if(oct_store_stock_get_quantity_by_id('product_production', $fc_item_wrap->getIdentifier()) > 0) {
            $date_options[$field_collection_id] = $start_date_obj->format(OCT_STORE_PRODUCTION_DATE_FORMAT);
        } elseif(!empty($fc_item_wrap->field_production_time_not_avail->value())) {

          $date = $start_date_obj->format(OCT_STORE_PRODUCTION_DATE_FORMAT);
          $date_options[$field_collection_id] = $date;
          $not_avail_date_options[$field_collection_id] = $date;
        }
      }
    }


    $tickets_info = array(
      'adult_tickets' => array(
        'price' => $wrap->field_production_adult_t_price->value(),
        'label' => t('Adult'),
        'qty_min' => 0,
        'qty_max' => 255,
      ),
      'student_tickets' => array(
        'price' => $wrap->field_production_student_t_price->value(),
        'label' => t('Student (with student ID)'),
        'qty_min' => 0,
        'qty_max' => 255,
      ),
      'child_tickets' => array(
        'price' => $wrap->field_production_child_t_price->value(),
        'label' => t('Children (ages 2 – 12)'),
        'qty_min' => 0,
        'qty_max' => 255,
      ),
      'child_groups' => array(
        'price' => $wrap->field_production_c_group_t_price->value(),
        'label' => t('Group Children (20 to 74)'),
        'qty_min' => 20,
        'qty_max' => 74,
      ),
      'child_50_plus_group_tickets' => array(
        'price' => $wrap->field_production_c50_grp_t_price->value(),
        'label' => t('Group Children (75+)'),
        'qty_min' => 75,
        'qty_max' => 255,
      ),
    );

  } catch (EntityMetadataWrapperException $exc) {
    watchdog('oct_store_production', __FUNCTION__ . '() <pre>' .  $exc->getTraceAsString() . '</pre>', NULL, WATCHDOG_ERROR);
    drupal_set_message($exc->getMessage(), 'error');
  }

  return array($date_options, $tickets_info, $fees, $not_avail_date_options, $not_avail_message);
}

/**
 * Get Product nodes array.
 *
 * @return array
 */
function oct_store_production_load_productions() {
  $productions = array();
  module_load_include('inc', 'fnl_store', 'includes/fnl_store.helpers');
  $views_result = fnl_store_views_retrieve('oct_store_production_source');

  foreach ($views_result as $row) {
    $productions[$row->nid] = htmlspecialchars_decode($row->node_title);
  }

  return $productions;
}