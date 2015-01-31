<?php
/**
 * @file
 * stanford_sweeteners.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function stanford_sweeteners_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'stanford_sweetener_carousel';
  $bean_type->label = 'Sweetener Carousel';
  $bean_type->options = '';
  $bean_type->description = 'Stanford Sweetener carousel block';
  $export['stanford_sweetener_carousel'] = $bean_type;

  return $export;
}

