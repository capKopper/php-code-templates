<?php

/**
 * @file
 * Main extension file for the 'placeholder' extension.
 */

/**
 * Implements hook_element_info_alter().
 */
function %%MACHINE_NAME%%_extension_placeholder_element_info_alter(&$types) {
  $elements = omega_theme_get_setting('%%MACHINE_NAME%%_placeholder_elements', array());

  foreach (array_filter($elements) as $element) {
    if (isset($types[$element])) {
      $types[$element]['#pre_render'][] = '%%MACHINE_NAME%%_extension_placeholder_element_prerender';
    }
  }
}

/**
 * Ceonvert element title to placeholder.
 */
function %%MACHINE_NAME%%_extension_placeholder_element_prerender($element) {
  if (!isset($element['#attributes']['placeholder'])) {
    $element['#title_display'] = 'none';

    if (isset($element['#title'])) {
      $element['#attributes']['placeholder'] = $element['#title'];


      // Take car of Name field specific behavior.
      if (isset($element['#attributes']['class']) && in_array('name-element', $element['#attributes']['class'])) {
        if (in_array('name-core-component', $element['#attributes']['class'])) {
          $element['#attributes']['placeholder'] .= '*';
        }

        if (isset($element['#description'])) {
          unset($element['#description']);
        }
      }
      elseif (!empty($element['#required'])) {
        $element['#attributes']['placeholder'] .= '*';
      }
    }
  }

  return $element;
}
