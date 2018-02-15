<?php $title = 'name'; ?>
<?php include 'tpl/includes/head.inc'; ?>
<body class="page page-store-camps">
<div class="outer-wrapper">
<?php include 'tpl/layout/header.inc'; ?>
<div class="inner-wrapper site-container">
<div class="button-go-page">
  <a href="#">Psst! Sneak check out our KIDS ONLY page!</a>
</div>
<div class="inner">
<div class="content-wrapper with-sidebar">
<aside class="sidebar sidebar-right">

  <div class="b-subscribe">
    <div class="b-subscribe-text">Enter your email for OCT updates!</div>
    <div class="b-subscribe-field">
      <div id="mc_embed_signup">
        <form
          action="//oklahomachildrenstheatre.us9.list-manage.com/subscribe/post?u=ccf807fb860604bfaaccd4da6&amp;id=70c766ed1c"
          method="post" id="mc-embedded-subscribe-form" name="mc-embedded-subscribe-form" class="validate"
          target="_blank" novalidate="">
          <div id="mc_embed_signup_scroll">
            <div class="mc-field-group">
              <input type="email" value="" name="EMAIL" class="required email text" id="mce-EMAIL">
              <input type="submit" value="" name="subscribe" id="mc-embedded-subscribe" class="button submit">
            </div>
            <div id="mce-responses" class="clear">
              <div class="response" id="mce-error-response" style="display:none"></div>
              <div class="response" id="mce-success-response" style="display:none"></div>
            </div>
          </div>
        </form>
      </div>
    </div>
  </div>

  <div class="b-sponsors">
    <div class="name">Sponsors</div>
    <div class="slider">
      <ul class="sponsors-list">
        <li><a href="#">MidFirst Bank</a></li>
        <li><a href="#">Oklahoma Arts Council</a></li>
        <li><a href="#">National Endowment for the Arts</a></li>
        <li><a href="#">Oklahoma City University</a></li>
        <li><a href="#">The Inasmuch Foundation</a></li>
        <li><a href="#">Allied Arts</a></li>
        <li><a href="#">Mercedes-Benz of OKC</a></li>
        <li><a href="#">MidFirst Bank</a></li>
        <li><a href="#">Oklahoma Arts Council</a></li>
      </ul>
    </div>
  </div>
  <div class="b-sidebar-links">
    <ul class="sidebar-links">
      <li class="facebook">Follow us on<a href="$">
          Facebook</a></li>
      <li class="calendar">View the<a href="#"> Calendar</a></li>
      <li class="member"><a href="#">Become a Member</a><br>Get season
        tickets, plus 10% off tuition for any camp or class!
      </li>
      <li class="donation"><a href="#">Make a Donation</a><br>Donations allow us to continue to
        bring arts education to the children of Oklahoma. Remember your gift is 100% tax
        deductible.
      </li>

    </ul>
  </div>
  <div class="oct-cart-block">
    <a href="/cart">Cart</a></div>
  <div class="sponsor-logos">

    <ul class="logos-list">
      <li><a href="#" target="_blank"><img src="theme/images/tmp/oklahoma_arts.png" alt=""></a></li>

      <li><a href="#" target="_blank"><img src="theme/images/tmp/allied_arts.png" alt=""> </a></li>

      <li><a href="#" target="_blank"><img src="theme/images/tmp/oklahomaCityUniversity.png" alt=""></a>
      </li>
    </ul>
  </div>

</aside>
<div class="site-container">
<h1>Camps</h1>


