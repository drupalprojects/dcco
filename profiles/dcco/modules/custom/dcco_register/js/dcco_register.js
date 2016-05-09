(function ($) {

  Drupal.behaviors.dcco_register = {

    attach: function(context) {

      var current = Number($('.dcco-register-current').text().replace(/[^0-9\.]+/g,''));
      var total = Number($('.dcco-register-total').text().replace(/[^0-9\.]+/g,''));
      var percent = (current * 100)/total;
      var percentRounded = Math.ceil(percent * 100) / 100;
      var pricePoints = $('<ul class="dcco-register-price-points no-bullets"></ul>');

      if (percentRounded > 110) {
        percentRounded = 110;
      }

      function scrollToSubmit() {
        $('html, body').animate({
          scrollTop: $("#edit-submit").offset().top
        }, 2000);
      }

      // Insert the graph.

      $('<div class="dcco-register-graph" style="width: 100%; border: 1px solid #004499; border-radius: 3px;"><div class="bar" style="width: ' + percentRounded + '%; height: 50px; background: #00388d;"></div></div>').appendTo('.view-dcco-register-total-contributions .view-header');

      // Insert the price points.

      $('<li><button class="button--secondary margin--bottom">' + Drupal.t('Free Level') + '</button></li>')
        .click(function(){
          $('#edit-amount').val('0'); scrollToSubmit();
        })
        .appendTo(pricePoints);

      $('<li><button class="button--secondary margin--bottom">' + Drupal.t('$25 - Contributor Level') + '</button><p>Free T-shirt</p></li>')
        .click(function(){
          $('#edit-amount').val('25'); scrollToSubmit()
        })
        .appendTo(pricePoints);

      $('<li><button class="button--secondary margin--top">' +  Drupal.t('$50 - Yeti Level') + '</button><p>Free T-shirt + Awesomeness</p></li>')
        .click(function(){
          $('#edit-amount').val('50'); scrollToSubmit();
        })
        .appendTo(pricePoints);

      pricePoints.prependTo('#dcco-register-registration');

      $('<p>Contribute $25.00 or more and receive a DrupalCamp 2016 T-shirt while supplies last.</p>').prependTo('#dcco-register-registration');

    }

  };

})(jQuery);
