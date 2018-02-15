<?php
/**
 * Module available hooks.
 */

/**
 * Register payment providers.
 */
function hook_fnl_store_payment_providers() {
  return array(
    'paypal' => array(
      'title' => 'PayPal',
      'checkout_description' => 'PayPal - pay without sharing your financial information.',
      //calbacks
      'settings_form_callback' => 'fnl_store_paypal_settings_form', // arguments ($form_full, &$form_state)
      'payment_callback' => 'fnl_store_paypal_pay', // arguments (&$order)
    )
  );
}

function fnl_store_payment_transaction_before_save($trasaction) {

}

function fnl_store_payment_transaction_after_save($trasaction) {

}

function fnl_store_payment_get_transaction_amount_alter(&$amount, $order) {

}


/**
 * Invoked by cron for outdated pedning order. Decide to chenge order status to failed or not.
 */
function fnl_store_payment_check_pending_orders_alter(&$set_status_to_failed, $order) {

}