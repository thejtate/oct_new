<?php
/**
 * Created by PhpStorm.
 * User: yulia
 * Date: 1/3/16
 * Time: 11:38
 */
define('NODEBLOCK_CANCEL_POLICY', 231);

/**
 * Implements hook_preprocess_html().
 */
function oct_new_preprocess_html(&$vars) {

  $viewport = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'user-scalable=yes, width=device-width',
    ),
  );
  $handheldhriendly = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'HandheldFriendly',
      'content' => 'false',
    ),
  );

  // Setup IE meta tag to force IE rendering mode.
  $meta_ie_render_engine = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'X-UA-Compatible',
      'content' => 'IE=edge',
    ),
    '#weight' => '-99999',
    '#prefix' => '<!--[if IE]>',
    '#suffix' => '<![endif]-->',
  );

  drupal_add_html_head($meta_ie_render_engine, 'meta_ie_render_engine');
  drupal_add_html_head($viewport, 'viewport');
  drupal_add_html_head($handheldhriendly, 'handheldhriendly');
  $vars['classes_array'][] = 'page';
  if ($node = menu_get_object()) {
    $vars['classes_array'][] = 'page-' . str_replace('_', '-', $node->type);
    try {
      $node_wrapper = entity_metadata_wrapper('node', $node);
      if (isset($node_wrapper->field_page_body_class)) {
        $body_class = $node_wrapper->field_page_body_class->value();
        if (!empty($body_class)) {
          $vars['classes_array'][] = $body_class;
        }
      }

      if (isset($node_wrapper->field_page_top_image)) {
        $top_img = $node_wrapper->field_page_top_image->value();
        if (!empty($top_img)) {
          $vars['classes_array'][] = 'page-with-title-image';
        }
      }

    }
    catch (EntityMetadataWrapperException $exc) {
      watchdog(
        'template',
        'See ' . __FUNCTION__ . '() <pre>' . $exc->getTraceAsString() . '</pre>',
        NULL, WATCHDOG_ERROR
      );
    }
    switch ($node->type) {
      case 'board_of_directors':
        $vars['classes_array'][] = 'page-about-us';
        break;
      case 'product_ftb':
        $vars['classes_array'][] = 'page-ftb-tickets';
        break;
      case 'camp_general':
        $vars['classes_array'][] = 'page-summer';
        break;
      case 'fairy_tale_ball':
        $vars['classes_array'][] = 'page-ftb';
        break;
      case 'camp_enrollment':
        $vars['classes_array'][] = 'page-store';
        break;
      case 'donations':
        $vars['classes_array'][] = 'page-donation';
        break;
      case 'class_enrollment':
        $vars['classes_array'][] = 'page-store';
        break;
      case 'sponsorship_opportunities':
        $vars['classes_array'][] = 'page-sponsorship';
        break;
      case 'camps_landing':
        $properties = $node_wrapper->getPropertyInfo();
        $type = 'field_camps_landing_type';
        if (array_key_exists($type, $properties)) {
          $type_class = $node_wrapper->$type->value();
          if ($type_class) {
            $vars['classes_array'][] = 'page-' . $type_class;
          }
        }
        break;
      default :
        break;
    }
  }

  //dsm($vars['theme_hook_suggestions']);
  if (array_intersect(
    array(
      'html__store__camps',
      'html__user'
    ),
    $vars['theme_hook_suggestions']
  )) {
    $vars['classes_array'][] = 'page';
  }

  if (array_intersect(
    array(
      'html__store__camps'
    ),
    $vars['theme_hook_suggestions']
  )) {
    $vars['classes_array'][] = 'page-store';
  }

  if(in_array('html__production__tickets', $vars['theme_hook_suggestions'])) {
    $vars['classes_array'][] = 'page-tickets';
  }

  if(in_array('html__store__complete', $vars['theme_hook_suggestions'])) {
    $vars['classes_array'][] = 'page-cart';
  }

  if (drupal_is_front_page()) {
    $vars['classes_array'][] = 'page-home';
  }
  if (module_exists('fnl_store') && (drupal_match_path($_GET['q'], FNL_STORE_CHECKOUT_URL) ||
      drupal_match_path(drupal_get_path_alias($_GET['q']), FNL_STORE_CHECKOUT_URL))
  ) {
    $vars['classes_array'][] = 'page-checkout';
  }

}

/**
 * Implements hook_preprocess().
 */
function oct_new_preprocess(&$vars, $hook) {
  $vars['theme_path'] = base_path() . path_to_theme();
}

/**
 * Implements hook_preprocess_page().
 */
