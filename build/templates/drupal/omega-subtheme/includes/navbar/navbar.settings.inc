<?php

/**
 * @file
 * Contains the theme settings form elements for the navbar extension.
 */

/**
 * Implements hook_extension_EXTENSION_theme_settings_form_alter().
 */
function %%MACHINE_NAME%%_extension_navbar_settings_form($element, &$form, $form_state) {
  $breakpoints = breakpoints_breakpoint_load_all_theme('%%MACHINE_NAME%%');

  if (!$breakpoints) {
    $element['missing_breakpoints'] = array(
      '#markup' => t('There are no breakpoints defined in the theme info file.'),
    );
  }
  elseif (!libraries_get_path('matchmedia')) {
    $element['missing_matchmedia'] = array(
      '#markup' => t('The matchmedia library is missing. You should download the theme library using the library make file.'),
    );
  }
  else {
    $options = array();

    foreach ($breakpoints as $breakpoint) {
      $options[$breakpoint->name] = $breakpoint->name;
    }

    $default = array_intersect($options, array('tiny', 'small', 'narrow'));
    $default = omega_theme_get_setting('%%MACHINE_NAME%%_navbar_breakpoints', $default);

    $element['%%MACHINE_NAME%%_navbar_breakpoints'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Mobile navigation breakpoints'),
      '#description' => t('Specify the breakpoints where the mobile menu is active'),
      '#options' => $options,
      '#default_value' => array_filter($default),
    );

    $element['%%MACHINE_NAME%%_navbar_wrapper'] = array(
      '#type' => 'textfield',
      '#title' => t('Navigation bar wrapper'),
      '#description' => t('Specify a valid jQuery selector that points to the navigation bar wrapper.'),
      '#default_value' => omega_theme_get_setting('%%MACHINE_NAME%%_navbar_wrapper', '.l-navigation'),
    );
  }

  return $element;
}
