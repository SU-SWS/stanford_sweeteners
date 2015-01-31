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
  if ($module == "bean" && $api == "types") {
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

/** Implements hook_bean_types.
 * This function exists only for installation purposes and beans are
 * exported and managed through the ui.
 * See: https://drupal.org/node/1897834 for issue details.
 * @return array of bean types
 */
function stanford_sweeteners_bean_types() {
  include_once "stanford_sweeteners.bean.inc";
  $plugins = array();
  $types = stanford_sweeteners_bean_admin_ui_types();
  $plugin_path = drupal_get_path('module', 'stanford_sweeteners') . '/plugins/bean';

  foreach($types as $k => $bean_type) {
    $plugins[$k] = array(
      'label' => $bean_type->name,
      'description' => t($bean_type->description),
      'handler' => array(
        'class' => 'StanfordSweetenerBean',
        'parent' => 'bean',
        'path' => $plugin_path,
        'file' => 'stanford_sweeteners.bean.type.inc',
      ),
    );
  }

  return $plugins;
}
