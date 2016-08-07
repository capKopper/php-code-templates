(function ($) {

  /**
   * Provide a button for toggle the navbar.
   */
  Drupal.theme.prototype.%%MACHINE_NAME%%NavbarButton = function (title, classes) {
    if (!title) {
      var title = Drupal.t('Toggle menu');
    }
    var classes = classes ? ' ' + classes : '';
    return $('<a href="javascript:;" class="navbar-button' + classes + '" title="' + title + '"></a>');
  };

  /**
   * Provide a mask DIV.
   */
  Drupal.theme.prototype.%%MACHINE_NAME%%NavbarMask = function () {
    return $('<div class="navbar-mask"></div>');
  };

  /**
   * Process the main menu.
   *
   * @param context
   *   The context for which the behavior is being executed. This is either the
   *   full page or a piece of HTML that was just added through Ajax.
   * @param settings
   *   An array of settings (added through drupal_add_js()). Instead of accessing
   *   Drupal.settings directly you should use this because of potential
   *   modifications made by the Ajax callback that also produced 'context'.
   */
  Drupal.behaviors.%%MACHINE_NAME%%Navbar = {
    wrapper: null,
    button: null,
    mask: null,
    mobileState: false,

    /**
     * The breakpoints for which the mobile mode should be enabled.
     *
     * @type Array
     */
    breakpoints: [],

    attach: function (context, settings) {
      var behavior = this;
      var %%MACHINE_NAME%%Settings = settings.%%MACHINE_NAME%% || {};
      var navbarSettings = %%MACHINE_NAME%%Settings.navbar || {};

      behavior.breakpoints = navbarSettings.breakpoints || [];

      if (behavior.breakpoints && navbarSettings.wrapper) {
        $(navbarSettings.wrapper, context).once('%%MACHINE_NAME%%-navbar', function () {
          behavior.wrapper = $(this);
          behavior.wrapper.children().wrapAll('<div class="navbar-content"></div>')
          behavior.button = $(Drupal.theme('%%MACHINE_NAME%%NavbarButton')).insertBefore(behavior.wrapper);
          behavior.mask = $(Drupal.theme('%%MACHINE_NAME%%NavbarMask')).prependTo('.l-page');

          $(document).on('breakpointMatch', function(e) {
            if ($.inArray(e.breakpoint, behavior.breakpoints) < 0) {
              behavior.disableMobileNavbar();
            }
            else {
              behavior.enableMobileNavbar();
            }
          });
        });
      }
    },

    enableMobileNavbar: function() {
      if (this.wrapper && !this.mobileState) {
        var behavior = this;
        behavior.mobileState = true;
        behavior.button.on('click', behavior.toggleMenu);
        behavior.mask.bind('click', behavior.toggleMenu);
      }
    },

    disableMobileNavbar: function() {
      if (this.wrapper && this.mobileState) {
        var behavior = this;
        behavior.mobileState = false;
        behavior.button.unbind('click');
        behavior.mask.unbind('click');
        $('.l-page').removeClass('menu-visible');
      }
    },

    toggleMenu: function() {
      $('body').toggleClass('menu-visible');
    }

  };

})(jQuery);
