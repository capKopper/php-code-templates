<?php

/**
 * @file
 * %%MACHINE_NAME%% editing UI.
 */

use Drupal\%%MACHINE_NAME%%\Entity\%%ENTITY_CLASS_NAME%% as %%ENTITY_CLASS_ALIAS%%;

/**
 * Form callback: create or edit a %%ENTITY_LOWERCASE_NAME%%.
 */
function %%MACHINE_NAME%%_form($form, &$form_state, %%ENTITY_CLASS_ALIAS%% $%%MACHINE_NAME%%, $op = 'edit', $entity_type) {
  // Add the breadcrumb for the form's location.
  %%MACHINE_NAME%%_set_breadcrumb();

  // Add the default field elements.
  $form['label'] = array(
    '#type' => 'textfield',
    '#title' => t('%%ENTITY_TITLE%% Label'),
    '#default_value' => isset($%%MACHINE_NAME%%->label) ? $%%MACHINE_NAME%%->label : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  // Add the field related form elements.
  $form_state['%%MACHINE_NAME%%'] = $%%MACHINE_NAME%%;

  if (empty($langcode)) {
    $langcode = LANGUAGE_NONE;
  }

  field_attach_form('%%MACHINE_NAME%%', $%%MACHINE_NAME%%, $form, $form_state, $langcode);

  $form['status'] = array(
    '#type' => 'radios',
    '#title' => t('Status'),
    '#options' => array(
      '1' => t('Active'),
      '0' => t('Disabled'),
    ),
    '#default_value' => $%%MACHINE_NAME%%->status,
    '#required' => TRUE,
    '#weight' => 35,
  );

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // Simply use default language
  $form['language'] = array(
    '#type' => 'value',
    '#value' => $langcode,
  );

  // We add the form #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save %%ENTITY_LOWERCASE_NAME%%'),
    '#submit' => $submit + array('%%MACHINE_NAME%%_edit_form_submit'),
  );

  if (!empty($%%MACHINE_NAME%%->label)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete %%ENTITY_LOWERCASE_NAME%%'),
      '#suffix' => l(t('Cancel'), '%%ENTITY_ADMIN_PATH%%'),
      '#submit' => $submit + array('%%MACHINE_NAME%%_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'] = array('%%MACHINE_NAME%%_edit_form_validate');

  return $form;
}

/**
 * Form API validate callback for the %%ENTITY_LOWERCASE_NAME%% form.
 */
function %%MACHINE_NAME%%_edit_form_validate(&$form, &$form_state) {
  $%%MACHINE_NAME%% = $form_state['%%MACHINE_NAME%%'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('%%MACHINE_NAME%%', $%%MACHINE_NAME%%, $form, $form_state);
}

/**
 * Form API submit callback for the %%ENTITY_LOWERCASE_NAME%% form.
 */
function %%MACHINE_NAME%%_edit_form_submit(&$form, &$form_state) {
  global $user;

  // Save the entity and go back to the list of %%ENTITY_TITLE_PLURAL%%.
  $%%MACHINE_NAME%% = entity_ui_controller('%%MACHINE_NAME%%')->entityFormSubmitBuildEntity($form, $form_state);

  // Save default parameters back into the $%%MACHINE_NAME%% object.
  $%%MACHINE_NAME%%->label = $form_state['values']['label'];
  $%%MACHINE_NAME%%->status = $form_state['values']['status'];
  $%%MACHINE_NAME%%->language = $form_state['values']['language'];

  // Set the %%ENTITY_LOWERCASE_NAME%%'s uid if it's being created at this time.
  if (empty($%%MACHINE_NAME%%->%%ENTITY_PRIMARY_KEY%%)) {
    $%%MACHINE_NAME%%->uid = $user->uid;
  }

  // Notify field widgets.
  field_attach_submit('%%MACHINE_NAME%%', $%%MACHINE_NAME%%, $form, $form_state);

  // Save the $%%MACHINE_NAME%%.
  $%%MACHINE_NAME%%->save();

  // Send feedback message to the user.
  drupal_set_message(t('%%ENTITY_TITLE%% @label saved.', array('@label' => $%%MACHINE_NAME%%->label)));

  $form_state['redirect'] = '%%ENTITY_ADMIN_PATH%%';
}

/**
 * Form API submit callback for the delete button.
 */
function %%MACHINE_NAME%%_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = '%%ENTITY_ADMIN_PATH%%/manage/' . $form_state['%%MACHINE_NAME%%']->%%ENTITY_PRIMARY_KEY%% . '/delete';
}

/**
 * Sets the breadcrumb for administrative %%ENTITY_LOWERCASE_NAME%% pages.
 */
function %%MACHINE_NAME%%_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('%%ENTITY_TITLE%%'), '%%ENTITY_ADMIN_PATH%%'),
  );

  drupal_set_breadcrumb($breadcrumb);
}
