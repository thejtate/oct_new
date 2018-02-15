(function ($) {

    if (typeof Drupal != 'undefined') {
        Drupal.behaviors.oct = {
            attach: function (context, settings) {
                init();
            },

            completedCallback: function () {
                // Do nothing. But it's here in case other modules/themes want to override it.
            }
        }
    }

    $(function () {
        if (typeof Drupal == 'undefined') {
            init();
        }

        $(window).load(function () {
            initNavHeight();
          initFormStyler();
        });
    });

    function init() {

    }


  function initFormStyler() {
    $('.content-wrapper select').styler({
      selectPlaceholder: 'Select...'
    });
  }

    function initNavHeight() {
        var $elem = $('.site-header .nav > ul > li');

        for (var i = 0; i < $elem.length; i++) {
            $elem.eq(i).css({height: 55 + i});
        }
    }

})(jQuery);