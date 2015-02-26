<?php
/**
 * @file
 * stanford_sweeteners_isotope.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_sweeteners_isotope_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sweeteners_isotope_filter';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Sweeteners Isotope Filter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sweeteners Isotope Filter';
  $handler->display->display_options['css_class'] = 'sweetener-isotope-filter';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'stanford_sweeteners_isotope_filter_block';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Content using Category */
  $handler->display->display_options['relationships']['reverse_field_s_sweet_category_node']['id'] = 'reverse_field_s_sweet_category_node';
  $handler->display->display_options['relationships']['reverse_field_s_sweet_category_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_s_sweet_category_node']['field'] = 'reverse_field_s_sweet_category_node';
  $handler->display->display_options['relationships']['reverse_field_s_sweet_category_node']['required'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'sweetener_category' => 'sweetener_category',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'isotope_options');
  $handler->display->display_options['block_description'] = 'Sweetener Isotope Filter';
  $translatables['sweeteners_isotope_filter'] = array(
    t('Master'),
    t('Sweeteners Isotope Filter'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field_s_sweet_category'),
    t('Block'),
    t('Sweetener Isotope Filter'),
  );
  $export['sweeteners_isotope_filter'] = $view;

  $view = new view();
  $view->name = 'sweeteners_isotope_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sweeteners Isotope Page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sweeteners Isotope Page';
  $handler->display->display_options['css_class'] = 'sweetener-isotope-page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'isotope';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['label'] = 'Isotope Filter';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'sweeteners_isotope_filter:default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['empty'] = 'Sweetener No Title';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_sweet_image']['id'] = 'field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['table'] = 'field_data_field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['field'] = 'field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_sweet_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_sweet_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_sweet_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_sweet_image']['settings'] = array(
    'image_style' => 'sm-landscape',
    'image_link' => '',
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="sweetener-thumb">[field_s_sweet_image]</span> 
<h3>[title]</h3>
';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'sweetener-link';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field: Category */
  $handler->display->display_options['fields']['field_s_sweet_category']['id'] = 'field_s_sweet_category';
  $handler->display->display_options['fields']['field_s_sweet_category']['table'] = 'field_data_field_s_sweet_category';
  $handler->display->display_options['fields']['field_s_sweet_category']['field'] = 'field_s_sweet_category';
  $handler->display->display_options['fields']['field_s_sweet_category']['label'] = '';
  $handler->display->display_options['fields']['field_s_sweet_category']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_s_sweet_category']['element_class'] = 'isotope-filter';
  $handler->display->display_options['fields']['field_s_sweet_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_sweet_category']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_sweet_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_sweet_category']['delta_offset'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'stanford_sweetener' => 'stanford_sweetener',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'sweetener_isotope_page');
  $handler->display->display_options['path'] = 'sweeteners';
  $translatables['sweeteners_isotope_page'] = array(
    t('Master'),
    t('Sweeteners Isotope Page'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Isotope Filter'),
    t('Sweetener No Title'),
    t('<span class="sweetener-thumb">[field_s_sweet_image]</span> 
<h3>[title]</h3>
'),
    t('Page'),
  );
  $export['sweeteners_isotope_page'] = $view;

  return $export;
}