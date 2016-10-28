<?php

/**
 * Implements hook_preprocess_html().
 *
 * @see template_preprocess_field()
 *
 * @todo create an omega extension to configure this.
 */
function %%MACHINE_NAME%%_preprocess_field(&$variables) {
  global $language;

  $settings = array(
    'fr' => array('colon' => '&nbsp;:&nbsp;'),
  );

  $settings += array(
    $language->language => array(),
  );

  $settings[$language->language] += array(
    'colon' => ':&nbsp;',
  );

  $variables['label_separator'] = $settings[$language->language]['colon'];
}
