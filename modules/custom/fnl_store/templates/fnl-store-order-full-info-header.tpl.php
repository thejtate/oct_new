<?php
/**
 * Template for order full info head.
 * @variables
 *    $order
 */
?>

<h3><?php print t('Order id: ') . $order->oid?></h3>

<?php if(!empty($order->data['checkout_values']['user'])):?>
  <?php $user_data = $order->data['checkout_values']['user'];?>
  <h3><?php print t('Bill to'); ?></h3>

  <?php fnl_store_print($user_data['first_name'])?>
  <?php fnl_store_print($user_data['last_name'])?>
  </br>
  <?php fnl_store_print($user_data['city'])?>
  <?php fnl_store_print($user_data['state'])?>
  <?php fnl_store_print($user_data['zip'])?>
  <?php fnl_store_print($user_data['address'])?>
  </br>
  <?php fnl_store_print($user_data['phone'])?>
  <?php fnl_store_print($user_data['email'])?>
  </br>

<?php endif;?>