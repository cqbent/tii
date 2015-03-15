<?php
/**
 * @file
 * tii_share.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tii_share_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sharethis_display';
  $context->description = '';
  $context->tag = 'sharethis display';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'events' => 'events',
        'news_article' => 'news_article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'sharethis-sharethis_block' => array(
          'module' => 'sharethis',
          'delta' => 'sharethis_block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('sharethis display');
  $export['sharethis_display'] = $context;

  return $export;
}
