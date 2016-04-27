<?php
/**
 * @file
 * cream_feature_schedule.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cream_feature_schedule_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cream_schedule_timetable';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_timeslot';
  $view->human_name = 'cream_schedule_timetable';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Schedule';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'cream_timetable';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_schedule_date' => 'field_schedule_date',
    'title' => 'title',
    'title_1' => 'title_1',
    'title_2' => 'title_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_schedule_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Referencing Session */
  $handler->display->display_options['relationships']['reverse_field_session_timeslot_node']['id'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['relationships']['reverse_field_session_timeslot_node']['table'] = 'eck_timeslot';
  $handler->display->display_options['relationships']['reverse_field_session_timeslot_node']['field'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['relationships']['reverse_field_session_timeslot_node']['ui_name'] = 'Referencing Session';
  $handler->display->display_options['relationships']['reverse_field_session_timeslot_node']['label'] = 'Session';
  /* Relationship: Referencing Schedule */
  $handler->display->display_options['relationships']['reverse_field_schedule_timeslots_node']['id'] = 'reverse_field_schedule_timeslots_node';
  $handler->display->display_options['relationships']['reverse_field_schedule_timeslots_node']['table'] = 'eck_timeslot';
  $handler->display->display_options['relationships']['reverse_field_schedule_timeslots_node']['field'] = 'reverse_field_schedule_timeslots_node';
  $handler->display->display_options['relationships']['reverse_field_schedule_timeslots_node']['ui_name'] = 'Referencing Schedule';
  $handler->display->display_options['relationships']['reverse_field_schedule_timeslots_node']['label'] = 'Schedule';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_room_target_id']['id'] = 'field_session_room_target_id';
  $handler->display->display_options['relationships']['field_session_room_target_id']['table'] = 'field_data_field_session_room';
  $handler->display->display_options['relationships']['field_session_room_target_id']['field'] = 'field_session_room_target_id';
  $handler->display->display_options['relationships']['field_session_room_target_id']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['relationships']['field_session_room_target_id']['label'] = 'Room';
  /* Field: Timeslot: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_timeslot';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Content: Schedule date */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['relationship'] = 'reverse_field_schedule_timeslots_node';
  $handler->display->display_options['fields']['field_schedule_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => '',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_schedule_timeslots_node';
  $handler->display->display_options['fields']['title']['label'] = 'Day';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_session_timeslot_node';
  /* Field: Room: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'eck_room';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_session_room_target_id';
  /* Field: Timeslot: Time */
  $handler->display->display_options['fields']['field_timeslot_time']['id'] = 'field_timeslot_time';
  $handler->display->display_options['fields']['field_timeslot_time']['table'] = 'field_data_field_timeslot_time';
  $handler->display->display_options['fields']['field_timeslot_time']['field'] = 'field_timeslot_time';
  $handler->display->display_options['fields']['field_timeslot_time']['label'] = '';
  $handler->display->display_options['fields']['field_timeslot_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_time']['settings'] = array(
    'display_format' => array(
      'hour' => 'G',
      'minute' => 'i',
      'separator' => ':',
      'period' => 'none',
      'period_separator' => '',
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_session_timeslot_node';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Sort criterion: Content: Schedule date (field_schedule_date) */
  $handler->display->display_options['sorts']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['sorts']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['sorts']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['sorts']['field_schedule_date_value']['relationship'] = 'reverse_field_schedule_timeslots_node';
  /* Sort criterion: Timeslot: Time (field_timeslot_time) */
  $handler->display->display_options['sorts']['field_timeslot_time_value']['id'] = 'field_timeslot_time_value';
  $handler->display->display_options['sorts']['field_timeslot_time_value']['table'] = 'field_data_field_timeslot_time';
  $handler->display->display_options['sorts']['field_timeslot_time_value']['field'] = 'field_timeslot_time_value';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'cream_timetable';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_schedule_date' => 'field_schedule_date',
    'title' => 'title',
    'title_1' => 'title_1',
    'title_2' => 'title_2',
    'field_timeslot_time' => 'field_timeslot_time',
    'nid' => 'nid',
    'type' => 'type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_schedule_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_timeslot_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['show_schedule'] = TRUE;
  $handler->display->display_options['style_options']['show_header'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Schedule date (field_schedule_date) */
  $handler->display->display_options['sorts']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['sorts']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['sorts']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['sorts']['field_schedule_date_value']['relationship'] = 'reverse_field_schedule_timeslots_node';
  /* Sort criterion: Timeslot: Time (field_timeslot_time) */
  $handler->display->display_options['sorts']['field_timeslot_time_value']['id'] = 'field_timeslot_time_value';
  $handler->display->display_options['sorts']['field_timeslot_time_value']['table'] = 'field_data_field_timeslot_time';
  $handler->display->display_options['sorts']['field_timeslot_time_value']['field'] = 'field_timeslot_time_value';
  /* Sort criterion: Content: Schedule date (field_schedule_date) */
  $handler->display->display_options['sorts']['field_schedule_date_value_1']['id'] = 'field_schedule_date_value_1';
  $handler->display->display_options['sorts']['field_schedule_date_value_1']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['sorts']['field_schedule_date_value_1']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['sorts']['field_schedule_date_value_1']['relationship'] = 'reverse_field_schedule_timeslots_node';
  $handler->display->display_options['path'] = 'schedule';

  /* Display: EVA Field */
  $handler = $view->new_display('entity_view', 'EVA Field', 'entity_view_timetable');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'cream_timetable';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_schedule_date' => 'field_schedule_date',
    'title' => 'title',
    'title_1' => 'title_1',
    'title_2' => 'title_2',
    'field_timeslot_time' => 'field_timeslot_time',
    'nid' => 'nid',
    'type' => 'type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_schedule_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_timeslot_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['show_header'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Schedule date (field_schedule_date) */
  $handler->display->display_options['sorts']['field_schedule_date_value']['id'] = 'field_schedule_date_value';
  $handler->display->display_options['sorts']['field_schedule_date_value']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['sorts']['field_schedule_date_value']['field'] = 'field_schedule_date_value';
  $handler->display->display_options['sorts']['field_schedule_date_value']['relationship'] = 'reverse_field_schedule_timeslots_node';
  /* Sort criterion: Timeslot: Time (field_timeslot_time) */
  $handler->display->display_options['sorts']['field_timeslot_time_value']['id'] = 'field_timeslot_time_value';
  $handler->display->display_options['sorts']['field_timeslot_time_value']['table'] = 'field_data_field_timeslot_time';
  $handler->display->display_options['sorts']['field_timeslot_time_value']['field'] = 'field_timeslot_time_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_schedule_timeslots_node';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'schedule',
  );
  $handler->display->display_options['show_title'] = 1;
  $export['cream_schedule_timetable'] = $view;

  return $export;
}
