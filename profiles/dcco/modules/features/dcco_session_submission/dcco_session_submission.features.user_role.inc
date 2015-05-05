<?php
/**
 * @file
 * dcco_session_submission.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dcco_session_submission_user_default_roles() {
  $roles = array();

  // Exported role: session curator.
  $roles['session curator'] = array(
    'name' => 'session curator',
    'weight' => 2,
  );

  return $roles;
}
