<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * %%THEME_TITLE%% theme.
 */

// Clear the static element info cache if our alter hook was not called.
// @see https://www.drupal.org/node/2351739.
// Use a dummy name because if using a generic name like "info", we may cause
// collision when the template file is loaded from the theme() function:
// include_once DRUPAL_ROOT . '/' . $include_file;
// Since the $info
// This is the case for example when using Mail System, setting this theme as
// the defaut for sending emails.
$info_f4te478ert7t = element_info('managed_file');

if (!isset($info_f4te478ert7t['#after_build']) || !in_array('%%MACHINE_NAME%%_file_managed_after_build', $info_f4te478ert7t['#after_build'])) {
  drupal_static_reset('element_info');
}

/**
 * Implements hook_theme_registry_alter().
 */
function %%MACHINE_NAME%%_theme_registry_alter(&$registry) {
  // Add usefull class to menu tree.
  if (isset($registry['menu_tree'])) {
    $key = array_search('%%MACHINE_NAME%%_preprocess_menu_tree', $registry['menu_tree']['preprocess functions']);

    if ($key !== FALSE) {
      unset($registry['menu_tree']['preprocess functions'][$key]);
      array_unshift($registry['menu_tree']['preprocess functions'], '%%MACHINE_NAME%%_preprocess_menu_tree');
    }
  }

  // The mailsystem module alters the registry, but not properly... So it
  // creates duplicates of preprocess and process hooks that are defined by
  // Omega and its sub-themes.
  if (module_exists('mailsystem')) {
    foreach ($registry as $hook => $item) {
      foreach (array('preprocess functions', 'process functions') as $phase) {
        if (isset($registry[$hook][$phase])) {
          $registry[$hook][$phase] = array_unique($registry[$hook][$phase]);
        }
      }
    }
  }
}

/**
 * Implements hook_element_info_alter().
 */
function %%MACHINE_NAME%%_element_info_alter(&$type) {
  if (isset($type['managed_file'])) {
    $type['managed_file']['#after_build'][] = '%%MACHINE_NAME%%_file_managed_after_build';
  }

  foreach (omega_extensions() as $extension => $info) {
    if (omega_extension_enabled($extension)) {
      $hook = $info['theme'] . '_extension_' . $extension . '_element_info_alter';

      if (function_exists($hook)) {
        $hook($type);
      }
    }
  }
}

/**
 * Implements hook_libraries_info_alter().
 */
function %%MACHINE_NAME%%_libraries_info_alter(&$libraries) {
  if (isset($libraries['flexslider']['files']['css'])) {
    unset($libraries['flexslider']['files']['css']);
  }
}

/**
 * Implements hook_field_widget_addressfield_standard_form_alter().
 */
function %%MACHINE_NAME%%_field_widget_addressfield_standard_form_alter(&$element, $form_state, $context) {
  // Use a container instead of a fieldset.
  $element['#type'] = 'item';
}

/**
 * After build callback for a "file managed" element.
 */
function %%MACHINE_NAME%%_file_managed_after_build($element, $form_state) {
  $jquery_filestyle_added = FALSE;
  $processed = &drupal_static(__FUNCTION__);

  if (!isset($processed['elements'])) {
    $processed['elements'] = array();
  }

  if (!$jquery_filestyle_added && $path = libraries_get_path('jquery.filestyle')) {
    $jquery_filestyle_added = TRUE;
    drupal_add_css($path . '/src/jquery-filestyle.min.css');
    drupal_add_js($path . '/src/jquery-filestyle.min.js');
  }

  if ($jquery_filestyle_added && !in_array($element['upload']['#id'], $processed['elements'])) {
    $processed['elements'][] = $element['upload']['#id'];
    $options = array(
      'buttonText' => $element['upload']['#title'],
      'inputSize' => '320px',
    );

    if (isset($element['#title'])) {
      $options['placeholder'] = $element['#title'];
      $element['#title_display'] = 'invisible';
    }

    drupal_add_js(array('%%MACHINE_NAME%%' => array(
      'filestyle' => array(
        '#' . $element['upload']['#id'] => $options,
      ),
    )),
    'setting');
  }

  return $element;
}

/**
 * Implements hook_field_widget_options_select_form_alter().
 */
function %%MACHINE_NAME%%_field_widget_options_select_form_alter(&$element, $form_state, $context) {
  $instance = $context['instance'];

  if ($instance['widget']['type'] === 'options_select' && !empty($instance['label'])) {
    $element['#title_display'] = 'invisible';
  }
}

/**
 * Implements hook_css_alter().
 */
function %%MACHINE_NAME%%_css_alter(&$css) {
  $path = drupal_get_path('module', 'panopoly_images') . '/panopoly-images.css';

  if (isset($css[$path])) {
    unset($css[$path]);
  }
}
