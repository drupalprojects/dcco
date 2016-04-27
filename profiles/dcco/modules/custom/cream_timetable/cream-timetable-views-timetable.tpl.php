<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $header_classes: An array of header classes keyed by field id.
 * - $header_attributes: An array of header attributes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <tbody>
    <?php foreach ($schedules as $schedule_day => $schedule_content) : ?>
      <?php if ($show_schedule) : ?>
        <?php /* Header row for the schedule. */ ?>
        <tr class="timetable-schedule">
          <th colspan="<?php print $total_span; ?>" scope="col">
            <?php /* TODO: use element setting from the view field! */ ?>
            <h3><?php print $schedule_content; ?></h3>
          </th>
        </tr>
      <?php endif; ?>
      <?php if ($show_header && !empty($rooms)) : ?>
        <?php /* Header row for the column labels: timeslot and rooms */ ?>
        <tr class="timetable-header">
          <th scope="col" class="timetable-timeslot">
            <?php print $timeslot_header_label; ?>
          </th>
          <?php foreach ($rooms as $room => $room_content) : ?>
            <th scope="col" class="timetable-room">
              <?php print $room_content; ?>
            </th>
          <?php endforeach; /* rooms */ ?>
        </tr>
      <?php endif; ?>
      <?php foreach ($timeslots[$schedule_day] as $timeslot_time => $timeslot_content) : ?>
        <?php /* Row for each timeslot */ ?>
        <tr>
          <th scope="row" class="timetable-timeslot">
            <?php print $timeslot_content; ?>
          </th>
          <?php foreach ($cells[$schedule_day][$timeslot_time] as $room => $room_fields) : ?>
            <td <? if (!empty($cell_full_width[$schedule_day][$timeslot_time][$room])) { print 'colspan="' . $room_span . '"'; } ?>>
              <?php foreach ($cell_fields as $field_name) : ?>
                <?php print $room_fields[$field_name]; ?>
              <?php endforeach; /* cell content */ ?>
            </td>
          <?php endforeach; /* room content */ ?>
        </tr>
      <?php endforeach; /* timeslots */ ?>
    <?php endforeach; /* schedules */ ?>


  </tbody>
</table>

  <?php

  // Multiple headers, one for each schedule.
  // foreach schedule:
    // ROW OF TH: schedule [SPAN!]
    // ROW OF TH: times, room cells
    // foreach rows for this schedule
      // TH: time
      // session cells [POSSIBLE SPAN]


?>




