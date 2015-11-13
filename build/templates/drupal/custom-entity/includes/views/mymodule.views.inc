<?php

/**
 * @file
 * Integrate %%MODULE_TITLE%% module with Views.
 */

/**
 * Implements hook_views_data_alter()
 */
function %%MACHINE_NAME%%_views_data_alter(&$data) {
  $data['%%MACHINE_NAME%%']['%%ENTITY_PRIMARY_KEY%%']['field'] = array(
    'handler' => 'Drupal\\%%MACHINE_NAME%%\\Views\\Handler\\Field\\%%ENTITY_CLASS_NAME%%',
    'click sortable' => TRUE,
  );

  $data['%%MACHINE_NAME%%']['label']['field'] = array(
    'handler' => 'Drupal\\%%MACHINE_NAME%%\\Views\\Handler\\Field\\%%ENTITY_CLASS_NAME%%',
    'click sortable' => TRUE,
  );

  $data['%%MACHINE_NAME%%']['uid'] = array(
    'title' => t('Creator'),
    'help' => t('Relate a %%ENTITY_LOWERCASE_NAME%% to the user who created it.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('%%ENTITY_TITLE%% creator'),
    ),
  );

  $data['%%MACHINE_NAME%%']['link_%%MACHINE_NAME%%'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the %%ENTITY_LOWERCASE_NAME%%.'),
      'handler' => 'Drupal\\%%MACHINE_NAME%%\\Views\\Handler\\Field\\%%ENTITY_CLASS_NAME%%Link',
    ),
  );

  $data['%%MACHINE_NAME%%']['edit_%%MACHINE_NAME%%'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the %%ENTITY_LOWERCASE_NAME%%.'),
      'handler' => 'Drupal\\%%MACHINE_NAME%%\\Views\\Handler\\Field\\%%ENTITY_CLASS_NAME%%EditLink',
    ),
  );

  $data['%%MACHINE_NAME%%']['delete_%%MACHINE_NAME%%'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the %%ENTITY_LOWERCASE_NAME%%.'),
      'handler' => 'Drupal\\%%MACHINE_NAME%%\\Views\\Handler\\Field\\%%ENTITY_CLASS_NAME%%DeleteLink',
    ),
  );

  $data['%%MACHINE_NAME%%']['clone_%%MACHINE_NAME%%'] = array(
    'field' => array(
      'title' => t('Clone Link'),
      'help' => t('Provide a link to clone the %%ENTITY_LOWERCASE_NAME%%.'),
      'handler' => 'Drupal\\%%MACHINE_NAME%%\\Views\\Handler\\Field\\%%ENTITY_CLASS_NAME%%CloneLink',
    ),
  );

  $data['%%MACHINE_NAME%%']['export_%%MACHINE_NAME%%'] = array(
    'field' => array(
      'title' => t('Export Link'),
      'help' => t('Provide a link to export the %%ENTITY_LOWERCASE_NAME%%.'),
      'handler' => 'Drupal\\%%MACHINE_NAME%%\\Views\\Handler\\Field\\%%ENTITY_CLASS_NAME%%ExportLink',
    ),
  );
}
