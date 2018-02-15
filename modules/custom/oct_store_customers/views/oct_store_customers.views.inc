<?php
/**
 * @file
 *   Views integration
 */

/**
 * Implements hook_views_data().
 */
function oct_store_customers_views_data() {
  $data = array();

  $data['oct_store_customers'] = array(
    'table' => array(
      'group' => t('Oct store customers'),
      'base' => array(
        'field' => 'oid',
        'title' => t('Oct store customers'),
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

  $data['oct_store_customers']['oid'] = array(
    'title' => t('Customers orders id.'),
    'help' => t('Customers orders id'),
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
      'label' => t('Order Customer relationship'),
      'title' => t('Order Customer relationship'),
      'help' => t('Related Customer'),
    ),
  );

  $data['oct_store_customers']['first_name'] = array(
    'title' => t('First name'),
    'help' => t('First name'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['oct_store_customers']['last_name'] = array(
    'title' => t('Last name'),
    'help' => t('Last name'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['oct_store_customers']['purchaser'] = array(
    'title' => t('Purchaser'),
    'help' => t('Purchaser'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['oct_store_customers']['phone'] = array(
    'title' => t('Phone'),
    'help' => t('Phone'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['oct_store_customers']['address'] = array(
    'title' => t('Address'),
    'help' => t('Address'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['oct_store_customers']['city'] = array(
    'title' => t('City'),
    'help' => t('City'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['oct_store_customers']['state'] = array(
    'title' => t('State'),
    'help' => t('State'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['oct_store_customers']['zip'] = array(
    'title' => t('Zip'),
    'help' => t('Zip'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['oct_store_customers']['email'] = array(
    'title' => t('Email'),
    'help' => t('Email'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // hook_views_data_item_field_

  // hook_views_data_item_table

  return $data;
}