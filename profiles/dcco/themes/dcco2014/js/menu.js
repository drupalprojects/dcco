(function($){
  Drupal.behaviors.emplementMenu = {
    attach: function (context, settings) {
      $('#page', context).once('asdfasdf', function(){
        var mainNav = responsiveNav('block-system-main-menu', {
          label: '<span class="mobile-main-menu icon-bars">Menu</span>'
        });
        if ($('#block-system-user-menu', context).length) {
          var userNav = responsiveNav('block-system-user-menu', {
            label: '<span class="mobile-user-menu icon-user">User Menu</span>'
          });
        };
      });
    }
  }
})(jQuery);
