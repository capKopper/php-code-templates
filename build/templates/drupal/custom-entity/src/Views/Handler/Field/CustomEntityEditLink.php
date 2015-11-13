<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */

namespace Drupal\%%MACHINE_NAME%%\Views\Handler\Field;

use Drupal\%%MACHINE_NAME%%\Entity\%%ENTITY_CLASS_NAME%% as %%ENTITY_CLASS_ALIAS%%;

class %%ENTITY_CLASS_NAME%%EditLink extends %%ENTITY_CLASS_NAME%%Link {

  /**
   * (@inheritdoc)
   */
  protected $op = 'edit';

  /**
   * (@inheritdoc)
   */
  protected function operation_uri(%%ENTITY_CLASS_ALIAS%% $%%MACHINE_NAME%%) {
    return "%%ENTITY_ADMIN_PATH%%/manage/$%%MACHINE_NAME%%->%%ENTITY_PRIMARY_KEY%%/edit";
  }

  /**
   * (@inheritdoc)
   */
  protected function operation_default_title() {
    return t('edit');
  }

}
