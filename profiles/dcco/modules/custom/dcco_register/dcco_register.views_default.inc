<?php

/**
 * Implements hook_views_default_views().
 */
function dcco_register_views_default_views() {

  $views = array();

 $view = new view();
  $view->name = 'dcco_register_total_contributions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_line_item';
  $view->human_name = 'Total Registration Contributions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Total Registration Contributions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>For DrupalCamp Colorado 2014, you can set your own registration price. <strong>How much is this camp worth to you?</strong></p>

      <p>Any registration contributions beyond our budget target will be donated to 3 charities: <a href="http://adainitiative.org/">The Ada Initiative</a>, <a href="http://code.org/">Code.org</a>, and <a href="https://www.eff.org/">Electronic Frontier Foundation</a>. Thank you for generously supporting the Camp and these organizations.</p>

      <p>We have so far raised <span class="dcco-register-current">[commerce_unit_price]</span> of our <span class="dcco-register-total">$4,000.00</span> goal.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Commerce Line Item: Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['required'] = TRUE;
  /* Field: SUM(Commerce Line item: Unit price) */
  $handler->display->display_options['fields']['commerce_unit_price']['id'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['table'] = 'field_data_commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['field'] = 'commerce_unit_price';
  $handler->display->display_options['fields']['commerce_unit_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['commerce_unit_price']['label'] = '';
  $handler->display->display_options['fields']['commerce_unit_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_unit_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_unit_price']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['commerce_unit_price']['group_column'] = 'amount';
  /* Filter criterion: Commerce Line Item: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Filter criterion: Commerce Line item: Product (commerce_product) */
  $handler->display->display_options['filters']['commerce_product_product_id']['id'] = 'commerce_product_product_id';
  $handler->display->display_options['filters']['commerce_product_product_id']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['filters']['commerce_product_product_id']['field'] = 'commerce_product_product_id';
  $handler->display->display_options['filters']['commerce_product_product_id']['value']['value'] = '1';
  /* Filter criterion: Commerce Order: Order state */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'order_id';
  $handler->display->display_options['filters']['state']['value'] = array(
    'pending' => 'pending',
    'completed' => 'completed',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  $views[$view->name] = $view;
  return $views;

}
