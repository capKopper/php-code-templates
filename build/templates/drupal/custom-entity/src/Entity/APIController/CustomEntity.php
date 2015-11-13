<?php
/**
 * @file
 *
 */

namespace Drupal\%%MACHINE_NAME%%\Entity\APIController;

use Drupal\%%MACHINE_NAME%%\Entity\%%ENTITY_TYPE_CLASS_NAME%% as %%ENTITY_TYPE_CLASS_ALIAS%%;

/**
 * The Controller for Entityform entities
 */
class %%ENTITY_CLASS_NAME%% extends \EntityAPIController {

  /**
   * Create a %%ENTITY_LOWERCASE_NAME%%.
   *
   * @param array $values
   *   An array containing the possible values.
   *
   * @return object
   *   A object with all default fields initialized.
   */
  public function create(array $values = array()) {
    // Add values that are specific to our entity.
    $values += array(
      '%%ENTITY_PRIMARY_KEY%%' => '',
      'is_new' => TRUE,
      'label' => '',
      'uid' => '',
      'status' => 1,
      'created' => '',
      'changed' => '',
    );

    $entity = parent::create($values);

    return $entity;
  }

  /**
   * Saves a %%ENTITY_LOWERCASE_NAME%%.
   *
   * @param $entity
   *   The full %%ENTITY_LOWERCASE_NAME%% object to save.
   * @param $transaction
   *   An optional transaction object.
   *
   * @return
   *   SAVED_NEW or SAVED_UPDATED depending on the operation performed.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    global $user;

    // Hardcode the changed time.
    $entity->changed = REQUEST_TIME;

    if (empty($entity->{$this->idKey}) || !empty($entity->is_new)) {
      // Set the creation timestamp if not set, for new entities.
      if (empty($entity->created)) {
        $entity->created = REQUEST_TIME;
      }
    }
    else {
      // Otherwise if the entity is not new but comes from an entity_create()
      // or similar function call that initializes the created timestamp and uid
      // value to empty strings, unset them to prevent destroying existing data
      // in those properties on update.
      if ($entity->created === '') {
        unset($entity->created);
      }
      if ($entity->uid === '') {
        unset($entity->uid);
      }
    }

    // Determine if we will be inserting a new entity.
    $entity->is_new = empty($entity->{$this->idKey});

    return parent::save($entity, $transaction);
  }

  /**
   * Builds a structured array representing the entity's content.
   *
   * The content built for the entity will vary depending on the $view_mode
   * parameter.
   *
   * @param $entity Drupal\%%MACHINE_NAME%%\Entity\%%ENTITY_CLASS_NAME%%
   *   An entity object.
   * @param $view_mode
   *   View mode, e.g. 'full', 'teaser'...
   * @param $langcode
   *   (optional) A language code to use for rendering. Defaults to the global
   *   content language of the current request.
   * @return
   *   The renderable array.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $content['title'] = array(
      '#type' => 'item',
      '#title' => t('Label'),
      '#markup' => check_plain($entity->label),
    );

    $statuses = %%MACHINE_NAME%%_status_options_list();

    $content['status'] = array(
      '#type' => 'item',
      '#title' => t('Status'),
      '#markup' => $statuses[(int) (isset($entity->status) && (bool) $entity->status)],
    );

    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }

}
