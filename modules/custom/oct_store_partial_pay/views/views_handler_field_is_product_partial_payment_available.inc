<?php

/**
 * Views field handler. For product partial payment availability
 */

class views_handler_field_is_product_partial_payment_available extends views_handler_field {

  function option_definition() {
    $options =  parent::option_definition();

    $options['yes_label'] = array('default' => 'Yes');
    $options['no_label'] = array('default' => 'No');

    return $options;
  }

  /**
   * Default options form that provides the label widget that all fields
   * should have.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['yes_label'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('Text for "Yes" values'),
      '#default_value' => $this->options['yes_label'],
      '#weight' => 90,
    );
    $form['no_label'] = array(
      '#type' => 'textfield',
      '#required' => TRUE,
      '#title' => t('Text for "No" values'),
      '#default_value' => $this->options['no_label'],
      '#weight' => 91,
    );

  }


  function render($values) {

    $product = new stdClass();
    $product->cid = $this->get_value($values);

    if(!empty($product->cid)) {

      $product->name = $this->get_value($values, 'name');
      $product->type = $this->get_value($values, 'type');
      $product->oid = $this->get_value($values, 'oid');
      $product->nid = $this->get_value($values, 'nid');
      $product->qty = $this->get_value($values, 'qty');
      $product->amount = $this->get_value($values, 'amount');
      $product->added = $this->get_value($values, 'added');

      $product->data = $this->get_value($values, 'data');
      $product->data = !empty($product->data) ? unserialize($product->data) : NULL;

      return oct_store_partail_pay_is_available_for_product($product) ? $this->options['yes_label'] : $this->options['no_label'];
    } else {
      return '';
    }
  }
}