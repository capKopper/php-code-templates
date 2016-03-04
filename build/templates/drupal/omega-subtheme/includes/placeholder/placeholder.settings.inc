<?php

/**
 * @file
 * Contains the theme settings form elements for the placeholder extension.
 */

/**
 * Implements hook_extension_EXTENSION_theme_settings_form_alter().
 */
function %%MACHINE_NAME%%_extension_placeholder_settings_form($element, &$form, $form_state) {
  $options = drupal_map_assoc(array('textfield', 'textarea', 'password'));
  $default = omega_theme_get_setting('%%MACHINE_NAME%%_placeholder_elements', $options);

  $element['%%MACHINE_NAME%%_placeholder_elements'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Elements'),
    '#description' => t('Select elements whose title should be converted to placeholder.'),
    '#options' => $options,
    '#default_value' => array_filter($default),
  );

  return $element;
}
