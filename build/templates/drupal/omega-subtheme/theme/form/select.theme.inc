<?php

/**
 * @file
 * Contains the theme function override for 'select'.
 */

/**
 * Returns HTML for a select form element.
 *
 * Just wrap the select tag to facilitate advanced theming.
 *
 * @ingroup themeable
 */
function %%MACHINE_NAME%%_select($variables) {
  return '<div class="form-select-wrapper">' . theme_select($variables) . '</div>';
}
