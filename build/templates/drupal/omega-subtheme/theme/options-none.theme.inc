<?php

/**
 * Returns HTML for the label for the empty value for options that are not required.
 *
 * @see theme_options_none()
 * @ingroup themeable
 */
function %%MACHINE_NAME%%_options_none($variables) {
  $instance = $variables['instance'];
  $option = $variables['option'];

  $output = '';
  switch ($instance['widget']['type']) {
    case 'options_buttons':
      $output = t('N/A');
      break;

    case 'options_select':
      if (!empty($instance['label'])) {
        $output = $instance['label'];

        if ($instance['required']) {
          $output .= ' *';
        }
      }
      else {
        $output = ($option == 'option_none' ? t('- None -') : t('- Select a value -'));
      }
      break;
  }

  return $output;
}
