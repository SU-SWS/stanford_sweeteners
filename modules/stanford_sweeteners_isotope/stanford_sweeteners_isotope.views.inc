<?php

/**
 * Implements hook_views_plugins().
 */
function stanford_sweeteners_isotope_views_plugins() {
  return array(
    'style' => array(
      'stanford_sweeteners_isotope' => array(
        'title' => t('Sweetener Isotope Grid'),
        'help' => t('Display the results using the jQuery Isotope plugin'),
        'handler' => 'stanford_sweeteners_isotope_plugin_style_isotope',
        'theme' => 'stanford_sweeteners_views_isotope',
        'uses options' => TRUE,
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
        'parent' => 'list',
        'theme file' => 'stanford_sweeteners_isotope.theme.inc',
        'theme path' => drupal_get_path("module", "stanford_sweeteners_isotope") . "/views",
      ),
      'stanford_sweeteners_isotope_filter' => array(
        'title' => t('Sweetener Isotope Filter'),
        'help' => t('Display the results formatted to filter an Isotope View'),
        'handler' => 'stanford_sweeteners_isotope_plugin_style_isotope_filter',
        'theme' => 'stanford_sweeteners_isotope_filter',
        'uses options' => TRUE,
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
        'parent' => 'list',
        'theme file' => 'stanford_sweeteners_isotope.theme.inc',
        'theme path' => drupal_get_path("module", "stanford_sweeteners_isotope") . "/views",
      ),
    ),
  );
}