function oct_new_preprocess_page(&$vars) {
  $main_menu_tree = menu_tree_all_data('main-menu');
  $vars['main_menu_expanded'] = menu_tree_output($main_menu_tree);
  $vars['footer_menu'] = theme('links__menu_footer_menu', array(
    'links' => menu_navigation_links('menu-footer-menu'),
  ));
  $vars['top_img'] = '';
  if ($node = menu_get_object()) {
    try {
      $node_wrapper = entity_metadata_wrapper('node', $node);
      if (isset($node_wrapper->field_page_top_image)) {
        $top_img = $node_wrapper->field_page_top_image->value();
        if (!empty($top_img)) {
          $vars['top_img'] = $top_img['0']['uri'];
        }
      }
    }
    catch (EntityMetadataWrapperException $exc) {
      watchdog(
        'template',
        'See ' . __FUNCTION__ . '() <pre>' . $exc->getTraceAsString() . '</pre>',
        NULL, WATCHDOG_ERROR
      );
    }
  }
}

/**
 * Implements template_preprocess_node().
 */
function oct_new_preprocess_node(&$vars) {
  $node = $vars['node'];

  if (isset($vars['view_mode'])) {
    $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '__' . $vars['view_mode'];
  }

  switch ($node->type) {
    case 'camp_general':
      $vars['classes_array'][] = 'content-top';
      break;
    case 'camp_enrollment':
      $vars['show_text_title'] = !empty($node->field_page_top_image[LANGUAGE_NONE][0]['uri']);
      break;
    case 'product_ftb':
      $vars['classes_array'][] = 'left-part';
      $vars['show_text_title'] = TRUE;
      break;
    case 'camps_landing':
      $type = (!empty($vars['content']['field_camps_landing_type']) &&
        !empty($vars['content']['field_camps_landing_type']['#items'])) ?
        $vars['content']['field_camps_landing_type']['#items'][0]['value'] : '';
      if (($type == 'classes') && !empty($vars['content']['field_camps_landing_items'])) {
        $vars['content']['field_camps_landing_items'][0]['#header'][0]['data'] = t('DATES');
      }
      break;
  }
}


/**
 * Implements hook_preprocess_field().
 */
function oct_new_preprocess_field(&$vars) {
  $element = $vars['element'];
  switch ($element['#field_name']) {
    case 'field_bod_top_list':
    case 'field_bod_bottom_list':
    case 'field_staff_top_list':
    case 'field_staff_bottom_list':
    case 'field_image_list':
    case 'field_text_list':
      $vars['theme_hook_suggestions'][] = 'field__field_list';
      break;
    case 'field_bod_tl_name':
    case 'field_bod_bl_name':
    case 'field_staff_tl_name':
    case 'field_staff_bl_name':
      $vars['theme_hook_suggestions'][] = 'field__field_list_name';
      break;
    case 'field_bod_tl_position':
    case 'field_bod_bl_position':
    case 'field_staff_tl_position':
    case 'field_staff_bl_position':
      $vars['theme_hook_suggestions'][] = 'field__field_list_position';
      break;
    case 'field_main_image':
    case 'field_ftb_items_image':
    case 'field_class_image':
      $vars['classes_array'][] = 'img';
      break;
    case 'field_contact_us_content':
      $vars['classes_array'][] = 'contacts';
      break;
    case 'field_contact_us_content_text':
    case 'field_ftbf_bottom_desc':
    case 'field_ftb_items_desc':
      $vars['classes_array'][] = 'text';
      break;
    case 'field_contact_us_content_left':
    case 'field_contact_us_content_right':
      $vars['classes_array'][] = 'part';
      break;
    case 'field_camp_general_date':
      $vars['classes_array'][] = 'subtitle';
      break;
    case 'field_section_title':
      $vars['theme_hook_suggestions'][] = 'field__field_page_content_title';
      break;
    case 'field_camp_general_link':
      $vars['theme_hook_suggestions'][] = 'field__link_with_arrow';
      break;
    case 'field_ftb_items_date_place':
      $vars['classes_array'][] = 'desc';
      break;
    case 'field_block_content':
      $vars['classes_array'][] = 'items';
      break;
    case 'field_production_period':
      $vars['classes_array'][] = 'date';
      break;
    case 'field_omn_history':
      $vars['classes_array'][] = 'history-list';
      break;
  }
}


/**
 * Implements hook_form_alter().
 */
