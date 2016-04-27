<?php
/**
 * @file
 * cream_feature_schedule.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cream_feature_schedule_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_session_room'.
  $permissions['create field_session_room'] = array(
    'name' => 'create field_session_room',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_session_timeslot'.
  $permissions['create field_session_timeslot'] = array(
    'name' => 'create field_session_timeslot',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create keynote content'.
  $permissions['create keynote content'] = array(
    'name' => 'create keynote content',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create schedule content'.
  $permissions['create schedule content'] = array(
    'name' => 'create schedule content',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create scheduled_item content'.
  $permissions['create scheduled_item content'] = array(
    'name' => 'create scheduled_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create session content'.
  /*$permissions['create session content'] = array(
    'name' => 'create session content',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
      'participant' => 'participant',
    ),
    'module' => 'node',
  );*/

  // Exported permission: 'delete any keynote content'.
  $permissions['delete any keynote content'] = array(
    'name' => 'delete any keynote content',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any schedule content'.
  $permissions['delete any schedule content'] = array(
    'name' => 'delete any schedule content',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any scheduled_item content'.
  $permissions['delete any scheduled_item content'] = array(
    'name' => 'delete any scheduled_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any session content'.
  /*$permissions['delete any session content'] = array(
    'name' => 'delete any session content',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'node',
  );*/

  // Exported permission: 'eck add room room entities'.
  $permissions['eck add room room entities'] = array(
    'name' => 'eck add room room entities',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add timeslot timeslot entities'.
  $permissions['eck add timeslot timeslot entities'] = array(
    'name' => 'eck add timeslot timeslot entities',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer room room entities'.
  $permissions['eck administer room room entities'] = array(
    'name' => 'eck administer room room entities',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete room room entities'.
  $permissions['eck delete room room entities'] = array(
    'name' => 'eck delete room room entities',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete timeslot timeslot entities'.
  $permissions['eck delete timeslot timeslot entities'] = array(
    'name' => 'eck delete timeslot timeslot entities',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit room room entities'.
  $permissions['eck edit room room entities'] = array(
    'name' => 'eck edit room room entities',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit timeslot timeslot entities'.
  $permissions['eck edit timeslot timeslot entities'] = array(
    'name' => 'eck edit timeslot timeslot entities',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list room room entities'.
  $permissions['eck list room room entities'] = array(
    'name' => 'eck list room room entities',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view room room entities'.
  $permissions['eck view room room entities'] = array(
    'name' => 'eck view room room entities',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'edit any keynote content'.
  $permissions['edit any keynote content'] = array(
    'name' => 'edit any keynote content',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any schedule content'.
  /*$permissions['edit any schedule content'] = array(
    'name' => 'edit any schedule content',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'node',
  );*/

  // Exported permission: 'edit any scheduled_item content'.
  $permissions['edit any scheduled_item content'] = array(
    'name' => 'edit any scheduled_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any session content'.
  /*$permissions['edit any session content'] = array(
    'name' => 'edit any session content',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'node',
  );*/

  // Exported permission: 'edit field_session_room'.
  $permissions['edit field_session_room'] = array(
    'name' => 'edit field_session_room',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_session_timeslot'.
  $permissions['edit field_session_timeslot'] = array(
    'name' => 'edit field_session_timeslot',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own session content'.
  /*$permissions['edit own session content'] = array(
    'name' => 'edit own session content',
    'roles' => array(
      'administrator' => 'administrator',
      'participant' => 'participant',
    ),
    'module' => 'node',
  );*/

  // Exported permission: 'edit schedule timetable'.
  $permissions['edit schedule timetable'] = array(
    'name' => 'edit schedule timetable',
    'roles' => array(
      'administrator' => 'administrator',
      'organiser' => 'organiser',
    ),
    'module' => 'timetable',
  );

  // Exported permission: 'view field_session_room'.
  $permissions['view field_session_room'] = array(
    'name' => 'view field_session_room',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_session_timeslot'.
  $permissions['view field_session_timeslot'] = array(
    'name' => 'view field_session_timeslot',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
