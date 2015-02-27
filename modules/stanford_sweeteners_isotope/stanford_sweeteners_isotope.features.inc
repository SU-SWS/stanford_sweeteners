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
    'name' => 'sweetener_-_card',
    'label' => 'Sweetener - Card',
    'effects' => array(
      16 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
