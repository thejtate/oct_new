<?php
/**
 * Template for order totals.
 * @variables
 *    $order
 */
?>

<?php if(isset($order->subtotal_amount) && isset($order->amount)):?>

  <table class="table-price">
    <tr class="subtotal">
      <td><?php print t('Total'); ?>: </td><td> <?php print fnl_store_format_amount($order->amount); ?></td>
    </tr>
      <tr class="subtotal">
          <?php $total_payed = !empty($order->data['partial_payment']['total_payed_amount']) ? $order->data['partial_payment']['total_payed_amount'] : 0;?>
          <td><?php print t('Amount Paid'); ?>: </td><td> <?php print fnl_store_format_amount(-$total_payed); ?></td>
      </tr>
    <tr>
      <td><h4><?php print t('Amount Due'); ?>: </h4></td><td><h4> <b> <?php print fnl_store_format_amount($order->amount - $total_payed); ?></b></h4></td>
    </tr>
  </table>

<?php endif;?>