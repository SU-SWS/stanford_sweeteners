/**
 * initiates slick carousels
 */

(function ($) {

  Drupal.behaviors.stanford_sweeteners = {
    attach: function (context, settings) {
      $.each(Drupal.settings.stanford_sweeteners, function(id, settings) {
        $("." + id + " .view-content", context).slick(settings);
      });
    }
  };

})(jQuery);
