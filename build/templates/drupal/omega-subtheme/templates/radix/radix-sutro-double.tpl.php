<?php
/**
 * @file
 * Template for Radix Sutro Double.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display sutro-double clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="container-fluid">
    <?php if ($content['header']): ?>
      <div class="col-md-12 sutro-double-header panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['header']; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($content['column1'] || $content['column2']): ?>
      <div class="sutro-double-first-wrapper clearfix">
        <div class="col-md-6 sutro-double-column1 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['column1']; ?>
          </div>
        </div>
        <div class="col-md-6 sutro-double-column2 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['column2']; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($content['middle']): ?>
      <div class="col-md-12 sutro-double-middle panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['middle']; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($content['secondcolumn1'] || $content['secondcolumn2']): ?>
      <div class="sutro-double-second-wrapper clearfix">
        <div class="col-md-6 sutro-double-secondcolumn1 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['secondcolumn1']; ?>
          </div>
        </div>
        <div class="col-md-6 sutro-double-secondcolumn2 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['secondcolumn2']; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($content['footer']): ?>
      <div class="col-md-12 sutro-double-footer panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['footer']; ?>
        </div>
      </div>
    <?php endif; ?>
  </div>

</div><!-- /.sutro-double -->
