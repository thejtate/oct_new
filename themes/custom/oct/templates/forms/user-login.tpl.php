<?php
/**
 * Created by PhpStorm.
 * User: Sergey Grigorenko (svipsa@gmail.com)
 * Date: 15.04.15
 * Time: 15:15
 */
?>



<div class="form">
  <h4>Sign in</h4>
  <?php print drupal_render($form['name']); ?>
  <?php print drupal_render($form['pass']); ?>
  <div class="btn-wrap">
    <div class="submit-wrapper">
      <?php print drupal_render($form['actions']['submit']); ?>
    </div>
  </div>
  <?php print drupal_render_children($form) ?>
</div>

<div class="block-reg">
  <span><?php print t("New here?");?></span>
  <?php print l(t("Go!"), "user/register", array("attributes" => array("class" => array("button-go"))));?>
</div>