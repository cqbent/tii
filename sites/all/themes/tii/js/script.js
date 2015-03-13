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

    
    $(document).ready(function() {
        console.log('this');
        if (typeof zAccordian == 'function') {
            
            $(".slider-list").zAccordion({
                tabWidth: 50,
                speed: 650,
                slideClass: 'slider',
                animationStart: function () {
                    //$('.slider-list').find('li.slider-open div').css('display', 'none');
                    //$('.slider-list').find('li.slider-previous div').css('display', 'none');
                },
                animationComplete: function () {
                    //$('.slider-list').find('li div').fadeIn(600);
                },
                width: 905,
                height: 298
            });
            
        }
        // if title in ckeditor image then create caption format
        $('.node .field-name-body img').each(function(index, element) {
            if ($(this).attr('title')) {
                $(this)
                    .wrap('<div class="nbimage" style="float:'+$(this).css('float')+'"></div>')
                    .after('<div class="imgtitle">'+$(this).attr('title')+'</div><div class="imgcaption">'+$(this).attr('alt')+'</div>');
            }
            else {
                //$(this).wrap('<div class="image></div>');
            }
        });
        
        $('.steering-committee-list li').click(function() {
            if ($(this).hasClass('active')) {
                $(this).removeClass('active');
            }
            else {
                $(this).addClass('active');
            }
        });
        
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
