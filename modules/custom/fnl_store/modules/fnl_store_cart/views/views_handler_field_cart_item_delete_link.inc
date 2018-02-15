<?php

/**
 * Custom handler for cart item delete link
 */

class views_handler_field_cart_item_delete_link extends views_handler_field {


  /**
   * Renders the link.
   */
  function render_link($cid) {
    global $user;


      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "store/remove-product/$cid";
      $this->options['alter']['query'] = drupal_get_destination();

      $text = !empty($this->options['text']) ? $this->options['text'] : t('Delete');

      return $text;

  }

  function render($values) {
    $value = $this->get_value($values);
    $user_id = $this->get_value($values, 'user_id');

    if($user_id == fnl_store_cart_user_id()) {
      return $this->render_link($value);
    } else {
      return '';
    }

  }

  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => 'Remove', 'translatable' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
    parent::options_form($form, $form_state);

    // The path is set by render_link function so don't allow to set it.
    $form['alter']['path'] = array('#access' => FALSE);
    $form['alter']['external'] = array('#access' => FALSE);
  }

}