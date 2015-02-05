<?php
/**
 * stanford_sweeteners.bean.type.inc
 */

class StanfordSweetenerBean extends BeanPlugin {


  /**
   * Overrides the view method.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $old_content = $content;
    $content = array();

    $view = views_get_view('sweeteners');
    $selection_choice = !empty($bean->field_sweet_select_choice[LANGUAGE_NONE][0]['value']) ? $bean->field_sweet_select_choice[LANGUAGE_NONE][0]['value'] : "manual";
    $func = "view_selection_" . $selection_choice;

    // If there is a selection option call it.
    if (method_exists($this, $func)) {
      $this->{$func}($bean, $view);
    }
    else {
      drupal_set_message("Could not find item selection choice for sweetener carousel", "error");
    }

    $handler = $view->display['carousel_branding_block']->handler;

    // Work with attachments.
    $displays = $handler->get_option('displays');
    $displays[$view->current_display] = 1;
    $handler->set_option('displays', $displays);

    // $handler->attach_to($view->current_display);

    // Generate the output.
    $carousel = $view->preview();

    // Slick javscript options...
    $opts = array();
    $opts['slidesToShow'] = isset($bean->field_sweetener_num_items[LANGUAGE_NONE][0]['value']) ? (int) $bean->field_sweetener_num_items[LANGUAGE_NONE][0]['value'] : 3;
    $opts['slidesToScroll'] = isset($bean->field_sweetener_num_items[LANGUAGE_NONE][0]['value']) ? (int) $bean->field_sweetener_num_items[LANGUAGE_NONE][0]['value'] : 3;
    $slick_option = isset($bean->field_sweetener_num_items[LANGUAGE_NONE][0]['value']) ? $bean->field_sweetener_num_items[LANGUAGE_NONE][0]['value'] : 1;
    $slick_theme = $this->get_slick_display_options($slick_option);

    // Slick Id only available after ->preview() is called.
    stanford_sweeteners_load_slick_settings($view->slick_id, $slick_theme, $opts);

    // Set the content on the render array and be happy.
    $content['carousel']['#markup'] = $carousel;
    return $content;
  }

  /**
   * Get the theme options for Slick.
   * @param  [type] $int [description]
   * @return [type]      [description]
   */
  protected function get_slick_display_options($int) {
    $values = array();
    $values[1] = "1 item";
    $values[2] = "2 items";
    $values[3] = "3 items";
    $values[4] = "4 items";
    $values[5] = "5 items";
    $values[6] = "6 items";

    // If not set return all of them.
    if (empty($int)) {
      return $values;
    }

    return $values[$int];
  }

  /**
   * [view_selection_manual description]
   * @param  [type] &$view [description]
   * @return [type]        [description]
   */
  protected function view_selection_manual(&$bean, &$view) {

    // Set the display.
    $view->set_display('sweetener_carousel');

    // If there are a list of entity relationships then we need to add them
    // as arguments to the view.
    if (!empty($bean->field_sweetener_etr[LANGUAGE_NONE])) {
      $args = array("");
      foreach ($bean->field_sweetener_etr[LANGUAGE_NONE] as $index => $value_array) {
        $args[0] .= "+" . $value_array['target_id'];
      }
      $args[0] = ltrim($args[0], "+");
      $view->set_arguments($args);
    }

  }

  /**
   * [view_selection_type description]
   * @param  [type] &$bean [description]
   * @param  [type] &$view [description]
   * @return [type]        [description]
   */
  protected function view_selection_type(&$bean, &$view) {
    // Set the display.
    $view->set_display('sweetener_carousel_category');

    // If there are a list of entity relationships then we need to add them
    // as arguments to the view.
    if (!empty($bean->field_s_sweet_category[LANGUAGE_NONE])) {
      $args = array("");
      foreach ($bean->field_s_sweet_category[LANGUAGE_NONE] as $index => $value_array) {
        $args[0] .= "+" . $value_array['tid'];
      }
      $args[0] = ltrim($args[0], "+");
      $view->set_arguments($args);
    }

  }

  /**
   * [view_selection_subsite description]
   * @param  [type] &$bean [description]
   * @param  [type] &$view [description]
   * @return [type]        [description]
   */
  protected function view_selection_subsite(&$bean, &$view) {
    // Set the display.
    $view->set_display('sweetener_carousel_subsite');

    // If there are a list of entity relationships then we need to add them
    // as arguments to the view.
    if (!empty($bean->field_stanford_subsite_sub_tags[LANGUAGE_NONE])) {
      $args = array("");
      foreach ($bean->field_stanford_subsite_sub_tags[LANGUAGE_NONE] as $index => $value_array) {
        $args[0] .= "+" . $value_array['tid'];
      }
      $args[0] = ltrim($args[0], "+");
      $view->set_arguments($args);
    }

  }

  /**
   * [view_selection_type description]
   * @param  [type] &$bean [description]
   * @param  [type] &$view [description]
   * @return [type]        [description]
   */
  protected function view_selection_audience(&$bean, &$view) {
    // Set the display.
    $view->set_display('sweetener_carousel_audience');

    // If there are a list of entity relationships then we need to add them
    // as arguments to the view.
    if (!empty($bean->field_s_sweet_audience[LANGUAGE_NONE])) {
      $args = array("");
      foreach ($bean->field_s_sweet_audience[LANGUAGE_NONE] as $index => $value_array) {
        $args[0] .= "+" . $value_array['tid'];
      }
      $args[0] = ltrim($args[0], "+");
      $view->set_arguments($args);
    }

  }

}
