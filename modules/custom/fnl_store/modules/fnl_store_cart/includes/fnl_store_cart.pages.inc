<?php

/**
 * @file
 * Cart pages callbacks.
 */

/**
 * Page callback for removing products from cart.
 */
function fnl_store_cart_remove_product_callback($cart_product) {
  fnl_store_cart_remove_product($cart_product);
  drupal_set_message(t('Product %name was deleted.', array('%name' => $cart_product->name)));
  drupal_goto();//go to destination if exist
  return t('Product deleted.');
}