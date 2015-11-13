<?php

/**
 * @file
 * Handle the '%%ENTITY_TITLE%% view' override task.
 *
 * This plugin overrides %%ENTITY_PATH%%/%%%MACHINE_NAME%% and reroutes it to the
 * page manager, where a list of tasks can be used to service this request based
 * upon criteria supplied by access plugins.
 */

use Drupal\%%MACHINE_NAME%%\Entity\%%ENTITY_CLASS_NAME%% as %%ENTITY_CLASS_ALIAS%%;

/**
 * Specialized implementation of hook_%%MACHINE_NAME%%_task_tasks().
 */
function %%MACHINE_NAME%%_%%MACHINE_NAME%%_view_page_manager_tasks() {
  return array(
    // This is a 'page' task and will fall under the page admin UI
    'task type' => 'page',

    'title' => t('%%ENTITY_TITLE%% template'),

    'admin title' => t('%%ENTITY_TITLE%% template'),
    'admin description' => t('When enabled, this overrides the default Drupal behavior for displaying %%ENTITY_LOWERCASE_NAME%% at <em>%%ENTITY_PATH%%/%%%MACHINE_NAME%%</em>. If you add variants, you may use selection criteria such as %%ENTITY_LOWERCASE_NAME%% type or language or user access to provide different views of %%ENTITY_TITLE_PLURAL%%. If no variant is selected, the default Drupal %%ENTITY_LOWERCASE_NAME%% view will be used. This page only affects %%ENTITY_TITLE_PLURAL%% viewed as pages, it will not affect %%ENTITY_TITLE_PLURAL%% viewed in lists or at other locations. Also please note that if you are using pathauto, aliases may make a %%ENTITY_LOWERCASE_NAME%% to be somewhere else, but as far as Drupal is concerned, they are still at %%ENTITY_PATH%%/%%%MACHINE_NAME%%.'),
    'admin path' => '%%ENTITY_PATH%%/%%%MACHINE_NAME%%',

    // Menu hooks so that we can alter the %%ENTITY_PATH%%/%%%MACHINE_NAME%% menu
    // entry to point to us.
    'hook menu' => '%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_menu',
    'hook menu alter' => '%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_menu_alter',

    // This task uses 'context' handlers and must implement these to give the
    // handler data it needs.
    'handler type' => 'context',
    'get arguments' => '%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_get_arguments',
    'get context placeholders' => '%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_get_contexts',

    // Allow this to be enabled or disabled:
    'disabled' => variable_get('%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_disabled', TRUE),
    'enable callback' => '%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_enable',
    'access callback' => '%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_access_check',
  );
}

/**
 * Callback defined by %%MACHINE_NAME%%_%%MACHINE_NAME%%_view_%%MACHINE_NAME%%_tasks().
 *
 * Alter the %%ENTITY_LOWERCASE_NAME%% view input so that %%ENTITY_LOWERCASE_NAME%% view comes to us rather
 * than the normal %%ENTITY_LOWERCASE_NAME%% view process.
 */
function %%MACHINE_NAME%%_%%MACHINE_NAME%%_view_menu_alter(&$items, $task) {
  if (variable_get('%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_disabled', TRUE)) {
    return;
  }

  // Override the %%ENTITY_LOWERCASE_NAME%% view handler for our purpose.
  $callback = $items['%%ENTITY_PATH%%/%%%MACHINE_NAME%%']['page callback'];
  if ($callback == '%%MACHINE_NAME%%_page_view' || variable_get('%%MACHINE_NAME%%_override_anyway', FALSE)) {
    $items['%%ENTITY_PATH%%/%%%MACHINE_NAME%%']['page callback'] = '%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_page';
    $items['%%ENTITY_PATH%%/%%%MACHINE_NAME%%']['file path'] = $task['path'];
    $items['%%ENTITY_PATH%%/%%%MACHINE_NAME%%']['file'] = $task['file'];
  }
  else {
    // automatically disable this task if it cannot be enabled.
    variable_set('%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_disabled', TRUE);
    if (!empty($GLOBALS['%%MACHINE_NAME%%_enabling_%%MACHINE_NAME%%_view'])) {
      drupal_set_message(t('Page manager module is unable to enable %%ENTITY_PATH%%/%%%MACHINE_NAME%% because some other module already has overridden with %callback.', array('%callback' => $callback)), 'error');
    }
  }
}

