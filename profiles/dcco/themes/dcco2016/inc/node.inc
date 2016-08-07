<?php

/**
 * Implements hook_preprocess_node()
 */
function dcco2016_preprocess_node(&$vars) {

  // Set shortcut variables. Hooray for less typing!
  $type = $vars['type'];
  $mode = $vars['view_mode'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];

  $speaker_field = $vars['field_speaker'];

  $index = 0;
  foreach ($speaker_field as $speaker) {
    $profile = profile2_load_by_user($speaker['target_id']);
    $profile_image = $profile['personal_information']->field_profile_image;
    $image_vars = array(
      'style_name' => 'user_photo',
      'path' => $profile_image['und'][0]['uri'],
    );
    $image = !empty($profile_image) ? theme_image_style($image_vars) : null;
    $vars['speakers'][$index]['uid'] = $speaker['target_id'];
    $vars['speakers'][$index]['speaker_image'] = $image;
    $vars['speakers'][$index]['speaker_first_name'] = $profile['personal_information']->field_first_name;
    $vars['speakers'][$index]['speaker_last_name'] = $profile['personal_information']->field_last_name;
    $index++;
  }

  $vars['content']['speakers'] = $vars['speakers'];

  // Uncomment the lines below to see variables you can use to target a field.
  // This requires http://drupal.org/project/devel to be installed.
  // dpm($type, 'Type:');
  // dpm($mode, 'Mode:');

  // Example: Adding a classes base on view mode.
  // switch ($mode) {
  //   case 'photo_teaser':
  //     $classes[] = 'bg-white gutters-half l-space-trailing';
  //     break;
  // }
}
