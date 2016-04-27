<?php
/**
 * @file
 * dcco_session_submission.features.inc
 */

/**
 * Implements hook_views_api().
 */
function dcco_session_submission_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dcco_session_submission_node_info() {
  $items = array(
    'session' => array(
      'name' => t('Session'),
      'base' => 'node_content',
      'description' => t('This is a session submission.'),
      'has_title' => '1',
      'title_label' => t('Session title'),
      'help' => '',
    ),
  );
  return $items;
}
