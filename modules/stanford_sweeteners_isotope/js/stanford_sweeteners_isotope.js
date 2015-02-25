(function($) {

  Drupal.behaviors.stanford_sweeteners_isotope = {
    attach: function (context, settings) {
      Stanford_sweeteners_isotope.init(context, settings);
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
    itemSelector: '.isotope-element'
  });

  var $optionSets = $('#isotope-checkbox-options .option-set', context),
      $optionBoxes = $optionSets.find('input');

  $optionBoxes.change(function(e) {
    var filters = [];
    $optionBoxes.filter(":checked").each(function(i, v) {
      filters.push($(v).val());
    });

    var options = {};
    options.filter = filters.join(", ");

    $container.isotope(options);
  });

};






// var filters = {};

// /*
// * Manage Checkbox State
// * Build Isotope filter list based on selected checkboxes
// */
// function checkboxFilter( $checkbox ) {


//   var checkbox = $checkbox[0];
//   filter = new Array();

//   jQuery('.option-set input:checked').each(function() {
//     checkboxvalue = jQuery(this).attr('value');
//     filter.push( checkboxvalue);
//   });


//   filter = filter.join(',');

//   return(filter);
// }

// /*
// * Manage Containers.
// * This module supports 1 or more Isotope Containers.  This is where functionality to manage layout
// * After a filter has been applied are added
// */
// function manageContainer(instance, divNumber){

//   //Isotope Containers May have a header identified as isotope-header_($count).
//   //Remove headers where filter empty the container.
//   var headerID = 'isotope-header_' + divNumber;  //work with header with the same divNumber as class
//   if( jQuery('#' + headerID).length ){
//     removeHeaderforEmpty(instance, headerID);
//   }

// }
// /*
// * Remove Headers for Empty Containers
// * Called by:  manageContainer
// */
// function removeHeaderforEmpty(instance, headerID){

//   var containerElements = instance.$filteredAtoms.length;

//   //if hide headers without elements
//   if(containerElements == 0){
//     jQuery('#' + headerID).hide(500);
//   }else{
//     jQuery('#' + headerID).show(500);
//   }
// }

// /*
// * Main Function for Isotope Display Logic
// * Currently there are two actions
// *   - Link Clicks: For Blocks rendering taxonomy as links, click event will fire Isotope Logic associated with this display
// *   - Checkbox Clicks:  For Blocks rendering taxonomy as checkboxes , click events will fire Isotope logic associated with this display
// * BBQ.JS is used to manage Hash state of Isotope Filter

// */
// (function($) {
//   $(document).ready(function() {

//   //There can be one ore more Isotope Containers in the View
//   var containers = new Array();
//   var hashOptions = "";

//   //defaultCheckboxState();

//   //Define Isotope Defaults for containers
//   $('div[id^="isotope-container"]').each(function (i,v) {
//     containers[i] = $('#' + v.id),
//           // object that will keep track of options
//           isotopeOptions = {},
//           // defaults, used if not explicitly set in hash
//           defaultOptions = {
//             filter: '*',
//             sortAscending: true,
//             layoutMode: 'masonry'
//     };
//   });

// /*
// *  On Hash Change (triggered by BBQ.pushstate), Apply Isotope Filter and rules
// */
//  $(window).bind( 'hashchange', function( event ){


//     options = $.deparam.fragment(window.location.hash, true);

//     if(options['filter'] == undefined){
//       //show the default view  of all
//     }
//     else if(options['filter']){
//        hashOptions = options['filter'];

//     } //no filter, but checkboxes all selected (first page load)
//     else{
//       //empty filters reset to all - so we need this to return nothing

//       options['filter'] = '.empty';
//       hashOptions = '.empty';
//     }

//     if($('#isotope-checkbox-options').length !=0) {
//       checkboxHashState();
//      }

//      //$('#isotope-container').isotope({ filter: '.ba, .bs' });


//     $('div[id^="isotope-container"]').each(function (i,v) {
//         containers[i].isotope(options, function($changedItems, instance){
//         containerID = containers[i].attr("id");
//         var divNumber = containerID.match(/\d+/);
//         manageContainer(instance, divNumber);
//       });
//     });
//  })

//   //Trigger hashchange on window load, so bookmarks work
//   $(window).trigger('hashchange');

//   /*
//   Update Hash for filter and bookmarking
//   */
//   function setIsotopeHash(){

//      var options = {};
//      options['filter'] = hashOptions;
//      $.bbq.pushState( options );

//   }

//  //Checkbox Click Event
//  //Manage checkboxes
//  //Trigger Hash Change for filter
//  $( "#isotope-checkbox-options" ).change('[id^=isotope-container]', function(jQEvent ) {

//     var $checkbox = $( jQEvent.target );
//     hashOptions = checkboxFilter($checkbox);
//     setIsotopeHash();

//  });

//   //Logic for links view, build filter based on cselected link
//   var $optionSets = $('#isotope-options .option-set'),
//   $optionLinks = $optionSets.find('a');

//   $optionLinks.click('[id^=isotope-container]',function(){

//     var $this = $(this);

//     // Don'tt proceed if already  selected
//     if ( $this.hasClass('selected') ) {
//       return false;
//     }
//     var $optionSet = $this.parents('.option-set');
//     $optionSet.find('.selected').removeClass('selected');
//     $this.addClass('selected');

//     var options = {},
//         key = $optionSet.attr('data-option-key'),
//         value = $this.attr('data-option-value');

//     // parse 'false' as false boolean
//     value = value === 'false' ? false : value;
//     options[ key ] = value;

//     var href = $this.attr('href').replace(/^#/, ''),
//     options = $.deparam( href, true );


//     if ( key === 'layoutMode' && typeof changeLayoutMode === 'function' ) {
//       // changes in layout modes need extra logic
//       changeLayoutMode( $this, options )
//     } else {
//        hashOptions = value;
//        setIsotopeHash();
//     }

//     return false;
//   });

//   function defaultCheckboxState(){

//     options = $.deparam.fragment(window.location.hash, true);

//     if(!options['filter']){
//        jQuery('.option-set').find('input').each(function() {
//         jQuery(this).attr('checked','checked');
//         hashOptions += this.value + ',';
//         setIsotopeHash();
//       });
//     }

//   }

//   /*
//   * ensure checkboxes match hashOptions list
//   * check all boxes, if hashOptions list contains no filter
//   */
//   function checkboxHashState(){

//    if(hashOptions){

//       $('input[type=checkbox]').each(function () {
//         if(hashOptions.indexOf(this.value) >= 0 ){
//             this.checked = true;
//         }else{
//            this.checked = false;
//         }
//       });
//   }

//   }
//  });
// })(jQuery);

