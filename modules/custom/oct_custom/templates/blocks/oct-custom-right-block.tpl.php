<?php
/**
 * Created by PhpStorm.
 * User: Sergey Grigorenko (svipsa@gmail.com)
 * Date: 27.04.15
 * Time: 17:21
 */
?>

<div class="sidebar-item <?php print $class; ?>">
  <?php if (!empty($content)): ?>
    <p><?php print $content; ?></p>
  <?php endif;?>
  <?php if (isset($link)): ?>
    <?php print $link; ?>
  <?php endif;?>
</div>