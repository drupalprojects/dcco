<?php
/**
 * @file
 * dcco_training.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function dcco_training_commerce_product_default_types() {
  $items = array(
    'product_training' => array(
      'type' => 'product_training',
      'name' => 'Training',
      'description' => 'A product type for training classes.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function dcco_training_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dcco_training_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dcco_training_node_info() {
  $items = array(
    'training_session' => array(
      'name' => t('Training Session'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
