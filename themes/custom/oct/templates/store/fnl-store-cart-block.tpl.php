<?php

/**
* Cart block.
* Available variables:
*  $cart
*/
$count = !empty($order->total_qty) ? $order->total_qty : 0;
$amount = !empty($order->amount) ? $order->amount : 0;
?>
<div class="fnl-store-cart-block oct-cart-block">
  <?php print l("Cart $$amount", FNL_STORE_CART_PAGE);?>
</div>