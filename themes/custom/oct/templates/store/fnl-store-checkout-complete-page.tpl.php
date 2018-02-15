<?php
/**
 * Checkout complete page template
 *
 * @variables:
 *  $order
 */
?>
<p>
<?php print t('Your order is complete! Your order number is !number', array('!number' => '<b>' . $order->oid . '</b>'))?>
</p>

<?php if(empty($order->data['user_created'])): ?>

<?php //USER NOT CREATED;?>
<p>
<?php print t('Thank you for shopping at OCT Store. While logged in, you may continue shopping or view your current order status and order history.'); ?>
</p>
<?php //END USER NOT CREATED;?>

<?php else: ?>

<?php //NEW USER CREATED;?>
<p>
  <?php print t("Thank you for supporting the Oklahoma Children's Theatre."); ?>
</p>
<p>
  <?php print t('Your current order has been processed and you should receive an email shortly with your purchase confirmation.'); ?>
</p>

<p>
  <b>
  <?php print t('You will need to print off your confirmation as that will be your tickets.'); ?>
  </b>
</p>

<p>
  <?php print t('Please !contact_us with any questions or comments.', array('!contact_us' => l('contact us', 'node/' . OCT_CUSTOM_CONTACT_US_NID))); ?>
</p>

<p><b><?php print t('Username')?>:</b> <?php print $order->data['user_created']['name'];?></p>
<p><b><?php print t('Password')?>:</b> <?php print $order->data['user_created']['password'];?></p>
<?php //END USER CREATED;?>

<?php endif; ?>

<p><?php print l('Return to the homepage.', '<front>')?></p>