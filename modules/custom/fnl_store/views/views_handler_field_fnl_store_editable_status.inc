<?php

/**
 * @file
 * Order editable status handler.
 */

class views_handler_field_fnl_store_editable_status extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->add_related_js();
  }


  function render($values) {

    $oid = $this->get_value($values, 'oid');
    $user_id = $this->get_value($values, 'user_id');

    if($this->has_access_to_edit_order($user_id)) {

      $id = drupal_html_id('editable-status-select');
      $options = drupal_map_assoc(fnl_store_order_statuses());

      $options = array_diff($options, array(FNL_ORDER_STATUS_CART));

      $select = array(
        '#name' => 'status_select',
        '#options' => $options,
        '#value' => $this->get_value($values),
        '#attributes' => array(
          'data-order-id' => $oid,
          'data-editable' => 'order_status',
          'data-loader-placeholder-id' => 'status-loader-placeholder-' . $id,
          'id' => $id,
        ),
      );

      return theme('select', array('element' => $select)) . '<span id="status-loader-placeholder-' . $id . '" style="display:none;"></span> ';
    } else {
      //return plain text value
      return parent::render($values);
    }

  }

  function has_access_to_edit_order($user_id) {
    $current_user_id = fnl_store_cart_user_id();
    return user_access('fnl store edit orders') || ($current_user_id === $user_id);
  }

  function add_related_js() {
    $added = &drupal_static(__FUNCTION__);
    if(!$added) {
      $added = TRUE;
      drupal_add_library('system', 'drupal.ajax');
      drupal_add_js(drupal_get_path('module', 'fnl_store') . '/js/fnl_store_editable_status.js');
    }
  }

}