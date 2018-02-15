<?php

/**
 * @file
 * Cron callbacks.
 */


function fnl_store_payment_check_pending_orders() {

  $hours = variable_get('fnl_store_payment_set_payment_failed_interval', 24);
  $db_time_zone = new DateTimeZone('UTC');

  if(!empty($hours)) {
    $changed_date = new DateTime("now -$hours hours", $db_time_zone);

    $oids = db_select('fnl_store_orders', 'o')
      ->condition('status', FNL_ORDER_STATUS_PAYMENT_IN_PROGRESS)
      ->condition('changed', $changed_date->format(DATE_FORMAT_DATETIME), '<')
      ->fields('o', array('oid'))
      ->execute()
      ->fetchCol();

    foreach ($oids as $oid) {
      $order = fnl_store_order_load($oid);

      if($order->status == FNL_ORDER_STATUS_PAYMENT_IN_PROGRESS) {

      $set_status_to_failed = TRUE;
      drupal_alter('fnl_store_payment_check_pending_orders', $set_status_to_failed, $order);

        if($set_status_to_failed) {
          watchdog('fnl_store_payment', "Order # $oid has payment status 'In Progress' more than $hours hours. Status set to Failed.");
          $order->status = FNL_ORDER_STATUS_PAYMENT_FAILED;
          fnl_store_order_save($order);
        }
      }
    }
  }
}