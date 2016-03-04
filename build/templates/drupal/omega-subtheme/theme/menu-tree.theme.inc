<?php

/**
 * Returns HTML for a wrapper for a menu sub-tree.
 *
 * @param $variables
 *   An associative array containing:
 *   - tree: An HTML string containing the tree's items.
 *
 * @see theme_menu_tree()
 * @ingroup themeable
 */
function %%MACHINE_NAME%%_menu_tree($variables) {
  return '<ul' . drupal_attributes($variables['attributes_array']) . '>' . $variables['tree'] . '</ul>';
}
