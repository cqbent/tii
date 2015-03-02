<?php
/**
 * @file
 * tii_research.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tii_research_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create research content'.
  $permissions['create research content'] = array(
    'name' => 'create research content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any research content'.
  $permissions['delete any research content'] = array(
    'name' => 'delete any research content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own research content'.
  $permissions['delete own research content'] = array(
    'name' => 'delete own research content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in research'.
  $permissions['delete terms in research'] = array(
    'name' => 'delete terms in research',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any research content'.
  $permissions['edit any research content'] = array(
    'name' => 'edit any research content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own research content'.
  $permissions['edit own research content'] = array(
    'name' => 'edit own research content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in research'.
  $permissions['edit terms in research'] = array(
    'name' => 'edit terms in research',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
