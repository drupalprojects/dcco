<?php
/**
 * @file
 * cream_feature_schedule.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cream_feature_schedule_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_schedule_date'
  $field_bases['field_schedule_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_schedule_date',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 'day',
        'hour' => 0,
        'minute' => 0,
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'timezone_db' => '',
      'todate' => '',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_schedule_description'
  $field_bases['field_schedule_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_schedule_description',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_schedule_timeslots'
  $field_bases['field_schedule_timeslots'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_schedule_timeslots',
    'foreign keys' => array(),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'schedule_timeslot' => array(
            'status' => 1,
          ),
          'session_room' => array(
            'status' => 0,
          ),
          'session_timeslot' => array(
            'status' => 0,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'timeslot' => 'timeslot',
        ),
      ),
      'target_type' => 'timeslot',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_session_description'
  $field_bases['field_session_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_session_description',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_session_room'
  $field_bases['field_session_room'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_session_room',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(
      'eck_room' => array(
        'columns' => array(
          'target_id' => 'id',
        ),
        'table' => 'eck_room',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'schedule_timeslot' => array(
            'status' => 0,
          ),
          'session_room' => array(
            'status' => 1,
          ),
          'session_timeslot' => array(
            'status' => 0,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'direction' => 'ASC',
          'property' => 'title',
          'type' => 'property',
        ),
        'target_bundles' => array(),
      ),
      'target_type' => 'room',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_session_timeslot'
  $field_bases['field_session_timeslot'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_session_timeslot',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(
      'eck_timeslot' => array(
        'columns' => array(
          'target_id' => 'id',
        ),
        'table' => 'eck_timeslot',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'session_timeslot',
      'handler_settings' => array(
        'behaviors' => array(
          'schedule_timeslot' => array(
            'status' => 0,
          ),
          'session_room' => array(
            'status' => 0,
          ),
          'session_timeslot' => array(
            'status' => 1,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'target_bundles' => array(
          'timeslot' => 'timeslot',
        ),
      ),
      'target_type' => 'timeslot',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_session_track'
  $field_bases['field_session_track'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_session_track',
    'foreign keys' => array(),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'schedule_timeslot' => array(
            'status' => 0,
          ),
          'session_room' => array(
            'status' => 0,
          ),
          'session_timeslot' => array(
            'status' => 0,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'direction' => 'ASC',
          'property' => 'name',
          'type' => 'property',
        ),
        'target_bundles' => array(
          'track' => 'track',
        ),
      ),
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
