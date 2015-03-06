<?php
/**
 * @file
 * tii_homepage_features.features.inc
 */

/**
 * Implements hook_views_api().
 */
function tii_homepage_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tii_homepage_features_node_info() {
  $items = array(
    'homepage_features' => array(
      'name' => t('Homepage Features'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
