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
        var w_height = $(window).height();
        var w_width = $(window).width();
        if ($('body').hasClass('front') && w_width > 779) {
            createSliderNav();
            $(".slider-list").zAccordion({
                tabWidth: '6%',
                speed: 650,
                auto: true,
                slideClass: 'slider',
                animationStart: function () {
                    $('.slider-list').find('li.slider-open .views-field-field-slice-image').css('display', 'none');
                    $('.slider-list').find('li.slider-open .views-field-title, li.slider-open .views-field-field-image').css('display','block');
                    var s_index = $('.slider-list').find('li.slider-open').index();
                    //$('.slider-nav li:nth-child('+s_index+')');
                    activateNav(s_index + 1);
                    //console.log(s_index);
                },
                animationComplete: function () {
                    $('.slider-list').find('li.slider-closed .views-field-title, li.slider-closed .views-field-field-image').fadeOut();
                    $('.slider-list').find('li.slider-closed .views-field-field-slice-image').fadeIn();
                },
                buildComplete: function() {
                    //createSliderNav();
                },
                width: '100%',
                height: 325
            });
        }
        if ($('body').hasClass('front') && w_width < 780) {
            $('.slider-list').slidesjs({
                width: 700,
                height: 325,
                navigation: {
                    effect: "fade"
                },
                pagination: {
                    effect: "fade"
                },
                effect: {
                    fade: {
                        speed: 400
                    }
                }
            });
        }
        function createSliderNav() {
            // build nav controls
            var s_count = $('.slider-list li').length;
            var s_controls = ''; var active_init = ''
            for (c = 0; c < s_count; c++) {
                if (c == 0) { active_init = ' class="active"'; }
                else { active_init = ''; }
                s_controls += '<li'+active_init+'><span>'+c+'</span></li>';
            }
            s_controls += '<li class="play-pause"><span></span></li>';
            $('.accordian-slider').append('<ul class="slider-nav">'+s_controls+'</ul>');
            $(".slider-nav li:not(.play-pause)").click(function() {
                $(".slider-list").zAccordion("stop");
                $(".slider-nav li.play-pause").addClass('paused');
                $(".slider-list").zAccordion("trigger", $(this).index());
            });
            $(".slider-nav li.play-pause").click(function() {
                if ($(this).hasClass('paused')) {
                    $(".slider-list").zAccordion("start");
                    $(this).removeClass('paused');
                }
                else {
                    $(".slider-list").zAccordion("stop");
                    $(this).addClass('paused');
                }
            });
        }
        function activateNav(i) {
            $('.slider-nav li').removeClass("active");
            $('.slider-nav li:nth-child('+i+')').addClass('active');
            console.log('xx: '+i);
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
        
         /* mobile menu - add action */
        $('.block-menu-block').click(function() {
            if ($('.block-menu-block').hasClass('menu-active')) {
                $('.block-menu-block').removeClass('menu-active');
            }
            else {
                $('.block-menu-block').addClass('menu-active');
            }
        });
        
        /* extend page to bottom of screen */
        c_height = $('#page > .container').height()
        f_height = w_height - c_height;
        $('#footer').css('min-height', f_height);
        console.log($('#footer').height());
        
        /* set position of h1 tag depending on how many lines it has */
        var h_title = $('h1.page__title').height();
        console.log(h_title);
        if (h_title > 110) {
            $('h1.page__title').addClass('three');
        }
        else if (h_title > 55) {
            $('h1.page__title').addClass('two');
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
