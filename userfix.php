<?php

// Grab all users.
$users = db_query("SELECT u.uid FROM {users} u WHERE u.uid > 2");

while ($u = db_fetch_object($users)) {
  // Load the user.
  $account = user_load($u->uid);

  // See if they had a picture last year.
  if (!empty($account->picture)) {
    // Do a lo-fi filetype parse.
    $profile_parts = explode('.', $account->picture);
    $filetype = end($profile_parts);

    // Random error check because it just seems like a bad thing if we don't have a filetype :)
    if (!empty($filetype)) {

      // Change pictures value to correct value.
      $account->picture = 'sites/default/files/pictures/picture-' . $account->uid . '.' . $filetype;

      // Save the user.
      user_save($account, (array) $account);
    }
  }
}