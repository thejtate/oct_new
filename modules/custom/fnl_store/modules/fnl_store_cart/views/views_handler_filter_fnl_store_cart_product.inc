<?php

/**
 * @file
 * Custom filter for datetime custom table fields
 */

class views_handler_filter_fnl_store_cart_product extends views_handler_filter_in_operator {
  function get_value_options() {

    $products = fnl_store_products();
    $products_options = array();
    foreach ($products as $name => $info) {
      $products_options[$name] = $info['title'];
    }

    $this->value_options = $products_options;
  }
}