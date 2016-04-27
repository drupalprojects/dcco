<?php
/**
 * @file
 * dcco_sponsors.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dcco_sponsors_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sponsors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sponsors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Molybdenum';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'Sponsorship term';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'sponsorship_levels' => 'sponsorship_levels',
    'tags' => 0,
  );
  /* Field: Content: Sponsor logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsorship level (field_sponsorship_level) */
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['id'] = 'field_sponsorship_level_tid';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['table'] = 'field_data_field_sponsorship_level';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['field'] = 'field_sponsorship_level_tid';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['vocabulary'] = 'sponsorship_levels';

  /* Display: Page:Sponsors */
  $handler = $view->new_display('page', 'Page:Sponsors', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sponsors';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_sponsorship_level',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Sponsor logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Sponsorship level */
  $handler->display->display_options['fields']['field_sponsorship_level']['id'] = 'field_sponsorship_level';
  $handler->display->display_options['fields']['field_sponsorship_level']['table'] = 'field_data_field_sponsorship_level';
  $handler->display->display_options['fields']['field_sponsorship_level']['field'] = 'field_sponsorship_level';
  $handler->display->display_options['fields']['field_sponsorship_level']['label'] = '';
  $handler->display->display_options['fields']['field_sponsorship_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsorship_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsorship_level']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'sponsor' => 'sponsor',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'sponsors';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Sponsors';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block:Molybdenum */
  $handler = $view->new_display('block', 'Block:Molybdenum', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Molybdenum Sponsors';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsorship level (field_sponsorship_level) */
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['id'] = 'field_sponsorship_level_tid';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['table'] = 'field_data_field_sponsorship_level';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['field'] = 'field_sponsorship_level_tid';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['vocabulary'] = 'sponsorship_levels';

  /* Display: Block:Platnum */
  $handler = $view->new_display('block', 'Block:Platnum', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Platnum Sponsors';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsorship level (field_sponsorship_level) */
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['id'] = 'field_sponsorship_level_tid';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['table'] = 'field_data_field_sponsorship_level';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['field'] = 'field_sponsorship_level_tid';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['vocabulary'] = 'sponsorship_levels';

  /* Display: Block:Gold */
  $handler = $view->new_display('block', 'Block:Gold', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gold Sponsors';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsorship level (field_sponsorship_level) */
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['id'] = 'field_sponsorship_level_tid';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['table'] = 'field_data_field_sponsorship_level';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['field'] = 'field_sponsorship_level_tid';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['vocabulary'] = 'sponsorship_levels';

  /* Display: Block:Silver */
  $handler = $view->new_display('block', 'Block:Silver', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Silver Sponsors';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsorship level (field_sponsorship_level) */
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['id'] = 'field_sponsorship_level_tid';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['table'] = 'field_data_field_sponsorship_level';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['field'] = 'field_sponsorship_level_tid';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['vocabulary'] = 'sponsorship_levels';

  /* Display: Block:Molybdenum - random */
  $handler = $view->new_display('block', 'Block:Molybdenum - random', 'block_5');
  $handler->display->display_options['display_description'] = 'Random single Molybdenum sponsor for use on side blocks.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsorship level (field_sponsorship_level) */
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['id'] = 'field_sponsorship_level_tid';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['table'] = 'field_data_field_sponsorship_level';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['field'] = 'field_sponsorship_level_tid';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sponsorship_level_tid']['vocabulary'] = 'sponsorship_levels';
  $export['sponsors'] = $view;

  return $export;
}
