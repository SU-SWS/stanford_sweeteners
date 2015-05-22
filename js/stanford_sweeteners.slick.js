/**
 * initiates slick carousels
 */

(function ($) {

  Drupal.behaviors.stanford_sweeteners = {
    attach: function (context, settings) {

      $.each(Drupal.settings.stanford_sweeteners, function(id, settings) {
        $("." + id + " .view-content", context).slick(settings);
      });

      this.move_buttons();

      // Fire on resize.
      $('.sweetener-arrows').bind('DOMSubtreeModified', function(e) {
        Drupal.behaviors.stanford_sweeteners.move_buttons();
      });

    },
    move_buttons: function () {
      var dots = $(".slick-dots");
      var next = $(".sweetener-arrows").find(".slick-next");
      if (dots.length) {
        next.remove();
        next.insertAfter(dots);
      }
    }
  };


})(jQuery);

