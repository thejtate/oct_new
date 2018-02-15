
<?php global $base_path; ?>
<?php $path_to_theme = drupal_get_path('theme', 'oct_new'); ?>

<?php print render($form['cart']); ?>
<div class="form-item form-type-textfield form-text-discount">
  <?php print render($form['discount']); ?>
</div>
<div class="form-item form-text-partial">
  <?php print render($form['partial_payment']); ?>
</div>

<div class="form form-checkout">
  <fieldset>
    <div class="fieldset-wrapper">
      <h5><strong><?php print t('Billing Information'); ?></strong></h5>

      <div class="form-item form-type-textfield style-a width-50">
        <?php print render($form['user']['first_name']); ?>
      </div>

      <div class="form-item form-type-textfield width-50">
        <?php print render($form['user']['last_name']); ?>
      </div>

      <div class="form-item form-type-textfield">
        <?php print render($form['user']['address']); ?>
      </div>
      <div class="form-item form-type-textfield form-text-city">
        <?php print render($form['user']['city']); ?>
      </div>

      <div class="form-item form-type-textfield form-text-state">
        <?php print render($form['user']['state']); ?>
      </div>

      <div class="form-item form-type-textfield form-text-zip">
        <?php print render($form['user']['zip']); ?>
      </div>
    </div>
  </fieldset>

  <fieldset class="billing-second-column">
<!--    <h5><strong>--><?php //print t('Billing Information'); ?><!--</strong></h5>-->

    <div class="fieldset-wrapper">

      <div class="form-item form-type-textfield style-a width-50">
        <?php print render($form['user']['phone']); ?>
      </div>

      <div class="form-item form-type-textfield style-a width-50">
        <?php print render($form['user']['email']); ?>
      </div>

      <div class="form-item form-type-textfield style-a width-50">
        <?php print render($form['user']['email_confirm']); ?>
      </div>

    </div>
  </fieldset>
  <p><strong><?php print t('Payment Method'); ?></strong></p>

  <div class="text">
    <img src="<?php print $base_path . $path_to_theme; ?>/images/icons/paypal.png">

    <p><i><?php print t('Pay without sharing your financial information (no PayPal account required). Includes:'); ?></i></p>
    <img src="<?php print $base_path . $path_to_theme; ?>/images/icons/cards.png" alt="">
  </div>
</div>

<div class="btn-wrap style-c with-arrow">
  <div class="form-actions">
    <?php print render($form['submit']); ?>
  </div>
</div>

<?php hide($form['user']); ?>
<?php print drupal_render_children($form); ?>