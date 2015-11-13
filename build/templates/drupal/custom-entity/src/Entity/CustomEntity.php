<?php
/**
 * @file
 *
 */

namespace Drupal\%%MACHINE_NAME%%\Entity;

/**
 * The class used for %%ENTITY_LOWERCASE_NAME%% entities
 */
class %%ENTITY_CLASS_NAME%% extends \Entity {

  /**
   * The user ID who created this %%ENTITY_LOWERCASE_NAME%%.
   *
   * @var int
   */
  public $uid;

  /**
   * The label of this %%ENTITY_LOWERCASE_NAME%%.
   *
   * @var string
   */
  public $label;

  /**
   * Class constructor.
   */
  public function __construct($values = array()) {
    parent::__construct($values, '%%MACHINE_NAME%%');
  }

  /**
   * Defines the default entity label.
   */
  protected function defaultLabel() {
    return $this->label;
  }

  /**
   * Defines the default entity URI.
   */
  protected function defaultUri() {
    return array('path' => '%%ENTITY_PATH%%/' . $this->%%ENTITY_PRIMARY_KEY%%);
  }

  /**
   * Returns the user who created this %%ENTITY_LOWERCASE_NAME%%.
   */
  public function user() {
    return user_load($this->uid);
  }

  /**
   * Sets a new user as author.
   *
   * @param $account
   *   The user account object or the user account id (uid).
   */
  public function setUser($account) {
    $this->uid = is_object($account) ? $account->uid : $account;
  }

}
