<?php

/**
 * @file
 * Form for adding camps to user cart.
 */

define('OCT_STORE_CC_MAX_CHILDREN', 3);
/**
 * Debug helper constant.
 */
define('OCT_STORE_CC_REQUIRED', TRUE);

/**
 * Classes, Camps form
 */
function oct_store_cc_form($form, &$form_state, $node_content, $type) {
  module_load_include('inc', 'fnl_store', 'includes/fnl_store.helpers');

  $form_wrap_id = 'oct-store-camps-form-wrapper';
  $products_wrapper_id = 'oct-store-camps-products-table';
  $default_birth_date = date_format(new DateObject('January 01 -5 year'), 'Y-m-d');

  $form['#prefix'] = '<div id="' . $form_wrap_id . '">';
  $form['#suffix'] = '</div>';
  $form['#node_content'] = $node_content;
  $form['#tree'] = TRUE;

  $form_state['product_type'] = $type;

  $step = empty($form_state['storage']['step']) ? 1 : $form_state['storage']['step'];
  $form_state['storage']['step'] = $step;

  $children = empty($form_state['storage']['children']) ? 1 : $form_state['storage']['children'];
  $form_state['storage']['children'] = $children;

  switch($step) {
    case 1:
      $form['step1'] = array(
        '#type' => 'fieldset',
        '#title' => '',
      );

      $form['step1']['children'] = array(
        '#type' => 'fieldset',
        '#title' => t('Child`s Information'),
        //'#theme_wrappers' => array('oct_store_cc_children'),
      );

      for($i = 0; $i < $children; $i++) {

        $form['step1']['children']['child_' . $i] = array(
          '#type' => 'fieldset',
          '#title' => t('Child') . " " . ($i +1),
        );

        $form['step1']['children']['child_' . $i]['first_name'] =  array(
          '#type' => 'textfield',
          '#required' => OCT_STORE_CC_REQUIRED,
          '#title' => t('First Name'),
        );

        $form['step1']['children']['child_' . $i]['last_name'] = array(
          '#type' => 'textfield',
          '#required' => OCT_STORE_CC_REQUIRED,
          '#title' => t('Last Name'),
        );

        $form['step1']['children']['child_' . $i]['allergy'] = array(
          '#type' => 'textarea',
          '#required' => FALSE,
          '#cols' => 60,
          '#rows' => 5,
          '#resizable' => FALSE,
          '#title' => t('Allergies / Medications / Special Needs'),
        );

        $form['step1']['children']['child_' . $i]['birth_date'] = array(
          '#type' => 'date_select',
          '#required' => OCT_STORE_CC_REQUIRED,
          '#title' => t('Date of Birth: (enter to unlock classes)'),
          //'#default_value' => $default_birth_date,
          '#default_value' => array(),
          '#date_format' => "d-m-Y",
          '#date_year_range' => '-15:-3',
           '#after_build' => array('oct_store_ccs_date_select_after_build'),
        );

        $form['step1']['children']['child_' . $i]['gender'] = array(
          '#type' => 'select',
          '#required' => OCT_STORE_CC_REQUIRED,
          '#title' => t('Gender'),
          '#empty_option' => t('M/F'),
          '#options' => array('Male' => 'M', 'Female' => 'F'),
        );

        $form['step1']['children']['child_' . $i]['t-shirt'] = array(
          '#prefix' => '<div class="radios-clear-click">',
          '#suffix' => '</div>',
          '#type' => 'radios',
          '#required' => FALSE,
          '#title' => t('T-Shirt size'),
          //'#empty_option' => t('Please select...'),
          '#options' => drupal_map_assoc(array(
            t('X Small'),
            t('Small'),
            t('Medium'),
            t('Large'),
          )),
          '#description' => t('All campers are required to purchase the current year camp tee shirt.
          Please only select a shirt size if you have not purchased one.'),
        );



      }

      if($children > 1) {
        $form['step1']['remove_child'] = array(
          '#type' => 'submit',
          '#value' => t('Remove child'),
          '#name' => 'add_child',
          '#limit_validation_errors' => array(),
          '#submit' => array('oct_store_cc_form_remove_child_submit'),
          '#ajax' => array(
            'wrapper' => $form_wrap_id,
            'callback' => 'oct_store_cc_form_replace',
            'method' => 'replaceWith',
          ),
        );
      }

      if($children < OCT_STORE_CC_MAX_CHILDREN) {
        $form['step1']['add_child'] = array(
          '#type' => 'submit',
          '#value' => t('Add child'),
          '#name' => 'add_child',
          '#limit_validation_errors' => array(),
          '#submit' => array('oct_store_cc_form_add_child_submit'),
          '#ajax' => array(
            'wrapper' => $form_wrap_id,
            'callback' => 'oct_store_cc_form_replace',
            'method' => 'replaceWith',
          ),
        );
      }


      list($products, $product_groups) = oct_store_cc_load_camps_products($type);

      $form_state['products'] = $products;

      $form['step1']['products'] = array(
        '#prefix' => '<div id="' . $products_wrapper_id . '">',
        '#suffix' => '</div>',
        '#type' => 'fieldset',
        '#tree' => TRUE,
        '#title' => t('Products'),
        '#collapsible' => FALSE,
        '#collapsed' => FALSE,
        '#theme_wrappers' => array('oct_store_camp_form_table'),
        //Custom form element params, for using in theme_wrappers function
        '#product_data' => $products,
        '#children' => $children,
        '#product_groups' => $product_groups,
      );

      foreach ($products as $key => $product) {
        $collection_id = $product->data['full_info']['collection_id'];


        $form['step1']['products'][$collection_id] = array(
          '#tree' => TRUE,
        );

        if($product->data['full_info']['available_qty'] > 0) {
          for($i = 0; $i < $children; $i++) {

            $form['step1']['products'][$collection_id]['child_' . $i] = array(
              '#type' => 'checkbox',
              '#title' => ' ',
              '#default_value' => FALSE,
              '#attributes' => array(
                'data-child' => $i,
                'data-price' => $product->data['full_info']['price'],
                'data-min-age' => $product->data['full_info']['min_age'],
                'data-max-age' => $product->data['full_info']['max_age'],
              ),
            );
          }
        }

      }

      $form['step1']['products']['next'] = array(
        '#type' => 'submit',
        '#value' => t('Add to cart'),
        '#name' => 'next',
        '#submit' => array('oct_store_cc_form_next_submit'),
        '#validate' => array('oct_store_cc_form_validate_selected_products'),
        '#ajax' => array(
          'wrapper' => $form_wrap_id,
          'callback' => 'oct_store_cc_form_ajax_submit',
          'method' => 'replaceWith',
        ),
        // ra__ajax
      );


      break;
    case 2:

      $form['step2'] = array(
        '#type' => 'fieldset',
        '#title' => t(''),
      );

      $form['step2']['parents'] = array(
        '#type' => 'fieldset',
        '#title' => t('Parent`s Information'),
      );

      //Parents Primary

      $form['step2']['parents']['primary'] = array(
        '#type' => 'fieldset',
        '#title' => t('Primary Contact'),
      );

      $form['step2']['parents']['primary']['first_name'] = array(
        '#type' => 'textfield',
        '#required' => OCT_STORE_CC_REQUIRED,
        '#title' => t('First Name'),
      );

      $form['step2']['parents']['primary']['last_name'] = array(
        '#type' => 'textfield',
        '#required' => OCT_STORE_CC_REQUIRED,
        '#title' => t('Last Name'),
      );

      $form['step2']['parents']['primary']['phone_type'] = array(
        '#type' => 'select',
        '#required' => FALSE,
        '#title' => t('Phone # Type'),
        '#empty_option' => t('- Select -'),
        '#options' => oct_store_cc_phone_type_options(),
      );
      
      $form['step2']['parents']['primary']['phone'] = array(
        '#type' => 'masked_input',
        '#required' => OCT_STORE_CC_REQUIRED,
        '#title' => t('Phone'),
        '#mask' => '(999)999-9999'
      );

//      $form['step2']['parents']['primary']['cellphone'] = array(
//        '#type' => 'masked_input',
//        '#required' => FALSE,
//        '#title' => t('Cell Phone'),
//        '#mask' => '(999)999-9999'
//      );

      $form['step2']['parents']['primary']['email'] = array(
        '#type' => 'emailfield',
        '#required' => OCT_STORE_CC_REQUIRED,
        '#title' => t('Email Address'),
      );

      $form['step2']['parents']['primary']['relationship'] = array(
        '#type' => 'select',
        '#required' => FALSE,
        '#title' => t('Relationship to child'),
        '#empty_option' => t('- Select -'),
        '#options' => array(
          'mother' => t('Mother'),
          'father' => t('Father'),
          'grandparent' => t('Grandparent'),
          'aunt_uncle' => t('Aunt/uncle'),
          'sibling' => t('Sibling'),
          'guardian_other' => t('Guardian/other'),
        ),
      );

      //Parents Emergency (Alternate)

      $form['step2']['parents']['alternate'] = array(
        '#type' => 'fieldset',
        '#title' => t('Emergency Contact'),
      );

      $form['step2']['parents']['alternate']['first_name'] = array(
        '#type' => 'textfield',
        '#required' => OCT_STORE_CC_REQUIRED,
        '#title' => t('First Name'),
      );

      $form['step2']['parents']['alternate']['last_name'] = array(
        '#type' => 'textfield',
        '#required' => OCT_STORE_CC_REQUIRED,
        '#title' => t('Last Name'),
      );

      $form['step2']['parents']['alternate']['phone_type'] = array(
        '#type' => 'select',
        '#required' => FALSE,
        '#title' => t('Phone # Type'),
        '#empty_option' => t('- Select -'),
        '#options' => oct_store_cc_phone_type_options(),
      );

      $form['step2']['parents']['alternate']['phone'] = array(
        '#type' => 'masked_input',
        '#required' => OCT_STORE_CC_REQUIRED,
        '#title' => t('Phone'),
        '#mask' => '(999)999-9999'
      );

//      $form['step2']['parents']['alternate']['cellphone'] = array(
//        '#type' => 'masked_input',
//        '#required' => FALSE,
//        '#title' => t('Cell Phone'),
//        '#mask' => '(999)999-9999'
//      );

      $form['step2']['parents']['alternate']['email'] = array(
        '#type' => 'emailfield',
        '#required' => OCT_STORE_CC_REQUIRED,
        '#title' => t('Email Address'),
      );
      // Saved in 'emergency_relationship' table field
      $form['step2']['parents']['alternate']['relationship'] = array(
        '#type' => 'select',
        '#required' => FALSE,
        '#title' => t('Relationship to child'),
        '#empty_option' => t('- Select -'),
        '#options' => array(
          'mother' => t('Mother'),
          'father' => t('Father'),
          'grandparent' => t('Grandparent'),
          'aunt_uncle' => t('Aunt/uncle'),
          'sibling' => t('Sibling'),
          'guardian_other' => t('Guardian/other'),
        ),
      );


      //Emergency

      $form['step2']['emergency'] = array(
        '#type' => 'fieldset',
        '#title' => t('Emergency Medical Release'),
        '#access' => FALSE,
      );

      $form['step2']['emergency']['first_name'] = array(
        '#type' => 'textfield',
        '#required' => OCT_STORE_CC_REQUIRED,
        '#title' => t('First Name'),
      );

      $form['step2']['emergency']['last_name'] = array(
        '#type' => 'textfield',
        '#required' => OCT_STORE_CC_REQUIRED,
        '#title' => t('Last Name'),
      );

      $form['step2']['emergency']['phone'] = array(
        '#type' => 'masked_input',
        '#required' => OCT_STORE_CC_REQUIRED,
        '#title' => t('Phone'),
        '#mask' => '(999)999-9999'
      );

      $form['step2']['emergency']['is_other_information'] = array(
        '#type' => 'radios',
        '#required' => OCT_STORE_CC_REQUIRED,
        '#title' => t('Other information.'),
        '#options' => array('yes' => t('Yes'), 'no' => t('No')),
        '#default_value' => 'no',
      );

      $form['step2']['emergency']['other_information'] = array(
        '#type' => 'textarea',
        '#required' => FALSE,
        '#title' => t('If YES, please explain below'),
        '#states' => array(
          'invisible' => array(
            ':input[name="step2[emergency][is_other_information]"]' => array('value' => 'no'),
          ),
        ),
      );

      //Actions
      $form['step2']['previous'] = array(
        '#type' => 'submit',
        '#value' => t('Previous'),
        '#name' => 'prev',
        '#limit_validation_errors' => array(),
        '#submit' => array('oct_store_cc_form_prev_submit'),
        '#ajax' => array(
          'wrapper' => $form_wrap_id,
          'callback' => 'oct_store_cc_form_ajax_submit',
          'method' => 'replaceWith',
        ),
      );

      $form['step2']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Add to cart'),
        '#name' => 'add',
        '#validate' => array('oct_store_cc_add_to_card_validate'),
        '#submit' => array('oct_store_cc_form_submit'),
        '#ajax' => array(
          'wrapper' => $form_wrap_id,
          'callback' => 'oct_store_cc_form_ajax_submit',
          'method' => 'replaceWith',
        ),
        // ra__ajax
      );

      break;
  }

  oct_store_cc_product_type_form_altering($form, $form_state, $node_content, $type);
  oct_store_cc_add_multistep_values_recursive($form, $form_state);

  $form['#attached']['js'][] = drupal_get_path('module', 'oct_store_cc') . '/js/oct_store_cc.js';
  return $form;
}

