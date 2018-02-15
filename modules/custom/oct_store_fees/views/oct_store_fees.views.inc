<?php
/**
 * Implements hook_views_data_alter().
 */
function oct_store_fees_views_data_alter(&$data) {
  if (isset($data['fnl_store_orders'])) {
    $data['fnl_store_orders']['fees'] = array(
      'title' => t('Order fees'),
      'help' => t('Order fees'),
      'field' => array(
        'handler' => 'views_handler_field_oct_store_fees_rendered',
        'real field' => 'oid',
        'additional fields' => array(
          'data',
        ),
      ),
    );

    $data['fnl_store_orders']['data'] = array(
      'title' => t('Serialized field'),
      'help' => t('Serialized array of fields'),
      'field' => array(
        'handler' => 'views_handler_field_oct_store_serial_field',
        'real field' => 'data',
      ),
    );

  }
}