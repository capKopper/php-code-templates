<?php
/**
 * @file
 * Definition of the node plugin.
 */

$plugin = array(
  // _ctools_registry_files_alter() will never find the class file and claim for
  // missing plugin class file, but we don't care of that since the file is
  // loaded using PSR-4.
  'handler' => 'Drupal\\%%MACHINE_NAME%%\\Panelizer\\%%ENTITY_CLASS_NAME%%',
  'entity path' => '%%ENTITY_PATH%%/%%%MACHINE_NAME%%',
  'uses page manager' => TRUE,
  'hooks' => array(
    'menu' => TRUE,
    'admin_paths' => TRUE,
    'permission' => TRUE,
    'panelizer_defaults' => TRUE,
    'default_page_manager_handlers' => TRUE,
    'form_alter' => TRUE,
    //'page_alter' => TRUE,
    'views_data_alter' => TRUE,
  ),
);
