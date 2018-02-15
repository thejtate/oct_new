<?php
/**
 * Checkout compleete page template
 *
 * @variables:
 *  $order
 *  $cart - Cart views
 */
?>
<p>
<?php print t('Your order is complete! Your order number is !number', array('!number' => $order->oid))?>
</p>

<p><?php print l('Return to homepage.', '<front>')?></p>