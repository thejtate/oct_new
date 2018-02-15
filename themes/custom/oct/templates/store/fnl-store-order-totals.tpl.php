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
      <td><?php print t('Total'); ?>: </td><td> <?php print fnl_store_format_amount($order->amount); ?></td>
    </tr>
  </table>

<?php endif;?>