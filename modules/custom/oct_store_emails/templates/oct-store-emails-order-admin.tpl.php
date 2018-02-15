<?php
/**
 * Order admin email template.
 * Based on old site email template
 *
 * @variables
 *    $order
 *    $cart
 */
?>

<?php if(!empty($message)): ?>
    <p><?php print $message?></p>
<?php endif; ?>
<p>
  <?php echo l('<< View Order >>','store/manage/order/' . $order->oid, array('absolute' => TRUE)); ?><br />
</p>
<p>
  <?php echo t('Order number:'); ?> <?php echo l($order->oid,'store/manage/order/' . $order->oid, array('absolute' => TRUE)); ?><br />
  <?php echo t('Customer:'); ?>
  <?php fnl_store_print($order->data['checkout_values']['user']['purchaser']); ?>
   - <?php fnl_store_print($order->data['checkout_values']['user']['email']); ?><br />
  <?php echo t('Order total:'); ?> <?php fnl_store_print($order->amount); ?><br />
</p>

<p>
  <?php echo t('Products:'); ?><br />

  <?php if (!empty($cart['products'])) {
  foreach ($cart['products'] as $product) {
  ?>

  <b><?php echo $product->qty; ?> x </b>
  <b><?php echo $product->name .' - '. fnl_store_format_amount($product->amount); ?></b>

  <?php if(!empty($product->properties_list)):?>
  <ul>
    <?php foreach ($product->properties_list as $prop): ?>
      <li>
        <p style="margin: 0px; padding: 0px;">
          <?php print (!empty($prop['title']) ? $prop['title'] . ':' : ''); ?>
          <?php print (!empty($prop['value']) ? $prop['value']: ''); ?>
        </p>
      </li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>

<?php }
}?>
<br />


<p>
  <?php echo t('Order status:'); ?><br />
  <?php echo $order->status; ?>
</p>