<?php

/**
 * Implements hook_preprocess_html().
 *
 * @see template_preprocess_html()
 */
function %%MACHINE_NAME%%_preprocess_html(&$variables) {
  if ($term = menu_get_object('taxonomy_term', 2)) {
    $variables['classes_array'][] = drupal_html_class('taxonomy-vocabulary-' . drupal_html_class($term->vocabulary_machine_name));
  }

  $path = drupal_get_path('theme', '%%MACHINE_NAME%%');

  // Add icon for Android and Chrome (Apple icons are already handled by Omega).
  $meta = array(
    '#tag' => 'link',
    '#attributes' => array(
      'rel' => 'icon',
      'sizes' => '192x192',
      'href' => file_create_url($path . '/android-192x192.png'),
    ),
  );
  drupal_add_html_head($meta, 'android-192x192.png');

  // Add META for Windows 8.
  $metas = array(
    'msapplication-tile-image' => array(
      'name' => 'msapplication-TileImage',
      'content' => file_create_url($path . '/apple-touch-icon-precomposed-144x144.png'),
    ),
    'msapplication-tile-color' => array(
      'name' => 'msapplication-TileColor',
      'content' => '#FFFFFF',
    ),
  );

  if ($site_name = variable_get('site_name')) {
    $metas['msapplication-application-name'] = array(
      'name' => 'application-name',
      'content' => $site_name,
    );
  }

  // Add META for IE 11.
  $metas['msapplication-square70x70logo'] = array(
    'name' => 'msapplication-square70x70logo',
    'content' => file_create_url($path . '/ie-icon-precomposed-70x70.png'),
  );
  $metas['msapplication-square150x150logo'] = array(
    'name' => 'msapplication-square150x150logo',
    'content' => file_create_url($path . '/ie-icon-precomposed-150x150.png'),
  );
  $metas['msapplication-wide310x150logo'] = array(
    'name' => 'msapplication-wide310x150logo',
    'content' => file_create_url($path . '/ie-icon-precomposed-310x150.png'),
  );
  $metas['msapplication-square310x310logo'] = array(
    'name' => 'msapplication-square310x310logo',
    'content' => file_create_url($path . '/ie-icon-precomposed-310x310.png'),
  );

  $weight = 20;

  foreach ($metas as $key => $meta) {
    drupal_add_html_head(
      array(
        '#tag' => 'meta',
        '#attributes' => array(
          'name' => $meta['name'],
          'content' => $meta['content'],
        ),
        '#weight' => $weight,
      ),
      $key);
    $weight += .01;
  }
}