/**
 * Form changed, dependent on product type.
 */
function oct_store_cc_product_type_form_altering(&$form, &$form_state, $node_content, $type) {

  switch($type) {
    case 'class':
      if(!empty($form['step1'])) {
        $form['step1']['products']['#theme_wrappers'] = array('oct_store_class_form_table');
        $form['step1']['children']['#title'] = t('Enroll online');

        $child_childrens = element_children($form['step1']['children']);
        foreach ($child_childrens as $key) {
          $form['step1']['children'][$key]['t-shirt']['#access'] = FALSE;
        }
      }
      break;
    case 'camp':
      if(!empty($form['step1'])) {
        $child_childrens = element_children($form['step1']['children']);
        foreach ($child_childrens as $key) {
          $form['step1']['children'][$key]['birth_date']['#title'] = t('Date of Birth: (enter to unlock camps)');
        }
      }
      break;
  }
}

function oct_store_cc_form_add_child_submit($form, &$form_state) {
  $form_state['storage']['children']++;
  $form_state['rebuild'] = TRUE;
}

function oct_store_cc_form_remove_child_submit($form, &$form_state) {
  $form_state['storage']['children']--;
  $form_state['rebuild'] = TRUE;
}

function oct_store_cc_form_next_submit($form, &$form_state) {

  oct_store_cc_save_step_values($form, $form_state);
  $form_state['storage']['step']++;
  $form_state['rebuild'] = TRUE;
  oct_store_cc_restore_step_values($form, $form_state);
}

