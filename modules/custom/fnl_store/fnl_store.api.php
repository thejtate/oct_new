<?php
/**
 * Module available hooks.
 */


function hook_fnl_store_order_load_alter($order) {

}

function hook_fnl_store_order_before_save_alter($order) {

}

function hook_fnl_store_order_after_save_alter($order) {

}

function hook_fnl_store_review_order_alter($content, $order) {

}

function hook_fnl_store_empty_order_alter($order) {

}

function hook_fnl_store_products() {

  return array(
    'product_camp' => array(
      'title' => t('Camps'),
    )
  );

}