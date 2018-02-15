<?php
/**
 * @file
 *  Handlers for each discount type.
 */

/**
 * Handler for "manual" discount type.
 */
function oct_store_discounts_manual_handler(&$order, $cart, $discount, $discount_type_info) {

  if(!empty($order->data['triggered_discounts_nids']) && in_array($discount->nid, $order->data['triggered_discounts_nids'])) {

    $discount_amount = 0;

    foreach ($cart['products'] as $product) {

      if(empty($discount->products) || in_array($product->type, $discount->products)) {
        if($discount->percent_fixed === 'fixed') {
          //apply fixed discount amount, but not greater than product amount
          $discount_amount += ($discount->amount <= $product->amount) ? $discount->amount : $product->amount;
        } elseif($discount->percent_fixed === 'percent') {
          $discount_amount += $product->amount * $discount->amount / 100;
        }
      }
    }

    if($discount_amount !== 0) {
      $order->data['amount_modifications']['discounts'][] = array(
        'title' => $discount->title,
        'type' => 'discount',
        'value' => -$discount_amount,
      );
    }

    $order->amount = $order->amount - $discount_amount;
  }
}

/**
 * Handler for "class_camps_multiple" discount type.
 */
function oct_store_discounts_class_camps_multiple_handler(&$order, $cart, $discount, $discount_type_info) {

  $discount_amount = 0;

  $products_grouped_by_children = array();

  foreach ($cart['products'] as $product) {
    //make product groups for the same child
    if(in_array($product->type, $discount_type_info['products'])) {
      $full_child_info_string = trim(strtolower($product->data['child_info']['first_name']));
      $full_child_info_string .= '_' . trim(strtolower($product->data['child_info']['last_name']));
      $full_child_info_string .= '_' . trim(strtolower($product->data['child_info']['birth_date']));

      $products_grouped_by_children[$full_child_info_string][] = $product;
    }
  }

  foreach ($products_grouped_by_children as $child => $child_products) {
    foreach ($child_products as $delta => $product) {
      //for each child product starts from second
      if($delta != 0) {
        if($discount->percent_fixed === 'fixed') {
          //apply fixed discount amount, but not greater than product amount
          $discount_amount += ($discount->amount <= $product->amount) ? $discount->amount : $product->amount;
        } elseif($discount->percent_fixed === 'percent') {
          $discount_amount += $product->amount * $discount->amount / 100;
        }
      }
    }
  }

  if($discount_amount !== 0) {

    $order->data['amount_modifications']['discounts'][] = array(
      'title' => $discount->title,
      'type' => 'discount',
      'value' => -$discount_amount,
    );

    $order->amount = $order->amount - $discount_amount;
  }

}