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

      // Insert the graph.

      $('<div class="dcco-register-graph" style="width: 100%; border: 1px solid #ff6c54; border-radius: 3px;"><div class="bar" style="width: ' + percentRounded + '%; height: 50px; background: #f6a06b;"></div></div>').appendTo('.view-dcco-register-total-contributions .view-header');

      // Insert the price points.

      $('<li class="button--secondary margin--bottom">' + Drupal.t('Free Level') + '</li>')
        .click(function(){
          $('#edit-amount').val('0');
        })
        .appendTo(pricePoints);

      $('<li class="button--secondary margin--bottom">' + Drupal.t('$25 - Contributor Level' + '<br/>' + '(free T-shirt)') + '</li>')
        .click(function(){
          $('#edit-amount').val('25');
        })
        .appendTo(pricePoints);

      $('<li class="button--secondary">' +  Drupal.t('$50 - Yeti Level' + '<br/>' + '(free T-shirt + awesomeness)') + '</li>')
        .click(function(){
          $('#edit-amount').val('50');
        })
        .appendTo(pricePoints);

      pricePoints.prependTo('#dcco-register-registration');

      $('<p>Contribute $25.00 or more and receive a DrupalCamp 2015 T-shirt while supplies last.</p>').prependTo('#dcco-register-registration');

    }

  };

})(jQuery);
