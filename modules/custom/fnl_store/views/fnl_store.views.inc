<?php

/**
 * @file
 * Views integration.
 */

/**
 * Implements hook_views_data().
 */
function fnl_store_views_data() {
  $data = array();

  $data['fnl_store_orders'] = array(
    'table' => array(
      'group' => t('Funnel store orders'),
      'base' => array(
        'field' => 'oid',
        'title' => t('Orders'),
        'weight' => -10,
      ),
      'join' => array(
        'user' => array(
          'left_field' => 'uid',
          'field' => 'uid',
        ),
      ),
    ),
  );

  $data['fnl_store_orders']['oid'] = array(
    'title' => t('Order id'),
    'help' => t('Order id'),
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

  $data['fnl_store_orders']['cart_created'] = array(
    'title' => t('Cart created'),
    'help' => t('Cart created'),
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

  $data['fnl_store_orders']['created'] = array(
    'title' => t('Created date time'),
    'help' => t('Created date time'),
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

  $data['fnl_store_orders']['changed'] = array(
    'title' => t('Changed date time'),
    'help' => t('Changed date time'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_datetime',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_fnl_store_datetime',
      // Note that you can override the field-wide label:
      'label' => t('Changed date time'),
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

  $data['fnl_store_orders']['subtotal_amount'] = array(
    'title' => t('Subtotal amount'),
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

  $data['fnl_store_orders']['amount'] = array(
    'title' => t('Total amount'),
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

  $data['fnl_store_orders']['user_id'] = array(
    'title' => t('User'),
    'help' => t(
      'Relate an order to the user who created the order.'
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'label' => t('revision user'),
    ),
  );

  $data['fnl_store_orders']['status'] = array(
    'title' => t('Order status'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_fnl_store_order_status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['fnl_store_orders']['editable_status'] = array(
    'title' => t('Editable Order status'),
    'help' => t('Editable Order status'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_editable_status',
      'real field' => 'status',
      'additional fields' => array(
        'user_id', 'oid',
      ),
      'click sortable' => TRUE,
    ),
  );

  $data['fnl_store_orders']['view_order_link'] = array(
    'field' => array(
      'title' => t('Order Link'),
      'help' => t('Provide a simple link to the order page.'),
      'handler' => 'views_handler_field_view_order_link',
      'real field' => 'oid',
    ),
  );

  // Define a handler for an area used to summarize a set of line items.
  $data['fnl_store_orders']['order_total'] = array(
    'title' => t('Order total'),
    'help' => t('Displays the order total field formatted; requires an Order ID in first view argument.'),
    'area' => array(
      'handler' => 'views_handler_area_order_total',
    ),
  );
  $data['fnl_store_orders']['order_header'] = array(
    'title' => t('Order Header info'),
    'help' => t('Displays the order header information. (Billing, etc...)'),
    'area' => array(
      'handler' => 'views_handler_area_order_full_info_header',
    ),
  );

  $data['fnl_store_orders']['test_mode'] = array(
    'title' => t('Test mode'),
    'help' => t('Is order was processed in test mode?.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      // Note that you can override the field-wide label:
      'label' => t('My field'),
      // This setting is used by the boolean filter handler, as possible option.
      'type' => 'yes-no',
      // Use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment.
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // hook_views_data_item_field_

  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function fnl_store_views_plugins(){
  $plugins = array();

  $plugins['argument validator']['fnl_store_orders'] = array(
    'title' => t('Store order'),
    'handler' => 'views_plugin_argument_validate_order',
  );

  return $plugins;
}

