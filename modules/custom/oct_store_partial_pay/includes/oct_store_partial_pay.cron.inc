<?php

/**
 * @file
 * Cron callbacks.
 */

function oct_store_partial_pay_send_email_reminder_cron() {

  $q = db_select('fnl_store_orders', 'o')
    ->fields('o', array('oid'))
    ->condition('o.status', FNL_ORDER_STATUS_PAYMENT_PARTIAL);

  $q->join('oct_store_partial_pay', 'p', 'p.oid = o.oid');

  $notif_due_date = new DateTime('+2 days', new DateTimeZone('UTC'));
  $q->where('DATE(p.due_date) = :date', array(':date' => $notif_due_date->format(DATE_FORMAT_DATE)));

  $orders_info = $q->execute()->fetchAll();

  if(!empty($orders_info)) {
    watchdog('oct_store_partial_pay', "Order ids pushed to queue for Reminder emails <pre>" . print_r($orders_info, TRUE) . '</pre>');
    $queue = DrupalQueue::get('oct_store_partial_pay_reminder_notification');

    foreach ($orders_info as $order) {
      $queue->createItem($order->oid);
    }
  }

}

function oct_store_partial_pay_send_cancel_order_email() {

  $q = db_select('fnl_store_orders', 'o')
    ->fields('o', array('oid'))
    ->condition('o.status', FNL_ORDER_STATUS_PAYMENT_PARTIAL);

  $q->join('oct_store_partial_pay', 'p', 'p.oid = o.oid');

  $db_timezone = new DateTimeZone('UTC');
  $notif_due_date_from = new DateTime('-1 day 15:00');
  $notif_due_date_to = new DateTime('15:00');
  $notif_due_date_from->setTimeZone($db_timezone);
  $notif_due_date_to->setTimeZone($db_timezone);

  $q->where(
    'p.due_date >= :datefrom AND p.due_date < :dateto',
    array(
      ':datefrom' => $notif_due_date_from->format(DATE_FORMAT_DATETIME),
      ':dateto' => $notif_due_date_to->format(DATE_FORMAT_DATETIME)
    )
  );

  $orders_info = $q->execute()->fetchAll();

  if(!empty($orders_info)) {
    watchdog('oct_store_partial_pay', "Order ids pushed to queue for Cancel order emails <pre>" . print_r($orders_info, TRUE) . '</pre>');
    $queue = DrupalQueue::get('oct_store_partial_cancel_order_notification');

    foreach ($orders_info as $order) {
      $queue->createItem($order->oid);
    }
  }

}