function oct_store_cc_form_prev_submit($form, &$form_state) {
  oct_store_cc_save_step_values($form, $form_state);
  $form_state['storage']['step']--;
  $form_state['rebuild'] = TRUE;
  oct_store_cc_restore_step_values($form, $form_state);
}

function oct_store_cc_save_step_values($form, &$form_state) {
  $current_step = 'step' . $form_state['storage']['step'];

  if (!empty($form_state['input'][$current_step])) {
    $form_state['storage']['values'][$current_step] = $form_state['input'][$current_step];
  }
}

function oct_store_cc_restore_step_values($form, &$form_state) {
  $current_step = 'step' . $form_state['storage']['step'];

  if (!empty($form_state['storage']['values'][$current_step])) {
    $form_state['values'][$current_step] = $form_state['storage']['values'][$current_step];
  }
}

function oct_store_cc_form_replace($form, &$form_state) {
  return $form;
}


function oct_store_cc_form_ajax_submit($form, $form_state) {

  if(!empty($form_state['submit_finish'])) {
    //add product finish
    ctools_include('ajax');
    $commands[] = ctools_ajax_command_redirect(FNL_STORE_CART_PAGE);
  } else {
    //else just replace form.
    views_include('ajax');
    views_add_js('ajax_view');

    $html = drupal_render($form);
    $commands[] = ajax_command_insert(NULL, $html);
    $commands[] = ajax_command_prepend(NULL, theme('status_messages'));
    $commands[] = views_ajax_command_scroll_top('#' . $form['#id']);
  }

    $output = array('#type' => 'ajax', '#commands' => $commands);


  return $output;
}

