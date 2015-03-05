<?php
/**
 * @file
 * tii_events.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function tii_events_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|events|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'events';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'node_link' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'View event information',
        'wrapper' => '',
        'class' => '',
      ),
    ),
  );
  $export['node|events|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function tii_events_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|events|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'events';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_event_thumbnail_image',
        1 => 'title',
        2 => 'field_event_subtitle',
        3 => 'field_event_speaker_host',
        4 => 'field_event_location',
        5 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_event_thumbnail_image' => 'ds_content',
      'title' => 'ds_content',
      'field_event_subtitle' => 'ds_content',
      'field_event_speaker_host' => 'ds_content',
      'field_event_location' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|events|teaser'] = $ds_layout;

  return $export;
}
