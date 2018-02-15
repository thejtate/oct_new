#!/bin/bash

#helper dev script to reinstall modules, for updating schema

drush dis oct_store_cc -y
drush pm-uninstall oct_store_cc -y

drush dis fnl_store_cart -y
drush pm-uninstall fnl_store_cart -y

drush dis fnl_store_paypal -y
drush pm-uninstall fnl_store_paypal -y

drush dis fnl_store_payment -y
drush pm-uninstall fnl_store_payment -y

drush dis fnl_store -y
drush pm-uninstall fnl_store -y


drush en oct_store_cc -y
drush en fnl_store_paypal -y

#enable cart block
drush php-eval "db_delete('block')->condition('module', 'fnl_store_cart')->execute();
\$record = array(
  'module' => 'fnl_store_cart',
  'delta' => 'fnl_store_cart',
  'theme' => 'oct',
  'status' => 1,
  'weight' => -10,
  'region' => 'sidebar_right',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'prom-room
message-board',
  'title' => '<none>',
  'cache' => -1,
  );

drupal_write_record('block', \$record);"