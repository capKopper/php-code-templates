<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying links to entities
 * as fields.
 */

namespace Drupal\%%MACHINE_NAME%%\Views\Handler\Field;

use Drupal\%%MACHINE_NAME%%\Entity\%%ENTITY_CLASS_NAME%% as %%ENTITY_CLASS_ALIAS%%;

/**
 * Field handler to present a link to a %%ENTITY_LOWERCASE_NAME%% operation.
 *
 * @ingroup views_field_handlers
 */
class %%ENTITY_CLASS_NAME%%Link extends \views_handler_field {

  /**
   * The current operation.
   *
   * @var string
   */
  protected $op = 'view';

  /**
   * The class constructor.
   *
   * (@inheritdoc)
   */
  public function construct() {
    parent::construct();

    $this->additional_fields['%%ENTITY_PRIMARY_KEY%%'] = '%%ENTITY_PRIMARY_KEY%%';
    $this->additional_fields['type'] = 'type';
  }

  /**
   * (@inheritdoc)
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  /**
   * (@inheritdoc)
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );

    // The path is set by render_link function so don't allow to set it.
    $form['alter']['path'] = array('#access' => FALSE);
    $form['alter']['external'] = array('#access' => FALSE);
  }

  /**
   * (@inheritdoc)
   */
  public function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * (@inheritdoc)
   */
  public function render($values) {
    $%%ENTITY_PRIMARY_KEY%% = $this->get_value($values, '%%ENTITY_PRIMARY_KEY%%');
    $type = $this->get_value($values, 'type');

    if ($%%ENTITY_PRIMARY_KEY%% && $type) {
      $data = array(
        '%%ENTITY_PRIMARY_KEY%%' => $%%ENTITY_PRIMARY_KEY%%,
        'type' => $type,
      );

      if ($entity = entity_create('%%MACHINE_NAME%%', $data)) {
        return $this->render_link($entity, $values);
      }
    }
  }

  /**
   * (@inheritdoc)
   */
  public function render_link(%%ENTITY_CLASS_ALIAS%% $%%MACHINE_NAME%%, $values) {
    if (%%MACHINE_NAME%%_access($this->op, $%%MACHINE_NAME%%)) {
      $%%ENTITY_PRIMARY_KEY%% = $values->{$this->aliases['%%ENTITY_PRIMARY_KEY%%']};

      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = $this->operation_uri($%%MACHINE_NAME%%);
      $text = !empty($this->options['text']) ? $this->options['text'] : $this->operation_default_title();
      return $text;
    }
  }

  /**
   * Get the target URI for the current operation.
   *
   * @return string
   */
  protected function operation_uri(%%ENTITY_CLASS_ALIAS%% $%%MACHINE_NAME%%) {
    return "%%ENTITY_PATH%%/$%%MACHINE_NAME%%->%%ENTITY_PRIMARY_KEY%%";
  }

  /**
   * Get the link default title for the current operation.
   *
   * @return string
   */
  protected function operation_default_title() {
    return t('view');
  }

}
