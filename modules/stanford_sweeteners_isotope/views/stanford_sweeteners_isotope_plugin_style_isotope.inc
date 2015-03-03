<?php

/**
 * @file
 */

/**
 * Style plugin.
 */
class stanford_sweeteners_isotope_plugin_style_isotope extends views_plugin_style_list {

  /**
   * Add the checkbox option.
   * @return [type] [description]
   */
  function option_definition() {
    $options = parent::option_definition();
    $options["filter_field"] = array("default" => '');
    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $field_options = array_keys($this->display->display_options['fields']);
    $field_options = array_combine($field_options, $field_options);

    $form['filter_field'] = array(
      '#type' => 'checkboxes',
      '#title' => t("Fields to use as Isotope filters"),
      '#options' => $field_options,
      '#default_value' => $this->options['filter_field'],
    );

    return $form;
  }

}


