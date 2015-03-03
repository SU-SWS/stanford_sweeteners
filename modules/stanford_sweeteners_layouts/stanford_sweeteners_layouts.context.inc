<?php
/**
 * @file
 * stanford_sweeteners_layouts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_sweeteners_layouts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sweeteners_landing';
  $context->description = 'Sweeteners';
  $context->tag = 'Sweeteners';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'sweeteners_isotope_page' => 'sweeteners_isotope_page',
        'sweeteners_isotope_page:page_1' => 'sweeteners_isotope_page:page_1',
        'sweeteners_isotope_page:sweetener_isotope_page' => 'sweeteners_isotope_page:sweetener_isotope_page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-e45453d1642ffd0c9ec65173ce88d331' => array(
          'module' => 'views',
          'delta' => 'e45453d1642ffd0c9ec65173ce88d331',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-d946c006912e89db5aa2a8f902b8dc9c' => array(
          'module' => 'views',
          'delta' => 'd946c006912e89db5aa2a8f902b8dc9c',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sweeteners');
  $export['sweeteners_landing'] = $context;

  return $export;
}
