<?php

/**
 * @file
 * Cron functionality.
 */

/**
 * Cron callback. Remove old not ordered carts.
 */
function fnl_store_cart_delete_old_carts() {

  $days = variable_get('fnl_store_cart_delete_anonymous_carts_interval', 30);
  $db_time_zone = new DateTimeZone('UTC');

  if(!empty($days)) {
    $now_date = new DateTime("now -$days days", $db_time_zone);
  }

  $oids = db_select('fnl_store_orders', 'o')
    ->condition('status', FNL_ORDER_STATUS_CART)
    ->condition('changed', $now_date->format(DATE_FORMAT_DATETIME), '<')
    ->fields('o', array('oid'))
    ->execute()
    ->fetchCol();

  if($oids) {
    foreach ($oids as $oid) {
      fnl_store_order_delete($oid);
    }
  }
}
