<?php
// $Id:

/**
 * Preprocess function to build the isotope grid.
 */
function template_preprocess_stanford_sweeteners_views_isotope(&$vars) {
  template_preprocess_views_view_list($vars);
  libraries_load('jquery.isotope');
  drupal_add_js(drupal_get_path('module', 'stanford_sweeteners_isotope') . "/js/jquery.history.js");
  drupal_add_js(drupal_get_path('module', 'stanford_sweeteners_isotope') . "/js/stanford_sweeteners_isotope.js");

  // Add the current path to the settings.
  $view = $vars['view'];
  $url = $view->get_path();
  $js_settings = array("stanford_sweeteners_isotope" => array("urlpath" => $url));
  drupal_add_js($js_settings, 'setting');

  $rows = &$vars['rows'];
  $results = $view->result;
  $options = $view->style_plugin->options;
  $handler = $view->style_plugin;
  $fields = &$view->field;
  $filter_fields = array_values($vars['options']['filter_field']);
  $vars['attributes'] = array();
  $vars['classlist'] = array();
  $vars['isotope_id'] = 'views-isotope-' . $view->name . '-' . $view->style_plugin->display->id;

  // Add all the filters...
  foreach ($rows as $index => $value) {
    $classes = array();
    foreach ($filter_fields as $field_name) {
      if (empty($field_name)) {
        continue;
      }
      // Not sure why this yet.
      $field_name = "field_" . $field_name;
      foreach ($results[$index]->{$field_name} as $result_field) {
        $classes[] = substr(drupal_clean_css_identifier(stanford_sweeteners_isotope_trim($result_field['rendered']['#markup'])), 0, 64);
      }
    }
    $vars['classlist'][$index] = implode($classes, " ");
  }

}

/**
 * Preprocess function to build the isotope filter block.
 */
function template_preprocess_stanford_sweeteners_isotope_filter(&$vars) {
  template_preprocess_views_view_list($vars);

  $view = $vars['view'];
  $options = $view->style_plugin->options;
  $handler = $view->style_plugin;
  $fields = &$view->field;
  $rows = &$vars['rows'];
  $vars['attributes'] = array();
}
