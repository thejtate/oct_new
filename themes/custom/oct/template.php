<?php
/**
 * Created by PhpStorm.
 * User: Sergey Grigorenko (svipsa@gmail.com)
 * Date: 13.04.15
 * Time: 15:06
 */


define("OCT_PROP_ROOM_PAGE", "prop-room");
define("OCT_MESSAGE_BOARD_PAGE", "message-board");
define("OCT_MESSAGE_ADD_BLOCK_BID", 1);


/**
 * Implements template_preprocess_html().
 */
function oct_preprocess_html(&$vars) {
  global $user;

  $vars['classes_array'][] = 'page';

  if (drupal_is_front_page()) {
    $vars['classes_array'][] = 'page-main';
  }

  $node = menu_get_object('node', 1);
  if ($node) {
    switch ($node->type) {
      case 'board_of_directors':
      case 'staff':
        $vars['classes_array'][] = 'page-about';
        break;
      case 'page':
        $vars['classes_array'][] = 'page-page';
        $node_wrapper = entity_metadata_wrapper("node", $node);
        $body_class = $node_wrapper->field_page_body_class->value();
        if (!empty($body_class)) {
          $body_classes = explode(",", $body_class);
          $vars['classes_array'] = array_merge($vars['classes_array'], $body_classes);
        }
        break;
      case 'artists':
        $vars['classes_array'][] = 'page-artists';
        $vars['classes_array'][] = 'page-about';
        break;
      case 'contact_us':
        $vars['classes_array'][] = 'page-Contact-Us';
        break;
      case 'faq':
        $vars['classes_array'][] = 'page-main';
        break;
      case 'fairy_tale_ball':
        $vars['classes_array'][] = 'page-main';
        $vars['classes_array'][] = 'page-fairy';
        break;
      case 'camps_description':
        $vars['classes_array'][] = 'page-main';
        $vars['classes_array'][] = 'page-description';
        break;
      case 'camps_list':
        $vars['classes_array'][] = 'page-main';
        $vars['classes_array'][] = 'page-camps';
        break;
      case 'fun_extras':
        $vars['classes_array'][] = 'page-main';
        $vars['classes_array'][] = 'page-fun-extras';
        break;
      case 'event':
        $vars['classes_array'][] = 'page-main';
        break;
    }
  }

  if (in_array("html__prop_room", $vars['theme_hook_suggestions'])) {
    $vars['classes_array'][] = 'page-message-board';
    $vars['classes_array'][] = 'page-prop-room';
  }

  if (in_array("html__message_board", $vars['theme_hook_suggestions'])) {
    $vars['classes_array'][] = 'page-message-board';
  }


  // User account page - set default template
  if (in_array("html__user__%", $vars['theme_hook_suggestions'])) {
    foreach ($vars['classes_array'] as $key => $class) {
      if ($class == "page-user") {
        unset($vars['classes_array'][$key]);
      }
    }
    $vars['classes_array'][] = 'page-user-account';
    $vars['classes_array'][] = 'page-header-pig';
  }


  if (in_array("html__sitemap", $vars['theme_hook_suggestions'])) {
    $vars['classes_array'][] = 'page-header-pig';
  }


}

/**
 * Implements template_preprocess_page().
 */
function oct_preprocess_page(&$vars) {
  global $user;
  // Render menus
  $main_menu_tree = oct_menu_tree_full_data('main-menu');
  if (drupal_is_front_page()){
    foreach($main_menu_tree as $key => $item){
      if ($item['link']['link_path'] == "<front>"){
        $main_menu_tree[$key]['link']['in_active_trail'] = TRUE;
      }
    }
  }
  $tree = menu_tree_output($main_menu_tree);
  $vars['main_menu'] = render($tree);



  $vars['footer_menu'] = theme('links__menu_footer_menu', array(
    'links' => menu_navigation_links('menu-footer-menu'),
  ));

  $vars['path_to_theme'] = path_to_theme();

  $vars['back_stage_block'] = array(
    "#type" => "markup",
    "#markup" => '<div class="button-go-page">' . l(t("Psst! Sneak check out our KIDS ONLY page!"), "message-board") . '</div>'
  );



  $node = menu_get_object('node', 1);
  if ($node) {
    switch ($node->type) {
      case 'camps_list':
        drupal_set_title(t("Camps"));
        break;
    }
  }



  if (in_array("page__prop_room", $vars['theme_hook_suggestions']) || in_array("page__message_board", $vars['theme_hook_suggestions'])) {
    $vars['theme_hook_suggestions'][] = "page__backstage";

    if (isset($user->name) && !empty($user->name)) {
      //$username = '<span class="user-login">' . $user->name . '</span>';
      $username = l($user->name, "user", array("attributes" => array("class" => array("user-login"))));
      $logout_link = l(t('LOG OUT'), "user/logout", array("attributes" => array("class" => array("log-out-link"))));
      $vars['user_content_menu'] = t('Welcome back !username !logout', array(
        "!username" => $username,
        "!logout" => $logout_link
      ));
    }
  }

  // User account page - set default template
  if (in_array("page__user__%", $vars['theme_hook_suggestions'])) {
    foreach ($vars['theme_hook_suggestions'] as $key => $theme) {
      if ($theme == "page__user") {
        unset($vars['theme_hook_suggestions'][$key]);
      }
    }
  }
}


