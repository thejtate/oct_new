(function ($) {
    Drupal.behaviors.fnlStoreEditableStatus = {
      attach: function (context, settings) {

          $('select[data-editable="order_status"]', context).once('task-status-editable', function() {
              var $elem = $(this);
              $elem.change(function(){
                  var $this = $(this),
                      val = $this.val(),
                      order_id = $this.data('order-id'),
                      loader_placeholder_id = "#" + $this.data('loader-placeholder-id'),
                      url = Drupal.settings.basePath + "store/order-status/edit/" + order_id + "/" + val;

                  var ajax_options = {
                      url: url,
                      progress: {'type': 'throbber', message: Drupal.t('Please wait')},
                      element: this
                  };

                  var ajax = new Drupal.ajax(false, loader_placeholder_id, ajax_options);
                  ajax.eventResponse(ajax, {});

              })
          });

      }
    };
})(jQuery);