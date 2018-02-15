/**
 * Created by Sergey Grigorenko (svipsa@gmail.com) on 06.05.15.
 */
(function ($) {
    Drupal.behaviors.octCustomFtbForm = {
        attach: function (context, settings) {
          var $form = $(".node-fairy-tale-ball-form"),
              $form_row = $form.find(".ftb-form-row"),
              $spons_row = $form.find(".ftb-form-spons-row"),
              $wish_row = $form.find(".wtb-wish-donate"),
              $wish_cost_inp = $($wish_row).find("#edit-wish-donate-cost"),
              $this = this;

            $this.formRecalculate();

            $form_row.each(function(i, el){
                $(el).find("select").change(function(){
                    $this.formRecalculate();
                });
            });

            $spons_row.each(function(i, el){
                $(el).find("input[type=checkbox]").change(function(){
                    $this.formRecalculate();
                });
            });

            $wish_cost_inp.keyup(function(i, el){
                $this.formRecalculate();
            });

            $($wish_row).find("input[type=checkbox]").change(function(){
                if (!$(this).prop("checked")){
                    $wish_cost_inp.val("");
                }
                $this.formRecalculate();
            });


        },

        formRecalculate: function(){
            var total = 0.00;
            var fee = 3; // percent
            var description = '';

            var $form = $(".node-fairy-tale-ball-form"),
                $form_row = $form.find(".ftb-form-row"),
                $spons_row = $form.find(".ftb-form-spons-row"),
                $wish_row = $form.find(".wtb-wish-donate"),

                $total_el = $form.find("#edit-total"),
                $fee_el = $form.find("#edit-handling-fee"),
                $total_cost_el = $form.find("#edit-total-attendee-cost"),
                $description_el = $form.find("#edit-description")
                ;

            // rows
            $form_row.each(function(i, el){
                var count = $(el).find("select option:selected").val();
                var input_el = $(el).find("input");
                if (count > 0) {
                    var label = $(el).find(".ftb-form-item label").text();
                    var cost = $(el).find(".ftb-cost").text();
                    var subtotal = parseInt(cost) * parseInt(count);
                    input_el.val(subtotal);
                    total += subtotal;
                    description += label + " (" + count + ")\r\n";
                } else {
                    input_el.val(0);
                }
            });

            // Sponsorships
            $spons_row.each(function(i, el){
                var checkbox = $(el).find("input[type=checkbox]");
                if (checkbox.prop("checked")){
                    var label = $(el).find(".ftb-form-item label").text();
                    var cost = $(el).find(".ftb-spons-cost").text();
                    total += parseInt(cost);
                    description += label + " (Sponsorships)" + "\r\n";
                }
            });


            // Wish donate
            var wish_checkbox = $wish_row.find("input[type=checkbox]");
            if (wish_checkbox.prop("checked")){
                var wish_cost = $wish_row.find("#edit-wish-donate-cost").val()
                var label = $wish_row.find(".form-item-wish-donate-checkbox label").text();
                var subtotal = parseInt(wish_cost);
                if (subtotal > 0){
                    total += parseInt(subtotal);
                    description += label + " ($" + parseInt(subtotal) + ")" + "\r\n";
                }
            }



            var fee = total * fee / 100;
            var total_cost = total + fee;
            $total_el.val(total.toFixed(2));
            $fee_el.val(fee.toFixed(2));
            $total_cost_el.val(total_cost.toFixed(2));

            $description_el.val(description);

            //console.log(total);

        },

        completedCallback: function () {
            // Do nothing. But it's here in case other modules/themes want to override it.
        }
    }
})(jQuery);