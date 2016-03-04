<?php

/**
 * Preprocess theme function to print a single record from a row, with fields
 *
 * @todo create an omega extension to configure this.
 */
function %%MACHINE_NAME%%_preprocess_views_view_fields(&$vars) {
  global $language;

  $settings = array(
    'fr' => array('colon' => '&nbsp;:&nbsp;'),
  );

  if (isset($settings[$language->language]['colon'])) {
    $view = $vars['view'];

    foreach ($vars['fields'] as $id => $object) {
      if ($object->label && $object->handler->options['element_label_colon']) {
        $object->label_html = $object->label . $settings[$language->language]['colon'];

        if ($object->element_label_type) {
          $class = '';
          if ($object->handler->options['element_default_classes']) {
            $class = 'views-label views-label-' . $object->class;
          }

          $element_label_class = $object->handler->element_label_classes($view->row_index);
          if ($element_label_class) {
            if ($class) {
              $class .= ' ';
            }

            $class .= $element_label_class;
          }

          $pre = '<' . $object->element_label_type;
          if ($class) {
            $pre .= ' class="' . $class . '"';
          }
          $pre .= '>';

          $object->label_html = $pre . $object->label_html . '</' . $object->element_label_type . '>';
        }
      }
    }
  }
}
