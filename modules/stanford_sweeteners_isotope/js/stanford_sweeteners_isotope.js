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

/**
 * The main thingamajiggy.
 * @param  {[type]} context  [description]
 * @param  {[type]} settings [description]
 * @return {[type]}          [description]
 */
Stanford_sweeteners_isotope.init = function(context, settings) {

  // Cuz I don't want to wrap everything ok!
  $ = jQuery;

  // There can be only one.
  var $container = $('#isotope-container', context);

  // Trigger iso!
  $container.isotope({
    itemSelector: '.isotope-element',
    sortAscending: true,
    layoutMode: 'masonry'
  });

  var $optionSets = $('#isotope-checkbox-options .option-set', context),
      $optionBoxes = $optionSets.find('input');

  $optionBoxes.change(function(e) {
    var filters = [];
    $optionBoxes.filter(":checked").each(function(i, v) {
      filters.push($(v).val());
    });

    var options = {};

    // If there are no filters or all filters are selected show everything.
    if (filters.length >= 0 && filters.length < $optionBoxes.length) {
      options.filter = filters.join(", ");
    }
    else {
      options.filter = "*";
    }

    $container.isotope(options);
  });

};

/**
 * [isotope_update description]
 * @return {[type]} [description]
 */
Stanford_sweeteners_isotope.isotope_update = function() {

  var $container = $('#isotope-container');

  var $optionSets = $('#isotope-checkbox-options .option-set'),
      $optionBoxes = $optionSets.find('input');

  var filters = [];
  $optionBoxes.filter(":checked").each(function(i, v) {
    filters.push($(v).val());
  });

  var options = {};

  // If there are no filters or all filters are selected show everything.
  if (filters.length >= 0 && filters.length < $optionBoxes.length) {
    options.filter = filters.join(", ");
  }
  else {
    options.filter = "*";
  }

  $container.isotope(options);
};


/**
 * Adds deeplinking to the filters
 * @param  {[type]} context  [description]
 * @param  {[type]} settings [description]
 * @return {[type]}          [description]
 */
Stanford_sweeteners_isotope.historystate_init = function(context, settings) {

  // Bind to StateChange Event
  // History.Adapter.bind(window,'statechange',function() {
  //   var State = History.getState();
  // });

  // Cuz we roll like that.
  $ = jQuery;

  // Get elements
  var $optionSets = $('#isotope-checkbox-options .option-set', context),
      $optionBoxes = $optionSets.find('input');

  // Handle the current state
  var state = History.getState();
  if (state.hash !== Drupal.settings.basePath + "sweeteners") {
    var hashparams = state.hash.replace(Drupal.settings.basePath + "sweeteners", "");
    // var selectors = hashparams.split("/");
    var selector = hashparams.replace(/\//g, ",#");
    selector = selector.replace(",", "");
    $optionBoxes.not(selector).attr("checked", false);
    Stanford_sweeteners_isotope.isotope_update();
  }

  // Add change handlers to the checkboxes.
  $optionBoxes.change(function(e) {
    var filters = [];

    $optionBoxes.filter(":checked").each(function(i, v) {
      filters.push($(v).val());
    });

    var hash = Drupal.settings.basePath + "sweeteners";

    // If there are no filters or all filters are selected show everything.
    if (filters.length > 0 && filters.length < $optionBoxes.length) {
      var params = filters.join("/");
      params = params.replace(/\./g, "");
      hash += "/" + params;
    }

    // Making changes!
    History.replaceState(null, null, hash);

  });

};

