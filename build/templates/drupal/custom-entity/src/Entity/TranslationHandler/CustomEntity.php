<?php
/**
 * @file
 * Translation handler for the %%ENTITY_LOWERCASE_NAME%% entity.
 */

namespace Drupal\%%MACHINE_NAME%%\Entity\TranslationHandler;

/**
 * %%ENTITY_TITLE%% translation handler.
 *
 * @see %%MACHINE_NAME%%_entity_info()
 */
class %%ENTITY_CLASS_NAME%% extends \EntityTranslationDefaultHandler {

  public function __construct($entity_type, $entity_info, $entity) {
    parent::__construct('%%MACHINE_NAME%%', $entity_info, $entity);
  }

  /**
   * Checks whether the current user has access to this %%ENTITY_LOWERCASE_NAME%%.
   */
  public function getAccess($op) {
    return %%MACHINE_NAME%%_access($op, $this->entity);
  }

  /**
   * @see EntityTranslationDefaultHandler::entityFormTitle()
   */
  protected function entityFormTitle() {
    return %%MACHINE_NAME%%_page_title($this->entity);
  }

  /**
   * Returns whether the entity is active (TRUE) or disabled (FALSE).
   */
  protected function getStatus() {
    return (boolean) $this->entity->status;
  }

}
