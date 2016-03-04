<?php

/**
 * @file
 * Main extension file for the 'navbar' extension.
 */

/**
 * Implements hook_extension_EXTENSION_registry_alter().
 */
function %%MACHINE_NAME%%_extension_navbar_theme_registry_alter(&$registry) {
  $registry['html']['preprocess functions'][] = '%%MACHINE_NAME%%_extension_navbar_preprocess_html';
}

/**
 * Implements hook_extension_EXTENSION_preprocess_html().
 *
 * @see template_preprocess_html()
 */
function %%MACHINE_NAME%%_extension_navbar_preprocess_html(&$variables) {
  if (module_exists('breakpoints') && $breakpoints = breakpoints_breakpoint_load_all_theme('%%MACHINE_NAME%%')) {
    $path_to_theme = drupal_get_path('theme', '%%MACHINE_NAME%%');
    $media_queries = array();

    if (!$matchmedia_path = libraries_get_path('matchmedia')) {
      return;
    }

    // The Media Queries behavior needs to be processed after all other behaviors,
    // so other behaviors that relies on the initial resize event will be
    // satisfied.
    $options = array('group' => JS_THEME, 'weight' => 1000);

    // Matchmedia library.
    drupal_add_js($matchmedia_path . '/matchmedia.min.js', $options);

    // Our overriden Omega Match Media JS
    drupal_add_js($path_to_theme . '/js/%%MACHINE_NAME%%.mediaqueries.js', $options);

    foreach ($breakpoints as $breakpoint) {
      $media_queries[$breakpoint->name] = $breakpoint->breakpoint;
    }

    drupal_add_js($path_to_theme . '/js/%%MACHINE_NAME%%.navbar.js');
    drupal_add_js(array('%%MACHINE_NAME%%' => array('mediaQueries' => $media_queries)), 'setting');

    $mobile_breakpoints = array_keys($media_queries);
    $default = array_intersect($mobile_breakpoints, array('tiny', 'small', 'narrow'));
    $mobile_breakpoints = omega_theme_get_setting('%%MACHINE_NAME%%_navbar_breakpoints', $default);

    // Add breakpoints for the navigation menu.
    drupal_add_js(array('%%MACHINE_NAME%%' => array(
      'navbar' => array(
        'breakpoints' => array_filter(array_values($mobile_breakpoints)),
        'wrapper' => omega_theme_get_setting('%%MACHINE_NAME%%_navbar_wrapper', '.l-navigation'),
      ),
    )),
    'setting');
  }
}
