<?php
/**
 * @file
 * Defaut views for %%MODULE_TITLE%% module.
 */

/**
 * Implements hook_views_default_views().
 */
function %%MACHINE_NAME%%_views_default_views() {
  $export = array();

  if (module_exists('admin_views')) {
    $view = new view();
    $view->name = '%%ENTITY_VIEW_NAME%%';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = '%%MACHINE_NAME%%';
    $view->human_name = '%%ENTITY_TITLE_PLURAL%%';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Manage %%ENTITY_TITLE_PLURAL%%';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'plus';
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'administer %%MACHINE_NAME%%';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Apply';
    $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reset';
    $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per page';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- All -';
    $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Offset';
    $handler->display->display_options['pager']['options']['tags']['first'] = '« first';
    $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ previous';
    $handler->display->display_options['pager']['options']['tags']['next'] = 'next ›';
    $handler->display->display_options['pager']['options']['tags']['last'] = 'last »';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      '%%ENTITY_PRIMARY_KEY%%' => '%%ENTITY_PRIMARY_KEY%%',
      'label' => 'label',
      'type' => 'type',
      'language' => 'language',
      'status' => 'status',
      'created' => 'created',
      'name' => 'name',
      'edit_%%MACHINE_NAME%%' => 'edit_%%MACHINE_NAME%%',
      'delete_%%MACHINE_NAME%%' => 'edit_%%MACHINE_NAME%%',
      'clone_%%MACHINE_NAME%%' => 'edit_%%MACHINE_NAME%%',
      'export_%%MACHINE_NAME%%' => 'edit_%%MACHINE_NAME%%',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
      '%%ENTITY_PRIMARY_KEY%%' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'label' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'type' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'language' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'status' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'created' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'name' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'edit_%%MACHINE_NAME%%' => array(
        'align' => '',
        'separator' => ' - ',
        'empty_column' => 0,
      ),
      'delete_%%MACHINE_NAME%%' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'clone_%%MACHINE_NAME%%' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'export_%%MACHINE_NAME%%' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    $handler->display->display_options['style_options']['sticky'] = TRUE;
    /* Relationship: %%ENTITY_TITLE%% : Creator */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    /* Field: %%ENTITY_TITLE%% : %%ENTITY_TITLE%% ID */
    $handler->display->display_options['fields']['%%ENTITY_PRIMARY_KEY%%']['id'] = '%%ENTITY_PRIMARY_KEY%%';
    $handler->display->display_options['fields']['%%ENTITY_PRIMARY_KEY%%']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['%%ENTITY_PRIMARY_KEY%%']['field'] = '%%ENTITY_PRIMARY_KEY%%';
    /* Field: %%ENTITY_TITLE%% : Label */
    $handler->display->display_options['fields']['label']['id'] = 'label';
    $handler->display->display_options['fields']['label']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['label']['field'] = 'label';
    $handler->display->display_options['fields']['label']['link_to_entity'] = 1;
    /* Field: %%ENTITY_TITLE%% : %%ENTITY_TITLE%% type */
    $handler->display->display_options['fields']['type']['id'] = 'type';
    $handler->display->display_options['fields']['type']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['type']['field'] = 'type';
    $handler->display->display_options['fields']['type']['label'] = 'Type';
    /* Field: %%ENTITY_TITLE%% : Language */
    $handler->display->display_options['fields']['language']['id'] = 'language';
    $handler->display->display_options['fields']['language']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['language']['field'] = 'language';
    /* Field: %%ENTITY_TITLE%% : Status */
    $handler->display->display_options['fields']['status']['id'] = 'status';
    $handler->display->display_options['fields']['status']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['status']['field'] = 'status';
    /* Field: %%ENTITY_TITLE%% : Changed */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['date_format'] = 'short';
    $handler->display->display_options['fields']['created']['second_date_format'] = 'panopoly_time';
    /* Field: Utilisateur : Name */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'uid';
    /* Field: %%ENTITY_TITLE%% : Edit link */
    $handler->display->display_options['fields']['edit_%%MACHINE_NAME%%']['id'] = 'edit_%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['edit_%%MACHINE_NAME%%']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['edit_%%MACHINE_NAME%%']['field'] = 'edit_%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['edit_%%MACHINE_NAME%%']['label'] = 'Actions';
    /* Field: %%ENTITY_TITLE%% : Delete link */
    $handler->display->display_options['fields']['delete_%%MACHINE_NAME%%']['id'] = 'delete_%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['delete_%%MACHINE_NAME%%']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['delete_%%MACHINE_NAME%%']['field'] = 'delete_%%MACHINE_NAME%%';
    /* Field: %%ENTITY_TITLE%% : Clone Link */
    $handler->display->display_options['fields']['clone_%%MACHINE_NAME%%']['id'] = 'clone_%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['clone_%%MACHINE_NAME%%']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['clone_%%MACHINE_NAME%%']['field'] = 'clone_%%MACHINE_NAME%%';
    /* Field: %%ENTITY_TITLE%% : Export Link */
    $handler->display->display_options['fields']['export_%%MACHINE_NAME%%']['id'] = 'export_%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['export_%%MACHINE_NAME%%']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['fields']['export_%%MACHINE_NAME%%']['field'] = 'export_%%MACHINE_NAME%%';
    /* Sort criterion: %%ENTITY_TITLE%% : Changed */
    $handler->display->display_options['sorts']['changed']['id'] = 'changed';
    $handler->display->display_options['sorts']['changed']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['sorts']['changed']['field'] = 'changed';
    $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
    /* Sort criterion: %%ENTITY_TITLE%% : Label */
    $handler->display->display_options['sorts']['label']['id'] = 'label';
    $handler->display->display_options['sorts']['label']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['sorts']['label']['field'] = 'label';
    /* Filter criterion: %%ENTITY_TITLE%% : Label */
    $handler->display->display_options['filters']['label']['id'] = 'label';
    $handler->display->display_options['filters']['label']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['filters']['label']['field'] = 'label';
    $handler->display->display_options['filters']['label']['operator'] = 'contains';
    $handler->display->display_options['filters']['label']['exposed'] = TRUE;
    $handler->display->display_options['filters']['label']['expose']['operator_id'] = 'label_op';
    $handler->display->display_options['filters']['label']['expose']['label'] = 'Label';
    $handler->display->display_options['filters']['label']['expose']['operator'] = 'label_op';
    $handler->display->display_options['filters']['label']['expose']['identifier'] = 'label';
    $handler->display->display_options['filters']['label']['expose']['remember'] = TRUE;
    $handler->display->display_options['filters']['label']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
    );
    $handler->display->display_options['filters']['label']['expose']['autocomplete_items'] = '10';
    $handler->display->display_options['filters']['label']['expose']['autocomplete_min_chars'] = '0';
    $handler->display->display_options['filters']['label']['expose']['autocomplete_field'] = 'label';
    $handler->display->display_options['filters']['label']['expose']['autocomplete_raw_suggestion'] = 1;
    $handler->display->display_options['filters']['label']['expose']['autocomplete_raw_dropdown'] = 1;
    $handler->display->display_options['filters']['label']['expose']['autocomplete_dependent'] = 0;
    /* Filter criterion: %%ENTITY_TITLE%% : %%ENTITY_TITLE%% type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['exposed'] = TRUE;
    $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
    $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
    $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
    $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
    $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
    $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
    );
    /* Filter criterion: %%ENTITY_TITLE%% : Language */
    $handler->display->display_options['filters']['language']['id'] = 'language';
    $handler->display->display_options['filters']['language']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['filters']['language']['field'] = 'language';
    $handler->display->display_options['filters']['language']['exposed'] = TRUE;
    $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
    $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
    $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
    $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
    $handler->display->display_options['filters']['language']['expose']['remember'] = TRUE;
    $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
    );
    /* Filter criterion: %%ENTITY_TITLE%% : Status */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = '%%MACHINE_NAME%%';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['exposed'] = TRUE;
    $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
    $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
    $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
    $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
    $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
    $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
    );

    /* Display: System */
    $handler = $view->new_display('system', 'System', 'admin_overview');
    $handler->display->display_options['defaults']['access'] = FALSE;
    $handler->display->display_options['path'] = '%%ENTITY_ADMIN_PATH%%';

    $export['%%ENTITY_VIEW_NAME%%'] = $view;
  }

  return $export;
}
