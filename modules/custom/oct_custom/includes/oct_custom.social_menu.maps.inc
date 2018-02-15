<?php
/**
 * @file Social maps
 */

/**
 * Social menu map.
 *
 * @return array
 */
function _oct_custom_social_menu_admin_settings_map() {
  return array(
    'oct_custom_social_menu_settings_facebook' => array(
      'title' => t('Facebook'),
      'class' => 'soc-1'
    ),
    'oct_custom_social_menu_settings_newsletter' => array(
      'title' => t('Newsletter'),
      'class' => 'soc-2'
    ),
    'oct_custom_social_menu_settings_memberships' => array(
      'title' => t('Memberships'),
      'class' => 'soc-3'
    ),
    'oct_custom_social_menu_settings_donate' => array(
      'title' => t('Donate'),
      'class' => 'soc-4'
    ),
  );
}
