<?php
/**
 * @file
 * Template for Radix Sutro.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display sutro clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="sutro-header panel-panel">
    <div class="panel-panel-inner">
      <?php print $content['header']; ?>
    </div>
  </div>

  <div class="sutro-content-wrapper panel-panel-wrapper">
    <div class="col-md-6 sutro-column1 panel-panel">
      <div class="panel-panel-inner">
        <?php print $content['column1']; ?>
      </div>
    </div>
    <div class="col-md-6 sutro-column2 panel-panel">
      <div class="panel-panel-inner">
        <?php print $content['column2']; ?>
      </div>
    </div>
  </div>

  <div class="sutro-footer panel-panel">
    <div class="panel-panel-inner">
      <?php print $content['footer']; ?>
    </div>
  </div>

</div><!-- /.sutro -->
