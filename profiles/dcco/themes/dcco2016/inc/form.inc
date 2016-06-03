<?php
/**
 * @file
 * Form hooks.
 */

/**
 * Implements hook_form_alter().
 */
function dcco2016_form_alter(&$form, &$form_state, $form_id) {

  // Add placeholder text to a form.
  switch ($form_id) {
    case "search_block_form":
      $form['search_block_form']['#attributes']['placeholder'] = "Enter a term";
      break;
    case "session_node_form":
      $title = empty($form['nid']['#value']) ? 'Propose a session' : 'Edit proposed session';
      drupal_set_title($title);
      break;
  }
}
