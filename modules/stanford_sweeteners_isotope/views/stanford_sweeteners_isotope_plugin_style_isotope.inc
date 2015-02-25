<?php

/**
 * @file
 */

/**
 * Style plugin.
 */
class stanford_sweeteners_isotope_plugin_style_isotope extends views_isotope_plugin_style_isotope {

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    // parent::options_form($form, $form_state);
    $form['render_as_checkboxes'] = array(
      '#type' => 'checkbox',
      '#title' => t('Render as checkboxes.'),
     );
    return($form);
  }

}


