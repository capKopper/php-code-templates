<?php

/**
 * Implements hook_preprocess_menu_link().
 *
 * @see template_preprocess_menu_link()
 */
function %%MACHINE_NAME%%_preprocess_menu_link(&$variables) {
  if (isset($variables['element']['#original_link'])) {
    $variables['element']['#attributes']['class'][] = 'menu-depth-' . $variables['element']['#original_link']['depth'];
    $variables['element']['#localized_options']['attributes']['class'][] = 'menu-depth-' . $variables['element']['#original_link']['depth'];
  }
}
