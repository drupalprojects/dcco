<?php

/**
 * @file
 * Contains the plugin class.
 */

/**
 * Views style plugin for the Cream timetable.
 */
class cream_timetable_plugin_style_timetable extends views_plugin_style_table {

  function option_definition() {
    $options = parent::option_definition();

    $options['show_schedule'] = array('default' => FALSE, 'bool' => TRUE);
    $options['show_header'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

  /**
   * Admin options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['show_schedule'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show the schedule name at the start of the sessions.'),
      '#default_value' => !empty($this->options['show_schedule']),
      '#description' => t('Enable this if the view is showing sessions from more than one schedule.'),
    );

    $form['show_header'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show the header of rooms.'),
      '#default_value' => !empty($this->options['show_header']),
      '#description' => t('Enable this if the view is showing sessions across different rooms.'),
    );
  }

}
