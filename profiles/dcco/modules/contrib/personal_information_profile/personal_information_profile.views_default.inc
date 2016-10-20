<?php
/**
 * @file
 * personal_information_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function personal_information_profile_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_personal_information';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User Personal Information';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'community_users';
  $handler->display->display_options['style_options']['wrapper_class'] = 'community_wrapper';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'personal_information' => 'personal_information',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user-personal-information/%';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Profile: Twitter */
  $handler->display->display_options['fields']['field_twitter']['id'] = 'field_twitter';
  $handler->display->display_options['fields']['field_twitter']['table'] = 'field_data_field_twitter';
  $handler->display->display_options['fields']['field_twitter']['field'] = 'field_twitter';
  $handler->display->display_options['fields']['field_twitter']['relationship'] = 'profile';
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Profile: Profile image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['relationship'] = 'profile';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextual filter: User: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'users';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['transform_dash'] = TRUE;
  /* Contextual filter: Profile: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'profile';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['relationship'] = 'profile';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'single-user';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h1 class="page-title">Say hello to user [name]</h1>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user-personal-information/%';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Profile: Profile image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['element_class'] = 'float--right';
  $handler->display->display_options['fields']['field_profile_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_profile_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'image_style' => 'user_photo',
    'image_link' => 'content',
  );
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['text'] = '<h3>[field_first_name] [field_last_name]</h3>';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Field: Bio */
  $handler->display->display_options['fields']['field_bio']['id'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['table'] = 'field_data_field_bio';
  $handler->display->display_options['fields']['field_bio']['field'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_bio']['label'] = '';
  $handler->display->display_options['fields']['field_bio']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_bio']['element_class'] = 'bio';
  $handler->display->display_options['fields']['field_bio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_bio']['element_default_classes'] = FALSE;
  /* Field: Profile: Job Title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_job_title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_job_title']['element_class'] = 'field';
  $handler->display->display_options['fields']['field_job_title']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_job_title']['element_label_class'] = 'label';
  $handler->display->display_options['fields']['field_job_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_job_title']['element_wrapper_class'] = 'cf';
  $handler->display->display_options['fields']['field_job_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_job_title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_job_title']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Profile: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_organization']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_organization']['element_class'] = 'field';
  $handler->display->display_options['fields']['field_organization']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_organization']['element_label_class'] = 'label';
  $handler->display->display_options['fields']['field_organization']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_organization']['element_wrapper_class'] = 'cf';
  $handler->display->display_options['fields']['field_organization']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_organization']['hide_empty'] = TRUE;
  /* Field: Profile: IRC Nickname */
  $handler->display->display_options['fields']['field_irc_nickname']['id'] = 'field_irc_nickname';
  $handler->display->display_options['fields']['field_irc_nickname']['table'] = 'field_data_field_irc_nickname';
  $handler->display->display_options['fields']['field_irc_nickname']['field'] = 'field_irc_nickname';
  $handler->display->display_options['fields']['field_irc_nickname']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_irc_nickname']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_irc_nickname']['element_class'] = 'field';
  $handler->display->display_options['fields']['field_irc_nickname']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_irc_nickname']['element_label_class'] = 'label';
  $handler->display->display_options['fields']['field_irc_nickname']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_irc_nickname']['element_wrapper_class'] = 'cf';
  $handler->display->display_options['fields']['field_irc_nickname']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_irc_nickname']['hide_empty'] = TRUE;
  /* Field: Profile: Twitter */
  $handler->display->display_options['fields']['field_twitter_1']['id'] = 'field_twitter_1';
  $handler->display->display_options['fields']['field_twitter_1']['table'] = 'field_data_field_twitter';
  $handler->display->display_options['fields']['field_twitter_1']['field'] = 'field_twitter';
  $handler->display->display_options['fields']['field_twitter_1']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_twitter_1']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_twitter_1']['element_class'] = 'field';
  $handler->display->display_options['fields']['field_twitter_1']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_twitter_1']['element_label_class'] = 'label';
  $handler->display->display_options['fields']['field_twitter_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_twitter_1']['element_wrapper_class'] = 'cf';
  $handler->display->display_options['fields']['field_twitter_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_twitter_1']['hide_empty'] = TRUE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = 'Edit your profile';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['path'] = 'profile-personal_information/1193/edit?destination=community';
  $handler->display->display_options['fields']['edit_node']['alter']['link_class'] = 'button--primary';
  $handler->display->display_options['fields']['edit_node']['element_type'] = '0';
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'button--primary';
  $handler->display->display_options['fields']['edit_node']['element_label_type'] = '0';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit your profile';
  $handler->display->display_options['path'] = 'community/%';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Camp Attendees';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="all-user-profiles">See All Attendees</a>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user-personal-information/%';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Profile: Profile image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_profile_image']['alter']['path'] = 'user-personal-information/[name]';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'image_style' => 'user_photo',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Community';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'all-users';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>The DrupalCamp Colorado community is made up of awesome developers, designers, site builders, and other technologists who you\'ll have an opportunity to share knowledge with this summer in Denver.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user-personal-information/%';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h3';
  $handler->display->display_options['fields']['name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Profile: Profile image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_profile_image']['alter']['path'] = 'community/[name]';
  $handler->display->display_options['fields']['field_profile_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_profile_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'image_style' => 'user_photo',
    'image_link' => '',
  );
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Profile: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['text'] = '<h3>[field_first_name] [field_last_name]</h3>';
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['path'] = 'community/[name]';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'community';
  $export['user_personal_information'] = $view;

  return $export;
}
