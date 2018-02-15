<?php
/**
 * Module available hooks.
 */

function hook_fnl_store_load_cart_alter($cart, $user_id) {

}

function hook_fnl_store_cart_before_add_product($product) {

}

function hook_fnl_store_cart_after_add_product($product) {

}

/**
 * @param $cid Cart item id
 */
function hook_fnl_store_cart_after_remove_product($product) {

}

function hook_fnl_store_cart_calculation_alter(&$order, $cart) {

}

/**
 * Prepare product line items to render in different templates
 */
function hook_fnl_store_cart_product_prepare_view($product) {

  if($product->type === 'product_camp') {

    $product->properties_list[] = array(
      'title' =>  t('Child’s first name'),
      'value' => !empty($product->data['child_info']['first_name']) ? check_plain($product->data['child_info']['first_name']) : '',
    );

    if(!empty($product->data['full_info']['days'])) {
      $product->properties_list[] = array(
        'title' =>  t('Days'),
        'value' => check_plain($product->data['full_info']['days']),
      );
    }

  }

}