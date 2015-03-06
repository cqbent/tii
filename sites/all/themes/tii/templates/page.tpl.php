<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<div id="page">
    <div class="container">
  <header class="header" id="header" role="banner">

    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
    <?php endif; ?>

    <?php if ($site_name || $site_slogan): ?>
      <div class="header__name-and-slogan" id="name-and-slogan">
        <?php if ($site_name): ?>
          <h1 class="header__site-name" id="site-name">
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="header__site-link" rel="home"><span><?php print $site_name; ?></span></a>
          </h1>
        <?php endif; ?>

        <?php if ($site_slogan): ?>
          <div class="header__site-slogan" id="site-slogan"><?php print $site_slogan; ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>

    <?php if ($secondary_menu): ?>
      <nav class="header__secondary-menu" id="secondary-menu" role="navigation">
        <?php print theme('links__system_secondary_menu', array(
          'links' => $secondary_menu,
          'attributes' => array(
            'class' => array('links', 'inline', 'clearfix'),
          ),
          'heading' => array(
            'text' => $secondary_menu_heading,
            'level' => 'h2',
            'class' => array('element-invisible'),
          ),
        )); ?>
      </nav>
    <?php endif; ?>

    <?php print render($page['header']); ?>

  </header>

  <div id="main">

    <div id="content" class="column" role="main">
      <?php print render($page['highlighted']); ?>
      <?php print $breadcrumb; ?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>

    <div id="navigation">

      <?php if ($main_menu): ?>
        <nav id="main-menu" role="navigation" tabindex="-1">
          <?php
          // This code snippet is hard to modify. We recommend turning off the
          // "Main menu" on your sub-theme's settings form, deleting this PHP
          // code block, and, instead, using the "Menu block" module.
          // @see https://drupal.org/project/menu_block
          print theme('links__system_main_menu', array(
            'links' => $main_menu,
            'attributes' => array(
              'class' => array('links', 'inline', 'clearfix'),
            ),
            'heading' => array(
              'text' => t('Main menu'),
              'level' => 'h2',
              'class' => array('element-invisible'),
            ),
          )); ?>
        </nav>
      <?php endif; ?>

      <?php print render($page['navigation']); ?>

    </div>

    <?php
      // Render the sidebars to see if there's anything in them.
      $sidebar_first  = render($page['sidebar_first']);
      $sidebar_second = render($page['sidebar_second']);
    ?>

    <?php if ($sidebar_first || $sidebar_second): ?>
      <aside class="sidebars">
        <?php print $sidebar_first; ?>
        <?php print $sidebar_second; ?>
      </aside>
    <?php endif; ?>

  </div>

        <svg id="tii-line">
            <line x1="130" y1="100%" x2="130" y2="0" stroke-width="2" 
            stroke="#e5751f" transform="rotate(12)"/>
        </svg>
        
        <svg class="svg-defs">
            <defs>
                <clipPath id="imageclip" clipPathUnits="objectBoundingBox">
                    <polygon points=".15 0, 1 0, .85 1, 0 1" />
                </clipPath>
                <clipPath id="sliderclip">
                    <polygon points="75 0, 755 0, 680 298, 0 298" />
                </clipPath>
                <clipPath id="sliceclip">
                    <polygon points="75 0, 125 0, 75 298, 0 298" />
                </clipPath>
            
            </defs>
        </svg>
        
        <style>
            .field-type-image, .views-field-field-image, .views-field-field-slice-image {
                -webkit-shape-outside: polygon(15% 0, 100% 0, 85% 100%, 0 100%);
                -moz-shape-outside: polygon(15% 0, 100% 0, 85% 100%, 0 100%);
                shape-outside: polygon(15% 0, 100% 0, 85% 100%, 0 100%);
            }
            
            .field-type-image image {
                clip-path: url(#imageclip);
            }
            /*
            .views-field-field-image image {
                clip-path: url(#sliderclip);
            }
            .views-field-field-slice-image image {
                clip-path: url(#sliceclip);
            }
            .views-field-field-image {
                -webkit-shape-inside: polygon(15% 0, 100% 0, 85% 100%, 0 100%);
                -moz-shape-inside: polygon(15% 0, 100% 0, 85% 100%, 0 100%);
                shape-inside: polygon(15% 0, 100% 0, 85% 100%, 0 100%);

            }
            */
        </style>
        
    </div>

    <?php print render($page['footer']); ?>

</div>

<?php print render($page['bottom']); ?>

<?php
if ($is_front) {
    ?>
    <script>
    jQuery(document).ready(function($) {
        $(".slider-list").zAccordion({
            tabWidth: 50,
            speed: 650,
            auto: false,
            slideClass: 'slider',
            animationStart: function () {
                $('.slider-list').find('li.slider-open .views-field-field-slice-image').css('display', 'none');
                $('.slider-list').find('li.slider-open .views-field-title, li.slider-open .views-field-field-image').css('display','block');
            },
            animationComplete: function () {
                $('.slider-list').find('li.slider-closed .views-field-title, li.slider-closed .views-field-field-image').fadeOut();
                $('.slider-list').find('li.slider-closed .views-field-field-slice-image').fadeIn();
            },
            width: 950,
            height: 325
        });
    });
    </script>
    <?php
}
?>