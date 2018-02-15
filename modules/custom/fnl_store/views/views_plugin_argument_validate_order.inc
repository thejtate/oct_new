<?php
/**
 * Validate order access.
 */

class views_plugin_argument_validate_order extends views_plugin_argument_validate {

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    $form['order_validate_message'] = array(
      '#markup' => '<div>' . t('Validate order access') . '</div>',
    );
  }


  function validate_argument($arg) {

    if (!is_numeric($arg)) {
      return FALSE;
    }
    $order = fnl_store_order_load($arg);
    if (!$order) {
      return FALSE;
    }

    $user_id = fnl_store_cart_user_id();
    if(!user_access('fnl store view full orders info') && ($user_id !== $order->user_id)) {
      return FALSE;
    }
    return TRUE;
  }

}