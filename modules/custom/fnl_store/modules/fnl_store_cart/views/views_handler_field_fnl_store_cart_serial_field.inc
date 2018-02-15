<?php

/**
 * @file
 * Custom class for serialized field.
 */
class views_handler_field_fnl_store_cart_serial_field extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    $options['field_name'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $options = array('t-shirt' => t('T-Shirt'));

    $form['field_name'] = array(
      '#type' => 'select',
      '#title' => t('Field'),
      '#options' => $options,
      '#default_value' => $this->options['field_name'],
      '#weight' => -5,
    );
  }

  function render($values) {

    $field_name = $this->options['field_name'];

    $data = $this->get_value($values);
    $data = !empty($data) ? unserialize($data) : NULL;

    if (!empty($data)) {
      $result = '';
      switch ($field_name) {
        case 't-shirt':
          $result = (isset($data['child_info']) && isset($data['child_info']['t-shirt'])) ?
            $data['child_info']['t-shirt'] : '';
          break;
      }
      return $result;
    }
    else {
      return '';
    }
  }
}