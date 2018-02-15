<?php
/**
 * Created by PhpStorm.
 * User: Sergey Grigorenko (svipsa@gmail.com)
 * Date: 27.04.15
 * Time: 17:21
 */
?>

<div class="ftb-form-spons-row" id="<?php print $key; ?>">
  <div class="ftb-spons-cost hidden"><?php print $price; ?></div>
  <div class="ftb-form-item">
    <input type="checkbox" id="ftb_spons_<?php print $key; ?>" name="ftb_spons_<?php print $key; ?>" value="1"/>
    <label for="ftb_spons_<?php print $key; ?>"><?php print $title; ?></label>
  </div>
  <?php if (!empty($items)): ?>
  <ul class="ftb-form-list-items">
    <?php foreach ($items as $k => $item): ?>
      <li><?php print $item; ?></li>
    <?php endforeach; ?>
  </ul>
  <?php endif; ?>
</div>