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
  $handler->display->display_options['title'] = 'Friday - Drupal Training Day';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    1 => '1',
    4 => '4',
    2 => '2',
    9 => '9',
    5 => '5',
    6 => '6',
    10 => '10',
    7 => '7',
    8 => '8',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
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
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<p>Get ready to join hundreds of <a href="/community">your fellow Drupal enthusiasts</a> from Colorado and beyond. Here are this year\'s training and sessions.</p>
<h3>Friday - Training</h3>
<p>Start your weekend with training. Learn to install and configure Drupal, build your first module, or expand your PHP skills.</p> 
';
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
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_register_for_training_product_id']['id'] = 'field_register_for_training_product_id';
  $handler->display->display_options['relationships']['field_register_for_training_product_id']['table'] = 'field_data_field_register_for_training';
  $handler->display->display_options['relationships']['field_register_for_training_product_id']['field'] = 'field_register_for_training_product_id';
  $handler->display->display_options['relationships']['field_register_for_training_product_id']['relationship'] = 'reverse_field_session_timeslot_node';
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
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Schedule';
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
  $handler->display->display_options['defaults']['header'] = FALSE;
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'schedule';

  /* Display: EVA Field */
  $handler = $view->new_display('entity_view', 'EVA Field', 'entity_view_timetable');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'footable';
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
  $handler->display->display_options['style_options']['footable'] = array(
    'expand' => 'id',
    'hide' => array(
      'id' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_schedule_date' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'title' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'title_1' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'title_2' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_timeslot_time' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'nid' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'type' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Schedule';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_timeslot_time' => 'field_timeslot_time',
    'field_schedule_date' => 'field_schedule_date',
    'title' => 'title',
    'title_1' => 'title_1',
    'title_2' => 'title_2',
    'nid' => 'nid',
    'type' => 'type',
    'field_track' => 'field_track',
    'field_experience_level' => 'field_experience_level',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_timeslot_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_schedule_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 1,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_track' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_experience_level' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Session URL */
  $handler->display->display_options['fields']['field_session_url']['id'] = 'field_session_url';
  $handler->display->display_options['fields']['field_session_url']['table'] = 'field_data_field_session_url';
  $handler->display->display_options['fields']['field_session_url']['field'] = 'field_session_url';
  $handler->display->display_options['fields']['field_session_url']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['field_session_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_session_url']['click_sort_column'] = 'url';
  /* Field: Timeslot: Time */
  $handler->display->display_options['fields']['field_timeslot_time']['id'] = 'field_timeslot_time';
  $handler->display->display_options['fields']['field_timeslot_time']['table'] = 'field_data_field_timeslot_time';
  $handler->display->display_options['fields']['field_timeslot_time']['field'] = 'field_timeslot_time';
  $handler->display->display_options['fields']['field_timeslot_time']['label'] = '';
  $handler->display->display_options['fields']['field_timeslot_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_time']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_timeslot_time']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_timeslot_time']['settings'] = array(
    'display_format' => array(
      'hour' => 'g',
      'minute' => 'i',
      'separator' => ':',
      'period' => 'none',
      'period_separator' => '',
    ),
  );
  /* Field: Content: Schedule date */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['relationship'] = 'reverse_field_schedule_timeslots_node';
  $handler->display->display_options['fields']['field_schedule_date']['label'] = '';
  $handler->display->display_options['fields']['field_schedule_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_schedule_date']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '/training/[title]';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['title_1']['label'] = 'Session';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[title_1]';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = 'training/[title_1]';
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Room: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'eck_room';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_session_room_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = 'Room';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_track']['id'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['table'] = 'field_data_field_track';
  $handler->display->display_options['fields']['field_track']['field'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['field_track']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Experience level */
  $handler->display->display_options['fields']['field_experience_level']['id'] = 'field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['table'] = 'field_data_field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['field'] = 'field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['field_experience_level']['label'] = 'Level';
  $handler->display->display_options['fields']['field_experience_level']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Timeslot: Time (field_timeslot_time) */
  $handler->display->display_options['sorts']['field_timeslot_time_value']['id'] = 'field_timeslot_time_value';
  $handler->display->display_options['sorts']['field_timeslot_time_value']['table'] = 'field_data_field_timeslot_time';
  $handler->display->display_options['sorts']['field_timeslot_time_value']['field'] = 'field_timeslot_time_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'reverse_field_schedule_timeslots_node';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['value'] = 'training';
  $handler->display->display_options['path'] = 'session-schedule';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Saturday';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_timeslot_time' => 'field_timeslot_time',
    'id' => 'id',
    'field_schedule_date' => 'field_schedule_date',
    'title' => 'title',
    'title_1' => 'title_1',
    'title_2' => 'title_2',
    'nid' => 'nid',
    'type' => 'type',
    'field_track' => 'field_track',
    'field_experience_level' => 'field_experience_level',
    'field_speaker' => 'field_speaker',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_timeslot_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
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
    'field_track' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_experience_level' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_speaker' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['footable'] = array(
    'expand' => 'field_timeslot_time',
    'hide' => array(
      'field_timeslot_time' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'id' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_schedule_date' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'title' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'title_1' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'title_2' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'nid' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'type' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_track' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'field_experience_level' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'field_speaker' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '&nbsp;
<h3>Saturday</h3>
<p>DrupalCamp Colorado Day two begins with sessions on everything Drupal.</p> ';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Timeslot: Time */
  $handler->display->display_options['fields']['field_timeslot_time']['id'] = 'field_timeslot_time';
  $handler->display->display_options['fields']['field_timeslot_time']['table'] = 'field_data_field_timeslot_time';
  $handler->display->display_options['fields']['field_timeslot_time']['field'] = 'field_timeslot_time';
  $handler->display->display_options['fields']['field_timeslot_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_time']['settings'] = array(
    'display_format' => array(
      'hour' => 'g',
      'minute' => 'i',
      'separator' => ':',
      'period' => 'none',
      'period_separator' => '',
    ),
  );
  /* Field: Timeslot: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_timeslot';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Content: Schedule date */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['relationship'] = 'reverse_field_schedule_timeslots_node';
  $handler->display->display_options['fields']['field_schedule_date']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['title_1']['label'] = 'Session';
  /* Field: Room: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'eck_room';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_session_room_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = 'Room';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_track']['id'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['table'] = 'field_data_field_track';
  $handler->display->display_options['fields']['field_track']['field'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['field_track']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_track']['alter']['text'] = '<span class="badge">[field_track]</span>';
  /* Field: Content: Experience level */
  $handler->display->display_options['fields']['field_experience_level']['id'] = 'field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['table'] = 'field_data_field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['field'] = 'field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['field_experience_level']['label'] = 'Level';
  $handler->display->display_options['fields']['field_experience_level']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_experience_level']['alter']['text'] = '<span class="badge">[field_experience_level]</span>';
  /* Field: Content: Speaker(s) */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['field_speaker']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'reverse_field_schedule_timeslots_node';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['value'] = 'Day 1';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'page' => 0,
    'entity_view_timetable' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_arguments'] = FALSE;

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sunday';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_timeslot_time' => 'field_timeslot_time',
    'id' => 'id',
    'field_schedule_date' => 'field_schedule_date',
    'title' => 'title',
    'title_1' => 'title_1',
    'title_2' => 'title_2',
    'nid' => 'nid',
    'type' => 'type',
    'field_track' => 'field_track',
    'field_experience_level' => 'field_experience_level',
    'field_speaker' => 'field_speaker',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_timeslot_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
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
    'field_track' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_experience_level' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_speaker' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['footable'] = array(
    'expand' => 'field_timeslot_time',
    'hide' => array(
      'field_timeslot_time' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'id' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_schedule_date' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'title' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'title_1' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'title_2' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'nid' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'type' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'field_track' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'field_experience_level' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
      'field_speaker' => array(
        'phone' => 'phone',
        'tablet' => 0,
      ),
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '&nbsp;
<h3>Sunday</h3>
<p>DrupalCamp Colorado Day three continues with more sessions.</p> ';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Timeslot: Time */
  $handler->display->display_options['fields']['field_timeslot_time']['id'] = 'field_timeslot_time';
  $handler->display->display_options['fields']['field_timeslot_time']['table'] = 'field_data_field_timeslot_time';
  $handler->display->display_options['fields']['field_timeslot_time']['field'] = 'field_timeslot_time';
  $handler->display->display_options['fields']['field_timeslot_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_time']['settings'] = array(
    'display_format' => array(
      'hour' => 'g',
      'minute' => 'i',
      'separator' => ':',
      'period' => 'none',
      'period_separator' => '',
    ),
  );
  /* Field: Timeslot: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_timeslot';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Content: Schedule date */
  $handler->display->display_options['fields']['field_schedule_date']['id'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['table'] = 'field_data_field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['field'] = 'field_schedule_date';
  $handler->display->display_options['fields']['field_schedule_date']['relationship'] = 'reverse_field_schedule_timeslots_node';
  $handler->display->display_options['fields']['field_schedule_date']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['title_1']['label'] = 'Session';
  /* Field: Room: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'eck_room';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_session_room_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = 'Room';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_track']['id'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['table'] = 'field_data_field_track';
  $handler->display->display_options['fields']['field_track']['field'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['field_track']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_track']['alter']['text'] = '<span class="badge">[field_track]</span>';
  /* Field: Content: Experience level */
  $handler->display->display_options['fields']['field_experience_level']['id'] = 'field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['table'] = 'field_data_field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['field'] = 'field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['field_experience_level']['label'] = 'Level';
  $handler->display->display_options['fields']['field_experience_level']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_experience_level']['alter']['text'] = '<span class="badge">[field_experience_level]</span>';
  /* Field: Content: Speaker(s) */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['relationship'] = 'reverse_field_session_timeslot_node';
  $handler->display->display_options['fields']['field_speaker']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'reverse_field_schedule_timeslots_node';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['value'] = 'Day 2';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'page' => 0,
    'entity_view_timetable' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['cream_schedule_timetable'] = $view;

  return $export;
}
