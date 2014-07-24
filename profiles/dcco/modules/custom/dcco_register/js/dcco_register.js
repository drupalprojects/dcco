(function ($) {

  Drupal.behaviors.dcco_register = {

    attach: function(context) {

      var current = Number($('.dcco-register-current').text().replace(/[^0-9\.]+/g,''));
      var total = Number($('.dcco-register-total').text().replace(/[^0-9\.]+/g,''));
      var percent = (current * 100)/total;
      var percentRounded = Math.ceil(percent * 100) / 100;
      var pricePoints = $('<ul class="dcco-register-price-points"></ul>');

      if (percentRounded > 110) {
        percentRounded = 110;
      }

      // Insert the graph.

      $('<div class="dcco-register-graph" style="width: 100%; border: 1px solid #999; border-radius: 3px;"><div class="bar" style="width: ' + percentRounded + '%; height: 50px; background: #00C584;"></div></div>').appendTo('.view-dcco-register-total-contributions .view-header');

      // Insert the price points.

      $('<li>' + Drupal.t('Contribute $25 or more and get a t-shirt! (while supplies last)') + '</li>')
        .click(function(){
          $('#edit-amount').val('25');
        })
        .appendTo(pricePoints);

      $('<li>' +  Drupal.t('Contribute $50 or more and be awesome! (forever)') + '</li>')
        .click(function(){
          $('#edit-amount').val('50');
        })
        .appendTo(pricePoints);

      pricePoints.prependTo('#dcco-register-registration');

    }

  };

})(jQuery);
