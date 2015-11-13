<?php
/**
 * @file
 *
 */

namespace Drupal\%%MACHINE_NAME%%\Entity\MetadataController;

/**
 * controller for generating some basic metadata for CRUD entity types.
 */
class %%ENTITY_CLASS_NAME%% extends \EntityDefaultMetadataController {

  /**
   * (@inheritdoc)
   */
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['%%ENTITY_PRIMARY_KEY%%'] = array(
      'label' => t('%%ENTITY_TITLE%% ID'),
      'description' => t('The internal numeric ID of the %%ENTITY_LOWERCASE_NAME%%.'),
      'type' => 'integer',
      'schema field' => '%%ENTITY_PRIMARY_KEY%%',
    );

    $properties['label'] = array(
      'label' => t('Label'),
      'description' => t('Label of the %%ENTITY_LOWERCASE_NAME%%.'),
      'type' => 'text',
      'required' => TRUE,
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'schema field' => 'label',
    );

    $properties['language'] = array(
      'label' => t('Language'),
      'type' => 'token',
      'description' => t('The language the %%ENTITY_LOWERCASE_NAME%% was created in.'),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer %%MACHINE_NAME%% entities',
      'options list' => 'entity_metadata_language_list',
      'schema field' => 'language',
    );

    $properties['status'] = array(
      'label' => t('Status'),
      'description' => t('Boolean indicating whether the %%ENTITY_LOWERCASE_NAME%% is active or disabled.'),
      'type' => 'boolean',
      'options list' => '%%MACHINE_NAME%%_status_options_list',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer %%MACHINE_NAME%% entities',
      'schema field' => 'status',
    );

    $properties['user'] = array(
      'label' => t('User'),
      'type' => 'user',
      'description' => t('The user who created the %%ENTITY_LOWERCASE_NAME%%.'),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'setter permission' => 'administer %%MACHINE_NAME%% entities',
      'required' => TRUE,
      'schema field' => 'uid',
    );

    $properties['created'] = array(
      'label' => t('Date submitted'),
      'type' => 'date',
      'description' => t('The date %%ENTITY_LOWERCASE_NAME%% was created.'),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer %%MACHINE_NAME%% entities',
      'required' => TRUE,
      'schema field' => 'created',
    );
    $properties['changed'] = array(
      'label' => t('Date changed'),
      'type' => 'date',
      'description' => t('The date the %%ENTITY_LOWERCASE_NAME%% was most recently updated.'),
      'setter callback' => 'entity_property_verbatim_set',
      'query callback' => 'entity_metadata_table_query',
      'setter permission' => 'administer %%MACHINE_NAME%% entities',
      'schema field' => 'changed',
    );

    // Type property is created in parent::entityPropertyInfo().
    $properties['type']['label'] = t('%%ENTITY_TITLE%% type');
    $properties['type']['type'] = '%%MACHINE_NAME%%_type';
    $properties['type']['schema field'] = 'type';
    $properties['type']['description'] = t('The %%ENTITY_LOWERCASE_NAME%% type.');

    // @todo This line could be removed depending on this http://drupal.org/node/1931376
    $properties['type']['required'] = TRUE;

    $properties['type']['setter callback'] = 'entity_property_verbatim_set';
    $properties['type']['setter permission'] = 'administer %%MACHINE_NAME%% entities';

    return $info;
  }

}
