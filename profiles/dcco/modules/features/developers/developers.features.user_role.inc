<?php
/**
 * @file
 * developers.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function developers_user_default_roles() {
  $roles = array();

  // Exported role: developer.
  $roles['developer'] = array(
    'name' => 'developer',
    'weight' => 3,
  );

  return $roles;
}
