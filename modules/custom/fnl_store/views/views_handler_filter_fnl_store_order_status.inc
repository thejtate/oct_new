<?php

/**
 * @file
 * Custom filter for datetime custom table fields
 */

class views_handler_filter_fnl_store_order_status extends views_handler_filter_in_operator {
  function get_value_options() {
    $this->value_options = drupal_map_assoc(fnl_store_order_statuses());
  }
}