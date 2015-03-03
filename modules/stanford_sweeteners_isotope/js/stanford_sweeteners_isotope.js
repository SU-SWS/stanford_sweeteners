(function($) {

  Drupal.behaviors.stanford_sweeteners_isotope = {
    attach: function (context, settings) {
      Stanford_sweeteners_isotope.init(context, settings);
      Stanford_sweeteners_isotope.historystate_init(context, settings);
    }
  };

})(jQuery);

// Initialize global object.
Stanford_sweeteners_isotope = {};
Stanford_sweeteners_isotope.event = {};
Stanford_sweeteners_isotope.addevent = {};

/**
 * The main thingamajiggy.
 * @param  {[type]} context  [description]
 * @param  {[type]} settings [description]
 * @return {[type]}          [description]
 */
Stanford_sweeteners_isotope.init = function(context, settings) {

  // Cuz I don't want to wrap everything ok!
  $ = jQuery;

  // There can be many.
  var containers = $('.isotope-container', context);

  // Loop through the containers...
  $.each(containers, function(i, v) {

    // ...and add the masonry layout to them.
    $(v).isotope({
      itemSelector: '.isotope-element',
      sortAscending: true,
      layoutMode: 'masonry'
    });

    // Find the filters and set their change handler.
    var filters = $(v).parents(".view:first").find(".isotope-options .filters");
    Stanford_sweeteners_isotope.addevent.checkboxes(filters);
    Stanford_sweeteners_isotope.addevent.clicklinks(filters);
  });

};

/**
 * [checkboxes description]
 * @param  {[type]} filters [description]
 * @return {[type]}         [description]
 */
Stanford_sweeteners_isotope.addevent.checkboxes = function(filters) {
  var inputs = filters.find("input");
  inputs.change(function(e) {
    var container = $(this).parents(".view-header").parent();
    Stanford_sweeteners_isotope.event.update(container);
  });
};

/**
 * [clicklinks description]
 * @param  {[type]} filters [description]
 * @return {[type]}         [description]
 */
Stanford_sweeteners_isotope.addevent.clicklinks = function(filters) {
  var inputs = filters.find("a");
  inputs.click(function(e) {
    e.preventDefault();
    var container = $(this).parents(".view-header").parent();
    Stanford_sweeteners_isotope.event.clicked(container, $(this));
  });
};


/**
 * [checkboxes description]
 * @param  {[type]} container [description]
 * @return {[type]}           [description]
 */
Stanford_sweeteners_isotope.event.update = function(view) {
  var options = {};
  var filters = Stanford_sweeteners_isotope.get_active_filters(view);
  var container = view.find(".isotope-container:first");
  var count = view.find(".filters input").length;

  // If there are no filters or all filters are selected show everything.
  if (filters.length > 0 && filters.length < count) {
    options.filter = filters.join(", ");
  }
  else {
    options.filter = "*";
  }

  container.isotope(options);
};

/**
 * [clicked description]
 * @param  {[type]} view     [description]
 * @param  {[type]} selector [description]
 * @return {[type]}          [description]
 */
Stanford_sweeteners_isotope.event.clicked = function(view, element) {
  var options = {};
  var filters = Stanford_sweeteners_isotope.get_active_filters(view);
  var container = view.find(".isotope-container:first");
  var count = view.find(".filters input").length;

  options.filter = element.data('option-value');

  if (filters.length > 0 && filters.length < count) {
    options.filter += " " + filters.join(", ");
  }

  container.isotope(options);
};


/**
 * [get_active_filters description]
 * @param  {[type]} view [description]
 * @return {[type]}      [description]
 */
Stanford_sweeteners_isotope.get_active_filters = function(view) {
  var filters = [];
  var count = view.find(".filters input").length;

  view.find(".filters input:checked").each(function(i, v) {
    filters.push($(v).val());
  });

  if (count == filters.length) {
    return [];
  }

  return filters;
};

/**
 * Adds deeplinking to the filters
 * @param  {[type]} context  [description]
 * @param  {[type]} settings [description]
 * @return {[type]}          [description]
 */
Stanford_sweeteners_isotope.historystate_init = function(context, settings) {

  // Cuz we roll like that.
  $ = jQuery;

  // Handle the current state
  var state = History.getState();
  if (state.hash !== (Drupal.settings.basePath + Drupal.settings.stanford_sweeteners_isotope.urlpath)) {
    var hashparams = state.hash.replace(Drupal.settings.basePath + Drupal.settings.stanford_sweeteners_isotope.urlpath, "");
    var selector = hashparams.replace(/\//g, ",.");
    selector = selector.replace(",", "");
    $(".isotope-options .filters input").not(selector).attr("checked", false);
    Stanford_sweeteners_isotope.event.update($('.isotope-container').parent().parent());
  }

  // Making changes!
  // History.replaceState(null, null, hash);
  // There can be many.
  var containers = $('.isotope-options .filters', context);

  // Loop through the containers...
  $.each(containers, function(i, v) {
    // Find the filters and set their change handler.
    Stanford_sweeteners_isotope.addevent.history_boxes($(v));
    Stanford_sweeteners_isotope.addevent.history_links($(v));
  });

};

/**
 * [history_boxes description]
 * @param  {[type]} filters [description]
 * @return {[type]}         [description]
 */
Stanford_sweeteners_isotope.addevent.history_boxes = function(filters) {
  var inputs = filters.find("input");
  inputs.change(function(e) {
    var view = $(this).parents(".view-header").parent();
    var filters = Stanford_sweeteners_isotope.get_active_filters(view);
    var filter_string = filters.join("/");
    filter_string = filter_string.replace(/\./g, "");
    var hash = Drupal.settings.basePath + Drupal.settings.stanford_sweeteners_isotope.urlpath + "/" + filter_string;
    History.replaceState(null, null, hash);
  });
};

/**
 * [history_boxes description]
 * @param  {[type]} filters [description]
 * @return {[type]}         [description]
 */
Stanford_sweeteners_isotope.addevent.history_links = function(filters) {
  var inputs = filters.find("a");
  inputs.click(function(e) {
    var view = $(this).parents(".view-header").parent();
    var filters = Stanford_sweeteners_isotope.get_active_filters(view);
    var filter_string = "";
    if (filters.length) {
      filter_string += filters.join("/") + "/";
    }
    filter_string += $(this).data('option-value');
    filter_string = filter_string.replace(/\./g, "");

    var hash = Drupal.settings.basePath + Drupal.settings.stanford_sweeteners_isotope.urlpath + "/" + filter_string;
    History.replaceState(null, null, hash);
  });
};