/**
 * Recursive set default values for current form step from $form_state['storage'].
 *
 *
 * @param $element
 * @param $form_state
 * @param array $parents
 */
function oct_store_cc_add_multistep_values_recursive(&$element, $form_state, $parents = array()) {
  $ignore_types = array('fieldset', 'hidden', 'submit');
  $step_name = 'step' . $form_state['storage']['step'];
  $children = element_children($element);

  foreach ($children as $child_key) {
    $child_parents = array_merge($parents, array($child_key));

    $child = &$element[$child_key];
    if(!empty($child['#type']) && !in_array($child['#type'], $ignore_types)) {

      if(!empty($form_state['values'][$step_name])
            && drupal_array_nested_key_exists($form_state['values'], $child_parents)) {
        $child['#default_value'] = drupal_array_get_nested_value($form_state['values'], $child_parents);
      }
    }
    $child_childrens = element_children($child);
    if(!empty($child_childrens)) {
      oct_store_cc_add_multistep_values_recursive($child, $form_state, $child_parents);
    }
  }
}

/**
 * Validate callback.
 */
function oct_store_cc_form_validate_selected_products(&$form, &$form_state) {

  $products = !empty($form_state['values']['step1']['products']) ? $form_state['values']['step1']['products'] : array();
  $children = empty($form_state['storage']['children']) ? 1 : $form_state['storage']['children'];

  for ($i = 0; $i < $children; $i++) {

    $selected_products = !empty($products)
      ? array_filter($products, function($v) use($i) { return !empty($v['child_' . $i]);} )
      : array();

    if(empty($selected_products)) {
      form_set_error('step1][products', t('Please select at least one camp for each Child.'));
      return;
    }

    //check child`s age for selected products
    $tz = date_default_timezone_object();
    $birth_date = $form_state['values']['step1']['children']['child_' . $i]['birth_date'];
    $age = DateTime::createFromFormat('Y-m-d', $birth_date)
      ->diff(new DateTime('now', $tz))
      ->y;
    $selected_product_keys = drupal_map_assoc(array_keys($selected_products));
    $selected_products_info = array_intersect_key($form_state['products'], $selected_product_keys);

    foreach ($selected_products_info as $product_key => $selected_product) {
      if($selected_product->data['full_info']['min_age'] > $age || $age >  $selected_product->data['full_info']['max_age']) {
        form_set_error('step1][products][' . $product_key .  '][child_' . $i, "Child " . ($i+1) . " does not meet the age requirements for $selected_product->name.");
      }
    }

  }
}


