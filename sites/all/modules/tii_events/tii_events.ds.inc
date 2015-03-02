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
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_event_thumbnail_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'field_event_subtitle',
        3 => 'field_event_speaker_host',
        4 => 'field_event_date',
        5 => 'field_event_location',
      ),
    ),
    'fields' => array(
      'field_event_thumbnail_image' => 'left',
      'title' => 'right',
      'field_event_subtitle' => 'right',
      'field_event_speaker_host' => 'right',
      'field_event_date' => 'right',
      'field_event_location' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
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
