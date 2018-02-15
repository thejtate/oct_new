<?php

/**
 * @file theme for List of products.
 */

?>
<ul class="partial-pay-not-available">
<?php foreach($products as $product): ?>
    <li><?php print $product->name?></li>
<?php endforeach; ?>
</ul>