<div class="content-inner">
<div class="region region-content">
  <div id="block-system-main" class="block block-system">

    <div class="content">
      <form action="/store/camps" method="post" id="oct-store-cc-camp-form" accept-charset="UTF-8">
        <div>
          <div class="form-item form-type-textfield form-item-first-name">
            <label for="edit-first-name">First Name <span class="form-required"
                                                          title="This field is required.">*</span></label>
            <input type="text" id="edit-first-name" name="first_name" value="" size="60" maxlength="128"
                   class="form-text required">
          </div>
          <div class="form-item form-type-textfield form-item-last-name">
            <label for="edit-last-name">Last Name <span class="form-required"
                                                        title="This field is required.">*</span></label>
            <input type="text" id="edit-last-name" name="last_name" value="" size="60" maxlength="128"
                   class="form-text required">
          </div>
          <div class="form-item form-type-textarea form-item-allergy">
            <label for="edit-allergy">Does your child have a serious food allergy? </label>

            <div class="form-textarea-wrapper"><textarea id="edit-allergy" name="allergy" cols="60" rows="5"
                                                         class="form-textarea"></textarea></div>
          </div>
          <div class="container-inline-date">
            <div class="form-item form-type-date-select form-item-birth-date">
              <label for="edit-birth-date">Date of Birth <span class="form-required"
                                                               title="This field is required.">*</span></label>

              <div id="edit-birth-date" class="date-padding clearfix">
                <div class="form-item form-type-select form-item-birth-date-day">
                  <label for="edit-birth-date-day">Day <span class="form-required"
                                                             title="This field is required.">*</span></label>

                  <div class="date-day"><select class="date-day form-select required ajax-processed"
                                                id="edit-birth-date-day" name="birth_date[day]">
                      <option value="1" selected="selected">1</option>
                      <option value="2">2</option>
                      <option value="3">3</option>
                      <option value="4">4</option>
                      <option value="5">5</option>
                      <option value="6">6</option>
                      <option value="7">7</option>
                      <option value="8">8</option>
                      <option value="9">9</option>
                      <option value="10">10</option>
                      <option value="11">11</option>
                      <option value="12">12</option>
                      <option value="13">13</option>
                      <option value="14">14</option>
                      <option value="15">15</option>
                      <option value="16">16</option>
                      <option value="17">17</option>
                      <option value="18">18</option>
                      <option value="19">19</option>
                      <option value="20">20</option>
                      <option value="21">21</option>
                      <option value="22">22</option>
                      <option value="23">23</option>
                      <option value="24">24</option>
                      <option value="25">25</option>
                      <option value="26">26</option>
                      <option value="27">27</option>
                      <option value="28">28</option>
                      <option value="29">29</option>
                      <option value="30">30</option>
                      <option value="31">31</option>
                    </select></div>
                </div>
                <div class="form-item form-type-select form-item-birth-date-month">
                  <label for="edit-birth-date-month">Month <span class="form-required"
                                                                 title="This field is required.">*</span></label>

                  <div class="date-month"><select class="date-month form-select required ajax-processed"
                                                  id="edit-birth-date-month" name="birth_date[month]">
                      <option value="1" selected="selected">Jan</option>
                      <option value="2">Feb</option>
                      <option value="3">Mar</option>
                      <option value="4">Apr</option>
                      <option value="5">May</option>
                      <option value="6">Jun</option>
                      <option value="7">Jul</option>
                      <option value="8">Aug</option>
                      <option value="9">Sep</option>
                      <option value="10">Oct</option>
                      <option value="11">Nov</option>
                      <option value="12">Dec</option>
                    </select></div>
                </div>
                <div class="form-item form-type-select form-item-birth-date-year">
                  <label for="edit-birth-date-year">Year <span class="form-required"
                                                               title="This field is required.">*</span></label>

                  <div class="date-year"><select class="date-year form-select required ajax-processed"
                                                 id="edit-birth-date-year" name="birth_date[year]">
                      <option value="1975">1975</option>
                      <option value="1976">1976</option>
                      <option value="1977">1977</option>
                      <option value="1978">1978</option>
                      <option value="1979">1979</option>
                      <option value="1980">1980</option>
                      <option value="1981">1981</option>
                      <option value="1982">1982</option>
                      <option value="1983">1983</option>
                      <option value="1984">1984</option>
                      <option value="1985">1985</option>
                      <option value="1986">1986</option>
                      <option value="1987">1987</option>
                      <option value="1988">1988</option>
                      <option value="1989">1989</option>
                      <option value="1990">1990</option>
                      <option value="1991">1991</option>
                      <option value="1992">1992</option>
                      <option value="1993">1993</option>
                      <option value="1994">1994</option>
                      <option value="1995">1995</option>
                      <option value="1996">1996</option>
                      <option value="1997">1997</option>
                      <option value="1998">1998</option>
                      <option value="1999">1999</option>
                      <option value="2000">2000</option>
                      <option value="2001">2001</option>
                      <option value="2002">2002</option>
                      <option value="2003">2003</option>
                      <option value="2004">2004</option>
                      <option value="2005">2005</option>
                      <option value="2006">2006</option>
                      <option value="2007">2007</option>
                      <option value="2008">2008</option>
                      <option value="2009">2009</option>
                      <option value="2010" selected="selected">2010</option>
                      <option value="2011">2011</option>
                      <option value="2012">2012</option>
                    </select></div>
                </div>
              </div>
            </div>
          </div>
          <div class="form-item form-type-select form-item-week">
            <label for="edit-week">Choose a week </label>
            <select id="edit-week" name="week" class="form-select ajax-processed">
              <option value="" selected="selected">- ANY -</option>
              <option value="1">June 1-5: Oh the Places You’ll Go!</option>
              <option value="2">June 8-12: Fearless Fairytales with Jack and Little Red</option>
              <option value="3">May 26-29: A Hero’s Quest</option>
            </select>
          </div>
          <div id="oct-store-camps-products-table">

            <div id="oct-store-camps-products-table">
              <h2>May 26-29: A Hero’s Quest</h2>
              <table class="products-table">
                <thead>
                <tr>
                  <th class="description">Description</th>
                  <th class="amount">Amount</th>
                  <th class="select">Select</th>
                </tr>
                </thead>
                <tbody>
                <tr>
                  <td class="description">
                    May 26 to May 27 | Ages 5 - 8 | test camp2
                  </td>
                  <td class="amount">
                    $12.00
                  </td>
                  <td class="select">
                    <div class="form-item form-type-checkbox form-item-products-69">
                      <input type="checkbox" id="edit-products-69" name="products[69]" value="1"
                             class="form-checkbox">
                    </div>
                  </td>
                </tr>
                <tr>
                  <td class="description">
                    May 27 to May 29 | Ages 5 - 8 | test camp2
                  </td>
                  <td class="amount">
                    $12.00
                  </td>
                  <td class="select">
                    <div class="form-item form-type-checkbox form-item-products-70">
                      <input type="checkbox" id="edit-products-70" name="products[70]" value="1"
                             class="form-checkbox">
                    </div>
                  </td>
                </tr>
                </tbody>
              </table>
            </div>
          </div>
          <div class="btn-wrap style-with-arrow arrow-right">

          <input type="submit" id="edit-submit" name="add" value="Add to cart" class="form-submit">

          </div><input
            type="hidden" name="form_build_id" value="form-Z49D8vPu2I4Hs7Rgv7CdHEGAY-X3lQ3fZlD2vQIp7pQ">
          <input type="hidden" name="form_id" value="oct_store_cc_camp_form">
        </div>
      </form>
    </div>
  </div>
</div>
</div>
</div>


</div>
</div>
</div>
<?php include 'tpl/layout/footer.inc'; ?>
</div>
</body>
</html>