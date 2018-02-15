<?php
/**
 * @file OCT custom blocks
 *
 * @author Sergey Grigorenko <svipsa@gmail.com>
 */

module_load_include("inc", "oct_custom", "includes/oct_custom.social_menu.maps");


/**
 * Social links mapping
 * @return array
 */
function oct_custom_block_social_map() {
  return array(
    "facebook" => t("Facebook"),
    "newsletter" => t("Newsletter"),
    "annual" => t("Annual Pass"),
    "donation" => t("Make a Donation")
  );
}


/**
 * Implements hook_block_info().
 */
function oct_custom_block_info() {
  $blocks = array();

  $blocks['oct_custom_subscribe_block'] = array(
    'info' => t('Oct custom: Subscribe block'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );

  $blocks['oct_custom_social_block'] = array(
    'info' => t('Oct custom: Social block'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );

  $blocks['oct_custom_make_donation'] = array(
    'info' => t('Oct custom: Make a Donation Online'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );

  $blocks['oct_custom_prop_room_block'] = array(
    'info' => t('Oct custom: Prop room block'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );

  $blocks['oct_custom_message_board_block'] = array(
    'info' => t('Oct custom: Message board block'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );

  $blocks['oct_custom_calendar_block'] = array(
    'info' => t('Oct custom: Calendar block'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );

  $blocks['oct_custom_social_menu_block'] = array(
    'info' => t('Oct custom: Social menu block'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
  );

  return $blocks;
}

/**
 * Implements hook_block_configure().
 */
function oct_custom_block_configure($delta = '') {
  $form = array();

  switch ($delta) {
    case 'oct_custom_social_block':
      $key = 'oct_custom_sb_';
      $base = array(
        '#type'=>'text_format',
        '#required' => FALSE,
        '#cols' => 60,
        '#rows' => 5,
      );
      $item_keys = oct_custom_block_social_map();
      foreach ($item_keys as $item_key => $item_title) {
        $def = variable_get($key . $item_key, '');
        $form[$key . $item_key] = array(
            '#title' => $item_title,
            '#default_value' => !empty($def) ? $def['value'] : $def,
          ) + $base;
      }
      break;
    case 'oct_custom_subscribe_block':
      $form['oct_custom_subscribe_block_mailchimp_form'] = array(
        '#title' => t("MailChimp Signup Form"),
        '#default_value' => variable_get('oct_custom_subscribe_block_mailchimp_form'),
        '#type' => 'textarea',
        '#required' => FALSE,
        '#cols' => 60,
        '#rows' => 5,
      );
      break;
    case 'oct_custom_make_donation':
      $form['oct_custom_make_donation_code'] = array(
        '#title' => t("Make a Donation Online code"),
        '#default_value' => variable_get('oct_custom_make_donation_code'),
        '#type' => 'textarea',
        '#required' => TRUE,
        '#cols' => 60,
        '#rows' => 5,
      );
      break;
    case 'oct_custom_prop_room_block':
      $form['oct_custom_prop_room_link'] = array(
        '#title' => t("Link"),
        '#default_value' => variable_get('oct_custom_prop_room_link'),
        '#type' => 'textfield',
        '#required' => TRUE,
      );
      $form['oct_custom_prop_room_text'] = array(
        '#title' => t("Text"),
        '#default_value' => variable_get('oct_custom_prop_room_text'),
        '#type' => 'textarea',
      );
      break;
    case 'oct_custom_message_board_block':
      $form['oct_custom_message_board_link'] = array(
        '#title' => t("Link"),
        '#default_value' => variable_get('oct_custom_message_board_link'),
        '#type' => 'textfield',
        '#required' => TRUE,
      );
      $form['oct_custom_message_board_text'] = array(
        '#title' => t("Text"),
        '#default_value' => variable_get('oct_custom_message_board_text'),
        '#type' => 'textarea',
      );
      break;
    case 'oct_custom_calendar_block':
      $form['oct_custom_calendar_link'] = array(
        '#title' => t("Link"),
        '#default_value' => variable_get('oct_custom_calendar_link'),
        '#type' => 'textfield',
        '#required' => TRUE,
      );
      $form['oct_custom_calendar_text'] = array(
        '#title' => t("Text"),
        '#default_value' => variable_get('oct_custom_calendar_text'),
        '#type' => 'textarea',
      );
      break;
    case 'oct_custom_social_menu_block':
      $item_keys = _oct_custom_social_menu_admin_settings_map();
      foreach ($item_keys as $item_key => $item) {
        $def = variable_get($item_key, '');
        $title = isset($item['title']) ? $item['title'] : '';
        $form[$item_key] = array(
          '#title' => $title,
          '#default_value' => $def,
          '#type' => 'textfield',
        );
      }
      break;
  }

  return $form;
}

/**
 * Implements hook_block_save().
 */
function oct_custom_block_save($delta = '', $edit = array()) {
  switch ($delta) {
    case 'oct_custom_social_block':
      $key = 'oct_custom_sb_';
      $item_keys = oct_custom_block_social_map();
      foreach ($item_keys as $item_key => $item_title) {
        if (isset($edit[$key . $item_key])) {
          variable_set($key . $item_key, $edit[$key . $item_key]);
        }
      }
      break;
    case 'oct_custom_subscribe_block':
      variable_set('oct_custom_subscribe_block_mailchimp_form', $edit['oct_custom_subscribe_block_mailchimp_form']);
      break;
    case 'oct_custom_make_donation':
      variable_set('oct_custom_make_donation_code', $edit['oct_custom_make_donation_code']);
      break;
    case 'oct_custom_prop_room_block':
      variable_set('oct_custom_prop_room_link', $edit['oct_custom_prop_room_link']);
      variable_set('oct_custom_prop_room_text', $edit['oct_custom_prop_room_text']);
      break;
    case 'oct_custom_message_board_block':
      variable_set('oct_custom_message_board_link', $edit['oct_custom_message_board_link']);
      variable_set('oct_custom_message_board_text', $edit['oct_custom_message_board_text']);
      break;
    case 'oct_custom_calendar_block':
      variable_set('oct_custom_calendar_link', $edit['oct_custom_calendar_link']);
      variable_set('oct_custom_calendar_text', $edit['oct_custom_calendar_text']);
      break;
    case 'oct_custom_social_menu_block':
      $item_keys = _oct_custom_social_menu_admin_settings_map();
      foreach ($item_keys as $item_key => $item) {
        if (isset($edit[$item_key])) {
          variable_set($item_key, $edit[$item_key]);
        }
      }
      break;
  }
}


/**
 * Implements hook_block_view().
 */
function oct_custom_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'oct_custom_social_block':
      $block['subject'] = '';
      $block['content'] = _oct_custom_social_block_content();
      break;
    case 'oct_custom_subscribe_block':
      $block['subject'] = t("Enter your email for OCT updates!");
      $block['content'] = variable_get('oct_custom_subscribe_block_mailchimp_form');
      break;
    case 'oct_custom_make_donation':
      $block['subject'] = "";
      $block['content'] = _oct_custom_make_donation_block_content();
      break;
    case 'oct_custom_prop_room_block':
      $block['subject'] = "";
      $block['content'] = _oct_custom_prop_room_block_content();
      break;
    case 'oct_custom_message_board_block':
      $block['subject'] = "";
      $block['content'] = _oct_custom_message_board_block_content();
      break;
    case 'oct_custom_calendar_block':
      $block['subject'] = "";
      $block['content'] = _oct_custom_calendar_block_content();
      break;
    case 'oct_custom_social_menu_block':
      $block['subject'] = "";
      $block['content'] = _oct_custom_social_menu_block_content();
      break;
  }

  return $block;
}

/**
 * Get social block content.
 * @return string
 * @throws Exception
 */
function _oct_custom_social_block_content() {
  $key = 'oct_custom_sb_';
  $item_keys = oct_custom_block_social_map();
  $variables['items'] = array();
  $variables['attributes'] = array("class" => array("sidebar-links"));

  foreach ($item_keys as $item_key => $item_title) {
    $data = variable_get($key . $item_key);
    if (!empty($data)) {
      $variables['items'][] = array(
        'data' => $data['value'],
        'class' => array($item_key)
      );
    }
  }
  return theme("oct_custom_social_block", $variables);
}


/**
 * Get donation block content.
 * @return string
 * @throws Exception
 */
function _oct_custom_make_donation_block_content(){
  $form_code = variable_get('oct_custom_make_donation_code');
  $output = '<div class="make-donation-wrapper">';
  $output .= '<a href="#" class="make-donation-btn">' . t("Make a donation") . '</a>';
  $output .= '<div class="make-donation-code">' . $form_code . '</div>';
  $output .= '</div>';

  return $output;
}


/**
 * Get Prop room block content.
 * @return string
 * @throws Exception
 */
function _oct_custom_prop_room_block_content(){
  $url = variable_get('oct_custom_prop_room_link');
  $vars['class'] = 'prap-room';
  $vars['link'] = (!empty($url)) ? l(t("Go!"), $url) : NULL;
  $vars['content'] = variable_get('oct_custom_prop_room_text');
  return theme("oct_custom_right_block", $vars);
}

/**
 * Get Message board block content.
 * @return string
 * @throws Exception
 */
function _oct_custom_message_board_block_content(){
  $url = variable_get('oct_custom_message_board_link');
  $vars['class'] = 'message-board';
  $vars['link'] = (!empty($url)) ? l(t("Go!"), $url) : NULL;
  $vars['content'] = variable_get('oct_custom_message_board_text');
  return theme("oct_custom_right_block", $vars);

}

/**
 * Get Calendar block content.
 * @return string
 * @throws Exception
 */
function _oct_custom_calendar_block_content(){
  $url = variable_get('oct_custom_calendar_link');
  $vars['class'] = 'calendar';
  $vars['link'] = (!empty($url)) ? l(t("Go!"), $url) : NULL;
  $vars['content'] = variable_get('oct_custom_calendar_text');
  return theme("oct_custom_right_block", $vars);
}

/**
 * Get social menu block content.
 */
function _oct_custom_social_menu_block_content() {
  $socials = _oct_custom_social_menu_admin_settings_map();
  $output = theme("oct_custom__social_menu", array('data' => $socials));
  return $output;
}