<?php

/**
 * @file
 * Custom class for serialized field.
 */
class views_handler_field_oct_store_serial_field extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    $options['field_name'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $options = array(
      't-shirt-fee' => t('Fee for T-Shirt'),
      'classes-camps-fee' => t('Fee for classes/camps'),
      'total-discount' => t('Total Discount'),
      'total-discount-sum' => t('Total Discount (SUM)'),
      'discount-name' => t('Discount Name'),
      'discount-name-comma-divider' => t('Discount Name (comma divider)'),
    );

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
        case 't-shirt-fee':
          $fees = (isset($data['amount_modifications']) && isset($data['amount_modifications']['fees'])) ?
            $data['amount_modifications']['fees'] : array();
          foreach ($fees as $item) {
            if ($item['title'] == 'Fee for T-shirts') {
              $result = fnl_store_format_amount($item['value']);
            }
          }
          break;
        case 'classes-camps-fee':
          $fees = (isset($data['amount_modifications']) && isset($data['amount_modifications']['fees'])) ?
            $data['amount_modifications']['fees'] : array();
          foreach ($fees as $item) {
            if ($item['title'] == 'Fee for classes/camps') {
              $result = fnl_store_format_amount($item['value']);
            }
          }
          break;
        case 'total-discount':
          $discounts = (isset($data['amount_modifications']) && isset($data['amount_modifications']['discounts']) &&
            !empty($data['amount_modifications']['discounts'])) ?
            $data['amount_modifications']['discounts'] : array();
          foreach ($discounts as $discount) {
            $value = isset($discount['value']) ? $discount['value'] : '';
            $result .= fnl_store_format_amount($value) . '<br/>';
          }
          break;
        case 'total-discount-sum':
          $discounts = (isset($data['amount_modifications']) && isset($data['amount_modifications']['discounts']) &&
            !empty($data['amount_modifications']['discounts'])) ?
            $data['amount_modifications']['discounts'] : array();
          $sum = 0;
          foreach ($discounts as $discount) {
            $value = isset($discount['value']) ? $discount['value'] : '';
            $sum += $value;
          }
          $result .= !empty($sum) ? fnl_store_format_amount($sum) : '';
          break;
        case 'discount-name':
          $discounts = (isset($data['amount_modifications']) && isset($data['amount_modifications']['discounts']) &&
            !empty($data['amount_modifications']['discounts'])) ?
            $data['amount_modifications']['discounts'] : array();
          foreach ($discounts as $discount) {
            $title = isset($discount['title']) ? $discount['title'] : '';
            $result .= $title . '<br/>';
          }
          break;
        case 'discount-name-comma-divider':
          $discounts = (isset($data['amount_modifications']) && isset($data['amount_modifications']['discounts']) &&
            !empty($data['amount_modifications']['discounts'])) ?
            $data['amount_modifications']['discounts'] : array();
          $titles = array();
          foreach ($discounts as $discount) {
            if(isset($discount['title'])) {
              $titles[] = $discount['title'];
            }
          }
          $result .= implode(', ' , $titles);
          break;
      }
      return $result;
    }
    else {
      return '';
    }
  }
}