(function ($) {

  Drupal.behaviors.octStoreCcForm = {
    attach: function (context, settings) {

        $('.radios-clear-click').once('radio_clear_click', clear_radiobutton_on_second_click_handler);

        ccFormActions($('#oct-store-camps-form-wrapper'));


    }
    //,detach = function(context, settings) {}
  };

    function ccFormActions($formWrap) {
        if(!$formWrap.length) return;

        var $productCheckboxes = $formWrap.find('table.products-table input')
            ,$resultsTable = $formWrap.find('div.results table')
            ,childrenCount = $resultsTable.find('tbody tr').length
            ,$bdayDateWrappers = $formWrap.find('.birthday-wrap')
            ,$bdayDateInputs = $bdayDateWrappers.find('select');

        init();

        function init() {

            $productCheckboxes.once('results-calculations').on('change', calculateResults);
            $bdayDateInputs.once('age-access').on('change', ageAccesabilityHandler);
            openSelectedCampsGroups();
            //ageAccesability();
            initAgeAccess();
            calculateResults();
        }

        function initAgeAccess() {
            $bdayDateWrappers.each(function(){
                ageAccesability($(this));
            });
        }

        function ageAccesabilityHandler(e) {
            ageAccesability($(e.target).parents('.birthday-wrap'));
            calculateResults();
        }

        function ageAccesability($dateWrap) {
            var day = $dateWrap.find('select.date-day').val()
                ,month = $dateWrap.find('select.date-month').val()
                ,year = $dateWrap.find('select.date-year').val()
                ,age = calculateAge(new Date(year, month - 1, day))
                ,childNumber = $dateWrap.data('child');

            $productCheckboxes.filter('[data-child="' + childNumber + '"]').each(function() {
                var $this = $(this)
                    ,minAge = $this.data('min-age')
                    ,maxAge = $this.data('max-age')
                    ,$productWrap = $this.parents('td.child');

                if((!day || !month || !year ||age < minAge || age > maxAge)) {
                    this.checked = false;
                    if(!$productWrap.hasClass('disabled')) {
                        $productWrap.addClass('disabled');
                    }
                } else {
                    $productWrap.removeClass('disabled');
                }

            });
        }



        function calculateAge(birthday) { // birthday is a date
            var ageDifMs = Date.now() - birthday.getTime();
            var ageDate = new Date(ageDifMs); // miliseconds from epoch
            return Math.abs(ageDate.getUTCFullYear() - 1970);
        }

        function calculateResults() {

            for (var i = 0; i < childrenCount; i++) {
                var count = 0,
                    total = 0;

                $productCheckboxes.filter('[data-child="' + i + '"]:checked').each(function(v, i){
                    var $elem = $(this);
                    count++;
                    total += parseFloat($elem.data('price'));
                });

                var $childRow = $resultsTable.find('tr.child-' + i);

                $childRow.find('td.camps').html(count);
                $childRow.find('td.subtotal').html('$' + total.toFixed(2));
            }

        }

        function openSelectedCampsGroups() {
            $productCheckboxes.filter(':checked').parents('.product-section-wrapper').each(function(){
                openCampsGroup($(this));
            });
        }

        function openCampsGroup($group) {
            var $sectionHeader = $group.find('.section-name');
            if(!$sectionHeader.hasClass('active')) {
                $sectionHeader.addClass('active');
                $group.find('.products-table').show();
            }
        }
    }

    /**
     * Function for uncheck radio buttons.
     */
    function clear_radiobutton_on_second_click_handler() {
        var $wrap = $(this)
            ,$radios = $wrap.find('input[type=radio]')
            ,checkedRadios = [];

        $radios.click(function () {
            var $this = $(this);

            if (checkedRadios[$this.prop('name')] == this) {
                this.checked = false;

                checkedRadios[$this.prop('name')] = null;
            } else {
                checkedRadios[$this.prop('name')] = this;
            }
        });
    }


})(jQuery);
