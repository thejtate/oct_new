<?php

/**
 * Cart views integration.
 */

/**
 * Implements hook_views_data().
 */
function fnl_store_cart_views_data() {

  $data = array();

  $data['fnl_store_cart'] = array(
    'table' => array(
      'group' => t('Funnel store cart'),
      'base' => array(
        'field' => 'cid',
        'title' => t('Funnel store cart'),
        'weight' => -10,
      ),
      'join' => array(
        'node' => array(
          'left_field' => 'nid',
          'field' => 'nid',
        ),
        'fnl_store_orders' => array(
          'left_field' => 'oid',
          'field' => 'oid',
        ),
        'user' => array(
          'left_field' => 'uid',
          'field' => 'user_id',
        ),
      ),
    ),
  );

  $data['fnl_store_cart']['name'] = array(
    'title' => t('Product name'),
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

  $data['fnl_store_cart']['cid'] = array(
    'title' => t('Cart item ID'),
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

  $data['fnl_store_cart']['user_id'] = array(
    'title' => t('Cart user id. (uid or token for anonymous users)'),
    'help' => t('Help'),
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

  $data['fnl_store_cart']['sku'] = array(
    'title' => t('Product SKU'),
    'help' => t('Product SKU'),
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

  $data['fnl_store_cart']['nid'] = array(
    'title' => t('Cart item node nid'),
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
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Cart item Node relationship'),
      'title' => t('Cart item Node relationship'),
      'help' => t('Related Node'),
    ),
  );

  $data['fnl_store_cart']['oid'] = array(
    'title' => t('Related order id.'),
    'help' => t('Related order id.'),
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
      'label' => t('Cart order relationship'),
      'title' => t('Cart order relationship'),
      'help' => t('Related order'),
    ),
  );

  // hook_views_data_item_field_

  $data['fnl_store_cart']['type'] = array(
    'title' => t('Product type'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_fnl_store_cart_product',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );


  $data['fnl_store_cart']['qty'] = array(
    'title' => t('Product quantity'),
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

  $data['fnl_store_cart']['amount'] = array(
    'title' => t('Product amount'),
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

  $data['fnl_store_cart']['added'] = array(
    'title' => t('Cart item added'),
    'help' => t('Cart item added date time'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_datetime',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_fnl_store_datetime',
      // Note that you can override the field-wide label:
      'label' => t('Cart item added'),
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

  $data['fnl_store_cart']['delete_link'] = array(
    'title' => t('Cart item delete link'),
    'help' => t('Cart item delete link'),
    'field' => array(
      'handler' => 'views_handler_field_cart_item_delete_link',
      'real field' => 'cid',
      'additional fields' => array(
        'user_id' => array(
          'field' => 'user_id'
        ),
      ),
    ),
  );

  $data['fnl_store_cart']['cid'] = array(
    'title' => t('Rendered product'),
    'help' => t('Rendered product'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_cart_rendered_product',
      'real field' => 'cid',
      'additional fields' => array(
        'name', 'type', 'data', 'oid', 'nid', 'qty', 'amount', 'added', 'sku'
      ),
    ),
  );

  $data['fnl_store_cart']['data'] = array(
    'title' => t('Serialized field'),
    'help' => t('Serialized array of fields'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_cart_serial_field', //T-shirt
      'real field' => 'data',
    ),
  );

  // hook_views_data_item_field_

  return $data;
}