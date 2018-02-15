<?php

/**
 * @file
 *  Payment views integration
 */

/**
 * Implements hook_views_data().
 */
function fnl_store_payment_views_data() {
  $data = array();

  $data['fnl_store_payment_transactions'] = array(
    'table' => array(
      'group' => t('Funnel store payment'),
      'base' => array(
        'field' => 'Primary key',
        'title' => t('Funnel store payment'),
        'help' => t('Funnel store transactions information'),
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

    $data['fnl_store_payment_transactions']['transaction_id'] = array(
    'title' => t('The transaction payment ID.'),
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

  $data['fnl_store_payment_transactions']['oid'] = array(
    'title' => t('Related order.'),
    'help' => t('Related order.'),
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
      'label' => t('Transaction order relationship'),
      'title' => t('Transaction order relationship'),
      'help' => t('Related order'),
    ),
  );

  $data['fnl_store_payment_transactions']['payment_provider'] = array(
    'title' => t('Payment provider'),
    'help' => t('Payment provider'),
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

  $data['fnl_store_payment_transactions']['amount'] = array(
    'title' => t('Payment amount'),
    'help' => t('Payment amount'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_amount',
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

  $data['fnl_store_payment_transactions']['remote_id'] = array(
    'title' => t('Remote id'),
    'help' => t('The remote identifier for this transaction'),
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


  $data['fnl_store_payment_transactions']['message'] = array(
    'title' => t('Message'),
    'help' => t('The human-readable message associated to this transaction.'),
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

  $data['fnl_store_payment_transactions']['created'] = array(
    'title' => t('Created'),
    'help' => t('Created datetime'),
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

  $data['fnl_store_payment_transactions']['changed'] = array(
    'title' => t('Updated'),
    'help' => t('Updated datetime'),
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

  $data['fnl_store_payment_transactions']['status'] = array(
    'title' => t('Status'),
    'help' => t('Status'),
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

  $data['fnl_store_payment_transactions']['test_mode'] = array(
    'title' => t('Test mode'),
    'help' => t('Test mode flag'),
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

  /**
   * Transactions history table
   */
  $data['fnl_store_payment_transactions_history'] = array(
    'table' => array(
      'group' => t('Funnel store payment history'),
      'base' => array(
        'field' => 'Primary key',
        'title' => t('Funnel store payment history'),
        'help' => t('Funnel store transactions information'),
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

  $data['fnl_store_payment_transactions_history']['transaction_id'] = array(
    'title' => t('The transaction payment ID.'),
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

  $data['fnl_store_payment_transactions_history']['oid'] = array(
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
      'label' => t('Transaction order relationship'),
      'title' => t('Transaction order relationship'),
      'help' => t('Related order'),
    ),
  );

  $data['fnl_store_payment_transactions_history']['payment_provider'] = array(
    'title' => t('Payment provider'),
    'help' => t('Payment provider'),
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

  $data['fnl_store_payment_transactions_history']['amount'] = array(
    'title' => t('Payment amount'),
    'help' => t('Payment amount'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_amount',
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

  $data['fnl_store_payment_transactions_history']['remote_id'] = array(
    'title' => t('Remote id'),
    'help' => t('The remote identifier for this transaction'),
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

  $data['fnl_store_payment_transactions_history']['message'] = array(
    'title' => t('Message'),
    'help' => t('The human-readable message associated to this transaction.'),
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

  $data['fnl_store_payment_transactions_history']['created'] = array(
    'title' => t('Created'),
    'help' => t('Created datetime'),
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

  $data['fnl_store_payment_transactions_history']['status'] = array(
    'title' => t('Status'),
    'help' => t('Status'),
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

  $data['fnl_store_payment_transactions_history']['test_mode'] = array(
    'title' => t('Test mode'),
    'help' => t('Test mode flag'),
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