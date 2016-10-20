<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
?>
<div class="profile"<?php print $attributes; ?>>
  <?php
  $personal_profile = $user_profile['profile_personal_information']['view']['profile2'];
  foreach ($personal_profile as $profile) {
    print render($profile['field_profile_image']);
    print '<ul>';
      print '<li><label>Name</label>' . render($profile['field_first_name']) . ' ' . render($profile['field_last_name']) . '</li>';
      if (!empty($profile['field_organization'])) { print '<li><label>Organization</label>' . render($profile['field_organization']) . '</li>'; }
      if (!empty($profile['field_job_title'])) { print '<li><label>Job title</label>' . render($profile['field_job_title']) . '</li>'; }
      if (!empty($profile['field_bio'])) { print '<li><label>Bio</label><div class="bio">' . render($profile['field_bio']) . '</div></li>'; }
      if (!empty($profile['field_how_long_drupal'])) { print '<li><label>Drupal experience</label>' . render($profile['field_how_long_drupal']) . '</li>'; }
      if (!empty($profile['field_twitter'])) { print '<li><label>Twitter</label><a href="'. render($profile['field_twitter']) . '">' . render($profile['field_twitter']) . '</a></li>'; }
      if (!empty($profile['field_irc_nickname'])) { print '<li><label>IRC</label><a href="https://drupal.org/u/' . render($profile['field_irc_nickname']) . '">' . render($profile['field_irc_nickname']) . '</a></li>'; }
    print '</ul>';
  }
  ?>
</div>
