<?php
/**
 * @file
 * cream_feature_schedule.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cream_feature_schedule_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cream_feature_schedule_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function cream_feature_schedule_eck_bundle_info() {
  $items = array(
  'room_room' => array(
  'machine_name' => 'room_room',
  'entity_type' => 'room',
  'name' => 'room',
  'label' => 'Room',
),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function cream_feature_schedule_eck_entity_type_info() {
$items = array(
       'room' => array(
  'name' => 'room',
  'label' => 'Room',
  'properties' => array(
    'title' => array(
      'label' => 'Title',
      'type' => 'text',
      'behavior' => 'title',
    ),
  ),
),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function cream_feature_schedule_node_info() {
  $items = array(
    'keynote' => array(
      'name' => t('Keynote'),
      'base' => 'node_content',
      'description' => t('Use a <em>keynote</em> for special sessions which will have nothing else scheduled alongside them.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'schedule' => array(
      'name' => t('Schedule'),
      'base' => 'node_content',
      'description' => t('A <em>schedule</em> describes a single day of the event, and may have a timetable.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'scheduled_item' => array(
      'name' => t('Scheduled item'),
      'base' => 'node_content',
      'description' => t('A scheduled item that is not a session, such as lunch or registration.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    /*'session' => array(
      'name' => t('Session'),
      'base' => 'node_content',
      'description' => t('A session can be a presentation, a BoF, or a sprint.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),*/
  );
  return $items;
}
