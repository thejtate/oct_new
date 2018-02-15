<?php
/**
 * @file
 *  Views integration
 */

/**
 * Implements hook_views_data().
 */
function oct_store_ftb_views_data() {
  $data = array();

  $data['oct_store_ftb_purchase'] = array(
    'table' => array(
      'group' => t('Fairy tale ball purchase info'),
      'base' => array(
        'field' => 'cid',
        'title' => t('Fairy tale ball purchase info.'),
        'help' => t('Fairy tale ball purchase info.'),
        'weight' => -10,
      ),
      'join' => array(
        'fnl_store_cart' => array(
          'left_field' => 'cid',
          'field' => 'cid',
        ),
      ),
    ),
  );

  $data['oct_store_ftb_purchase']['cid'] = array(
    'title' => t('Cart item ID'),
    'help' => t('Cart item ID'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array(
      'base' => 'fnl_store_cart', // The name of the table to join with.
      'base field' => 'cid', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Cart relationship'),
      'title' => t('Cart relationship'),
      'help' => t('Related cart'),
    ),
  );

  $data['oct_store_ftb_purchase']['name'] = array(
    'title' => t('Your Name / Company Name'),
    'help' => t('Your Name / Company Name'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

//  $data['oct_store_production_purchase']['cid'] = array(
//    'title' => t('Cart item ID'),
//    'field' => array(
//      'handler' => 'views_handler_field_numeric',
//      'click sortable' => TRUE,
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_numeric',
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_numeric',
//    ),
//    'relationship' => array(
//      'base' => 'fnl_store_cart', // The name of the table to join with.
//      'base field' => 'cid', // The name of the field on the joined table.
//      'handler' => 'views_handler_relationship',
//      'label' => t('Cart product relationship'),
//      'title' => t('Cart product relationship'),
//      'help' => t('Related cart product'),
//    ),
//  );
//
//  $data['oct_store_production_purchase']['datetime'] = array(
//    'title' => t('Date'),
//    'help' => t('Date'),
//    'field' => array(
//      'handler' => 'views_handler_field_fnl_store_datetime',
//      'click sortable' => TRUE,
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_fnl_store_datetime',
//      // Note that you can override the field-wide label:
//      'label' => t('Created date time'),
//      // This setting is used by the boolean filter handler, as possible option.
//      'type' => 'yes-no',
//      // Use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment.
//      'use equal' => TRUE,
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort_date',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_date',
//    ),
//  );
//
//  $data['oct_store_production_purchase']['quantity_adults'] = array(
//    'title' => t('Adults quantity'),
//    'help' => t('Adults quantity'),
//    'field' => array(
//      'handler' => 'views_handler_field_numeric',
//      'click sortable' => TRUE,
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_numeric',
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_numeric',
//    ),
//  );
//
//  $data['oct_store_production_purchase']['quantity_students'] = array(
//    'title' => t('Students quantity'),
//    'help' => t('Students quantity'),
//    'field' => array(
//      'handler' => 'views_handler_field_numeric',
//      'click sortable' => TRUE,
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_numeric',
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_numeric',
//    ),
//  );
//
//  $data['oct_store_production_purchase']['quantity_children'] = array(
//    'title' => t('Children quantity'),
//    'help' => t('Children quantity'),
//    'field' => array(
//      'handler' => 'views_handler_field_numeric',
//      'click sortable' => TRUE,
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_numeric',
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_numeric',
//    ),
//  );
//
//  $data['oct_store_production_purchase']['quantity_children_small_group'] = array(
//    'title' => t('Children small group quantity'),
//    'help' => t('Children small group quantity'),
//    'field' => array(
//      'handler' => 'views_handler_field_numeric',
//      'click sortable' => TRUE,
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_numeric',
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_numeric',
//    ),
//  );
//
//  $data['oct_store_production_purchase']['quantity_children_big_group'] = array(
//    'title' => t('Children big group quantity'),
//    'help' => t('Children big group quantity'),
//    'field' => array(
//      'handler' => 'views_handler_field_numeric',
//      'click sortable' => TRUE,
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_numeric',
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_numeric',
//    ),
//  );
//
//  $data['oct_store_production_purchase']['quantity_complimentary_adult'] = array(
//    'title' => t('Complimentary adult quantity'),
//    'help' => t('Complimentary adult quantity'),
//    'field' => array(
//      'handler' => 'views_handler_field_numeric',
//      'click sortable' => TRUE,
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_numeric',
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_numeric',
//    ),
//  );

  // hook_views_data_item_field_

  return $data;
}