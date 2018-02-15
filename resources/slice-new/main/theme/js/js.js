(function ($) {

  if (typeof Drupal != 'undefined') {
    Drupal.behaviors.projectName = {
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
      initFix();
    });
  });

  function init() {
    initDropDownFaq();
    initColumn();
    initElmsAnimation();
    initButtonTop();
    initSelect();
    initFix();
    initCampAccordion();
    initslider();
    initMobileNav();
    initFullWidthBlock();
  }

  function initFullWidthBlock() {
    var $elements = $(".full-block"),
      minWidth = 0;

    $(window).on('resize', setPosition);
    setPosition();

    function setPosition() {
      var $winWidth = $(window).outerWidth(),
        width;

      if ($winWidth > minWidth) {
        width = $winWidth;
      } else {
        width = minWidth;
      }

      $elements.width(width);
      $elements.css('margin-left', '-' + width / 2 + 'px');
    }
  }

  function initElmsAnimation() {

    var $elms = $('.el-with-animation');
    var animationEnd = [];

    $(window).on('resize scroll', checkScroll);

    checkScroll();

    function checkScroll() {
      if (animationEnd.length === $elms.length) return;

      for (var i = 0; i < $elms.length; i++) {
        var $currentEl = $elms.eq(i);
        if (!$currentEl.hasClass('animating-end') && $(window).height() + $(window).scrollTop() > $currentEl.offset().top + $currentEl.height() / 2 + 50) {
          animate($currentEl);
        }
      }
    }

    function animate(el) {
      el.addClass('animating-end');
      animationEnd.push(1);
    }

  }

  function initMobileNav() {
    var btn = document.querySelector('.btn-nav');

    if(!btn || btn.classList.contains('btn-nav-processed')) return;

    btn.classList.add('btn-nav-processed');

    btn.addEventListener('click', function(e) {
      e.preventDefault();

      document.body.classList.toggle('mobile-nav');
    });

    var $nav = $('.site-header .nav');
    var $navLiExpanded = $nav.find('li.expanded');
    var insert = $('<a class="btn-mobile" href="#"></a>');

    if (!$navLiExpanded.length) return;

    $navLiExpanded.prepend(insert);

    var $navLiExpandedUl = $navLiExpanded.find('ul.menu');
    var winWidth = $(window).outerWidth();

    $(window).on('resize', function () {
        if (winWidth > 768) {
          $navLiExpandedUl.attr('style', '');
          $navLiExpanded.removeClass('nav-active');
        }
    });

    var $btnNav = $nav.find('.btn-mobile');

    $btnNav.on('click touch', checkNav);

    function checkNav(e) {
      e.preventDefault();

      var $this = $(this).parent();
      var $thisUl = $(this).siblings('ul.menu');

      if ($this.hasClass('nav-active')) {
        $this.removeClass('nav-active');
        $thisUl.slideUp();

      } else {
        $this.siblings().removeClass('nav-active');
        $this.addClass('nav-active');
        $this.siblings().find('ul.menu').slideUp();
        $thisUl.slideDown();
      }
    }
  }

  function initslider(){
    $('.center').slick({
      centerMode: true,
      autoplay: true,
      infinite: true,
      dots:true,
      autoplaySpeed: 2000,
      arrows:false,
      variableWidth:true,
      slidesToShow: 1
    });
  }



  function initSelect() {
    $('select').select2({
      minimumResultsForSearch: Infinity,
      width: 'full'
    });
  }

  function initCampAccordion() {
    var $elem = $('.products-wrapper .section-name');

    $elem.eq(0).addClass('active');
    $('.product-section-wrapper').eq(0).find('.products-table').show();

    $elem.on('click', function () {
      var $this = $(this),
        $dropdown = $this.parent('.product-section-wrapper').find('.products-table');

      if ($this.hasClass('active')) {
        $dropdown.hide();
        $this.removeClass('active');
      } else {
        $dropdown.show();
        $this.addClass('active');
      }
    })
  }

  function initFix() {
    var $productHead =  $('.products-head');

    if (!$productHead.length) return;

    var $head = $('.products-wrapper'),
      $result = $('.results'),
      $header_position = $productHead.offset();

    $(window).on('resize', function () {
      $header_position = $productHead.offset();
    });

    $(window).on('scroll', function () {

      var $scroll = $(this).scrollTop();

      if ($scroll > $header_position.top) {
        $head.addClass('fixed');
        $result.css('top', $scroll - $header_position.top + 74);
      } else {
        $head.removeClass('fixed');
      }
    });
  }


  function initDropDownFaq() {
    var $link = $('.page-faq .item');

    $link.on('click', function () {

      var $drop = $(this).find('.desc');

      if ($(this).hasClass('active')) {
        $(this).removeClass('active');
        $drop.slideUp();

      } else {
        $link.removeClass('active');
        $link.find('.desc').slideUp();
        $(this).addClass('active');
        $drop.slideDown();
      }
    })
  }

  function initColumn() {
    $('.colums').columnize({
      columns: 2
    });
  }

  function initButtonTop() {
    var $btn = $('.btn-top a');


    $(window).bind('scroll', function () {

      var $scroll = $(this).scrollTop();

      if ($scroll > 300) {
        $('.btn-top').addClass('active');
      } else {
        $('.btn-top').removeClass('active');
      }
    });

    $btn.on('click', function (e) {
      e.preventDefault();

      $('html, body').animate({scrollTop: $('#site-header').offset().top}, 1000);
      return false;
    });
  }

})(jQuery);