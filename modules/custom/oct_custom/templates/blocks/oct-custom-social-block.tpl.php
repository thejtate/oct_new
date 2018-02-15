<?php
?>

<section class="section section-items">
  <div class="items">
    <?php foreach ($items as $key => $val) : ?>
      <div class="item">
        <?php print render($val['data']); ?>
      </div>
    <?php endforeach; ?>
  </div>
</section>

