<?php
/**
 * @file
 * dcco_landing_promo.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dcco_landing_promo_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'promo';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homepage Promo';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'promo';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'promos__wrapper';
  $handler->display->display_options['style_options']['wrapper_class'] = 'promos';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Field: Link (Excluded, used for rewriting promo image) */
  $handler->display->display_options['fields']['field_promo_link_1']['id'] = 'field_promo_link_1';
  $handler->display->display_options['fields']['field_promo_link_1']['table'] = 'field_data_field_promo_link';
  $handler->display->display_options['fields']['field_promo_link_1']['field'] = 'field_promo_link';
  $handler->display->display_options['fields']['field_promo_link_1']['ui_name'] = 'Link (Excluded, used for rewriting promo image)';
  $handler->display->display_options['fields']['field_promo_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_promo_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_promo_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_promo_link_1']['type'] = 'link_plain';
  /* Field: Excluded (path to promo image) */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['ui_name'] = 'Excluded (path to promo image)';
  $handler->display->display_options['fields']['uri']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="columns">
  <div class="columns__column">
    <h2>[title]</h2>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Promo Subtitle */
  $handler->display->display_options['fields']['field_promo_subtitle']['id'] = 'field_promo_subtitle';
  $handler->display->display_options['fields']['field_promo_subtitle']['table'] = 'field_data_field_promo_subtitle';
  $handler->display->display_options['fields']['field_promo_subtitle']['field'] = 'field_promo_subtitle';
  $handler->display->display_options['fields']['field_promo_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_promo_subtitle']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_promo_subtitle']['alter']['text'] = '[field_promo_subtitle]<hr>';
  $handler->display->display_options['fields']['field_promo_subtitle']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_promo_subtitle']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_promo_subtitle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_subtitle']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_promo_subtitle']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_promo_subtitle']['type'] = 'text_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_class'] = 'promo__body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'promo__body';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Promo Link */
  $handler->display->display_options['fields']['field_promo_link']['id'] = 'field_promo_link';
  $handler->display->display_options['fields']['field_promo_link']['table'] = 'field_data_field_promo_link';
  $handler->display->display_options['fields']['field_promo_link']['field'] = 'field_promo_link';
  $handler->display->display_options['fields']['field_promo_link']['label'] = '';
  $handler->display->display_options['fields']['field_promo_link']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_promo_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_link']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_promo_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_promo_link']['click_sort_column'] = 'url';
  /* Field: Content: Promo Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '  </div>
  <div class="columns__column">
    <figure class="promo__image">
      <a href="[field_promo_link_1]">[field_image]</a>
    </figure>
  </div>
</div>';
  $handler->display->display_options['fields']['field_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'promo',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'promo' => 'promo',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['promo'] = $view;

  return $export;
}
