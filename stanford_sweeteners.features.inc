<?php
/**
 * @file
 * stanford_sweeteners.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_sweeteners_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function stanford_sweeteners_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function stanford_sweeteners_node_info() {
  $items = array(
    'stanford_sweetener' => array(
      'name' => t('Sweetener'),
      'base' => 'node_content',
      'description' => t('Sweetener for the Cardinal at Work project.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
