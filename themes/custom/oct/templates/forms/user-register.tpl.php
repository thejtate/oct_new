<?php
/**
 * Created by PhpStorm.
 * User: Sergey Grigorenko (svipsa@gmail.com)
 * Date: 15.04.15
 * Time: 15:15
 */
?>



<div class="form form-registration">

  <div class="form-top-wrapper">
    <?php print drupal_render($form['field_user_parent_f_name']) ?>
    <?php print drupal_render($form['field_user_parent_l_name']) ?>
    <?php print drupal_render($form['field_user_childs_f_name']) ?>
    <?php print drupal_render($form['field_user_childs_l_name']) ?>
  </div>


  <?php hide($form['actions']); ?>
  <?php hide($form['field_user_agreement']); ?>
  <?php print drupal_render_children($form) ?>

  <?php print render($form['field_user_agreement']); ?>

  <div class="btn-wrap">
    <div class="submit-wrapper">
      <?php print drupal_render($form['actions']['submit']); ?>
    </div>
  </div>

</div>