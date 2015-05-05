<?php
/**
 * @file
 * personal_information_profile.features.inc
 */

/**
 * Implements hook_views_api().
 */
function personal_information_profile_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_profile2_type().
 */
function personal_information_profile_default_profile2_type() {
  $items = array();
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "main",
    "label" : "Main profile",
    "weight" : "0",
    "data" : { "registration" : true, "use_page" : true },
    "rdf_mapping" : []
  }');
  $items['personal_information'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "personal_information",
    "label" : "Personal Information",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 },
    "rdf_mapping" : []
  }');
  return $items;
}
