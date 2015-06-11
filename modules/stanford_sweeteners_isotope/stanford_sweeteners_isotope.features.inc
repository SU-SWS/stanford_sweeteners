<?php
/**
 * @file
 * stanford_sweeteners_isotope.features.inc
 */

/**
 * Implements hook_views_api().
 */
function stanford_sweeteners_isotope_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function stanford_sweeteners_isotope_image_default_styles() {
  $styles = array();

  // Exported image style: sweetener_-_card.
  $styles['sweetener_-_card'] = array(
    'label' => 'Sweetener - Card',
    'effects' => array(
      16 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 202,
          'height' => 130,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
