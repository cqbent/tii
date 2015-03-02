<?php
/**
 * @file
 * tii_news.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function tii_news_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_news:node/5
  $menu_links['main-menu_news:node/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/5',
    'router_path' => 'node/%',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_news:node/5',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_news-article:node/add/news-article
  $menu_links['navigation_news-article:node/add/news-article'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/news-article',
    'router_path' => 'node/add/news-article',
    'link_title' => 'News Article',
    'options' => array(
      'attributes' => array(
        'title' => 'Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.',
      ),
      'identifier' => 'navigation_news-article:node/add/news-article',
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
  // Exported menu link: navigation_news:news
  $menu_links['navigation_news:news'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'news',
    'router_path' => 'news',
    'link_title' => 'News',
    'options' => array(
      'identifier' => 'navigation_news:news',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('News');
  t('News Article');


  return $menu_links;
}
