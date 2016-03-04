<?php
/**
 * Process variables for entity.tpl.php.
 */
function %%MACHINE_NAME%%_preprocess_entity(&$variables) {
  $entity_type = $variables['elements']['#entity_type'];

  // Add a class to facilitate form theming of entityform types.
  if ($entity_type === 'entityform_type') {
    $entity = $variables['elements']['#entity'];

    if (isset($entity->type)) {
      $variables['classes_array'][] = drupal_html_class($entity_type . '-' . $entity->type);
    }
  }
}
