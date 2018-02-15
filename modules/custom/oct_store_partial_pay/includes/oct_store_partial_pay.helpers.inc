<?php

/**
 * @file dev helpers.
 */

function oct_store_partial_pay_test() {
  $order = fnl_store_order_load(2422);
  dsm($order);
  $cart = fnl_store_cart_load(2422);
  $order->data['checkout_values']['user']['email'] = 'test@test.comm';
  $output = '<iframe width="80%" height="1200px" frameborder="0" id="preview-frame">';

  $output .= '</iframe>';

  $output .= '<div id="mail-preview" style="display:none;">';
  $output  .= theme(
    'oct_store_emails_order_partial_paid_admin',
//    'oct_store_emails_order_partial_paid',
//    'oct_store_emails_order_partial_paid_canceled',
//    'oct_store_emails_order_partial_paid_finish_payment_reminder',
    array(
      'order' => $order,
      'cart' => $cart,
      'store_link' => l(variable_get('site_name', "Oklahoma Children's Theatre") . ' store', '<front>'),
      'site_logo' => oct_store_emails_site_logo_html(),
      'user_email' => oct_store_emails_get_user_email_from_order($order),
    )
  );
  $output .= '</div>';

  //insert iframe content dynamically
  drupal_add_js(
    'jQuery(document).ready(function () {
        jQuery("iframe#preview-frame").contents().find("body").html(jQuery("#mail-preview").html());
       });',
    array('type' => 'inline', 'scope' => 'footer', 'weight' => 5)
  );


  return '<h1> test</h1> <br>' . $output;
}