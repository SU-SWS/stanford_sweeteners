<?php

/**
 * @file
 */

/**
 * Style plugin.
 */
class stanford_sweeteners_isotope_plugin_style_isotope_filter extends views_plugin_style_list {

  /**
   * Add the checkbox option.
   * @return [type] [description]
   */
  function option_definition() {
    $options = parent::option_definition();
    $options["render_filters"] = array("default" => "checkboxes");
    $options["render_label"] = array("default" => "");
    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {

    // Filter render setting.
    $form['render_filters'] = array(
      '#type' => 'radios',
      '#title' => t('Render as checkboxes or links.'),
      '#options' => array(
        'links' => 'links',
        'checkboxes' => 'checkboxes',
      ),
      '#default_value' => $this->options['render_filters'],
    );

    // Label.
    $form['render_label'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to output as a label for the filters.'),
      '#default_value' => $this->options['render_label'],
    );

    return $form;
  }

}


