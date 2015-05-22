/**
 * initiates slick carousels
 */

(function ($) {

  Drupal.behaviors.stanford_sweeteners = {
    attach: function (context, settings) {

      $.each(Drupal.settings.stanford_sweeteners, function(id, settings) {
        $("." + id + " .view-content", context).slick(settings);
      });

      Drupal.behaviors.stanford_sweeteners.button_count = 0;
      this.move_buttons();

      // Fire on change to dots.
      $('.sweetener-arrows').bind('DOMSubtreeModified', function(e) {
        var count = $(this).find("li").length;
        if (count !== Drupal.behaviors.stanford_sweeteners.button_count) {
          Drupal.behaviors.stanford_sweeteners.move_buttons();
          Drupal.behaviors.stanford_sweeteners.button_count = count;
        }
      });

    },
    /**
     * @todo: Make this work with more than one item on a page.
     */
    move_buttons: function () {
      var dots = $(".slick-dots");
      var next = $(".sweetener-arrows").find(".slick-next");
      if (dots.length) {
        next.remove();
        next.insertAfter(dots);
        next.click(function() {
          $(this).parent().parent().find(".slick-slider").slick("slickNext");
        });
      }
    }
  };


})(jQuery);

