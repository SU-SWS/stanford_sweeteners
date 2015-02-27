<?php

/**
 * Implements hook_views_plugins().
 */
function stanford_sweeteners_isotope_views_plugins() {
  return array(
    'style' => array(
      'stanford_sweeteners_isotope_filter_block' => array(
        'title' => t('Isotope Filter Checkboxes Block'),
        'help' => t('Display the filter as a list of checkboxes'),
        'handler' => 'stanford_sweeteners_isotope_plugin_style_isotope',
        'theme' => 'stanford_sweeteners_isotope_filter_block',
        'uses options' => TRUE,
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
        'parent' => 'list',
        'theme file' => 'stanford_sweeteners_isotope.theme.inc',
        'theme path' => drupal_get_path('module', 'stanford_sweeteners_isotope') . "/views",
      ),
    ),
  );
}
