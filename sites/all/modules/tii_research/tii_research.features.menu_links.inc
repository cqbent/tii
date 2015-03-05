<?php
/**
 * @file
 * tii_research.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function tii_research_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_faculty-research:research/faculty-research
  $menu_links['main-menu_faculty-research:research/faculty-research'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'research/faculty-research',
    'router_path' => 'research/faculty-research',
    'link_title' => 'Faculty Research',
    'options' => array(
      'identifier' => 'main-menu_faculty-research:research/faculty-research',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_research:node/3',
  );
  // Exported menu link: main-menu_research:node/3
  $menu_links['main-menu_research:node/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Research',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_research:node/3',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: navigation_research:node/add/research
  $menu_links['navigation_research:node/add/research'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/research',
    'router_path' => 'node/add/research',
    'link_title' => 'Research',
    'options' => array(
      'attributes' => array(
        'title' => 'Research content type',
      ),
      'identifier' => 'navigation_research:node/add/research',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Faculty Research');
  t('Research');


  return $menu_links;
}
