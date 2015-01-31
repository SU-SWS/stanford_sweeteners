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
    $view->set_display('sweetener_carousel');
    $carousel = $view->preview();

    $opts = array();
    $opts['slidesToShow'] = isset($bean->field_sweetener_num_items[LANGUAGE_NONE][0]['value']) ? (int) $bean->field_sweetener_num_items[LANGUAGE_NONE][0]['value'] : 3;
    $opts['slidesToScroll'] = isset($bean->field_sweetener_num_items[LANGUAGE_NONE][0]['value']) ? (int) $bean->field_sweetener_num_items[LANGUAGE_NONE][0]['value'] : 3;

    $slick_theme = isset($bean->field_sweetener_carousel_mode[LANGUAGE_NONE][0]['value']) ? $bean->field_sweetener_carousel_mode[LANGUAGE_NONE][0]['value'] : "default";

    // Slick Id only available after ->preview() is called.
    stanford_sweeteners_load_slick_settings($view->slick_id, $slick_theme, $opts);

    $content['carousel']['#markup'] = $carousel;
    return $content;
  }

}
