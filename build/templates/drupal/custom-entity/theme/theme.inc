<?php
/**
 * @file
 *
 */

/**
 * Processes variables for %%ENTITY_CSS_NAME%%.tpl.php
 *
 * The $variables array contains the following arguments:
 * - $%%MACHINE_NAME%%
 * - $view_mode
 * - $page
 *
 * @see node.tpl.php
 */
function template_preprocess_%%MACHINE_NAME%%(&$variables) {
  $entity = $variables['elements']['#entity'];
  $variables['date'] = format_date($entity->created);

  if (empty($entity->status)) {
    $variables['classes_array'][] = '%%ENTITY_CSS_NAME%%-disabled';
  }
}
