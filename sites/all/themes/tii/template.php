<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function tii_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  tii_preprocess_html($variables, $hook);
  tii_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function tii_preprocess_html(&$variables, $hook) {
    // add class to body depending on whether page is a main or sub section
    $menutrail = menu_get_active_trail(); // if a child in the menu system
    $current_path = current_path();
    $current_path_alias = drupal_get_path_alias( $current_path );
    $path_segments = explode("/", $current_path_alias);  // if has a path prefix
    //dsm($menutrail);
    if (count($menutrail) >= 3 || count($path_segments) >= 2) {
        $variables['classes_array'][] = 'subsection';
    }
    else {
        $variables['classes_array'][] = 'mainsection';
    }
    
    // facebook stuff: if news or event post then add thumbnail image url into header source
    if (isset($variables['page']['content']['system_main']['nodes'])) {
        $yy = reset($variables['page']['content']['system_main']['nodes']);
        if (isset($yy['field_image'])) {
            //$img = file_create_url($yy['field_image']['#items'][0]['uri']);
            $img = $yy['field_image']['#items'][0]['uri'];
        }
        if (isset($yy['field_event_thumbnail_image'])) {
            //$img = file_create_url($yy['field_event_thumbnail_image']['#items'][0]['uri']);
            $img = $yy['field_event_thumbnail_image']['#items'][0]['uri'];
        }
        if ($img) {
            $imgthumb = image_style_url('medium',$img);
            $element = array(
                '#tag' => 'meta',
                '#attributes' => array(
                    "property" => "og:image",
                    "content" => t($imgthumb),
                ),
            );
            drupal_add_html_head($element,'og_image');
            //dsm($imgthumb);
        }
    }
    //dsm($variables);
    

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}



// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function tii_preprocess_page(&$variables, $hook) {
    drupal_add_css('//maxcdn.bootstrapcdn.com/font-awesome/4.2.0/css/font-awesome.min.css', 'external');
    if (drupal_is_front_page()) {
        drupal_add_js(drupal_get_path('theme', 'tii') .'/js/jquery.zaccordion.js', 'file');
        drupal_add_js(drupal_get_path('theme', 'tii') .'/js/jquery.slides.js', 'file');
    }
}
// */

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
/* -- Delete this line if you want to use this function
function tii_preprocess_node(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // tii_preprocess_node_page() or tii_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function tii_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function tii_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function tii_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
 * 
// */

function tii_preprocess_field(&$vars) {
    // if is field image then add svg wrapper; alter
    //dsm($vars);
}



function tii_image($variables) {
  //dsm($variables);
  $attributes = $variables['attributes'];
  $attributes['src'] = file_create_url($variables['path']);

  foreach (array('width', 'height', 'alt', 'title') as $key) {
    if (isset($variables[$key])) {
      $attributes[$key] = $variables[$key];
    }
  }
  /*
  if (isset($variables['style_name']) && (strstr($variables['style_name'],'tii_'))) {
      $img = '<svg width="'.$attributes['width'].'" height="'.$attributes['height'].'">
          <image xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="'.$attributes['src'].'" width="'.$attributes['width'].'" height="'.$attributes['height'].'"></image>
          </svg>';
  }
  else {
   * 
   */
      $img = '<img' . drupal_attributes($attributes) . ' />';
  //}
  return $img;
}



