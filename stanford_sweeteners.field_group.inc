<?php
/**
 * @file
 * stanford_sweeteners.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_sweeteners_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sweet_set|bean|stanford_sweetener_carousel|form';
  $field_group->group_name = 'group_sweet_set';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_sweetener_carousel';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Carousel Settings',
    'weight' => '2',
    'children' => array(
      0 => 'field_sweetener_num_items',
      1 => 'field_sweet_branding',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sweet-set field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sweet_set|bean|stanford_sweetener_carousel|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sweetener_selection|bean|stanford_sweetener_carousel|form';
  $field_group->group_name = 'group_sweetener_selection';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'stanford_sweetener_carousel';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Item selection',
    'weight' => '4',
    'children' => array(
      0 => 'field_sweetener_etr',
      1 => 'field_sweet_select_choice',
      2 => 'field_stanford_subsite_sub_tags',
      3 => 'field_s_sweet_category',
      4 => 'field_s_sweet_audience',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sweetener-selection field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sweetener_selection|bean|stanford_sweetener_carousel|form'] = $field_group;

  return $export;
}
