<?php
/**
 * @file
 * Defines the extra fields of %%ENTITY_LOWERCASE_NAME%% entity.
 */

namespace Drupal\%%MACHINE_NAME%%\Entity\ExtraFields;

class %%ENTITY_CLASS_NAME%% implements \EntityExtraFieldsControllerInterface {

  /**
   * Implements EntityExtraFieldsControllerInterface::fieldExtraFields().
   */
  public function fieldExtraFields() {
    $extra = [];

    foreach (%%MACHINE_NAME%%_get_types() as $type => $info) {
      $extra['%%MACHINE_NAME%%'][$type] = array(
        'form' => array(
          'label' => array(
            'label' => t('Label'),
            'description' => t('%%ENTITY_TITLE%% label form element'),
            'weight' => -5,
          ),
          'status' => array(
            'label' => t('Status'),
            'description' => t('%%ENTITY_TITLE%% status form element'),
            'weight' => 35,
          ),
        ),
        'display' => array(
          'label' => array(
            'label' => t('Label'),
            'description' => t('%%ENTITY_TITLE%% label'),
            'weight' => -5,
          ),
          'status' => array(
            'label' => t('Status'),
            'description' => t('Whether the %%ENTITY_TITLE%% is active or disabled'),
            'weight' => 5,
          ),
        ),
      );
    }

    return $extra;
  }

}
