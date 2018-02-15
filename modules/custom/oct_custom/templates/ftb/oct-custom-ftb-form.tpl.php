<?php
/**
 * Created by PhpStorm.
 * User: Sergey Grigorenko (svipsa@gmail.com)
 * Date: 27.04.15
 * Time: 17:21
 */

?>

<?php print $form['#variables']['base_items']; ?>
  <h3><?php print t("AND/OR");?></h3>
<?php print $form['#variables']['and_or_items']; ?>
  <h3><?php print t("OPTIONAL");?></h3>
<?php print $form['#variables']['optional_items']; ?>

  <div class="wtb-form">
    <?php print drupal_render($form['total']); ?>
    <?php print drupal_render($form['handling_fee']); ?>
    <?php print drupal_render($form['total_attendee_cost']); ?>
  </div>
  <div class="ftb-coin-details"><?php print $form['#variables']['coins_details']; ?></div>

  <div class="title-wrapper"><h2><?php print t("Sponsorships");?></h2></div>
  <div class="ftb-spons-desc"><?php print $form['#variables']['field_ftbf_spons_desc']; ?></div>

  <div class="ftb-spons-list">
    <?php print $form['#variables']['field_ftbf_spons']; ?>
  </div>

  <div class="wtb-wish-donate">
    <?php print drupal_render($form['wish_donate_checkbox']); ?>
    <?php print drupal_render($form['wish_donate_cost']); ?>
    <span><?php print t("Oklahoma Children’s Theatre");?></span>
  </div>

<?php print drupal_render_children($form); ?>

<?php if (isset($form['#variables']['bottom_description'])): ?>
  <div class="wtb-bottom-description">
    <?php print $form['#variables']['bottom_description']; ?>
  </div>
<?php endif; ?>