/**
 * Entry point for our overridden %%ENTITY_LOWERCASE_NAME%% view.
 *
 * This function asks its assigned handlers who, if anyone, would like to run
 * with it. If no one does, it passes through to Drupal core's
 * %%ENTITY_LOWERCASE_NAME%% view, which is %%MACHINE_NAME%%_page_view().
 */
function %%MACHINE_NAME%%_%%MACHINE_NAME%%_view_page(%%ENTITY_CLASS_ALIAS%% $%%MACHINE_NAME%%) {
  // Load my task plugin
  $task = page_manager_get_task('%%MACHINE_NAME%%_view');

  // Load the %%ENTITY_LOWERCASE_NAME%% entity into a context.
  ctools_include('context');
  ctools_include('context-task-handler');

  // We need to mimic Drupal's behavior of setting the %%ENTITY_LOWERCASE_NAME%% title here.
  drupal_set_title($%%MACHINE_NAME%%->label);
  $uri = entity_uri('%%MACHINE_NAME%%', $%%MACHINE_NAME%%);
  // Set the %%ENTITY_LOWERCASE_NAME%% path as the canonical URL to prevent duplicate content.
  drupal_add_html_head_link(array('rel' => 'canonical', 'href' => url($uri['path'], $uri['options'])), TRUE);
  // Set the non-aliased path as a default shortlink.
  drupal_add_html_head_link(array('rel' => 'shortlink', 'href' => url($uri['path'], array_merge($uri['options'], array('alias' => TRUE)))), TRUE);
  $contexts = ctools_context_handler_get_task_contexts($task, '', array($%%MACHINE_NAME%%));

  $output = ctools_context_handler_render($task, '', $contexts, array($%%MACHINE_NAME%%->%%ENTITY_PRIMARY_KEY%%));
  if ($output != FALSE) {
    return $output;
  }

  $function = '%%MACHINE_NAME%%_page_view';
  foreach (module_implements('%%MACHINE_NAME%%_override') as $module) {
    $call = $module . '_%%MACHINE_NAME%%_override';
    if (($rc = $call('%%MACHINE_NAME%%_view')) && function_exists($rc)) {
      $function = $rc;
      break;
    }
  }

  // Otherwise, fall back.
  return $function($%%MACHINE_NAME%%);
}

/**
 * Callback to get arguments provided by this task handler.
 *
 * Since this is the %%ENTITY_LOWERCASE_NAME%% view and there is no UI on the arguments, we
 * create dummy arguments that contain the needed data.
 */
function %%MACHINE_NAME%%_%%MACHINE_NAME%%_view_get_arguments($task, $subtask_id) {
  return array(
    array(
      'keyword' => '%%MACHINE_NAME%%',
      'identifier' => t('%%ENTITY_TITLE%% being viewed'),
      'id' => 1,
      'name' => 'entity_id:%%MACHINE_NAME%%',
      'settings' => array(),
    ),
  );
}

/**
 * Callback to get context placeholders provided by this handler.
 */
function %%MACHINE_NAME%%_%%MACHINE_NAME%%_view_get_contexts($task, $subtask_id) {
  return ctools_context_get_placeholders_from_argument(%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_get_arguments($task, $subtask_id));
}

/**
 * Callback to enable/disable the page from the UI.
 */
function %%MACHINE_NAME%%_%%MACHINE_NAME%%_view_enable($cache, $status) {
  variable_set('%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_disabled', $status);

  // Set a global flag so that the menu routine knows it needs
  // to set a message if enabling cannot be done.
  if (!$status) {
    $GLOBALS['%%MACHINE_NAME%%_enabling_%%MACHINE_NAME%%_view'] = TRUE;
  }
}

/**
 * Callback to determine if a page is accessible.
 *
 * @param $task
 *   The task plugin.
 * @param $subtask_id
 *   The subtask id
 * @param $contexts
 *   The contexts loaded for the task.
 * @return
 *   TRUE if the current user can access the page.
 */
function %%MACHINE_NAME%%_%%MACHINE_NAME%%_view_access_check($task, $subtask_id, $contexts) {
  $context = reset($contexts);
  return %%MACHINE_NAME%%_access('view', $context->data);
}
