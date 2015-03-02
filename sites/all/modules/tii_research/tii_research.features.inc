<?php
/**
 * @file
 * tii_research.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tii_research_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function tii_research_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tii_research_node_info() {
  $items = array(
    'research' => array(
      'name' => t('Research'),
      'base' => 'node_content',
      'description' => t('Research content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
