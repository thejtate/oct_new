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
      <td><?php print t('Subtotal'); ?>: </td><td> <?php print fnl_store_format_amount($order->subtotal_amount); ?></td>
    </tr>
    <?php if(!empty($order->data['amount_modifications']['fees'])): ?>
      <?php foreach($order->data['amount_modifications']['fees'] as $item): ?>
        <tr class="subtotal amount-modification">
          <td><?php print $item['title']; ?>: </td><td> <?php print fnl_store_format_amount($item['value']); ?></td>
        </tr>
      <?php endforeach; ?>
    <?php endif; ?>
    <?php if(!empty($order->data['amount_modifications']['discounts'])): ?>
      <?php foreach($order->data['amount_modifications']['discounts'] as $item): ?>
        <tr class="subtotal amount-modification">
          <td><?php print $item['title']; ?>: </td><td> <?php print fnl_store_format_amount($item['value']); ?></td>
        </tr>
      <?php endforeach; ?>
    <?php endif; ?>
    <tr>
      <td><h4><?php print t('Total'); ?>: </h4></td><td><h4> <b> <?php print fnl_store_format_amount($order->amount); ?></b></h4></td>
    </tr>

      <?php if(!empty($order->data['partial_payment']['total_payed_amount'])): ?>
          <tr class="subtotal amount-modification">
              <td><?php print t('Total Payed'); ?>: </td><td> <?php print fnl_store_format_amount(-$order->data['partial_payment']['total_payed_amount']); ?></td>
          </tr>
          <tr>
              <td><h4><?php print t('Due Amount'); ?>: </h4></td><td><h4> <b> <?php print fnl_store_format_amount($order->amount - $order->data['partial_payment']['total_payed_amount']); ?></b></h4></td>
          </tr>
      <?php endif; ?>
  </table>

<?php endif;?>