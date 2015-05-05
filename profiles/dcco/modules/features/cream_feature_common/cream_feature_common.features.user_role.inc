<?php
/**
 * @file
 * cream_feature_common.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function cream_feature_common_user_default_roles() {
  $roles = array();

  // Exported role: attendee.
  $roles['attendee'] = array(
    'name' => 'attendee',
    'weight' => 6,
  );

  // Exported role: organiser.
  $roles['organiser'] = array(
    'name' => 'organiser',
    'weight' => 3,
  );

  // Exported role: participant.
  $roles['participant'] = array(
    'name' => 'participant',
    'weight' => 4,
  );

  // Exported role: sponsor.
  $roles['sponsor'] = array(
    'name' => 'sponsor',
    'weight' => 7,
  );

  // Exported role: volunteer.
  $roles['volunteer'] = array(
    'name' => 'volunteer',
    'weight' => 5,
  );

  return $roles;
}
