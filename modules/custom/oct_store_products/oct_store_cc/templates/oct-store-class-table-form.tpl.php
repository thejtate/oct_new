<?php
/**
 * @file Fieldset table
 */
//dsm($element);
?>

<?php if ($element): ?>

  <?php //products table?>
<?php //$product_groups = $element['#product_groups']; ?>
  <?php $product_data = $element['#product_data']; ?>
  <?php $children = $element['#children']; ?>
  <?php if (empty($product_data)): ?>
    <?php //empty message?>
    <h3><?php print t('No classes'); ?></h3>
  <?php else: ?>

    <div class="products-wrapper">

      <div class="products-head">
        <span class="description"><?php print t('Class'); ?></span>
        <span class="ages"><?php print t('Ages'); ?></span>
        <span class="price"><?php print t('Price'); ?></span>
        <?php for($i = 0; $i < $children; $i++):?>
          <span class="child"><?php print t('Child !n', array('!n' => $i + 1)); ?></span>
        <?php endfor;?>
      </div>

      <div class="results">
        <table>
          <thead>
          <tr>
            <th class="name">&nbsp;</th>
            <th class="camps"><?php print t('# classes'); ?></th>
            <th class="subtotal"><?php print t('subtotal'); ?></th>
          </tr>
          </thead>
          <tbody>
          <?php for($i = 0; $i < $children; $i++):?>
            <tr class="child-<?php print($i);?>">
              <td class="name"><?php print t('Child !n', array('!n' => $i + 1)); ?></td>
              <td class="camps"> - </td>
              <td class="subtotal"> - </td>
            </tr>
          <?php endfor;?>
          </tbody>
        </table>
        <div class="add-button-wrapper">
          <div class="btn-wrap style-c with-arrow">
            <?php print render($element['next']);?>
          </div>
        </div>
      </div>

<!--        <div class="product-section-wrapper">-->
<!--          <h3 class="section-name">--><?php //print check_plain($group['week']) ?><!--</h3>-->
          <table class="products-table">
            <tbody>
            <?php foreach ($product_data as $product_key => $product_item): ?>

              <?php $info = (array) $product_item->data['full_info']; ?>
              <?php $is_full = ($info['available_qty'] <= 0);?>

              <?php //dsm($info);?>
              <tr<?php print ($is_full ? ' class="full"' : '');?>>
                <td class="description">
                  <?php ;// print check_plain($info['date']); ?>
                  <div class="name"><?php print ($is_full ? '<span class="full-mark">FULL!!</span> ' : '') . $info['name']; ?></div>
                  <div class="popup-desc">
                    <h6><?php print $info['name'];?></h6>
                    <p class="date"><?php print str_replace('to', '-', $info['date']) ;?></p>
                    <p class="time"><?php print str_replace('to', '-', $info['time']) ;?></p>
                    <div class="desc-inner"><?php print $info['description']?></div>
                  </div>
                </td>
                <td class="ages">
                  <?php print t('Ages'); ?> <?php print check_plain(
                    $info['min_age']
                  ); ?> - <?php print check_plain($info['max_age']); ?>
                </td>
                <td class="price">
                  $<?php print check_plain($info['price']); ?>
                </td>

                <?php for($i = 0; $i < $children; $i++):?>
                  <td class="child">
                    <?php if(!empty($element[$product_key]['child_' . $i])):?>
                      <span class="empty" title="ATTENTION! This child does not meet the age requirements. Please select another age appropriate camp.">-</span>
                      <?php print render($element[$product_key]['child_' . $i]); ?>
                    <?php endif;?>
                  </td>
                <?php endfor;?>

              </tr>

            <?php endforeach; ?>


            </tbody>
          </table>
<!--        </div>-->


    </div>

  <?php endif; ?>


<?php endif; ?>
