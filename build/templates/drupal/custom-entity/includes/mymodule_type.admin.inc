<?php

/**
 * @file
 * %%ENTITY_TITLE%% type editing UI.
 */

use Drupal\%%MACHINE_NAME%%\Entity\%%ENTITY_TYPE_CLASS_NAME%% as %%ENTITY_TYPE_CLASS_ALIAS%%;

/**
 * Generates the %%ENTITY_LOWERCASE_NAME%% type editing form.
 * @see %%MACHINE_NAME%%_type_form_validate()
 * @see %%MACHINE_NAME%%_type_form_submit()
 */
function %%MACHINE_NAME%%_type_form($form, &$form_state, %%ENTITY_TYPE_CLASS_ALIAS%% $%%MACHINE_NAME%%_type, $op = 'edit') {
  if ($op == 'clone') {
    $%%MACHINE_NAME%%_type->label .= ' (cloned)';
    $%%MACHINE_NAME%%_type->type = '';
  }

  $form_state['%%MACHINE_NAME%%_type'] = $%%MACHINE_NAME%%_type;

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $%%MACHINE_NAME%%_type->label,
    '#description' => t('The human-readable name of this %%ENTITY_LOWERCASE_NAME%% type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  if (empty($%%MACHINE_NAME%%_type->type)) {
    $form['type'] = array(
      '#type' => 'machine_name',
      '#default_value' => '',
      '#maxlength' => 32,
      '#machine_name' => array(
        'exists' => '%%MACHINE_NAME%%_get_types',
        'source' => array('label'),
      ),
      '#description' => t('A unique machine-readable name for this %%ENTITY_LOWERCASE_NAME%% type. It must only contain lowercase letters, numbers, and underscores.'),
    );
  }
  else {
    $form['type'] = array(
      '#type' => 'value',
      '#value' => $%%MACHINE_NAME%%_type->type,
    );
  }

  if (module_exists('entity_translation')) {
    $form['multilingual'] = array(
      '#type' => 'radios',
      '#title' => t('Multilingual support'),
      '#description' => t('If <em>Entity translation</em> is enabled it will be possible to provide a different version of the same %%ENTITY_LOWERCASE_NAME%% for each available language.') . '<br />' . t('You can find more options in the <a href="!url">entity translation settings</a>.', array('!url' => url('admin/config/regional/entity_translation'))) . '<br />' . t('Existing %%ENTITY_TITLE_PLURAL%% will not be affected by changing this option.'),
      '#options' => array(
        0 => t('Disabled'),
        ENTITY_TRANSLATION_ENABLED => t('Enabled via <em>Entity translation</em>'),
      ),
      '#default_value' => variable_get('language_%%MACHINE_NAME%%_type_' . $%%MACHINE_NAME%%_type->type, 0),
    );
  }

  $form['actions'] = array(
    '#type' => 'actions',
    '#weight' => 40,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save %%ENTITY_LOWERCASE_NAME%% type'),
    '#submit' => array_merge($submit, array('%%MACHINE_NAME%%_type_form_submit')),
  );

  if (!empty($form_state['%%MACHINE_NAME%%_type']->type)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete %%ENTITY_LOWERCASE_NAME%% type'),
      '#suffix' => l(t('Cancel'), '%%ENTITY_TYPE_ADMIN_PATH%%'),
      '#submit' => array_merge($submit, array('%%MACHINE_NAME%%_type_form_submit_delete')),
      '#weight' => 45,
    );
  }
  else {
    $form['actions']['save_continue'] = array(
      '#type' => 'submit',
      '#value' => t('Save and add fields'),
      '#suffix' => l(t('Cancel'), '%%ENTITY_TYPE_ADMIN_PATH%%'),
      '#submit' => array_merge($submit, array('%%MACHINE_NAME%%_type_form_submit')),
      '#weight' => 45,
    );
  }

  $form['#validate'][] = '%%MACHINE_NAME%%_type_form_validate';

  return $form;
}

/**
 * Form validate handler; validate the %%ENTITY_LOWERCASE_NAME%% type form.
 *
 * @see %%MACHINE_NAME%%_type_form()
 * @see %%MACHINE_NAME%%_type_form_submit()
 */
function %%MACHINE_NAME%%_type_form_validate($form, &$form_state) {
  $%%MACHINE_NAME%%_type = $form_state['%%MACHINE_NAME%%_type'];

  // If saving a new %%ENTITY_LOWERCASE_NAME%% type, ensure it has a unique machine name.
  if (empty($%%MACHINE_NAME%%_type->type) && %%MACHINE_NAME%%_get_types($form_state['values']['type'])) {
    form_set_error('type', t('The machine name specified is already in use.'));
  }
}

/**
 * Form API submit callback for the type form.
 */
function %%MACHINE_NAME%%_type_form_submit(&$form, &$form_state) {
  $%%MACHINE_NAME%%_type = entity_ui_form_submit_build_entity($form, $form_state);
  $%%MACHINE_NAME%%_type->save();

  // Set the multingual value for the %%ENTITY_LOWERCASE_NAME%% type if entity translation is enabled.
  if (module_exists('entity_translation')) {
    variable_set('language_%%MACHINE_NAME%%_type_' . $%%MACHINE_NAME%%_type->type, $form_state['values']['multilingual']);
  }

  // Redirect based on the button clicked.
  drupal_set_message(t('%%ENTITY_TITLE%% type saved.'));

  if ($form_state['triggering_element']['#parents'][0] == 'save_continue') {
    $form_state['redirect'] = '%%ENTITY_TYPE_ADMIN_PATH%%/manage/' . strtr($%%MACHINE_NAME%%_type->type, '_', '-') . '/fields';
  }
  else {
    $form_state['redirect'] = '%%ENTITY_TYPE_ADMIN_PATH%%';
  }
}

/**
 * Form API submit callback for the delete button.
 */
function %%MACHINE_NAME%%_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = '%%ENTITY_TYPE_ADMIN_PATH%%/manage/' . $form_state['%%MACHINE_NAME%%_type']->type . '/delete';
}
