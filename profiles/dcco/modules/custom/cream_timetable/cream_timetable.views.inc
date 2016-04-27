<?php

/**
 * @file cream_timetable.views.inc
 * Provides a Views display plugin for the Cream camp timetable.
 *
 * WARNING: this is a first draft, and as such as field names and settings
 * hardcoded. More work is required to move these into the plugin's settings UI.
 * If you need to change a particular value, please consider making a patch for
 * that rather than hacking the value directly, so that others can benefit from
 * the improvement.
 */

/**
 * Implements hook_views_plugins().
 */
function cream_timetable_views_plugins() {
  return array(
    'module' => 'cream_timetable',
    'style' => array(
      'cream_timetable' => array(
        'title' => t('Timetable'),
        'help' => t('Displays rows as a TODO.'),
        'handler' => 'cream_timetable_plugin_style_timetable',
        'path' => drupal_get_path('module', 'cream_timetable'),
        'theme' => 'cream_timetable_views_timetable',
        'theme file' => 'cream_timetable.views.inc',
        'theme path' => drupal_get_path('module', 'cream_timetable'),
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'uses fields' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}

/**
 * Callback to prepare row data for later rendering.
 *
 * @param $vars
 */
function template_preprocess_cream_timetable_views_timetable(&$vars) {
  $view     = $vars['view'];

  //dsm($view);
  /*
  foreach ($view->field as $field_name => $field_handler) {
    dsm($field_name . ': '
      . 'renders: ' . $field_handler->options['id'] . ' '
      . 'results: ' . $field_handler->field_alias
    );
    //dsm($field_handler);
    // This is the key of the renders array.
    //dsm($field_handler->options['id']);
    // This is the key of the results arary.
    //dsm($field_handler->field_alias);
  }
  */

  // We need the raw data for this grouping, which is passed in as $vars['rows'].
  // However, the template also needs to use for the rendered fields.  We
  // therefore swap the raw data out to a new variable and reset $vars['rows']
  // so that it can get rebuilt.
  // Store rows so that they may be used by further preprocess functions.
  $result   = $vars['result'] = $vars['rows'];
  $vars['rows'] = array();
  $vars['field_classes'] = array();
  $vars['header'] = array();

  $options  = $view->style_plugin->options;
  $handler  = $view->style_plugin;

  // Options that affect what we output.
  $vars['show_schedule'] = $handler->options['show_schedule'];
  $vars['show_header'] = $handler->options['show_header'];

  // Fields must be rendered in order as of Views 2.3, so we will pre-render
  // everything.
  // Rerender everything -- WTF! but Views does this too!
  $renders = $handler->render_fields($result);

  // This gets us an array keyed by row index, of all the fields.
  //dsm($view->result, 'result');
  //dsm($renders, 'renders');

  // TODO: get these from the view field handlers!
  $schedule_day_field = '';
  $schedule_day_field_result_key  = 'field_schedule_timeslots_eck_timeslot_title';
  $timeslot_time_field_result_key = 'field_data_field_timeslot_time_field_timeslot_time_value';
  $room_field_result_key          = 'eck_room_field_data_field_session_room_title';
  $field_lookup = array(
    'schedule' => array(
      'result_key' => 'field_schedule_timeslots_eck_timeslot_title',
      'render_key' => 'title',
    ),
    'timeslot' => array(
      'result_key' => 'field_data_field_timeslot_time_field_timeslot_time_value',
      'render_key' => 'field_timeslot_time',
    ),
    'room' => array(
      'result_key' => 'eck_room_field_data_field_session_room_title',
      'render_key' => 'title_2',
    ),
    'session_type' => array(
      'result_key' => 'field_session_timeslot_eck_timeslot_type',
    ),
  );
  // TODO: get from plugin settings
  // List of keys of rendered arrays that are for inclusion in the content cells.
  $vars['cell_fields'] = array('title_1');

  $timetable_grouped_results = array();

  $current_schedule_nid = NULL;
  $current_timeslot_time = NULL;

  $vars['schedules'] = array();
  $vars['timeslots'] = array();
  $vars['rooms'] = array();
  $vars['cells'] = array();

  $results_grouped = array();
  foreach ($view->result as $index => $result_row) {
    // Get grouping values from the result row.
    $schedule_day   = $result_row->{$field_lookup['schedule']['result_key']};
    $timeslot_time  = $result_row->{$field_lookup['timeslot']['result_key']};
    $room           = $result_row->{$field_lookup['room']['result_key']};

    // Set the index in the result row. We need this so that when we get a
    // result row in our new nested array, we can find the corresponding item in
    // the renders array.
    $result_row->__index = $index;

    // Build up our nested array.
    // Note that if the room is empty for a session, this gets keyed at NULL,
    // but that's okay as there should be only one session without a room for
    // any one timeslot.
    $results_grouped[$schedule_day][$timeslot_time][$room] = $result_row;

    // Compile an array of all the rendered schedule field values. This clobbers
    // the value each time but that doesn't matter as it's the same value.
    $vars['schedules'][$schedule_day] = $renders[$index][$field_lookup['schedule']['render_key']];

    // Same thing for timeslots, grouped by schedule.
    $vars['timeslots'][$schedule_day][$timeslot_time] = $renders[$index][$field_lookup['timeslot']['render_key']];

    // Same thing for rooms.
    if (!empty($room)) {
      $vars['rooms'][$room] = $renders[$index][$field_lookup['room']['render_key']];
    }

    // Finally, group the content cells.
    $vars['cells'][$schedule_day][$timeslot_time][$room] = $renders[$index];
    
    // TODO: do this properly using field attributes.
    if (in_array($result_row->{$field_lookup['session_type']['result_key']}, array(
        'keynote',
        'scheduled_item',
      ))) {
      $vars['cell_full_width'][$schedule_day][$timeslot_time][$room] = TRUE;
    }
  }
  
  /*
  // Add field classes
  $vars['field_classes'][$field][$num] = '';
  if ($fields[$field]->options['element_default_classes']) {
    $vars['field_classes'][$field][$num] = "views-field views-field-" . $vars['fields'][$field];
  }
  if ($classes = $fields[$field]->element_classes($num)) {
    if ($vars['field_classes'][$field][$num]) {
      $vars['field_classes'][$field][$num] .= ' ';
    }

    $vars['field_classes'][$field][$num] .= $classes;
  }
  $vars['field_attributes'][$field][$num] = array();
  */
  
  //dsm($vars['rooms'], '$rooms');
  
  // TODO: fill in empty cells!
  foreach (array_keys($results_grouped) as $schedule_day) {
    foreach (array_keys($results_grouped[$schedule_day]) as $timeslot_time) {
      foreach (array_keys($vars['rooms']) as $room) {
        if (!isset($vars['cells'][$schedule_day][$timeslot_time][$room])) {
          //$vars['cells'][$schedule_day][$timeslot_time][$room] = '';
        }
      }
    }
  }
  

  // TODO: pick up the field label for the timeslot field here.
  $vars['timeslot_header_label'] = t('Timeslot');

  // Span counts for cells.
  $vars['room_span'] = count($vars['rooms']);
  $vars['total_span'] = $vars['room_span'] + 1;

  // WARNING: will have gaps!!!
  //dsm($vars['cells'], 'cells');
  //dsm($results_grouped);


  $table_rows = array();
  foreach (array_keys($results_grouped) as $schedule_day) {
    // Make a header row for each new schedule.
    $row = array();

    // We need a rendered field, but we're not yet on a particular result row.
    // Any result row that's coming up in this part of the grouped array will
    // do, since they're all for this timeslot. So get the first one, but
    // don't remove it from the array as we're about to iterate over it.
    // TODO: notice!
    // TODO: stash these first renders in the grouped array when we make it!
    $reset = reset($results_grouped[$schedule_day]);
    $first_result_row = reset($reset);
    $row[] = $renders[$first_result_row->__index][$field_lookup['schedule']['render_key']];
    // TODO: colspan.

    $table_rows[] = $row;

    // Now one row for for each timeslot.
    foreach (array_keys($results_grouped[$schedule_day]) as $timeslot_time) {
      // Header row.
      $header_row = array();
      // TODO!

      // New row for this timeslot.
      $row = array();

      // Make an initial cell for the timeslot.
      // We need a rendered field, but we're not yet on a particular result row.
      // Any result row that's coming up in this part of the grouped array will
      // do, since they're all for this timeslot. So get the first one, but
      // don't remove it from the array as we're about to iterate over it.
      $first_result_row = reset($results_grouped[$schedule_day][$timeslot_time]);

      $row[] = $renders[$first_result_row->__index][$field_lookup['timeslot']['render_key']];

      foreach (array_keys($results_grouped[$schedule_day][$timeslot_time]) as $room) {
        $result_row = $results_grouped[$schedule_day][$timeslot_time][$room];
        //dsm($result_row);
        // Render the session name.
        $row[] = $renders[$result_row->__index]['title_1'];
      }

      $table_rows[] = $row;

    }

  }

  $vars['rows'] = $table_rows;
}
