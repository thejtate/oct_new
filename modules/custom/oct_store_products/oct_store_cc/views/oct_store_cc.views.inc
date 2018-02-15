<?php

/**
 * @file
 * Views integration.
 */

/**
 * Implements hook_views_data_alter().
 */
function oct_store_cc_views_data_alter(&$data) {

  //add numeric filters to integer lists
  $data['field_data_field_camp_min_age']['field_camp_min_age_value_integer'] =
    array(
      'group' => 'Content',
      'title' => 'Min age (field_camp_min_age) Numeric filter',
      'help' => 'Custom Numeric filter version for integer list',
      'title short' => 'Min age, numeric',
      'filter' => array(
        'field' => 'field_camp_min_age_value',
        'table' => 'field_data_field_camp_min_age',
        'handler' => 'views_handler_filter_numeric',
        'additional_field' => array('field_camp_min_age_value'),
        'field_name' => 'field_camp_min_age',
        'allow empty' => TRUE,
      )

    );
  $data['field_data_field_camp_max_age']['field_camp_max_age_value_integer'] =
    array(
      'group' => 'Content',
      'title' => 'Max age (field_camp_max_age) Numeric filter',
      'help' => 'Custom Numeric filter version for integer list',
      'title short' => 'Max age, numeric',
      'filter' => array(
        'field' => 'field_camp_max_age_value',
        'table' => 'field_data_field_camp_max_age',
        'handler' => 'views_handler_filter_numeric',
        'additional_field' => array('field_camp_max_age_value'),
        'field_name' => 'field_camp_max_age',
        'allow empty' => TRUE,
      )
    );

}

/**
 * Implements hook_views_data().
 */
