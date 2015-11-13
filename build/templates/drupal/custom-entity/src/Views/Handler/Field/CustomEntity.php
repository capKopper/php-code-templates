<?php

/**
 * @file
 * Contains the basic %%ENTITY_LOWERCASE_NAME%% field handler.
 */

namespace Drupal\%%MACHINE_NAME%%\Views\Handler\Field;

use Drupal\%%MACHINE_NAME%%\Entity\%%ENTITY_CLASS_NAME%% as %%ENTITY_CLASS_ALIAS%%;

class %%ENTITY_CLASS_NAME%% extends \views_handler_field {

  /**
   * (@inheritdoc)
   */
  public function init(&$view, &$options) {
    parent::init($view, $options);

    if (!empty($this->options['link_to_entity'])) {
      $this->additional_fields['%%ENTITY_PRIMARY_KEY%%'] = '%%ENTITY_PRIMARY_KEY%%';
      $this->additional_fields['type'] = 'type';
    }
  }

  /**
   * (@inheritdoc)
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['link_to_entity'] = array('default' => FALSE);
    return $options;
  }

  /**
   * (@inheritdoc)
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['link_to_entity'] = array(
      '#title' => t("Link this field to the %%ENTITY_LOWERCASE_NAME%%'s view page"),
      '#description' => t('This will override any other link you have set.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_entity']),
    );
  }

  /**
   * Render whatever the data is as a link to the %%ENTITY_LOWERCASE_NAME%%.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  public function render_link($data, $values) {
    if (!empty($this->options['link_to_entity']) && $data !== NULL && $data !== '') {
      $%%ENTITY_PRIMARY_KEY%% = $this->get_value($values, '%%ENTITY_PRIMARY_KEY%%');
      $type = $this->get_value($values, 'type');

      if ($%%ENTITY_PRIMARY_KEY%% && $type) {
        $entity = entity_create('%%MACHINE_NAME%%', array('%%ENTITY_PRIMARY_KEY%%' => $%%ENTITY_PRIMARY_KEY%%, 'type' => $type));

        if ($entity && %%MACHINE_NAME%%_access('view', $entity)) {
          $this->options['alter']['make_link'] = TRUE;
          $this->options['alter']['path'] = "%%ENTITY_PATH%%/$%%ENTITY_PRIMARY_KEY%%";
        }
      }
    }

    return $data;
  }

  /**
   * (@inheritdoc)
   */
  public function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }

}
