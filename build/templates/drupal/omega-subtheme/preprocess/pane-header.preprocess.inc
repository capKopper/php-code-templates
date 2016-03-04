<?php

/**
 * Implements hook_preprocess_pane_header().
 *
 * @see template_preprocess_pane_header()
 */
function %%MACHINE_NAME%%_preprocess_pane_header(&$variables) {
  $variables['site_name'] = l(
    '<span class="site-name">' . $variables['site_name'] . '</span>',
    '<front>',
    array(
      'attributes' => array(
        'title' => $variables['site_name'] .' | '. t('Home'),
        'class' => array('home-link'),
        'rel' => 'home'),
      'html' => TRUE,
    )
  );
}
