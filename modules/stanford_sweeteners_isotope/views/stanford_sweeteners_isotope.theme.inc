<?php
// $Id:

/**
 * Preprocess function to build the isotope filter block.
 */
function template_preprocess_stanford_sweeteners_isotope_filter_block(&$vars) {
  template_preprocess_views_view_list($vars);
  $view = $vars['view'];
  $options = $view->style_plugin->options;
  $handler = $view->style_plugin;
  $fields = &$view->field;
  $rows = &$vars['rows'];
  $vars['attributes'] = array();
  drupal_add_js(drupal_get_path('module', 'stanford_sweeteners_isotope') . '/js/stanford_sweeteners_isotope.js');
}
