<?php

/**
 * @file
 * Datetime handler for datetime custom table fields.
 */

class views_handler_field_fnl_store_datetime extends views_handler_field_date {
  function get_value($values, $field = NULL) {
    $value =  parent::get_value($values,$field);

    return !empty($value) ? strtotime($value . '+0000') : NULL;
  }
}