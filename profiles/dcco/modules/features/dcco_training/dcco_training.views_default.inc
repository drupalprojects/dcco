<?php
/**
 * @file
 * dcco_training.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dcco_training_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'training';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Training';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Accepted Sessions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    1 => '1',
    4 => '4',
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_track' => 'field_track',
    'field_experience_level' => 'field_experience_level',
    'field_speaker' => 'field_speaker',
    'created' => 'created',
    'field_accepted' => 'field_accepted',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_track' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_experience_level' => array(
      'sortable' => 1,
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
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_accepted' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<p>DrupalCamp Colorado\'s training is world class.</p>
';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no sessions for your criteria. Please adjust the filters and submit again.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_track']['id'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['table'] = 'field_data_field_track';
  $handler->display->display_options['fields']['field_track']['field'] = 'field_track';
  /* Field: Content: Experience level */
  $handler->display->display_options['fields']['field_experience_level']['id'] = 'field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['table'] = 'field_data_field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['field'] = 'field_experience_level';
  /* Field: Content: Speaker(s) */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  /* Sort criterion: Content: Track (field_track) */
  $handler->display->display_options['sorts']['field_track_tid']['id'] = 'field_track_tid';
  $handler->display->display_options['sorts']['field_track_tid']['table'] = 'field_data_field_track';
  $handler->display->display_options['sorts']['field_track_tid']['field'] = 'field_track_tid';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'training_session' => 'training_session',
  );
  /* Filter criterion: Content: Track (field_track) */
  $handler->display->display_options['filters']['field_track_tid']['id'] = 'field_track_tid';
  $handler->display->display_options['filters']['field_track_tid']['table'] = 'field_data_field_track';
  $handler->display->display_options['filters']['field_track_tid']['field'] = 'field_track_tid';
  $handler->display->display_options['filters']['field_track_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_track_tid']['expose']['operator_id'] = 'field_track_tid_op';
  $handler->display->display_options['filters']['field_track_tid']['expose']['label'] = 'Filter by Track';
  $handler->display->display_options['filters']['field_track_tid']['expose']['operator'] = 'field_track_tid_op';
  $handler->display->display_options['filters']['field_track_tid']['expose']['identifier'] = 'field_track_tid';
  $handler->display->display_options['filters']['field_track_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    9 => 0,
    5 => 0,
    6 => 0,
    8 => 0,
    4 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_track_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_track_tid']['vocabulary'] = 'track';
  /* Filter criterion: Content: Experience level (field_experience_level) */
  $handler->display->display_options['filters']['field_experience_level_tid']['id'] = 'field_experience_level_tid';
  $handler->display->display_options['filters']['field_experience_level_tid']['table'] = 'field_data_field_experience_level';
  $handler->display->display_options['filters']['field_experience_level_tid']['field'] = 'field_experience_level_tid';
  $handler->display->display_options['filters']['field_experience_level_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_experience_level_tid']['expose']['operator_id'] = 'field_experience_level_tid_op';
  $handler->display->display_options['filters']['field_experience_level_tid']['expose']['label'] = 'Filter By Experience Level';
  $handler->display->display_options['filters']['field_experience_level_tid']['expose']['operator'] = 'field_experience_level_tid_op';
  $handler->display->display_options['filters']['field_experience_level_tid']['expose']['identifier'] = 'field_experience_level_tid';
  $handler->display->display_options['filters']['field_experience_level_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    9 => 0,
    5 => 0,
    6 => 0,
    8 => 0,
    4 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_experience_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_experience_level_tid']['vocabulary'] = 'experience_level';

  /* Display: Training */
  $handler = $view->new_display('page', 'Training', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'DrupalCamp Training';
  $handler->display->display_options['display_description'] = 'These are all training sessions';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_track']['id'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['table'] = 'field_data_field_track';
  $handler->display->display_options['fields']['field_track']['field'] = 'field_track';
  /* Field: Content: Experience level */
  $handler->display->display_options['fields']['field_experience_level']['id'] = 'field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['table'] = 'field_data_field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['field'] = 'field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['label'] = 'Level';
  /* Field: Content: Accepted */
  $handler->display->display_options['fields']['field_accepted']['id'] = 'field_accepted';
  $handler->display->display_options['fields']['field_accepted']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['fields']['field_accepted']['field'] = 'field_accepted';
  $handler->display->display_options['fields']['field_accepted']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['path'] = 'training';
  $export['training'] = $view;

  return $export;
}
