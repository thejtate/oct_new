<?php
/**
 * Form fieldset theme wrapper template
 */

?>


<?php if ($element): ?>
<?php $children = element_children($element)?>

<table class="table">
  <thead>
  <tr>
    <th class="tickets"><?php print t('Tickets'); ?></th>
    <th class="price"><?php print t('Price'); ?></th>
    <th class="quantity"><?php print t('Quantity'); ?></th>
    <th class="subtotal"><?php print t('Subtotal'); ?></th>
  </tr>
  </thead>
  <tbody>
  <?php foreach($children as $child_key): ?>
      <tr>
        <td>
          <?php print $element[$child_key]['#title']?>
        </td>
        <td>
          $ <?php print number_format($element[$child_key]['#price'], 2)?>
        </td>
        <td>
          <?php print render($element[$child_key]);?>
        </td>
        <td class="subtotal">
          $0
        </td>
      </tr>
  <?php endforeach; ?>
  <?php foreach($element['#fees'] as $fee): ?>
    <tr>
      <td colspan="3"> <?php print check_plain($fee->title);?>
      </td>

      <td class="fee" data-type="<?php print $fee->percent_fixed;?>" data-amount="<?php print $fee->amount;?>">
        $0
      </td>

    </tr>
  <?php endforeach; ?>
  </tbody>
</table>
  <div class="total">
    <span><strong><?php print t('Total'); ?></strong></span>
    <span><strong class="totals">$0</strong></span>
  </div>
<?php endif;?>