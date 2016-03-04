(function ($, window, Drupal) {

  'use strict';

  /**
   * Toggles media-query specific body classes.
   *
   * You can define new media queries to listen to by writing them into the
   * Drupal.settings.%%MACHINE_NAME%%.mediaQueries array.
   *
   * This is an override of the Omega behavior:
   * - it do not use the Match Media timer, but the window resize event.
   * - it trigger a specific "breakpointMatch" event that can be catch by other
   *   scripts.
   *
   * Example, where myBreakpoints is an array of breakpoints:
   * <code>
   * $(document).on('breakpointMatch', function(e) {
   *   if ($.inArray(e.breakpoint, myBreakpoints) < 0) {
   *     doSomething();
   * }
   * else {
   *     doSomethingElse();
   *   }
   * );
   * </code>
   */
  Drupal.behaviors.%%MACHINE_NAME%%MediaQueryClasses = {
    mediaQueries: {},
    currentMedia: null,

    handler: function (name, mql) {
      var behavior = this;

      if (mql.matches) {
        if (!behavior.currentMedia || behavior.currentMedia != name) {
          $('body').removeClass(name + '-inactive').addClass(name + '-active');

          $.event.trigger({
            type: 'breakpointMatch',
            breakpoint: name,
            oldMedia: behavior.currentMedia
          });

          behavior.currentMedia = name;
        }
      }
      else {
        $('body').removeClass(name + '-active').addClass(name + '-inactive');
      }
    },

    attach: function (context, settings) {
      var behavior = this;
      var %%MACHINE_NAME%%Settings = settings.%%MACHINE_NAME%% || {};
      behavior.mediaQueries = %%MACHINE_NAME%%Settings.mediaQueries || {};

      $('body', context).once('%%MACHINE_NAME%%-mediaqueries', function () {
        if (behavior.mediaQueries) {
          $(window).resize(function() {
            $.each(behavior.mediaQueries, function (index, value) {
              behavior.handler(index, window.matchMedia(value));
            });
          });

          $(window).trigger('resize');
        }
      });
    }
  };

})(jQuery, window, Drupal);
