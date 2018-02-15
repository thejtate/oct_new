<?php

/**
 * @file
 * Custom filter for datetime custom table fields
 */

class views_handler_filter_fnl_store_datetime extends date_views_filter_handler_simple {
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->date_handler->date_type = DATE_DATETIME;
  }
}