/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {

    // if image added in ckeditor then look for 
    $('.node .field-name-body img').each(function(index, element) {
        $(this)
            .wrap('<div class="nbimage" style="float:'+$(this).css('float')+'"></div>')
            .after('<div class="imgtitle">'+$(this).attr('title')+'</div><div class="imgcaption">'+$(this).attr('alt')+'</div>');
    });
    
    $(document).ready(function() {
        if (typeof zAccordian == 'function') {
            
        }
        
        
        /*
         * for each slanted image:
         *  get image height
         *  get slant width based on tangent(deg) * image height
         *  set margin to -slant width
         *  set image width to 2 * slant width
         */
        /*
        $('.field-type-image').each(function() {
            var ih = $(this).height();
            var img = $(this).find('img');
            var slant = ih * -(getTanDeg(15));
            var w_extra = slant * 2;
            //$(this).find('img').css('margin-left',slant);
            //$(this).find('img').css('width','calc(100% + '+w_extra+')');
            //alert(getTanDeg(15));
        });
        */
    });
    
    


  }
};

function getTanDeg(deg) {
    var rad = deg * Math.PI/180;
    return Math.tan(rad);
}

})(jQuery, Drupal, this, this.document);
