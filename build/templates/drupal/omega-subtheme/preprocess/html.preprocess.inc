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

  if ($metas = theme_get_setting('metaicons', '%%MACHINE_NAME%%')) {
    // Put those meta in the bottom.
    $weight = 20;

    // Extra meta for Windows 8, that is not handled through the theme settings.
    if ($site_name = variable_get('site_name')) {
      $metas['msapplication-application-name'] = array(
        'name' => 'application-name',
        'content' => $site_name,
      );
    }

    foreach ($metas as $key => $meta_icon) {
      $meta_icon += [
        'tag' => 'meta',
        'name' => $key,
        'attributes' => [],
        'icon' => NULL,
        'content' => NULL,
        'weight' => $weight,
      ];

      if (isset($meta_icon['icon']) && is_file($meta_icon['icon'])) {
        $meta_icon['content'] = file_create_url($path . '/' . $meta_icon['icon']);
      }
      // Fallback to content if set.
      elseif (!isset($meta_icon['content'])) {
        continue;
      }

      switch ($meta_icon['tag']) {
        case 'link':
          // For link tag, use content as value for href.
          $meta_icon['attributes']['href'] = $meta_icon['content'];

          $meta = array(
            '#tag' => 'link',
            '#attributes' => $meta_icon['attributes'],
            '#weight' => $meta_icon['weight'],
          );
          break;

        case 'meta':
          $meta = [
            '#tag' => 'meta',
            '#attributes' => array(
              'name' => $meta['name'],
              'content' => $meta['content'],
            ),
            '#weight' => $meta_icon['weight'],
          ];

          break;

        default:
          // Ignore this one as tag is not valid.
          continue;
      }

      drupal_add_html_head($meta, $key);
      $weight += .01;
    }
  }
}
