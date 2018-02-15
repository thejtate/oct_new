<?php
/**
 * @file Render store product for views field handler
 *
 * Variables:
 *  - $product
 *
 * Templates
 * fnl-store-cart-product.tpl.php
 * fnl-store-cart-product--[product_name].tpl.php
 * 
 */
?>
<h3><?php print $product->name?></h3>

<ul>
  <?php foreach($product->properties_list as $prop): ?>

    <li>

      <?php if(!empty($prop['title'])): ?>
        <?php print $prop['title'];?>:
      <?php endif; ?>

      <?php if(!empty($prop['value'])): ?>
        <?php print $prop['value']?>
      <?php endif; ?>
    </li>

  <?php endforeach; ?>
</ul>