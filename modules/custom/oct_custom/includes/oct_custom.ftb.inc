<?php
/**
 * @file OCT Fairy Tale Ball
 *
 * @author Sergey Grigorenko <svipsa@gmail.com>
 */


/**
 * FTB form.
 * @param $form
 * @param $form_state
 * @param $variables
 * @return mixed
 */
function oct_custom_fairy_tale_ball_common_form($form, &$form_state, $variables){
  $form['#variables'] = $variables;

  $form['total'] = array(
    '#type' => 'textfield',
    '#title' => t('Total'),
    '#description' => t('Total'),
    '#default_value' => '0.00',
    '#disabled' => TRUE,
    '#prefix' => '<div class="form-input-wrapper">$',
    '#suffix' => '</div>',
  );

  $form['handling_fee'] = array(
    '#type' => 'textfield',
    '#title' => t('Handling Fee'),
    '#description' => t('Handling Fee'),
    '#default_value' => '0.00',
    '#disabled' => TRUE,
    '#prefix' => '<div class="form-input-wrapper">$',
    '#suffix' => '</div>',
  );

  $form['total_attendee_cost'] = array(
    '#type' => 'textfield',
    '#title' => t('TOTAL ATTENDEE COST'),
    '#description' => t('TOTAL ATTENDEE COST'),
    '#default_value' => '0.00',
    '#disabled' => TRUE,
    '#prefix' => '<div class="form-input-wrapper">$',
    '#suffix' => '</div>',
  );


  $form['wish_donate_checkbox'] = array(
    '#type' => 'checkbox',
    '#title' => t('Unable to attend, but I wish to donate'),
  );


  $form['wish_donate_cost'] = array(
    '#type' => 'textfield',
    '#title' => t('TOTAL ATTENDEE COST'),
    '#default_value' => '',
    '#prefix' => "$",
    '#suffix' => "to",
  );


  $form['description'] = array(
    '#type' => 'textarea',
    '#prefix' => '<div class="ftb-form-description">',
    '#suffix' => '</div>',
  );

  $form['#validate'][] = 'oct_custom_fairy_tale_ball_common_form_validate';
  $form['submit'] = array('#type' => 'submit', '#value' => t('Next'));

  $form['#theme'] = "oct_custom_ftb_form";
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'oct_custom') . '/js/oct_custom_ftb_form.js',
  );

  return $form;
}

/**
 * FTB form validate.
 * @param $form
 * @param $form_state
 */
function oct_custom_fairy_tale_ball_common_form_validate($form, &$form_state) {
  $total = (isset($form_state['values']['total'])) ? $form_state['values']['total'] : 0;
  $int_total = (int) $total;
  if (empty($int_total)){
    form_set_error('total', t("Choose something."));

  }
}


/**
 * FTB form submit.
 * @param $form
 * @param $form_state
 */
function oct_custom_fairy_tale_ball_common_form_submit($form, &$form_state) {
   $total = (isset($form_state['values']['total'])) ? $form_state['values']['total'] : 0;
   $handling_fee = (isset($form_state['values']['handling_fee'])) ? $form_state['values']['handling_fee'] : 0;
   $total_attendee_cost = (isset($form_state['values']['total_attendee_cost'])) ? $form_state['values']['total_attendee_cost'] : 0;
   $description = (isset($form_state['values']['description'])) ? $form_state['values']['description'] : '';

  //@TODO: Add to cart
}


/**
 * FTB page preprocess.
 * @param $vars
 * @throws Exception
 */
function _oct_custom_fairy_tale_ball_form_preprocess(&$vars) {
  $base_items_output = _oct_custom_fairy_tale_ball_form_render_item($vars, "field_ftbf_base_items");
  $and_or_items_output = _oct_custom_fairy_tale_ball_form_render_item($vars, "field_ftbf_and_or_items", "field_ftbf_ao_items");
  $optional_items_output = _oct_custom_fairy_tale_ball_form_render_item($vars, "field_ftbf_opt_items");
  $spons_output = _oct_custom_fairy_tale_ball_form_spons_render_item($vars, "field_ftbf_spons");

  $variables = array(
    'base_items' => $base_items_output,
    'and_or_items' => $and_or_items_output,
    'optional_items' => $optional_items_output,
    'coins_details' => render($vars['content']['field_ftbf_coins_details']),
    'field_ftbf_spons_desc' => render($vars['content']['field_ftbf_spons_desc']),
    'field_ftbf_spons' => $spons_output,
    'bottom_description' => render($vars['content']['field_ftbf_bottom_desc']),
  );

  $form = drupal_get_form('oct_custom_fairy_tale_ball_common_form', $variables);
  $vars['content']['ftb_form'] = array(
    '#type' => 'markup',
    '#markup' => drupal_render($form)
  );
}


/**
 * Implements hook_form_FORM_ID_alter().
 */
function oct_custom_form_oct_custom_fairy_tale_ball_common_form_alter(&$form, &$form_state, $form_id) {
  //kpr($form);
}






/**
 * Render FTB Form item.
 *
 * @param $vars
 * @param $field
 * @param null $fc_field
 * @return string
 * @throws Exception
 */
function _oct_custom_fairy_tale_ball_form_render_item($vars, $field, $fc_field = NULL) {
  $fc_field = (!empty($fc_field)) ? $fc_field : $field;
  $output = "";
  $items = (isset($vars['content'][$field]['#items'])) ? $vars['content'][$field]['#items'] : array();
  foreach ($items as $key => $value) {
    if (isset($value['value'])) {
      $fc_wrapper = entity_metadata_wrapper('field_collection_item', $value['value']);
      $options = array(
        'title' => $fc_wrapper->{$fc_field . "_title"}->value(),
        'description' => $fc_wrapper->{$fc_field . "_desc"}->value(),
        'cost' => $fc_wrapper->{$fc_field . "_cost"}->value(),
        'cost_description' => $fc_wrapper->{$fc_field . "_cost_desc"}->value(),
        'key' => 'ftb_key_' . $fc_wrapper->getIdentifier(),
      );
      $output .= theme("oct_custom_ftb_item", $options);
    }
  }
  return $output;
}

/**
 * Render FTB sponsors item.
 *
 * @param $vars
 * @param $field
 * @param null $fc_field
 * @return string
 * @throws Exception
 */
function _oct_custom_fairy_tale_ball_form_spons_render_item($vars, $field, $fc_field = NULL) {
  $fc_field = (!empty($fc_field)) ? $fc_field : $field;
  $output = "";
  $items = (isset($vars['content'][$field]['#items'])) ? $vars['content'][$field]['#items'] : array();
  foreach ($items as $key => $value) {
    if (isset($value['value'])) {
      $fc_wrapper = entity_metadata_wrapper('field_collection_item', $value['value']);
      $options = array(
        'title' => $fc_wrapper->{$fc_field . "_title"}->value(),
        'price' => $fc_wrapper->{$fc_field . "_price"}->value(),
        'items' => $fc_wrapper->{$fc_field . "_items"}->value(),
        'key' => 'ftb_spons_key_' . $fc_wrapper->getIdentifier(),
      );
      $output .= theme("oct_custom_ftb_spons", $options);
    }
  }
  return $output;
}