function oct_preprocess_node(&$vars) {
  $node = &$vars['node'];
  switch ($node->type) {
    case "sponsors_images_":
    case "sponsors_text_":
    case "homepage_post":
      if ($vars['view_mode'] == "full") {
        drupal_goto("<front>");
      }
      break;
    case "faq":
      $vars['back_link'] = l(t("Back"), "<front>", array("attributes" => array("class" => array("back"))));
      break;
    case "prop_room":
      if ($vars['view_mode'] == "full") {
        drupal_goto(OCT_PROP_ROOM_PAGE);
      }
      break;
    case "message":
      if ($vars['view_mode'] == "full") {
        drupal_goto(OCT_MESSAGE_BOARD_PAGE);
      }
      else {
        $message = '<div class="username">';
        $message .= '<span class="author-name">' . strip_tags($vars['name']) . '</span> ';
        $message .= '<span>' . t("said") . '</span>';
        $message .= '</div>';
        $message .= '<span class="date">' . format_date($vars['created'], "custom", "M j, Y") . '</span> ';
        $vars['submitted'] = $message;
      }
      break;
    case "sponsorship_opportunities":
      $field_file = field_get_items('node', $node, 'field_so_file');
      if (!isset($field_file[0]['uri'])){
        drupal_goto("<front>");
      }
      $file = drupal_realpath($field_file[0]['uri']);
      if (file_exists($file)){
        header('Content-Description: File Transfer');
        header('Content-Type: application/octet-stream');
        header('Content-Disposition: attachment; filename='.basename($file));
        header('Expires: 0');
        header('Cache-Control: must-revalidate');
        header('Pragma: public');
        header('Content-Length: ' . filesize($file));
        readfile($file);
        exit;
      }
      drupal_goto("<front>");
      break;
  }
}

function oct_theme() {
  $items = array();
  $items['user_login'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'oct') . '/templates/forms',
    'template' => 'user-login',
    'preprocess functions' => array(
      'oct_preprocess_user_login'
    ),
  );
  $items['user_register_form'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'oct') . '/templates/forms',
    'template' => 'user-register',
    'preprocess functions' => array(
      'oct_preprocess_user_register'
    ),
  );
  return $items;
}


/**
 * Preprocess user login form.
 * @param $vars
 */
function oct_preprocess_user_login(&$vars) {
  $form = &$vars['form'];
  $form['name']['description'] = t("Enter your Oklahoma Children's Theatre username.");
  $form['pass']['description'] = t("Enter the password that accompanies your username.");
  $form['actions']['submit']['#value'] = t("Enter");
}


/**
 * Preprocess user register form.
 * @param $vars
 */
function oct_preprocess_user_register(&$vars) {
  $form = &$vars['form'];
  $form['field_user_agreement'][LANGUAGE_NONE][0]['value']['#attributes']['disabled'] = 'disabled';

  $form['captcha']['#description'] = "";
  $form['captcha']['captcha_widgets']['captcha_response']['#title'] = t("Captcha");

  $form['account']['name']['#title'] = t("Pick a Username");
  $form['account']['name']['#description'] = "";
  $form['account']['mail']['#title'] = t("E-mail");
  $form['account']['mail']['#description'] = "";
  $form['account']['pass']['#description'] = "";
}


/**
 * Theme FAQ field.
 *
 * @param $variables
 * @return string
 */
function oct_faqfield_formatter($variables) {
  $output = '<div class="question"><p><span>Q. ' . $variables['question'] . '</span>';
  $output .= $variables['answer'] . '</p></div>';
  return $output;
}


/**
 * Implements template_preprocess_views_view().
 */
function oct_preprocess_views_view(&$vars) {
  switch ($vars['name']) {
    case "message_board":
      $block = block_load("afb", OCT_MESSAGE_ADD_BLOCK_BID); // message add block
      $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
      $vars['message_form'] = render($render_array);
      break;
  }
}


/**
 * Implements hook_preprocess_block().
 */
function oct_preprocess_block(&$vars) {
  //kpr($vars);
}


/**
 * Implements hook_form_alter().
 */
