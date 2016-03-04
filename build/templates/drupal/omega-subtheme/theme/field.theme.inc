<?php

/**
 * Returns HTML for a field.
 *
 * @see theme_field
 */
function %%MACHINE_NAME%%_field($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field__label"' . $variables['title_attributes'] . '>' . $variables['label'] . $variables['label_separator'] . '</div>';
  }

  // Render the items.
  $output .= '<div class="field__items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field__item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}
