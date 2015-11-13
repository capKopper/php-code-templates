<?php
/**
 * @file
 *
 */

namespace Drupal\%%MACHINE_NAME%%\Entity;

/**
 * The class used for %%ENTITY_LOWERCASE_NAME%% type entities
 */
class %%ENTITY_TYPE_CLASS_NAME%% extends \Entity {

  /**
   * The %%ENTITY_LOWERCASE_NAME%% type (bundle).
   *
   * @var mixed
   */
  public $type;

  /**
   * The %%ENTITY_LOWERCASE_NAME%% label.
   *
   * @var mixed
   */
  public $label;

  /**
   * Class constructor.
   */
  public function __construct($values = array()) {
    parent::__construct($values, '%%MACHINE_NAME%%_type');
  }

}
