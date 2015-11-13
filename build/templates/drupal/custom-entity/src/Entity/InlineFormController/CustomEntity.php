<?php
/**
 * @file
 * Defines the inline entity form controller for Model Entity.
 */

namespace Drupal\%%MACHINE_NAME%%\Entity\InlineFormController;

class %%ENTITY_CLASS_NAME%% extends \EntityInlineEntityFormController {

  /**
   * Overrides EntityInlineEntityFormController::labels().
   */
  public function labels() {
    return array(
      'singular' => t('%%ENTITY_TITLE%%'),
      'plural' => t('%%ENTITY_TITLE_PLURAL%%'),
    );
  }

  /**
   * Overrides EntityInlineEntityFormController::entityForm().
   */
  public function entityForm($entity_form, &$form_state) {
    module_load_include('inc', '%%MACHINE_NAME%%', 'includes/%%MACHINE_NAME%%.admin');
    return %%MACHINE_NAME%%_form($entity_form, $form_state, $entity_form['#entity']);
  }

}
