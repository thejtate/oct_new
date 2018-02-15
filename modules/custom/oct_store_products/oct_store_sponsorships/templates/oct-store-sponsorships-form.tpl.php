<?php

/**
 * @file Product form template
 *
 **/

//See in theme templates
?>
<?php if ($form): ?>
  <?php print theme('status_messages'); ?>

  <?php print drupal_render_children($form); ?>

<?php endif; ?>