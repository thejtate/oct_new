<?php
/**
 * Form fieldset theme wrapper template
 */
//dsm($element);
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
        <?php if($child_key !== 'names_lists'): ?>
        <tr>
          <td>
            <strong><?php print $element[$child_key]['#title']?></strong>
            <?php print $element[$child_key]['#ticket_description']?>
            <?php print render($element['names_lists'][$child_key]);?>
          </td>
          <td>
            $<?php print number_format($element[$child_key]['#price'], 2)?>
          </td>
          <td>
            <?php print render($element[$child_key]);?>
          </td>
          <td class="subtotal">
            $0
          </td>
        </tr>
        <?php endif; ?>
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
<!--    <div class="sponsor">-->
<!--      <span><strong>Sponsorship Opportunities</strong></span>-->
<!--  -->
<!--      <div class="btn-wrap style-c with-arrow">-->
<!--        <div class="form-actions">-->
<!--          <a href="#">View</a>-->
<!--        </div>-->
<!--      </div>-->
<!--    </div>-->
    <div class="total">
            <span><i><?php print render($element['#bottom_note'])?></i></span>
      <span><strong>Total</strong>	</span>
      <span><strong class="totals">$45.50</strong></span>
    </div>

<?php endif;?>