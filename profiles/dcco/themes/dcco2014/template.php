<?php
/**
 * @file
 * Template stuff.
 */

include 'inc/block.inc';
include 'inc/field.inc';
include 'inc/form.inc';
include 'inc/menu.inc';
include 'inc/node.inc';


function dcco2014_preprocess_html(&$variables) {
  // return;
  $theme_path = drupal_get_path('theme', 'dcco2014');
  drupal_add_css($theme_path . '/js/responsive-nav/responsive-nav.css');
  drupal_add_js($theme_path . '/js/responsive-nav/responsive-nav.min.js');
  // drupal_add_js($theme_path . '/js/menu.js', array('scope' => 'footer', 'weight' => 5));
  drupal_add_js($theme_path . '/js/menu.js');
}
