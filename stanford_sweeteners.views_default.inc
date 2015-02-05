<?php
/**
 * @file
 * stanford_sweeteners.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_sweeteners_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sweeteners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sweeteners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sweeteners Carousel';
  $handler->display->display_options['css_class'] = 'sweetener-carousel slick-carousel';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_sweet_image']['id'] = 'field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['table'] = 'field_data_field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['field'] = 'field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_sweet_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_sweet_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_sweet_image']['settings'] = array(
    'image_style' => 'caw-sm-landscape',
    'image_link' => 'content',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_s_sweet_image]
[title]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
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
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'sweeteners';

  /* Display: Manual Selection Block */
  $handler = $view->new_display('block', 'Manual Selection Block', 'sweetener_carousel');
  $handler->display->display_options['display_description'] = 'Manual Selection Block With Entity References';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_sweet_image']['id'] = 'field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['table'] = 'field_data_field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['field'] = 'field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_sweet_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_sweet_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_sweet_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_sweet_image']['settings'] = array(
    'image_style' => 'caw-sm-landscape',
    'image_link' => 'content',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="sweetener-image">[field_s_sweet_image]</div>
<h3>[title]</h3>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Sweeteners Carousel';

  /* Display: Category Selection Block */
  $handler = $view->new_display('block', 'Category Selection Block', 'sweetener_carousel_category');
  $handler->display->display_options['display_description'] = 'Category Selection Block';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_sweet_image']['id'] = 'field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['table'] = 'field_data_field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['field'] = 'field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_sweet_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_sweet_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_sweet_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_sweet_image']['settings'] = array(
    'image_style' => 'caw-sm-landscape',
    'image_link' => 'content',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="sweetener-image">[field_s_sweet_image]</div>
<h3>[title]</h3>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Category (field_s_sweet_category) */
  $handler->display->display_options['arguments']['field_s_sweet_category_tid']['id'] = 'field_s_sweet_category_tid';
  $handler->display->display_options['arguments']['field_s_sweet_category_tid']['table'] = 'field_data_field_s_sweet_category';
  $handler->display->display_options['arguments']['field_s_sweet_category_tid']['field'] = 'field_s_sweet_category_tid';
  $handler->display->display_options['arguments']['field_s_sweet_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_s_sweet_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_s_sweet_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_s_sweet_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_s_sweet_category_tid']['break_phrase'] = TRUE;
  $handler->display->display_options['block_description'] = 'Sweeteners Carousel By Type';

  /* Display: Subsite Selection Block */
  $handler = $view->new_display('block', 'Subsite Selection Block', 'sweetener_carousel_subsite');
  $handler->display->display_options['display_description'] = 'Subsite Selection Block';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_sweet_image']['id'] = 'field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['table'] = 'field_data_field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['field'] = 'field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_sweet_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_sweet_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_sweet_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_sweet_image']['settings'] = array(
    'image_style' => 'caw-sm-landscape',
    'image_link' => 'content',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="sweetener-image">[field_s_sweet_image]</div>
<h3>[title]</h3>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Subsite Tags (field_stanford_subsite_sub_tags) */
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['id'] = 'field_stanford_subsite_sub_tags_tid';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['table'] = 'field_data_field_stanford_subsite_sub_tags';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['field'] = 'field_stanford_subsite_sub_tags_tid';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_stanford_subsite_sub_tags_tid']['break_phrase'] = TRUE;
  $handler->display->display_options['block_description'] = 'Sweeteners Carousel';

  /* Display: Audience Selection Block */
  $handler = $view->new_display('block', 'Audience Selection Block', 'sweetener_carousel_audience');
  $handler->display->display_options['display_description'] = 'Audience Selection Block';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_s_sweet_image']['id'] = 'field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['table'] = 'field_data_field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['field'] = 'field_s_sweet_image';
  $handler->display->display_options['fields']['field_s_sweet_image']['label'] = '';
  $handler->display->display_options['fields']['field_s_sweet_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_s_sweet_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_s_sweet_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_s_sweet_image']['settings'] = array(
    'image_style' => 'caw-sm-landscape',
    'image_link' => 'content',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="sweetener-image">[field_s_sweet_image]</div>
<h3>[title]</h3>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Audience (field_s_sweet_audience) */
  $handler->display->display_options['arguments']['field_s_sweet_audience_tid']['id'] = 'field_s_sweet_audience_tid';
  $handler->display->display_options['arguments']['field_s_sweet_audience_tid']['table'] = 'field_data_field_s_sweet_audience';
  $handler->display->display_options['arguments']['field_s_sweet_audience_tid']['field'] = 'field_s_sweet_audience_tid';
  $handler->display->display_options['arguments']['field_s_sweet_audience_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_s_sweet_audience_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_s_sweet_audience_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_s_sweet_audience_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_s_sweet_audience_tid']['break_phrase'] = TRUE;
  $handler->display->display_options['block_description'] = 'Sweeteners Carousel By Audience';
  $translatables['sweeteners'] = array(
    t('Master'),
    t('Sweeteners Carousel'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('[field_s_sweet_image]
[title]'),
    t('All'),
    t('Page'),
    t('Manual Selection Block'),
    t('Manual Selection Block With Entity References'),
    t('<div class="sweetener-image">[field_s_sweet_image]</div>
<h3>[title]</h3>'),
    t('Category Selection Block'),
    t('Sweeteners Carousel By Type'),
    t('Subsite Selection Block'),
    t('Audience Selection Block'),
    t('Sweeteners Carousel By Audience'),
  );
  $export['sweeteners'] = $view;

  return $export;
}