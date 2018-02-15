(function ($) {
    Drupal.behaviors.octStoreProductionCalculation = {
        attach: function (context, settings) {

            $('.ftb-calculation-form').once('ftb-calculation-form', function () {
                var $form = $(this)
                    ,$tickets_selectors = $form.find('select.ticket')
                    ,$totals = $form.find('strong.totals')
                    ,$fees = $form.find('td.fee');

                //init run
                totalsCalculation();

                $tickets_selectors.change(totalsCalculation);

                function totalsCalculation() {
                    var total = 0
                        ,fees = 0
                        ,tickets = 0;

                    $tickets_selectors.each(function() {
                        var $this = $(this)
                            ,ticketCount = $this.val()
                            ,subtotal = ticketCount  * $this.data('price')
                            ,$row = $this.parents('tr');

                        $row.find('td.subtotal').html(formatPrice(subtotal));
                        total += +subtotal;
                        tickets += +ticketCount;
                        //Names visibility
                        $row.find('input.guest-names').each(function(i, el) {
                            if(i >= ticketCount) {
                                $(el).parents('.form-item').hide();
                            } else {
                                $(el).parents('.form-item').show();
                            }
                            //console.log(i);
                            //console.log(v);
                        });
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
                }

                function formatPrice(val) {
                    return '$ ' +  val.toFixed(2);
                }
            });

        }
    };
})(jQuery);