function oct_new_form_alter(&$form, &$form_state, $form_id) {
//  dsm($form_id);
  switch ($form_id) {
    case 'user_profile_form':
      oct_new_wrap_item($form['actions']['submit'], 'btn-wrap style-c with-arrow');
      hide($form['mimemail']);
      break;
    case 'user_register_form':
    case 'user_pass_reset':
    case 'user_pass':
      oct_new_wrap_item($form['actions']['submit'], 'btn-wrap style-c with-arrow');
      break;
    case 'oct_store_partial_pay_finish':
      oct_new_wrap_item($form['submit'], 'btn-wrap style-a');
      break;
    case 'user_login':
      oct_new_wrap_item($form['actions']['submit'], 'btn-wrap style-a');
      break;
    case 'oct_store_ftb_form':
      oct_new_wrap_item($form['submit'], 'btn-wrap style-c with-arrow');
      break;
    case 'oct_store_production_form':
      oct_new_wrap_item($form['submit'], 'btn-wrap style-c with-arrow');
      oct_new_wrap_item($form['production'], 'webform-component-select');
      oct_new_wrap_item($form['datetime'], 'webform-component-select');
      break;
    case 'oct_store_donation_form':
      $form['#attributes']['class'][] = 'form';
      $form['#attributes']['class'][] = 'form-style-a';
      oct_new_wrap_item($form['amount'], 'form-text-amount form-item');
      oct_new_wrap_item($form['city'], 'form-text-city');
      oct_new_wrap_item($form['state'], 'form-text-state');
      oct_new_wrap_item($form['zip'], 'form-text-zip');
      oct_new_wrap_item($form['phone'], 'style-a width-50');
      oct_new_wrap_item($form['email'], 'width-50');
      oct_new_wrap_item($form['submit'], 'form-actions');
      oct_new_wrap_item($form['submit'], 'btn-wrap with-arrow style-c');
      oct_new_wrap_item($form['submit'], 'actions-outer-wrapper');
      $form['amount']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['company_name']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['city']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['state']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['zip']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['phone']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['email']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['address']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['first_name']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['last_name']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      break;
    case 'oct_store_sponsorships_form':
      $form['#attributes']['class'][] = 'form';
      $form['#attributes']['class'][] = 'form-style-a';
      oct_new_wrap_item($form['amount'], 'form-text-amount form-item');
      oct_new_wrap_item($form['contribute'], 'form-text-amount form-item');
      oct_new_wrap_item($form['city'], 'form-text-city');
      oct_new_wrap_item($form['state'], 'form-text-state');
      oct_new_wrap_item($form['zip'], 'form-text-zip');
      oct_new_wrap_item($form['phone'], 'style-a width-50');
      oct_new_wrap_item($form['email'], 'width-50');
      oct_new_wrap_item($form['submit'], 'form-actions');
      oct_new_wrap_item($form['submit'], 'btn-wrap with-arrow style-c');
      oct_new_wrap_item($form['submit'], 'actions-outer-wrapper');
      $form['amount']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['company_name']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['city']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['state']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['zip']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['phone']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['email']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['address']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['first_name']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      $form['last_name']['#after_build'][] =  'oct_new_form_element_afterbuild_wrap_labels';
      break;
  }
}

/**
 * Wrap title in strong tag, exclude string in brackets ().
 */
function oct_new_form_element_afterbuild_wrap_labels($element) {

  $title = !empty($element['#title']) ? $element['#title'] : '';
  $title_parts = explode('(', $title);
  $first_part = array_shift($title_parts);

  $element['#title'] = '<strong>' . $first_part . '</strong>' . ((!empty($title_parts)) ? '('. implode('', $title_parts) : '');
  return $element;
}

function oct_new_wrap_item(&$element, $classes) {
  if (!empty($element)) {
    $element['#prefix'] = '<div class="' . $classes . '">' . (array_key_exists('#prefix', $element) ? $element['#prefix'] : '');
    $element['#suffix'] = (array_key_exists('#suffix', $element) ? $element['#suffix'] : '') . '</div>';
  }
}


/**
 * Implements template_preprocess_views_view().
 */
function oct_new_preprocess_views_view(&$vars) {
  $view = $vars['view'];
  $name = (isset($vars['view']->name)) ? $vars['view']->name : NULL;
  $current_display = (isset($vars['view']->current_display)) ? $vars['view']->current_display : NULL;

  if ($view->name == 'cart' && $view->current_display == 'cart') {
    $vars['classes_array'][] = 'view-cart';
  }
}

/**
 * Implements template_preprocess_block().
 */
function oct_new_preprocess_block(&$vars, $hook) {
  if (isset($vars['block'])) {
    switch ($vars['block']->delta) {
      case 'videos-block':
        $vars['theme_hook_suggestions'][] = 'block__media_horizontal';
        $vars['classes_array'][] = 'component';
        break;
      case 'menu-camps-landing':
        $vars['classes_array'][] = 'b-navigarion';
        break;
    }
    switch ($vars['block']->module) {
      case 'nodeblock':
        if ($vars['block']->bid == NODEBLOCK_CANCEL_POLICY) {
          $vars['classes_array'][] = 'view-cart';
        }
        break;
    }
  }
}

/**
 * Implements hook_menu_alter().
 */
function oct_new_menu_alter(&$items) {
  if(!empty($items['user/%user/edit']['title'])) {
    $items['user/%user/edit']['title'] = t('Edit Profile');
  }
  if(!empty($items['user/%user/view']['title'])) {
    $items['user/%user/view']['title'] = t('View Orders');
  }
}