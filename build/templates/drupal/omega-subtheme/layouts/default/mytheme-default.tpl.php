<?php
/**
 * @file
 * Template for %%THEME_TITLE%% default.
 */
?>
<div<?php print $attributes; ?>>
  <header class="l-header" role="banner">
    <div class="l-header-inside">
      <?php print render($page['header']); ?>

      <div class="l-navigation">
        <?php print render($page['navigation']); ?>
      </div>
    </div>
  </header>

  <div class="l-highlight">
    <div class="l-highlight-inside">
      <?php print render($page['highlight']); ?>
    </div>
  </div>

  <div class="page-container">
    <div class="l-main">
      <div class="l-main-inside">
        <a name="main-content"></a>
        <section class="l-content" role="main">
          <?php print render($page['content']); ?>
        </section>
      </div>
    </div>

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="l-sidebar">
        <div class="l-sidebar-inside">
          <?php print render($page['sidebar_first']); ?>
        </div>
      </aside>
    <?php endif; ?>
  </div>

  <footer class="l-footer" role="contentinfo">
    <div class="l-footer-top">
      <div class="l-footer-top-inside">
        <?php print render($page['footer_top']); ?>
      </div>
    </div>

    <div class="l-footer-bottom">
      <div class="l-footer-bottom-inside">
        <?php print render($page['footer_bottom']); ?>
      </div>
    </div>
  </footer>
</div>
