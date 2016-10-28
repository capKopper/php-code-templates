(function ($, window, Drupal) {

  /**
   * Attach various behaviors related to %%THEME_TITLE%% theme.
   */
  Drupal.behaviors.%%MACHINE_NAME%% = {

    attach: function (context, settings) {
      var %%MACHINE_NAME%%Settings = settings.%%MACHINE_NAME%% || {};

      this.externalLinks(context, %%MACHINE_NAME%%Settings);
      this.fileStyle(context, %%MACHINE_NAME%%Settings);
    },

    /**
     * Open external links in a new window.
     */
    externalLinks: function() {
      $('a[rel~="external"]').once('external').click( function() {
        window.open($(this).attr('href'));
        return false;
      });
    },

    /**
     * Style the file inputs using jQuery.fileStyle
     */
    fileStyle: function(context, settings) {
      if (settings.filestyle) {
        for (var id in settings.filestyle) {
          $(id).once('jfilestyle').jfilestyle(settings.filestyle[id]);
        }
      }
    }

  }

})(jQuery, window, Drupal);
