<?php

/**
 * @file
 * Custom class for rendered order fees.
 */

class views_handler_field_oct_store_fees_rendered extends views_handler_field {
  function render($values) {

    $data = $this->get_value($values, 'data');
    $data = !empty($data) ? unserialize($data) : NULL;

    if(!empty($data)) {

      return theme('oct_store_fees', array('data' => $data));
    } else {
      return '';
    }
  }
}