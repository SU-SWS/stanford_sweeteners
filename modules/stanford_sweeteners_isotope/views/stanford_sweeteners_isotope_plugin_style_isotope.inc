<?php

/**
 * @file
 */

/**
 * Style plugin.
 */
class stanford_sweeteners_isotope_plugin_style_isotope extends views_isotope_plugin_style_isotope {

  /**
   * Add the checkbox option.
   * @return [type] [description]
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['render_as_checkboxes'] = array('default' => TRUE);
    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    // parent::options_form($form, $form_state);
    $form['render_as_checkboxes'] = array(
      '#type' => 'checkbox',
      '#title' => t('Render as checkboxes.'),
      '#default_value' => $this->options['render_as_checkboxes'],
     );
    return($form);
  }

}


