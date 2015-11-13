<?php
/**
 * @file
 *
 */

namespace Drupal\%%MACHINE_NAME%%\Entity\UIController;

/**
 * UI controller.
 */
class %%ENTITY_TYPE_CLASS_NAME%% extends \EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['title'] = '%%ENTITY_TITLE%% types';
    $items[$this->path]['description'] = 'Manage %%ENTITY_LOWERCASE_NAME%% entity types, including adding and removing fields and the display of fields.';
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    return $items;
  }

}
