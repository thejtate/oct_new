(function ($) {
    var formController = null;

    Drupal.behaviors.octStoreProductionCalculation = {
      attach: function (context, settings) {

          $('.complimentary-calculation-form', context).once('complimentary-calculation', function() {
              formController = new FormController($(this));
          });

          if(formController) {
              formController.totalsCalculation();
              formController.countComplimentraryTickets();
          }
      }
    };

     function FormController($form) {
        var $complimentrary_tickets_selectors = $form.find('.complimentary-calculation')
            ,$tickets_selectors = $form.find('select.ticket')
            ,$complimentrary_result = $form.find('.complimentary-calculation-result')
            ,$totals = $form.find('strong.totals')
            ,childs_for_ticket = Drupal.settings.children_count_for_free_ticket
            ,$fees = $form.find('td.fee')
            ,self = this;

        $complimentrary_tickets_selectors.change(function() {self.countComplimentraryTickets()});
        $tickets_selectors.change(function() {self.totalsCalculation()});

        this.countComplimentraryTickets = function() {
            var totalChildrenCount = 0;

            $complimentrary_tickets_selectors.each(function(e){
                totalChildrenCount += parseInt($(this).val());
            });

            var freeTickets = Math.floor(totalChildrenCount/childs_for_ticket);

            $complimentrary_result.html(freeTickets);
        };

        this.totalsCalculation = function() {
            var total = 0
                ,fees = 0
                ,tickets = 0;

            $tickets_selectors.each(function() {
                var $this = $(this)
                    ,ticketCount = $this.val()
                    ,subtotal = ticketCount  * $this.data('price');

                $this.parents('tr').find('td.subtotal').html(formatPrice(subtotal));
                total += +subtotal;
                tickets += +ticketCount;
            });

            if(total !== 0) {
                $fees.each(function() {
                    var $this = $(this)
                        ,feeType = $this.data('type')
                        ,amount = $this.data('amount');

                    var fee = (feeType == 'percent') ? total * amount * 0.01 : amount;
                    $this.html(formatPrice(fee));
                    fees += +fee;
                });

                total = total + fees;
            }

            $totals.html(formatPrice(total));
        };

        function formatPrice(val) {
            return '$ ' +  val.toFixed(2);
        }

    }

})(jQuery);