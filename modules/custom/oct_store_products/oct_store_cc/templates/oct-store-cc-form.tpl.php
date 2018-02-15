<?php

/**
 * @file Product form template
 *
 */
//dsm($form);
//dsm($form['#node_content']);
?>

<?php if ($form): ?>
  <?php print theme('status_messages');?>


  <?php //Page1?>
  <?php if(!empty($form['step1'])):?>
    <div class="top-part">
      <?php print render($form['#node_content']['field_class_image']);?>
      <h4><?php print render($form['#node_content']['field_camp_enroll_p1_title']);?></h4>
      <div class="text">
        <?php print render($form['#node_content']['field_camp_enroll_p1_desc']);?>
      </div>
    </div>
    <div class="fieldset-wrapper">
      <fieldset class="form-wrapper" id="edit-step1-children">
        <legend>
          <?php print $form['step1']['children']['#title'];?>
        </legend>
        <?php hide($form['step1']['children'])?>
        <?php $children = element_children($form['step1']['children']);?>

        <?php foreach($children as $child_key): ?>

          <div class="fieldset-wrapper">
            <?php hide($form['step1']['children'][$child_key]);?>
            <fieldset class="form-wrapper">
              <legend>
                <?php print $form['step1']['children'][$child_key]['#title']?>
              </legend>
              <div class="left-part">

                <?php print render($form['step1']['children'][$child_key]['first_name'])?>
                <?php print render($form['step1']['children'][$child_key]['last_name'])?>
                <div class="birthday-wrap container-inline-date" data-child="<?php print str_replace('child_', '', $child_key)?>">
                  <?php print render($form['step1']['children'][$child_key]['birth_date'])?>
                </div>
                <div class="form-item form-item-children-gender">
                  <?php print render($form['step1']['children'][$child_key]['gender'])?>
                </div>

                <?php if (isset($form['step1']['children'][$child_key]['t-shirt']['#description']) &&
                        !empty($form['step1']['children'][$child_key]['t-shirt']['#description'])): ?>
                  <div class="t-shirt-information">
                    <?php print $form['step1']['children'][$child_key]['t-shirt']['#description']; ?>
                  </div>
                <?php $form['step1']['children'][$child_key]['t-shirt']['#description'] = ''; ?>
                <?php endif; ?>

                <?php print render($form['step1']['children'][$child_key]['t-shirt'])?>

              </div>
              <div class="right-part">
                <?php print render($form['step1']['children'][$child_key]['allergy'])?>
              </div>
              <?php print drupal_render_children($form['step1']['children'][$child_key])?>
            </fieldset>
          </div>

        <?php endforeach; ?>

        <?php print drupal_render_children($form['step1']['children'])?>

      </fieldset>
    </div>
    <div class="btn-wrap style-a not-alone">
      <?php if(!empty($form['step1']['remove_child'])): ?>
        <div class="form-actions">
          <?php print render($form['step1']['remove_child']);?>
        </div>
      <?php endif; ?>
      <?php if(!empty($form['step1']['add_child'])): ?>
        <div class="form-actions">
          <?php print render($form['step1']['add_child']);?>
        </div>
      <?php endif; ?>
    </div>

    <?php print drupal_render_children($form['step1'])?>

  <?php endif; //END Page1 ?>


  <?php ;//Page2 ?>
  <?php if(!empty($form['step2'])):?>

    <?php hide($form['step2']['parents']); ?>
    <div class="fieldset-wrapper">
    <fieldset class="form-wrapper" id="edit-step2-parents">
      <legend>
        <?php print $form['step2']['parents']['#title'] ?>
      </legend>
      <div class="fieldset-wrapper">
        <?php print drupal_render_children($form['step2']['parents']); ?>

        <?php if(!empty($form['#node_content']['field_camp_enroll_p2_pdf'][0]['#file']->uri)): ?>
            <?php $url = file_create_url($form['#node_content']['field_camp_enroll_p2_pdf'][0]['#file']->uri);
              $file_desc = render($form['#node_content']['field_camp_enroll_p2_desc']);
            ?>
        <?php endif; ?>
        <a href="<?php print $url;?>" target="_blank"><?php print $file_desc;?></a>
      </div>

    </fieldset>
    </div>

    <div class="fieldset-wrapper" >
      <?php hide($form['step2']['emergency']); ?>
      <fieldset class="form-wrapper" id="edit-step2-emergency">
        <legend>
<!--          --><?php //print $form['step2']['emergency']['#title'] ?>
        </legend>
        <div class="fieldset-wrapper">
          <fieldset class="form-wrapper">
            <legend><span class="fieldset-legend"><?php print t('Emergency Contact'); ?> </span></legend>
            <div class="fieldset-wrapper">
              <?php print render($form['#node_content']['field_camp_enroll_p2_em_note']);?>

              <?php print render($form['step2']['emergency']['first_name']);?>
              <?php print render($form['step2']['emergency']['last_name']);?>
              <?php print render($form['step2']['emergency']['phone']);?>
              <?php print render($form['step2']['emergency']['relationship']);?>

            </div>
          </fieldset>

          <fieldset class="form-wrapper">
            <div class="fieldset-wrapper">
<!--              --><?php //print render($form['#node_content']['field_camp_enroll_p2_other_note']);?>
              <?php print render($form['step2']['emergency']['is_other_information']);?>
              <?php print render($form['step2']['emergency']['other_information']);?>

              </div>
          </fieldset>
        </div>
      </fieldset>
    </div>


    <?php hide($form['step2']['previous']);?>
    <?php hide($form['step2']['submit']);?>
    <?php print drupal_render_children($form['step2'])?>
    <div class="text">
      <div class="left-part">

        <span><strong>
            <?php print render($form['#node_content']['field_camp_enroll_p2_title_left']);?>
          </strong></span>
        <?php print render($form['#node_content']['field_camp_enroll_p2_desc_left']);?>
      </div>
      <div class="right-part">
        <span><strong><?php print render($form['#node_content']['field_camp_enroll_p2_title_right']);?></strong></span>
        <?php print render($form['#node_content']['field_camp_enroll_p2_desc_right']);?>
      </div>
    </div>
    <div class="bottom-form">
      <span class="info">* Required fields</span>
      <div class="btn-wrap style-a not-alone">
        <div class="desc">
          <?php print render($form['#node_content']['field_camp_enroll_p2_terms']);?>
        </div>
        <div class="form-actions">
          <?php print render($form['step2']['previous']); ?>
        </div>

        <div class="form-actions">
          <?php print render($form['step2']['submit']); ?>
        </div>

      </div>
    </div>

  <?php endif; //END Page2 ?>

  <?php print drupal_render_children($form); ?>
  <?php
    if (!empty($form['#attached'])) {
      //drupal_process_attached($elements);
    };
  ?>


<?php endif; ?>