function oct_form_alter(&$form, &$form_state, $form_id) {

  switch ($form_id) {
    case "message_node_form":
      $form['ajax-submit']['#prefix'] = '<div class="btn-wrap"><div class="submit-wrapper">';
      $form['ajax-submit']['#value'] = t("Post it");
      $form['ajax-submit']['#suffix'] = '</div></div>';
      $form['ajax-submit']['#submit'][] = 'oct_message_ajax_form_submit';
      break;
    case "webform_client_form_39": // suggestion block
      $form['actions']['submit']['#prefix'] = '<div class="btn-wrap"><div class="submit-wrapper">';
      $form['actions']['submit']['#suffix'] = '</div></div>';
      break;
    case 'fnl_store_checkout_form':
      oct_wrap_element($form['submit'], 'btn-wrap style-with-arrow arrow-right');
      oct_wrap_element($form['cancel'], 'btn-wrap style-with-arrow arrow-left');
      oct_wrap_element($form['discount']['discount_submit'], 'btn-wrap');
      break;
    case 'oct_store_cc_camp_form':
      oct_wrap_element($form['submit'], 'btn-wrap style-with-arrow arrow-right');
      oct_wrap_element($form['t-shirt'], 'custom-inline-select');
      break;
    case 'oct_store_production_form':
      oct_wrap_element($form['submit'], 'btn-wrap style-with-arrow arrow-right');
      break;
  }
}

/**
 * Ajax message form submit. (for redirect view)
 * @param $form
 * @param $form_state
 */
function oct_message_ajax_form_submit($form, &$form_state) {
  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  $commands[] = ctools_ajax_command_redirect(OCT_MESSAGE_BOARD_PAGE);
  print ajax_render($commands);

  $messages = drupal_get_messages('status');
  drupal_set_message(t('You message has been saved.'));
  exit;
}



function oct_menu_tree_full_data($menu_name) {
  $tree = &drupal_static(__FUNCTION__, array());

  // Check if the active trail has been overridden for this menu tree.
  $active_path = menu_tree_get_path($menu_name);

  // Generate a cache ID(cid) specific for this page
  $item = menu_get_item($active_path);
  $cid = "links:$menu_name:full:{$item['href']}:{$GLOBALS['language']->language}";

  // Did we already build this menu during this request?
  if(isset($tree[$cid]))
    return $tree[$cid];

  // If the static variable doesn't have the data, check {cache_menu}.
  $cache = cache_get($cid, 'cache_menu');
  if($cache && isset($cache->data)) {
    $tree_params = $cache->data;
    if(isset($tree_params))
      return $tree[$cid] = menu_build_tree($menu_name, $tree_params);
  }

  $tree_params = array(
    'min_depth' => 1,
    'max_depth' => null,
  );
  // Parent mlids; used both as key and value to ensure uniqueness.
  // We always want all the top-level links with plid == 0.
  $active_trail = array(0 => 0);

  // Find a menu link corresponding to the current path. If $active_path
  // is NULL, let menu_link_get_preferred() determine the path.
  $active_link = menu_link_get_preferred($active_path, $menu_name);
  // The active link may only be taken into account to build the
  // active trail, if it resides in the requested menu. Otherwise,
  // we'd needlessly re-run _menu_build_tree() queries for every menu
  // on every page.
  if(@$active_link['menu_name'] == $menu_name) {
    // Use all the coordinates, except the last one because there
    // can be no child beyond the last column.
    for($i = 1; $i < MENU_MAX_DEPTH; $i++) {
      if($active_link['p' . $i])
        $active_trail[$active_link['p' . $i]] = $active_link['p' . $i];
    }
  }

  $parents = $active_trail;
  do {
    $result = db_select('menu_links', NULL, array('fetch' => PDO::FETCH_ASSOC))
      ->fields('menu_links', array('mlid'))
      ->condition('menu_name', $menu_name)
      //->condition('expanded', 1)
      ->condition('has_children', 1)
      ->condition('plid', $parents, 'IN')
      ->condition('mlid', $parents, 'NOT IN')
      ->execute();
    $num_rows = FALSE;
    foreach($result as $item) {
      $parents[$item['mlid']] = $item['mlid'];
      $num_rows = TRUE;
    }
  } while($num_rows);
  $tree_params['expanded'] = $parents;
  $tree_params['active_trail'] = $active_trail;

  // Cache the tree building parameters using the page-specific cid.
  cache_set($cid, $tree_params, 'cache_menu');

  // Build the tree using the parameters; the resulting tree will be cached by _menu_build_tree().
  return $tree[$cid] = menu_build_tree($menu_name, $tree_params);
}

/**
 * Wrap form element
 *
 * @param string $classes
 */
function oct_wrap_element(&$element, $classes) {
  if(!empty($element)) {
    $div_open = '<div class="' . $classes . '">';
    $div_close = '</div>';

    //leave original prfix/suffix if exists. and wrap element
    $element['#prefix'] = !empty($element['#prefix']) ? $div_open . $element['#prefix'] : $div_open;
    $element['#suffix'] = !empty($element['#suffix']) ? $element['#suffix'] . $div_close : $div_close;
  }
}