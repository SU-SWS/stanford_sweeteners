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
  $handler->display->display_options['style_plugin'] = 'stanford_sweeteners_isotope_filter';
  $handler->display->display_options['style_options']['render_label'] = 'Category';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Content using Category */
  $handler->display->display_options['relationships']['reverse_field_s_sweet_category_node']['id'] = 'reverse_field_s_sweet_category_node';
  $handler->display->display_options['relationships']['reverse_field_s_sweet_category_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_s_sweet_category_node']['field'] = 'reverse_field_s_sweet_category_node';
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

  /* Display: Category Filter Block */
  $handler = $view->new_display('block', 'Category Filter Block', 'isotope_options');
  $handler->display->display_options['block_description'] = 'Sweetener Isotope Filter';

  /* Display: No JS Menu Block */
  $handler = $view->new_display('block', 'No JS Menu Block', 'no_js_filter_menu');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sweeteners Filter';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'sweetener-isotope-filter no-js-menu';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'sweeteners-nojs/[name]';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Sweetener Isotope Filter';

  /* Display: Audience Filter Block */
  $handler = $view->new_display('block', 'Audience Filter Block', 'audience_filter');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'stanford_sweeteners_isotope_filter';
  $handler->display->display_options['style_options']['render_label'] = 'Audience';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Content using Audience */
  $handler->display->display_options['relationships']['reverse_field_s_sweet_audience_node']['id'] = 'reverse_field_s_sweet_audience_node';
  $handler->display->display_options['relationships']['reverse_field_s_sweet_audience_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_s_sweet_audience_node']['field'] = 'reverse_field_s_sweet_audience_node';
  $handler->display->display_options['relationships']['reverse_field_s_sweet_audience_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'sweetener_audience' => 'sweetener_audience',
  );
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
    t('Category Filter Block'),
    t('Sweetener Isotope Filter'),
    t('No JS Menu Block'),
    t('Sweeteners Filter'),
    t('Audience Filter Block'),
    t('field_s_sweet_audience'),
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
  $handler->display->display_options['title'] = 'Stanford Sweeteners';
  $handler->display->display_options['css_class'] = 'sweetener-isotope-page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'stanford_sweeteners_isotope';
  $handler->display->display_options['style_options']['filter_field'] = array(
    'field_s_sweet_category' => 'field_s_sweet_category',
    'field_s_sweet_audience' => 'field_s_sweet_audience',
    'title' => 0,
    'field_s_sweet_image' => 0,
    'path' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Introduction text';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p class="summary">It\'s pretty "sweet" to be connected with Stanford! Stanford Sweeteners present the "sweetest" perks and rewards of being affiliated with Stanford, from discounts and incentives to facilities access and professional development.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['label'] = 'Isotope Filter';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'sweeteners_isotope_filter:default';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view_1']['id'] = 'view_1';
  $handler->display->display_options['header']['view_1']['table'] = 'views';
  $handler->display->display_options['header']['view_1']['field'] = 'view';
  $handler->display->display_options['header']['view_1']['view_to_insert'] = 'sweeteners_isotope_filter:audience_filter';
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
    'image_style' => 'sweetener_-_card',
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
  $handler->display->display_options['fields']['field_s_sweet_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_sweet_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_sweet_category']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_s_sweet_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_sweet_category']['delta_offset'] = '0';
  /* Field: Field: Audience */
  $handler->display->display_options['fields']['field_s_sweet_audience']['id'] = 'field_s_sweet_audience';
  $handler->display->display_options['fields']['field_s_sweet_audience']['table'] = 'field_data_field_s_sweet_audience';
  $handler->display->display_options['fields']['field_s_sweet_audience']['field'] = 'field_s_sweet_audience';
  $handler->display->display_options['fields']['field_s_sweet_audience']['label'] = '';
  $handler->display->display_options['fields']['field_s_sweet_audience']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_sweet_audience']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_sweet_audience']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_s_sweet_audience']['delta_offset'] = '0';
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
  $handler->display->display_options['path'] = 'benefits-rewards/sweeteners';

  /* Display: No-Js */
  $handler = $view->new_display('page', 'No-Js', 'page_1');
  $handler->display->display_options['display_description'] = 'For users without Javascript';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'sweetener_category' => 'sweetener_category',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['path'] = 'sweeteners-nojs';
  $translatables['sweeteners_isotope_page'] = array(
    t('Master'),
    t('Stanford Sweeteners'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Introduction text'),
    t('<p class="summary">It\'s pretty "sweet" to be connected with Stanford! Stanford Sweeteners present the "sweetest" perks and rewards of being affiliated with Stanford, from discounts and incentives to facilities access and professional development.</p>'),
    t('Isotope Filter'),
    t('Sweetener No Title'),
    t('<span class="sweetener-thumb">[field_s_sweet_image]</span>
<h3>[title]</h3>
'),
    t('Page'),
    t('No-Js'),
    t('For users without Javascript'),
    t('All'),
  );
  $export['sweeteners_isotope_page'] = $view;

  return $export;
}