/**
 * Get products data from form_state. And validate
 */
function oct_store_cc_add_to_card_validate($form, &$form_state) {

  $form_state['add_products'] = array();

  $parents_info = $form_state['values']['step2']['parents'];
  $parents_info['emergency'] = $form_state['values']['step2']['emergency'];

  foreach ($form_state['storage']['values']['step1']['children'] as $child_key => $child) {

    $child_info = array();
    $child_info['first_name'] = $child['first_name'];
    $child_info['last_name'] = $child['last_name'];
    $child_info['gender'] = $child['gender'];
    $child_info['allergy'] = $child['allergy'];
    //convert array date input to date string value
    $child_info['birth_date'] = is_array($child['birth_date'])
      ? oct_store_cc_get_date_string_value($child['birth_date'])
      : $child['birth_date'];

    if(!empty($child['t-shirt'])) {
      $child_info['t-shirt'] = $child['t-shirt'];
    }

    $products = $form_state['storage']['values']['step1']['products'];

    $products_selected = array_filter(
      $products,
      function ($v) use ($child_key) {return !empty($v[$child_key]);}
    );

    $selected_product_keys = drupal_map_assoc(array_keys($products_selected));

    $selected_products_info = array_intersect_key($form_state['products'], $selected_product_keys);

    foreach ($selected_products_info as $product) {
      //add product data
      $add_product = clone $product;
      $add_product->data['child_info'] = $child_info;
      $add_product->data['parents_info'] = $parents_info;

      $form_state['add_products'][] = $add_product;
      $products_grouped_by_sku[$product->sku][] = $product;
    }
  }

  $stock_error = FALSE;
  foreach($products_grouped_by_sku as $sku => $products) {
    $selected_qty = 0;
    $first_product = reset($products);
    foreach ($products as $product) {
      $selected_qty += $product->qty;
    }

    $cart_qty = oct_store_stock_cart_product_qty($first_product->sku);
    $store_qty = oct_store_stock_get_quantity($first_product);

    $available_qty = (($store_qty - $cart_qty) <= 0) ? 0 : ($store_qty - $cart_qty);

    if(($available_qty - $selected_qty) < 0) {
      $stock_error = TRUE;
      drupal_set_message(t('The maximum quantity for @product that can be ordered is @number', array('@product' => $product->name, '@number' => $available_qty)), 'error');
    }
  }

  if($stock_error) {
     oct_store_cc_save_step_values($form, $form_state);
     $form_state['storage']['step'] = 1;
     $form_state['rebuild'] = TRUE;
     oct_store_cc_restore_step_values($form, $form_state);
  }

}


/**
 * Submit callback.
 */
