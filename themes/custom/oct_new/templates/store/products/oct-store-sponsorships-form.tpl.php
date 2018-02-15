<?php

/**
 * @file Product form template
 *
 **/
//dsm($form);
//dsm($form['#node_content']);
?>
<!--<h1>TEST2222</h1>-->
<?php if ($form): ?>
  <?php print theme('status_messages'); ?>
<div class="cols cols-2">
  <div class="col">
    <?php hide($form['packages'])?>
    <?php print drupal_render_children($form); ?>
  </div>
  <div class="col">
    <?php print render($form['packages']);?>
  </div>
</div>


<?php endif; ?>