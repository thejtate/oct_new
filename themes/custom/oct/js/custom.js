(function ($) {

    Drupal.behaviors.octCustom = {
        attach: function (context, settings) {
            initSocialBlock();
            initDonationBlock();
        },

        completedCallback: function () {
            // Do nothing. But it's here in case other modules/themes want to override it.
        }
    }



    function initSocialBlock(){
      $(".donation", "#block-oct-custom-oct-custom-social-block").find('a[href="#"]').click(function(e){
          e.preventDefault();
          $(".donation", "#block-oct-custom-oct-custom-social-block").find(".paypal-donate-form").submit();
      });
    }

    function initDonationBlock(){
        $(".make-donation-wrapper").find('a[href="#"]').click(function(e){
            e.preventDefault();
            $(".make-donation-code", ".make-donation-wrapper").find(".paypal-donate-form").submit();
        });
    }




})(jQuery);