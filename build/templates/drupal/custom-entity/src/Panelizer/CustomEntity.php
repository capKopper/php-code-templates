<?php
/**
 * @file
 * %%ENTITY_TITLE%% Panelizer entity plugin.
 */

namespace Drupal\%%MACHINE_NAME%%\Panelizer;

/**
 * The class used for %%ENTITY_LOWERCASE_NAME%% entities
 */
class %%ENTITY_CLASS_NAME%% extends \PanelizerEntityDefault {

  /**
   * (@inheritdoc)
   */
  public $views_table = '%%MACHINE_NAME%%';

  public $uses_page_manager = TRUE;

  // This is disabled by default, because it depends on the hierarchy level of
  // the entity type admin path. This last should not exceed 5 parts (from 0 to
  // 4) otherwise the maximum number of elements for a menu item (8) will be
  // overtaken.
  // If all is OK there, you need to uncomment the 2 following lines and the
  // method "hook_page_alter".
  //public $entity_admin_root = '%%ENTITY_ADMIN_PATH%%/manage/%';

  //public $entity_admin_bundle = 4;

  /**
   * (@inheritdoc)
   */
  public function entity_access($op, $entity) {
    return %%MACHINE_NAME%%_access($op, $entity);
  }

  /**
   * (@inheritdoc)
   */
  public function entity_save($entity) {
    return entity_save('%%MACHINE_NAME%%', $entity);
  }

  /**
   * (@inheritdoc)
   */
  public function entity_bundle_label() {
    return t('%%ENTITY_TITLE%% type');
  }

  /**
   * (@inheritdoc)
   */
  function get_default_display($bundle, $view_mode) {
    $display = parent::get_default_display($bundle, $view_mode);
    // Add the %%ENTITY_LOWERCASE_NAME%% label to the display since we can't get that automatically.
    $display->title = '%%%MACHINE_NAME%%:label';

    return $display;
  }

  /**
   * Identify whether page manager is enabled for this entity type.
   */
  public function is_page_manager_enabled() {
    return variable_get('%%MACHINE_NAME%%_%%MACHINE_NAME%%_view_disabled', TRUE);
  }

  /**
   * Implements a delegated hook_page_manager_handlers().
   *
   * This makes sure that all panelized entities have the proper entry
   * in page manager for rendering.
   */
  public function hook_default_page_manager_handlers(&$handlers) {
    $handler = new \stdClass;
    $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
    $handler->api_version = 1;
    $handler->name = '%%MACHINE_NAME%%_view_panelizer';
    $handler->task = '%%MACHINE_NAME%%_view';
    $handler->subtask = '';
    // NOTE: This is named panelizer_node for historical reasons.
    $handler->handler = 'panelizer_node';
    $handler->weight = -100;
    $handler->conf = array(
      'title' => t('%%ENTITY_TITLE%% panelizer'),
      'context' => 'argument_entity_id:%%MACHINE_NAME%%_1',
      'access' => array(),
    );
    $handlers['%%MACHINE_NAME%%_view_panelizer'] = $handler;

    return $handlers;
  }

  /**
   * Implements a delegated hook_form_alter.
   *
   * We want to add Panelizer settings for the bundle to the %%ENTITY_LOWERCASE_NAME%% type form.
   */
  public function hook_form_alter(&$form, &$form_state, $form_id) {
    if ($form_id == '%%MACHINE_NAME%%_type_form') {
      if (isset($form_state['%%MACHINE_NAME%%_type']->type)) {
        $bundle = $form_state['%%MACHINE_NAME%%_type']->type;
        $this->add_bundle_setting_form($form, $form_state, $bundle, array('type'));
      }
    }
  }

  /*public function hook_page_alter(&$page) {
    // Add an extra "Panelizer" action on the %%ENTITY_LOWERCASE_NAME%% types admin page.
    if ($_GET['q'] == '%%ENTITY_TYPE_ADMIN_PATH%%') {
      // This only works with some themes.
      if (!empty($page['content']['system_main']['table'])) {
        // Shortcut.
        $table = &$page['content']['system_main']['table'];

        // Operations column should always be the last column in header.
        // Increase its colspan by one to include possible panelizer link.
        $operationsCol = end($table['#header']);
        if (!empty($operationsCol['colspan'])) {
          $operationsColKey = key($table['#header']);
          $table['#header'][$operationsColKey]['colspan']++;
        }

        // Since we can't tell what row a type is for, but we know that they
        // were generated in this order, go through the original types list.
        $types = %%MACHINE_NAME%%_get_types();
        $row_index = 0;
        foreach ($types as $bundle => %%MACHINE_NAME%%_type) {
          $type = $types[$bundle];

          if ($this->is_panelized($bundle) && panelizer_administer_entity_bundle($this, $bundle)) {
            $table['#rows'][$row_index][] = array('data' => l(t('panelizer'), '%%ENTITY_ADMIN_PATH%%/manage/' . $bundle . '/panelizer'));
          }
          else {
            $table['#rows'][$row_index][] = array('data' => '');
          }
          // Update row index for next pass.
           $row_index++;
          }
        }
      }
    }
  }*/

  /**
   * (@inheritdoc)
   */
  public function preprocess_panelizer_view_mode(&$vars, $entity, $element, $panelizer, $info) {
    parent::preprocess_panelizer_view_mode($vars, $entity, $element, $panelizer, $info);

    if (empty($entity->status)) {
      $vars['classes_array'][] = '%%ENTITY_CSS_NAME%%-disabled';
    }
  }

  function render_entity($entity, $view_mode, $langcode = NULL, $args = array(), $address = NULL, $extra_contexts = array()) {
    // Just add a special tag to the entity so we know it is being rendered by
    // the Panelizer module, when the ENTITY_TYPE_view() hook is called.
    $entity->panelizer_rendering = TRUE;

    $info = parent::render_entity($entity, $view_mode, $langcode, $args, $address, $extra_contexts);
    if (empty($entity->status)) {
      $info['classes_array'][] = '%%ENTITY_CSS_NAME%%-disabled';
    }

    unset($entity->panelizer_rendering);
    return $info;
  }

}
