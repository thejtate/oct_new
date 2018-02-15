<?php
/**
 * Created by PhpStorm.
 * User: Sergey Grigorenko (svipsa@gmail.com)
 * Date: 27.04.15
 * Time: 17:21
 */
?>

<div class="ftb-form-row" id="<?php print $key;?>">
  <div class="ftb-cost hidden"><?php print $cost;?></div>
  <div class="ftb-form-item">
    <select name="ftb_qty_<?php print $key;?>">
      <?php for($i=0; $i<=10; $i++): ?>
        <option value="<?php print $i;?>"><?php print $i;?></option>
      <?php endfor;?>
    </select>
    <label for="ftb_qty_<?php print $key;?>"><?php print $title;?></label>
  </div>
  <div>
    <span>=$</span> <input type="text" name="ftb_price_<?php print $key;?>" value="" disabled="disabled"/>
    <?php if (!empty($cost_description)): ?>
      <span class="ftb-cost-description"><?php print $cost_description;?></span>
    <?php endif; ?>
  </div>

  <?php if (!empty($description)): ?>
    <div class="ftb-description"><?php print $description;?></div>
  <?php endif; ?>
</div>