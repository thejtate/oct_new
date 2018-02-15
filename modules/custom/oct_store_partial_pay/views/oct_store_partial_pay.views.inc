<?php

/**
 * @file Views integration.
 */

/**
 * Implements hook_views_data().
 */
function oct_store_partial_pay_views_data() {
  $data = array();

  $data['oct_store_partial_pay'] = array(
    'table' => array(
      'group' => t('Oct store partial pay info.'),
      'base' => array(
        'field' => 'oid',
        'title' => t('Partial pay info.'),
        'help' => t('Partial pay info.'),
        'weight' => -10,
      ),
      'join' => array(
        'fnl_store_orders' => array(
          'left_field' => 'oid',
          'field' => 'oid',
        ),
      ),
    ),
  );

  $data['oct_store_partial_pay']['oid'] = array(
    'title' => t('Order ID'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array(
      'base' => 'fnl_store_orders', // The name of the table to join with.
      'base field' => 'oid', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Partial payment order relationship'),
      'title' => t('Partial payment order relationship'),
      'help' => t('Related order'),
    ),
  );

  $data['oct_store_partial_pay']['due_date'] = array(
    'title' => t('Due Date'),
    'help' => t('Due Date'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_datetime',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_fnl_store_datetime',
      // Note that you can override the field-wide label:
      'label' => t('Created date time'),
      // This setting is used by the boolean filter handler, as possible option.
      'type' => 'yes-no',
      // Use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment.
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );


  $data['oct_store_partial_pay']['due_amount'] = array(
    'title' => t('Due amount'),
    'help' => t('Due amount'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_amount',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['oct_store_partial_pay']['total_payed_amount'] = array(
    'title' => t('Total payed amount'),
    'help' => t('Total payed amount'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_amount',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['oct_store_partial_pay']['to_pay_amount'] = array(
    'title' => t('To pay amount'),
    'help' => t('To pay amount (payment in progress)'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_amount',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['oct_store_partial_pay']['last_payed_amount'] = array(
    'title' => t('Last payed amount.'),
    'help' => t('Last payed amount, or current if in progress.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );


  $data['oct_store_partial_pay']['transactions_count'] = array(
    'title' => t('Transactions count'),
    'help' => t('Transactions count'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function oct_store_partial_pay_views_data_alter(&$data){
  if (isset($data['fnl_store_cart'])) {
    $data['fnl_store_cart']['is_available'] = array(
      'title' => t('Is Partial payment available'),
      'help' => t('Is Partial payment available'),
      'field' => array(
        'handler' => 'views_handler_field_is_product_partial_payment_available',
        'real field' => 'cid',
        'additional fields' => array(
          'name', 'type', 'data', 'oid', 'nid', 'qty', 'amount', 'added', 'sku'
        ),
      ),
    );
  }
}