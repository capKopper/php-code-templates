<?php
/**
 * @file
 *
 */

namespace Drupal\%%MACHINE_NAME%%\Entity\APIController;

/**
 * The Controller for %%ENTITY_LOWERCASE_NAME%% type entities
 */
class %%ENTITY_TYPE_CLASS_NAME%% extends \EntityAPIControllerExportable {

  /**
   * Create a %%ENTITY_LOWERCASE_NAME%% type.
   *
   * @param array $values
   *   An array containing the possible values.
   *
   * @return object
   *   A type object with all default fields initialized.
   */
  public function create(array $values = array()) {
    // Add values that are specific to our %%ENTITY_LOWERCASE_NAME%%.
    $values += array(
      'id' => '',
    );
    $entity_type = parent::create($values);

    return $entity_type;
  }

  /**
   * Overridden to clear cache.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $return = parent::save($entity, $transaction);

    // Reset the %%ENTITY_LOWERCASE_NAME%% type cache. We need to do this first so
    // menu changes pick up our new type.
    %%MACHINE_NAME%%_type_cache_reset();
    // Clear field info caches such that any changes to extra fields get
    // reflected.
    field_info_cache_clear();

    return $return;
  }

  /**
   * Overridden to clear cache.
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    parent::delete($ids, $transaction);

    if ($ids) {
      // Clear field info caches such that any changes to extra fields get
      // reflected.
      field_info_cache_clear();

      %%MACHINE_NAME%%_type_cache_reset();
    }
  }

}
