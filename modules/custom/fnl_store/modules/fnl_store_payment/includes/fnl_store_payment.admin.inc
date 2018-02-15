<?php
/**
 * @file
 * Payment module configuration
 */

/**
 * Payment module settings.
 */
function fnl_store_payment_settings_form($form, &$form_state){


  $form['common'] = array(
    '#type' => 'fieldset',
    '#tree' => FALSE,
    '#title' => t('Common settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['common']['fnl_store_payment_hide_single'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide payment selector for single payment provider.'),
    '#description' => t(
      'Hide provider selector in payment form for the single enabled providers.'
    ),
    '#default_value' => variable_get('fnl_store_payment_hide_single', TRUE),
  );

  $form['payment_providers'] = array(
    '#type' => 'fieldset',
    '#tree' => FALSE,
    '#title' => t('Payment Provders'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $providers = fnl_store_payment_providers();

  $form['payment_providers']['fnl_store_payment_providers_enabled'] = array(
    '#type' => 'checkboxes',
    '#required' => FALSE,
    '#title' => t('Enable payment providers'),
    '#options' => fnl_store_payment_providers_options($providers),
    '#default_value' => variable_get('fnl_store_payment_providers_enabled', array()),
  );

  foreach ($providers as $provider_id =>  $provider) {
    $form['payment_providers'][$provider_id] = array(
      '#type' => 'fieldset',
      '#tree' => FALSE,
      '#title' => $provider['title'],
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    if(!empty($provider['settings_form_callback']) && function_exists($provider['settings_form_callback'])) {
      $provider_form = call_user_func($provider['settings_form_callback'], $form, $form_state);
      $provider_form = !empty($provider_form) ? $provider_form : array();
      $form['payment_providers'][$provider_id] = array_merge($form['payment_providers'][$provider_id], $provider_form);
    }
  }


  return system_settings_form($form);
}
