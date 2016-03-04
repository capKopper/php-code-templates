<?php

/**
 * Implements hook_preprocess_menu_tree().
 */
function %%MACHINE_NAME%%_preprocess_menu_tree(&$variables) {
  $variables['attributes_array']['class'][] = 'menu';

  if ($children = element_children($variables['tree'])) {
    $first = $variables['tree'][$children[0]];

    if (isset($first['#original_link'])) {
      $variables['attributes_array']['class'][] = 'menu-depth-' . $first['#original_link']['depth'];
    }
  }
}
