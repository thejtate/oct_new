<?php

/**
 * @file
 * Store settings.
 */

/**
 * Store settings.
 */
function fnl_store_admin_form($form, &$form_state) {

  $form['fnl_store_currency'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#title' => t('Currency'),
    '#description' => t('Store currency'),
    '#default_value' => variable_get('fnl_store_currency', 'USD'),
    '#empty_option' => t('- Select -'),
    '#options' => drupal_map_assoc(
      array(
        'AUD',
        'BRL',
        'CAD',
        'CHF',
        'CZK',
        'DKK',
        'EUR',
        'GBP',
        'HKD',
        'HUF',
        'ILS',
        'JPY',
        'MXN',
        'MYR',
        'NOK',
        'NZD',
        'PHP',
        'PLN',
        'SEK',
        'SGD',
        'THB',
        'TRY',
        'TWD',
        'USD'
      )
    ),
  );

  return system_settings_form($form);
}
