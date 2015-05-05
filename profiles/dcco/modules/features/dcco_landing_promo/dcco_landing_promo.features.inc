<?php
/**
 * @file
 * dcco_landing_promo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dcco_landing_promo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dcco_landing_promo_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function dcco_landing_promo_image_default_styles() {
  $styles = array();

  // Exported image style: promo.
  $styles['promo'] = array(
    'name' => 'promo',
    'label' => 'Homepage Promo',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 800,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function dcco_landing_promo_node_info() {
  $items = array(
    'promo' => array(
      'name' => t('Promo'),
      'base' => 'node_content',
      'description' => t('Promo items that rotate on the landing page of the site.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => '',
    ),
  );
  return $items;
}
