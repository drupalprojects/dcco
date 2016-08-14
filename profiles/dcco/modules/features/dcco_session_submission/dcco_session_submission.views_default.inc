<?php
/**
 * @file
 * dcco_session_submission.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dcco_session_submission_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sessions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sessions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Accepted Sessions';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    1 => '1',
    2 => '2',
    9 => '9',
  );
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'footable';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_track' => 'field_track',
    'field_experience_level' => 'field_experience_level',
    'field_speaker' => 'field_speaker',
    'field_accepted' => 'field_accepted',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
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
    'field_accepted' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['footable'] = array(
    'expand' => 'title',
    'hide' => array(
      'title' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
      'body' => array(
        'phone' => 'phone',
        'tablet' => 'tablet',
      ),
      'field_track' => array(
        'phone' => 0,
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
      'field_accepted' => array(
        'phone' => 0,
        'tablet' => 0,
      ),
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<p>DrupalCamp Colorado\'s theme this year is <strong>Large Scale Drupal</strong>. We encourage sessions that explore all facets of planning, building, deploying, running, and monitoring. This, of course, does not preclude any other sessions. We want a wide variety of proposals!</p>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no sessions for your criteria. Please adjust the filters and submit again.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_speaker_target_id']['id'] = 'field_speaker_target_id';
  $handler->display->display_options['relationships']['field_speaker_target_id']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['relationships']['field_speaker_target_id']['field'] = 'field_speaker_target_id';
  $handler->display->display_options['relationships']['field_speaker_target_id']['label'] = 'User ref';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'field_speaker_target_id';
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
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '500';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
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
  $handler->display->display_options['fields']['field_speaker']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_speaker']['alter']['text'] = '[field_speaker]';
  $handler->display->display_options['fields']['field_speaker']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_speaker']['alter']['path'] = '/community/[field_speaker]';
  $handler->display->display_options['fields']['field_speaker']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_session_room']['id'] = 'field_session_room';
  $handler->display->display_options['fields']['field_session_room']['table'] = 'field_data_field_session_room';
  $handler->display->display_options['fields']['field_session_room']['field'] = 'field_session_room';
  $handler->display->display_options['fields']['field_session_room']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_session_timeslot']['id'] = 'field_session_timeslot';
  $handler->display->display_options['fields']['field_session_timeslot']['table'] = 'field_data_field_session_timeslot';
  $handler->display->display_options['fields']['field_session_timeslot']['field'] = 'field_session_timeslot';
  $handler->display->display_options['fields']['field_session_timeslot']['type'] = 'schedule_link';
  $handler->display->display_options['fields']['field_session_timeslot']['settings'] = array(
    'link' => 0,
  );
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
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
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Page:Session submitted */
  $handler = $view->new_display('page', 'Page:Session submitted', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Submitted Sessions';
  $handler->display->display_options['display_description'] = 'These are all submitted sessions.';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h3>Here is the list of proposed sessions.</h3>
<p>Check back occasionally to see what you can look forward to at the camp.</p>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_profile2';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['relationship'] = 'profile';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
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
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '500';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_track']['id'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['table'] = 'field_data_field_track';
  $handler->display->display_options['fields']['field_track']['field'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['alter']['text'] = '<span>[field_track]</span>&nbsp;';
  $handler->display->display_options['fields']['field_track']['element_default_classes'] = FALSE;
  /* Field: Content: Experience level */
  $handler->display->display_options['fields']['field_experience_level']['id'] = 'field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['table'] = 'field_data_field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['field'] = 'field_experience_level';
  $handler->display->display_options['fields']['field_experience_level']['label'] = 'Level';
  $handler->display->display_options['fields']['field_experience_level']['alter']['text'] = '<span>[field_experience_level]</span>&nbsp;';
  /* Field: Content: Speaker(s) */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_speaker']['alter']['text'] = '<span>[field_speaker]</span>';
  $handler->display->display_options['fields']['field_speaker']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_speaker']['alter']['path'] = '/community/[field_speaker]';
  $handler->display->display_options['fields']['field_speaker']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_speaker']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  /* Field: Content: Accepted */
  $handler->display->display_options['fields']['field_accepted']['id'] = 'field_accepted';
  $handler->display->display_options['fields']['field_accepted']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['fields']['field_accepted']['field'] = 'field_accepted';
  $handler->display->display_options['fields']['field_accepted']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['path'] = 'sessions/submitted';

  /* Display: Page:Session accepted */
  $handler = $view->new_display('page', 'Page:Session accepted', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Accepted Sessions';
  $handler->display->display_options['display_description'] = 'These are only the accepted sessions.';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Accepted (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Track (field_track) */
  $handler->display->display_options['filters']['field_track_tid']['id'] = 'field_track_tid';
  $handler->display->display_options['filters']['field_track_tid']['table'] = 'field_data_field_track';
  $handler->display->display_options['filters']['field_track_tid']['field'] = 'field_track_tid';
  $handler->display->display_options['filters']['field_track_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_track_tid']['expose']['operator_id'] = 'field_track_tid_op';
  $handler->display->display_options['filters']['field_track_tid']['expose']['label'] = 'Track';
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
  $handler->display->display_options['filters']['field_experience_level_tid']['expose']['label'] = 'Experience level';
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
  $handler->display->display_options['path'] = 'sessions';
  $export['sessions'] = $view;

  return $export;
}
