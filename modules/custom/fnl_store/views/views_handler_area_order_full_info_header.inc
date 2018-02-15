<?php


class views_handler_area_order_full_info_header extends views_handler_area {

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['empty']['#description'] = t("Even if selected, this area handler will never render if a valid order cannot be found in the View's arguments.");
  }

  function render($empty = FALSE) {

    if (!$empty || !empty($this->options['empty'])) {

      $first_argument = reset($this->view->argument);

      if ($first_argument instanceof views_handler_argument_numeric
      && !empty($first_argument->value[0])) {

        $order_id = $first_argument->value[0];
        if($order = fnl_store_order_load($order_id)) {
          return theme('fnl_store_order_full_info_header', array('order' => $order));
        }

      }
    }
  }
}
