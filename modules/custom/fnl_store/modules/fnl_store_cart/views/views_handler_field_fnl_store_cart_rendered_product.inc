<?php

/**
 * @file
 * Custom class for rendered field.
 */

class views_handler_field_fnl_store_cart_rendered_product extends views_handler_field {
  function render($values) {

    $product = new stdClass();
    $product->cid = $this->get_value($values);

    if(!empty($product->cid)) {

    $product->name = $this->get_value($values, 'name');
    $product->type = $this->get_value($values, 'type');
    $product->oid = $this->get_value($values, 'oid');
    $product->nid = $this->get_value($values, 'nid');
    $product->qty = $this->get_value($values, 'qty');
    $product->amount = $this->get_value($values, 'amount');
    $product->added = $this->get_value($values, 'added');

    $product->data = $this->get_value($values, 'data');
    $product->data = !empty($product->data) ? unserialize($product->data) : NULL;

      return theme('fnl_store_cart_product__' . $product->type, array('product' => $product));
    } else {
      return '';
    }
  }
}