function oct_store_cc_form_submit(&$form, &$form_state) {

  foreach ($form_state['add_products'] as $store_product) {

    fnl_store_cart_add_product($store_product);
  }

  drupal_set_message(t('Products added to !cart.', array('!cart' => l(t('your shopping cart'), FNL_STORE_CART_PAGE))));
  $form_state['submit_finish'] = TRUE;
}

function oct_store_cc_get_date_string_value($input) {
  $date_obj = date_select_input_date(
    array(
      '#date_format' => 'Y-m-d',
      '#date_timezone' => date_default_timezone(),
      '#date_flexible' => 0,
      '#date_increment' => 1
    ), $input);

  return !empty($date_obj) ? $date_obj->format('Y-m-d') : '';
}

/**
 * Products ajax callback.
 */
function oct_store_cc_products_ajax($form, $form_state) {
  return $form['products'];
}


/**
 * Load camp products info, based on selected birth date and camp week
 */
function oct_store_cc_load_camps_products($type, $birth_date = NULL) {

  $product_views_filters = array();


  if(!empty($birth_date)) {
    $age_in_years = oct_store_cc_get_age($birth_date);

    $product_views_filters['min_age'] = $age_in_years;
    $product_views_filters['max_age'] = $age_in_years;
  }

  if($type == 'camp') {
    $products_views_data = fnl_store_views_retrieve('c_and_c_forms_source', 'camps', $product_views_filters);

    $products = oct_store_cc_prepare_products($products_views_data, $type);
    $product_groups = oct_store_cc_camp_products_groups($products);
  } else {
    $products_views_data = fnl_store_views_retrieve('classes_forms_source', 'classes', $product_views_filters);

    $products = oct_store_cc_prepare_products($products_views_data, $type);
    $product_groups = array();
  }

  return array($products, $product_groups);
}


/**
 * Prepare products values. From Views result to store product objects
 */
function oct_store_cc_prepare_products($products, $type) {

  $prepared_products = array();

  foreach ($products as $key => $product) {

    $cart_product = new StdClass();
    $cart_product->nid = $product->nid;
    $cart_product->qty = 1;//this qty will be added to cart
    $cart_product->name = $product->name;
    $cart_product->type = 'product_' . $type;
    $cart_product->amount = $product->price;
    $cart_product->sku = 'product_' . $type . '_' . $product->collection_id;
    //camps related data
    $cart_product->data['full_info'] = (array) $product;
    $cart_qty = oct_store_stock_cart_product_qty($cart_product->sku);
    $cart_product->data['full_info']['available_qty'] = (($product->qty - $cart_qty) <= 0) ? 0 : $product->qty - $cart_qty;
    $prepared_products[$product->collection_id] = $cart_product;
  }

  return $prepared_products;
}

/**
 * Group by week taxonomy
 */
function oct_store_cc_camp_products_groups($products) {
  $groups = array();
  $group_number = 0;
  $previous_week = NULL;

  foreach ($products as $key => $product) {

    if($previous_week !== $product->data['full_info']['week']) {
      $group_number++;
    }

    $groups[$group_number]['products_keys'][] = $product->data['full_info']['collection_id'];
    $groups[$group_number]['week'] = $product->data['full_info']['week'];

    $previous_week = $product->data['full_info']['week'];
  }

  return $groups;
}

/**
 * Get weeks taxonomy options
 */
function oct_store_cc_get_camp_weeks_options() {
  $options = array();
  $vocabulary = taxonomy_vocabulary_machine_name_load('summer_camp_dates');

  if($vocabulary) {
    $tree = taxonomy_get_tree($vocabulary->vid, 0, NULL, TRUE);
    $options = array();

    if ($tree) {
      foreach ($tree as $term) {
        $options[$term->tid] = entity_label('taxonomy_term', $term);
      }
    }
  }

  return $options;
}

/**
 * Calculate age in years.
 *
 * @param string $birthday - date in Y-m-d format
 * @return int age in years.
 */
function oct_store_cc_get_age($birthday) {
  $from = new DateTime($birthday);
  $to = new DateTime('today');
  return $from->diff($to)->y;
}

/**
 * Add empty value text.
 */
function oct_store_ccs_date_select_after_build($element, $form_state) {
  foreach (array('day', 'month', 'year', 'hour', 'minute', 'second') as $key) {
    if(!empty($element[$key])) {
      $element[$key]['#empty_option'] = t('-select-');

      if(isset($element[$key]['#options']['']) && empty($element[$key]['#options'][''])) {
        $element[$key]['#options'][''] = t('-select-');
      }
    }
  }
  return $element;
}