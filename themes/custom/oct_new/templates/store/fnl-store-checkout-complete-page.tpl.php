<?php
/**
 * Checkout complete page template
 *
 * @variables:
 *  $order
 * $cart - Cart views
 */
?>

<h3 class="complete-head">
<?php print t('Your order is complete!');?>
</h3>
<div class="invoice">
  <?php print render($invoice);?>
  <div class="btn-wrap style-a">
    <div class="form-actions">
      <a href="javascript:window.print()" class="button"><?php print t('Print'); ?></a>
    </div>
  </div>
</div>

