<?php

/**
 * @file
 * Save, loading, updating cart.
 */

/**
 * Load order cart.
 *
 * @param $oid optional, will load cart attached to the order.
 * Load current
 * @param bool $reset
 * @return mixed
 */
function fnl_store_cart_load($oid = NULL, $reset = FALSE) {

  $oid = !empty($oid) ? $oid : fnl_store_cart_order_id_load();

  $carts_static = &drupal_static('fnl_store_cart');
  if (!isset($carts_static[$oid]) || $reset) {
    $cart = array();
    $products = db_select('fnl_store_cart', 'c')
      ->condition('oid', $oid)
      ->fields('c')
      ->execute()
      ->fetchAll();

    if(!empty($products)) {
      foreach ($products as &$product) {
        if(!empty($product->data)) {
          $product->data = unserialize($product->data);
        }
      }
    }

    $cart['products'] = $products;

    drupal_alter('fnl_store_load_cart', $cart, $oid);

    $carts_static[$oid] = !empty($cart['products']) ? $cart : NULL;
  }

  return $carts_static[$oid];
}

/**
 * Add product to cart.
 *
 * @param $cart_item
 * @param $oid Order id, by default current user cart order (optional)
 *
 * @return object Saved product.
 */
function fnl_store_cart_add_product($product, $oid = NULL) {

  if(!isset($product->user_id)) {
    $product->user_id = fnl_store_cart_user_id();
  }

  $product->oid = !empty($oid) ? $oid : fnl_store_cart_order_id_load();
  $order = fnl_store_order_load($product->oid);
  if(empty($order)) {
    $order = fnl_store_cart_order_new();
    $product->oid = $order->oid;
  }

  $product->added = gmdate(DATE_FORMAT_DATETIME, REQUEST_TIME);

  module_invoke_all('fnl_store_cart_before_add_product', $product);

  if(drupal_write_record('fnl_store_cart', $product)) {
    $carts_static = &drupal_static('fnl_store_cart');
    $carts_static[$product->oid] = NULL;//reset static for this cart
  }

  module_invoke_all('fnl_store_cart_after_add_product', $product);

  fnl_store_cart_attach_calculation($order);

  return $product;
}

/**
 * Remove cart product.
 *
 * @param $cid
 */
function fnl_store_cart_remove_product($product) {

  db_delete('fnl_store_cart')
    ->condition('cid', $product->cid)
    ->execute();

  $carts_static = &drupal_static('fnl_store_cart');
  $carts_static = NULL;//reset static

  module_invoke_all('fnl_store_cart_after_remove_product', $product);

  $order = fnl_store_order_load($product->oid);
  if(!empty($order)) {
    fnl_store_cart_attach_calculation($order);
  }
}

/**
 * Calculate cart totals.
 */
function fnl_store_cart_attach_calculation(&$order) {
  $cart = fnl_store_cart_load($order->oid);

  $order->total_qty = 0;
  $order->subtotal_amount = 0;
  $order->amount = 0;

  if(!empty($cart['products'])) {
    foreach ($cart['products'] as $product) {
      $order->total_qty += $product->qty;
      $order->subtotal_amount += $product->amount * $product->qty;
    }
  }

  $order->amount = $order->subtotal_amount;

  drupal_alter('fnl_store_cart_calculation', $order, $cart);

  fnl_store_order_save($order);
}


/**
 * Load single product.
 *
 * @param $cid Cart item id.
 * @return mixed
 */
function fnl_store_cart_product_load($cid) {
  $product = db_select('fnl_store_cart', 'c')
    ->condition('cid', $cid)
    ->fields('c')
    ->execute()
    ->fetchObject();
  return $product;
}

/**
 * Load user order id for current cart.
 */
function fnl_store_cart_order_id_load($user_id = NULL) {
  $user_id = empty($user_id) ? fnl_store_cart_user_id() : $user_id;

  return db_select('fnl_store_orders', 'o')
    ->condition('o.user_id', $user_id)
    ->condition('o.status', FNL_ORDER_STATUS_CART)
    ->fields('o', array('oid'))
    ->execute()->fetchField();
}

/**
 * Update order cart user id. Need for changing user_id from anonymous to registered users.
 *
 * @param $oid int Order id
 * @param $user_id int new userid
 */
function fnl_store_cart_update_user_id($oid, $user_id) {
  db_update('fnl_store_cart')
    ->fields(array('user_id' => $user_id))
    ->condition('oid', $oid)
    ->execute();
}