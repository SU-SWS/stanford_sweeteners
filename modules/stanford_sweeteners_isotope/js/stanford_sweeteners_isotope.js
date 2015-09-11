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

  // Make labels have toggle css class
  var labels = filters.find("label");
  labels.click(function(e) {
    if ($(this).find("input:checked").length) {
      $(this).addClass("checked");
    }
    else {
      $(this).removeClass("checked");
    }
  });

  // Add click handles to the checkboxes
  var inputs = filters.find("input");

  inputs.change(function(e) {
    // Aria checked status.
    var chkd = $(this).attr('aria-checked');
    if (chkd === "true") { chkd = false; }
    else { chkd = true; }
    $(this).attr('aria-checked', chkd);

    var container = $(this).parents(".view-header").parent();
    Stanford_sweeteners_isotope.event.update(container);
  });

  // Add focus to label.
  inputs.focus(function(e) {
    $(this).parents("label").addClass("hover");
  });
  inputs.blur(function(e) {
    $(this).parents("label").removeClass("hover");
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
  var groups = Stanford_sweeteners_isotope.get_active_filters_grouped(view);
  var container = view.find(".isotope-container:first");
  var count = view.find(".filters input").length;

  if (groups.length > 1) {
    var filters = [];

    $.each(groups, function(key, group) {

      // Ghost entries. I (l) javascript.
      if (typeof group == "undefined") {
        return;
      }

      $.each(group, function(i, v) {
        $.each(groups, function(ii, vv) {
          if (ii == key || typeof vv == "undefined") {
            return;
          }

          filters.push(v + vv.join(""));
        });
      });
    });

    options.filter = filters.join(", ");
  }
  else if (groups.length == 1 && typeof groups[0] !== "undefined") {
    options.filter = groups[0].join(", ");
  }

  // Check to see that there is something after all.
  if (typeof options.filter == "undefined" || options.filter.length <= 0) {
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
    options.filter += " " + filters.join("");
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
 * [get_active_filters description]
 * @param  {[type]} view [description]
 * @return {[type]}      [description]
 */
Stanford_sweeteners_isotope.get_active_filters_grouped = function(view) {
  var filters = [];
  var groups = view.find(".filters");

  $.each(groups, function(i, v) {
    filters[i] = [];
    var boxes = $(v).find("input:checked");
    boxes.each(function(ii, vv) {
      filters[i].push($(vv).val());
    });

    if(filters[i].length <= 0) {
      filters.splice(i, 1);
    }

  });

  // Reset the index.
  filters = $(filters).filter(function() { return true; });
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
  var clean_hash = state.hash.split("?")[0];
  if (clean_hash !== (Drupal.settings.basePath + Drupal.settings.stanford_sweeteners_isotope.urlpath)) {
    var hashparams = clean_hash.replace(Drupal.settings.basePath + Drupal.settings.stanford_sweeteners_isotope.urlpath, "");
    var selector = hashparams.replace(/\//g, ",.");
    selector = selector.replace(",", "");
    $(".isotope-options .filters input").filter(selector).attr("checked", true);
    $(".isotope-options .filters input").filter(selector).attr("aria-checked", true);
    $(".isotope-options .filters input").filter(selector).parent().addClass("checked");
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
    History.replaceState(null, document.title, hash);
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
    History.replaceState(null, document.title, hash);
  });
};

