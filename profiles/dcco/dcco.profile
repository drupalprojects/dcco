<?php
/**
 * @file
 * Enables modules and site configuration for the Drupalcamp Colorado site.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function dcco_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = 'DrupalCamp Colorado';
  $form['server_settings']['#collapsible'] = 'TRUE';
  $form['server_settings']['#collapsed'] = 'TRUE';
  $form['server_settings']['site_default_country']['#default_value'] = 'US';
}
