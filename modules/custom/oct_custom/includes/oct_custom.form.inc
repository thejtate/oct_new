<?php

/**
 * @file
 * clri_custom.form.inc
 */

/**
 * Custom page with site settings
 */
function oct_custom_site_settings_form() {
  $form = array();

  $form['event_info'] = array(
    '#type' => 'fieldset',
    '#title' => t('30th Anniversary info'),
    '#weight' => 1,
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['event_info']['frontpage-anv-info'] = array(
    '#type' => 'textarea',
    '#title' => t('Text'),
    '#default_value' => variable_get('frontpage-anv-info', ''),
    '#size' => 60,
  );
  
  $form['event_info']['oct_custom_menu_file_fid'] = array(
    '#title' => t('Ticket Image'),
    '#type' => 'managed_file',
    '#description' => t('The uploaded image file will be used as the ticket image on the homepage and donations page.'),
    '#default_value' => variable_get('oct_custom_menu_file_fid', ''),
    '#upload_location' => 'public://',
  );

  return system_settings_form($form);
}

/**
 * Verifies that the user supplied a file with the form.
 */
function oct_custom_site_settings_form_validate($form, &$form_state) {
  if (!isset($form_state['values']['oct_custom_menu_file_fid']) ||
    !is_numeric($form_state['values']['oct_custom_menu_file_fid'])) {
    form_set_error('oct_custom_menu_file_fid', t('Please select an image to upload.'));
  }
}


/**
 * Form submit.
 */
function oct_custom_site_settings_form_submit($form, &$form_state) {

  if ($form_state['values']['oct_custom_menu_file_fid'] != 0) {

    $file = file_load($form_state['values']['oct_custom_menu_file_fid']);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);

    file_usage_add($file, 'oct_custom', 'menu_file', 1);

    $file_path = file_create_url($file->uri);
    $menu_link = menu_link_load(OCT_CUSTOM_MENU_DOWNLOAD_PDF_MLID);
    $menu_link['link_path'] = $file_path;
    menu_link_save($menu_link);

    variable_set('oct_custom_menu_file_fid', $file->fid);

    drupal_set_message(t('The file @file_name was uploaded and saved with an ID of @fid.',
      array(
        '@file_name' => $file->filename,
        '@fid' => $file->fid,
      )
    ));
  }

  elseif ($form_state['values']['oct_custom_menu_file_fid'] == 0) {

    $fid = variable_get('oct_custom_menu_file_fid', FALSE);
    $file = $fid ? file_load($fid) : FALSE;
    if ($file) {
      file_usage_delete($file, 'oct_custom', 'menu_file', 1);
      file_delete($file);
    }

    variable_set('oct_custom_menu_file_fid', FALSE);
    drupal_set_message(t('The file @file_name was removed.', array('@file_name' => $file->filename)));
  }

}