function oct_store_cc_views_data() {

  $data = array();

  $data['oct_store_camp_class_purchase'] = array(
    'table' => array(
      'group' => t('Camp and classes purchase info'),
      'base' => array(
        'field' => 'cid',
        'title' => t('Camp and classes purchase info.'),
        'help' => t('Camp and classes purchase info.'),
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

  $data['oct_store_camp_class_purchase']['cid'] = array(
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

  $data['oct_store_camp_class_purchase']['week'] = array(
    'title' => t('Camp week'),
    'help' => t('Camp week'),
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

  $data['oct_store_camp_class_purchase']['product_type'] = array(
    'title' => t('Product type class or camp'),
    'help' => t(''),
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

  $data['oct_store_camp_class_purchase']['event_date_from'] = array(
    'title' => t('Camp date from'),
    'help' => t('Camp date from'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_datetime',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_fnl_store_datetime',
      // Note that you can override the field-wide label:
      'label' => t('Created date time'),
      // This setting is used by the boolean filter handler, as possible option.
      'type' => 'yes-no',
      // Use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment.
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );

  $data['oct_store_camp_class_purchase']['event_date_to'] = array(
    'title' => t('Camp date to'),
    'help' => t('Camp date to'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_datetime',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_fnl_store_datetime',
      // Note that you can override the field-wide label:
      'label' => t('Created date time'),
      // This setting is used by the boolean filter handler, as possible option.
      'type' => 'yes-no',
      // Use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment.
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );

  $data['oct_store_camp_class_purchase']['birth_date'] = array(
    'title' => t('Birth date'),
    'help' => t('Birth date'),
    'field' => array(
      'handler' => 'views_handler_field_fnl_store_datetime',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_fnl_store_datetime',
      // Note that you can override the field-wide label:
      'label' => t('Created date time'),
      // This setting is used by the boolean filter handler, as possible option.
      'type' => 'yes-no',
      // Use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment.
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );

  $data['oct_store_camp_class_purchase']['first_name'] = array(
    'title' => t('Child First name'),
    'help' => t('Child First name'),
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

  $data['oct_store_camp_class_purchase']['last_name'] = array(
    'title' => t('Child Last name'),
    'help' => t('Child Last name'),
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
  $data['oct_store_camp_class_purchase']['gender'] = array(
    'title' => t('Child gender'),
    'help' => t('Child gender'),
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

  $data['oct_store_camp_class_purchase']['days'] = array(
    'title' => t('Days of week'),
    'help' => t('Days of week'),
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

  $data['oct_store_camp_class_purchase']['allergy'] = array(
    'title' => t('Child allergy'),
    'help' => t('Child allergy'),
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

  /**
   * Parent Information: Primary Contact
   */
  $data['oct_store_camp_class_purchase']['primary_first_name'] = array(
    'title' => t('Parent`s Information: Primary Contact First Name'),
    'help' => t('Parent`s Information: Primary Contact First Name'),
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

  $data['oct_store_camp_class_purchase']['primary_last_name'] = array(
    'title' => t('Parent`s Information: Primary Contact Last Name'),
    'help' => t('Parent`s Information: Primary Contact Last Name'),
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

  $data['oct_store_camp_class_purchase']['primary_daytime_phone'] = array(
    'title' => t('Parent`s Information: Primary Contact Phone'),
    'help' => t('Parent`s Information: Primary Contact Phone (backward compatibility)'),
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

  $data['oct_store_camp_class_purchase']['primary_phone_type'] = array(
    'title' => t('Parent`s Information: Primary Phone Type'),
    'help' => t('Parent`s Information: Primary Phone type'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_in_operator',
      'options callback' => 'oct_store_cc_phone_type_options',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['oct_store_camp_class_purchase']['primary_cell_phone'] = array(
    'title' => t('Parent`s Information: Primary Contact Cell Phone'),
    'help' => t('Parent`s Information: Primary Contact Cell Phone'),
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

  $data['oct_store_camp_class_purchase']['primary_email'] = array(
    'title' => t('Parent`s Information: Primary Contact Email'),
    'help' => t('Parent`s Information: Primary Contact Email'),
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

  $data['oct_store_camp_class_purchase']['primary_relationship'] = array(
    'title' => t('Parent`s Information: Primary Contact Relationship to child'),
    'help' => t('Parent`s Information: Primary Contact Relationship to child'),
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


  /**
   * Parent Information:Alternate Contact
   */
  $data['oct_store_camp_class_purchase']['alternate_first_name'] = array(
    'title' => t('Parent`s Information: Alternate Contact First Name'),
    'help' => t('Parent`s Information: Alternate Contact First Name'),
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

  $data['oct_store_camp_class_purchase']['alternate_last_name'] = array(
    'title' => t('Parent`s Information: Alternate Contact Last Name'),
    'help' => t('Parent`s Information: Alternate Contact Last Name'),
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

  $data['oct_store_camp_class_purchase']['emergency_phone_type'] = array(
    'title' => t('Parent`s Information: Emergency Phone Type'),
    'help' => t('Parent`s Information: Emergency Phone type'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_in_operator',
      'options callback' => 'oct_store_cc_phone_type_options',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['oct_store_camp_class_purchase']['alternate_daytime_phone'] = array(
    'title' => t('Parent`s Information: Alternate Contact Phone'),
    'help' => t('Parent`s Information: Alternate Contact Phone'),
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

  $data['oct_store_camp_class_purchase']['alternate_cell_phone'] = array(
    'title' => t('Parent`s Information: Alternate Contact Cell Phone'),
    'help' => t('Parent`s Information: Alternate Contact Cell Phone (backward compatibility)'),
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

  $data['oct_store_camp_class_purchase']['alternate_email'] = array(
    'title' => t('Parent`s Information: Alternate Contact Email'),
    'help' => t('Parent`s Information: Alternate Contact Email'),
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


  /**
   * Emergency Medical Release
   */
  $data['oct_store_camp_class_purchase']['emergency_first_name'] = array(
    'title' => t('Emergency Medical Release: Emergency Contact First Name'),
    'help' => t('Emergency Medical Release: Emergency Contact First Name'),
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

  $data['oct_store_camp_class_purchase']['emergency_last_name'] = array(
    'title' => t('Emergency Medical Release: Emergency Contact Last Name'),
    'help' => t('Emergency Medical Release: Emergency Contact Last Name'),
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

  $data['oct_store_camp_class_purchase']['emergency_daytime_phone'] = array(
    'title' => t('Emergency Medical Release: Emergency Contact Daytime Phone'),
    'help' => t('Emergency Medical Release: Emergency Contact Daytime Phone'),
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

  $data['oct_store_camp_class_purchase']['emergency_relationship'] = array(
    'title' => t('Emergency Medical Release: Emergency Contact Relationship to child'),
    'help' => t('Emergency Medical Release: Emergency Contact Relationship to child'),
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

  $data['oct_store_camp_class_purchase']['emergency_is_other_information'] = array(
    'title' => t('Emergency Medical Release: Emergency Contact Is Other Information'),
    'help' => t('Emergency Medical Release: Emergency Contact Is Other Information'),
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

  $data['oct_store_camp_class_purchase']['emergency_other_information'] = array(
    'title' => t('Emergency Medical Release: Emergency Contact Other Information'),
    'help' => t('Emergency Medical Release: Emergency Contact Other Information'),
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


//   hook_views_data_item_field_

  return $data;
}