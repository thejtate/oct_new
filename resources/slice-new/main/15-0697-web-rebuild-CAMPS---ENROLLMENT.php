<?php $title = 'Enrollment'; ?>
<?php include 'tpl/includes/head.inc'; ?>
<body class="page page-store">
<div class="outer-wrapper">
<?php include 'tpl/layout/header.inc'; ?>
<div class="inner-wrapper site-container">
<div class="title"><h2>Camp Enrollment</h2></div>
<div class="content-wrapper">
<div class="content-inner">
<div class="region region-content">
<div id="block-system-main" class="block block-system">


<div class="content">
<div id="oct-store-camps-form-wrapper">
<h4>“Story Stars” 2015 Summer Camps</h4>

<div class="text">
  <p><strong>Mouse over camp names to view a description.</strong></p>

  <p> You will be required to verify the age of each child, and will NOT be allowed to enroll a child in any camps that
    is
    not age appropriate. If you have difficulty enrolling, please call the office at (405) 606-7003.</p>
</div>

<form action="/store/camps" method="post" id="oct-store-cc-form--4" accept-charset="UTF-8">
<div>
<fieldset class="form-wrapper" id="edit-step1">
<div class="fieldset-wrapper">
<fieldset class="form-wrapper" id="edit-step1-children">
  <legend><span class="fieldset-legend">Child`s Information</span></legend>
  <div class="fieldset-wrapper">
    <fieldset class="form-wrapper" id="edit-step1-children-child-0">
      <legend><span class="fieldset-legend">Child 1</span></legend>
      <div class="fieldset-wrapper">
        <div class="left-part">
          <div class="form-item form-type-textfield form-item-step1-children-child-0-first-name">
            <label for="edit-step1-children-child-0-first-name">First Name <span class="form-required"
                                                                                 title="This field is required.">*</span></label>
            <input type="text" id="edit-step1-children-child-0-first-name" name="step1[children][child_0][first_name]"
                   value="" size="60" maxlength="128" class="form-text required">
          </div>
          <div class="form-item form-type-textfield form-item-step1-children-child-0-last-name">
            <label for="edit-step1-children-child-0-last-name">Last Name <span class="form-required"
                                                                               title="This field is required.">*</span></label>
            <input type="text" id="edit-step1-children-child-0-last-name" name="step1[children][child_0][last_name]"
                   value="" size="60" maxlength="128" class="form-text required">
          </div>

          <div class="container-inline-date">
            <div class="form-item form-type-date-select form-item-step1-children-child-0-birth-date">
              <label for="edit-step1-children-child-0-birth-date">Date of Birth <span class="form-required"
                                                                                      title="This field is required.">*</span></label>

              <div id="edit-step1-children-child-0-birth-date" class="date-padding clearfix">
                <div class="form-item form-type-select form-item-step1-children-child-0-birth-date-day">
                  <label for="edit-step1-children-child-0-birth-date-day">Day <span class="form-required"
                                                                                    title="This field is required.">*</span></label>

                  <div class="date-day"><select class="date-day form-select required"
                                                id="edit-step1-children-child-0-birth-date-day"
                                                name="step1[children][child_0][birth_date][day]">
                      <option value="1">1</option>
                      <option value="2">2</option>
                      <option value="3" selected="selected">3</option>
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
                <div class="form-item form-type-select form-item-step1-children-child-0-birth-date-month">
                  <label for="edit-step1-children-child-0-birth-date-month">Month <span class="form-required"
                                                                                        title="This field is required.">*</span></label>

                  <div class="date-month"><select class="date-month form-select required"
                                                  id="edit-step1-children-child-0-birth-date-month"
                                                  name="step1[children][child_0][birth_date][month]">
                      <option value="1">Jan</option>
                      <option value="2" selected="selected">Feb</option>
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
                <div class="form-item form-type-select form-item-step1-children-child-0-birth-date-year">
                  <label for="edit-step1-children-child-0-birth-date-year">Year <span class="form-required"
                                                                                      title="This field is required.">*</span></label>

                  <div class="date-year"><select class="date-year form-select required"
                                                 id="edit-step1-children-child-0-birth-date-year"
                                                 name="step1[children][child_0][birth_date][year]">
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

          <div class="form-item form-type-select form-item-step1-children-child-0-gender form-item-children-gender">
            <label for="edit-step1-children-child-0-gender">Gender <span class="form-required"
                                                                         title="This field is required.">*</span></label>
            <select id="edit-step1-children-child-0-gender" name="step1[children][child_0][gender]"
                    class="form-select required">
              <option value="">M/F</option>
              <option value="Male" selected="selected">M</option>
              <option value="Female">F</option>
            </select>
          </div>

          <div class="form-item form-type-radios form-item-step1-children-child-0-t-shirt">
            <label for="edit-step1-children-child-0-t-shirt">T-Shirt size (optional) </label>

            <div id="edit-step1-children-child-0-t-shirt" class="form-radios">
              <div class="form-item form-type-radio form-item-step1-children-child-0-t-shirt">
                <input type="radio" id="edit-step1-children-child-0-t-shirt-x-small"
                       name="step1[children][child_0][t-shirt]" value="X Small" class="form-radio"> <label
                  class="option"
                  for="edit-step1-children-child-0-t-shirt-x-small">X
                  Small </label>

              </div>
              <div class="form-item form-type-radio form-item-step1-children-child-0-t-shirt">
                <input type="radio" id="edit-step1-children-child-0-t-shirt-small"
                       name="step1[children][child_0][t-shirt]" value="Small" class="form-radio"> <label class="option"
                                                                                                         for="edit-step1-children-child-0-t-shirt-small">Small </label>

              </div>
              <div class="form-item form-type-radio form-item-step1-children-child-0-t-shirt">
                <input type="radio" id="edit-step1-children-child-0-t-shirt-medium"
                       name="step1[children][child_0][t-shirt]" value="Medium" class="form-radio"> <label class="option"
                                                                                                          for="edit-step1-children-child-0-t-shirt-medium">Medium </label>

              </div>
              <div class="form-item form-type-radio form-item-step1-children-child-0-t-shirt">
                <input type="radio" id="edit-step1-children-child-0-t-shirt-large"
                       name="step1[children][child_0][t-shirt]" value="Large" checked="checked" class="form-radio">
                <label
                  class="option" for="edit-step1-children-child-0-t-shirt-large">Large </label>

              </div>
            </div>
          </div>

        </div>

        <div class="right-part">
          <div class="form-item form-type-textarea form-item-step1-children-child-0-allergy">
            <label for="edit-step1-children-child-0-allergy">Allergies / Medications / Special Needs </label>

            <div class="form-textarea-wrapper"><textarea id="edit-step1-children-child-0-allergy"
                                                         name="step1[children][child_0][allergy]" cols="60" rows="5"
                                                         class="form-textarea"></textarea></div>
          </div>


        </div>
    </fieldset>
  </div>
</fieldset>
<div class="btn-wrap style-a not-alone">
  <div class="form-actions">
    <input type="submit" id="edit-step1-remove-child" name="add_child" value="Remove child"
           class="form-submit ajax-processed">
  </div>
  <div class="form-actions">
    <input type="submit" id="edit-step1-add-child" name="add_child"
           value="Add child" class="form-submit ajax-processed">
  </div>
</div>
<div id="oct-store-camps-products-table">


<div class="products-wrapper">

<div class="products-head">
  <span class="description">Camp</span>
  <span class="ages">Ages</span>
  <span class="price">Price</span>
  <span class="child">Child 1</span>
  <span class="child">Child 2</span>
</div>

<div class="results">
  <table>
    <thead>
    <tr>
      <th class="name">&nbsp;</th>
      <th class="camps"># camps</th>
      <th class="subtotal">subtotal</th>
    </tr>
    </thead>
    <tbody>
    <tr class="child-1">
      <td class="name">Child 1</td>
      <td class="camps"> 2</td>
      <td class="subtotal"> $300</td>
    </tr>
    <tr class="child-1">
      <td class="name">Child 2</td>
      <td class="camps"> 3</td>
      <td class="subtotal"> $450</td>
    </tr>
    </tbody>
  </table>
  <div class="add-button-wrapper">
    <div class="btn-wrap style-c with-arrow">
      <div class="form-actions">
        <input type="submit" id="edit-step1-products-next" name="next" value="Add to cart"
               class="form-submit ajax-processed">
      </div>
    </div>
  </div>
</div>

<div class="product-section-wrapper">
  <h3 class="section-name">June 8-12: Fearless Fairytales with Jack and Little Red</h3>
  <table class="products-table">
    <!--          <thead>-->
    <!--          <tr>-->
    <!--            <th class="description">--><!--</th>-->
    <!--            <th class="age">&nbsp;</th>-->
    <!--            <th class="amount">--><!--</th>-->
    <!--            -->  <!--            <th class="select">--><!--</th>-->
    <!--            -->  <!--          </tr>-->
    <!--          </thead>-->
    <tbody>


    <tr>
      <td class="description">
        test1
        <div class="popup-desc">
          <h6>Musical Theatre</h6>

          <p>In Musical Theatre camp, students can save the day through music and dance. Campers will learn and rehearse
            numbers from several fun and exciting musical productions. For each camp, the Friday performances will give
            entertainers an opportunity to delight the audience with a showcase of their performance.</p>
        </div>
      </td>
      <td class="ages">
        Ages 5 - 8
      </td>
      <td class="price">
        $12.00
      </td>

      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-67-child-0">
          <input type="checkbox" id="edit-step1-products-67-child-0" name="step1[products][67][child_0]" value="1"
                 class="form-checkbox">
          <label for=""></label>
        </div>
      </td>
      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-67-child-1">
          <input type="checkbox" id="edit-step1-products-67-child-1" name="step1[products][67][child_1]" value="1"
                 class="form-checkbox">
          <label for=""></label>
        </div>
      </td>

    </tr>


    <tr>
      <td class="description">
        test1
      </td>
      <td class="ages">
        Ages 5 - 8
      </td>
      <td class="price">
        $12.00
      </td>

      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-68-child-0">
          <input type="checkbox" id="edit-step1-products-68-child-0" name="step1[products][68][child_0]" value="1"
                 checked="checked" class="form-checkbox">
          <label for="edit-step1-products-68-child-0"> </label>
        </div>
      </td>
      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-68-child-1">
          <input type="checkbox" id="edit-step1-products-68-child-1" name="step1[products][68][child_1]" value="1"
                 class="form-checkbox">
          <label for="edit-step1-products-68-child-1"> </label>
        </div>
      </td>

    </tr>


    </tbody>
  </table>
</div>
<div class="product-section-wrapper">
  <h3 class="section-name">May 26-29: A Hero’s Quest</h3>
  <table class="products-table">
    <tbody>


    <tr>
      <td class="description">
        test camp2
      </td>
      <td class="ages">
        Ages 5 - 8
      </td>
      <td class="price">
        $12.00
      </td>

      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-69-child-0">
          <input type="checkbox" id="edit-step1-products-69-child-0" name="step1[products][69][child_0]" value="1"
                 class="form-checkbox">
        </div>
      </td>
      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-69-child-1">
          <input type="checkbox" id="edit-step1-products-69-child-1" name="step1[products][69][child_1]" value="1"
                 checked="checked" class="form-checkbox">
        </div>
      </td>

    </tr>


    <tr>
      <td class="description">
        test camp2
      </td>
      <td class="ages">
        Ages 5 - 8
      </td>
      <td class="price">
        $12.00
      </td>

      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-70-child-0">
          <input type="checkbox" id="edit-step1-products-70-child-0" name="step1[products][70][child_0]" value="1"
                 class="form-checkbox">
        </div>
      </td>
      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-70-child-1">
          <input type="checkbox" id="edit-step1-products-70-child-1" name="step1[products][70][child_1]" value="1"
                 class="form-checkbox">
        </div>
      </td>


    </tr>

    <tr>
      <td class="description">
        test camp2
      </td>
      <td class="ages">
        Ages 5 - 8
      </td>
      <td class="price">
        $12.00
      </td>

      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-70-child-0">
          <input type="checkbox" id="edit-step1-products-70-child-0" name="step1[products][70][child_0]" value="1"
                 class="form-checkbox">
        </div>
      </td>
      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-70-child-1">
          <input type="checkbox" id="edit-step1-products-70-child-1" name="step1[products][70][child_1]" value="1"
                 class="form-checkbox">
        </div>
      </td>


    </tr>


    </tbody>
  </table>
</div>

<div class="product-section-wrapper">
  <h3 class="section-name">May 26-29: A Hero’s Quest</h3>
  <table class="products-table">
    <tbody>


    <tr>
      <td class="description">
        test camp2
      </td>
      <td class="ages">
        Ages 5 - 8
      </td>
      <td class="price">
        $12.00
      </td>

      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-69-child-0">
          <input type="checkbox" id="edit-step1-products-69-child-0" name="step1[products][69][child_0]" value="1"
                 class="form-checkbox">
        </div>
      </td>
      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-69-child-1">
          <input type="checkbox" id="edit-step1-products-69-child-1" name="step1[products][69][child_1]" value="1"
                 checked="checked" class="form-checkbox">
        </div>
      </td>

    </tr>


    <tr>
      <td class="description">
        test camp2
      </td>
      <td class="ages">
        Ages 5 - 8
      </td>
      <td class="price">
        $12.00
      </td>

      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-70-child-0">
          <input type="checkbox" id="edit-step1-products-70-child-0" name="step1[products][70][child_0]" value="1"
                 class="form-checkbox">
        </div>
      </td>
      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-70-child-1">
          <input type="checkbox" id="edit-step1-products-70-child-1" name="step1[products][70][child_1]" value="1"
                 class="form-checkbox">
        </div>
      </td>


    </tr>

    <tr>
      <td class="description">
        test camp2
      </td>
      <td class="ages">
        Ages 5 - 8
      </td>
      <td class="price">
        $12.00
      </td>

      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-70-child-0">
          <input type="checkbox" id="edit-step1-products-70-child-0" name="step1[products][70][child_0]" value="1"
                 class="form-checkbox">
        </div>
      </td>
      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-70-child-1">
          <input type="checkbox" id="edit-step1-products-70-child-1" name="step1[products][70][child_1]" value="1"
                 class="form-checkbox">
        </div>
      </td>


    </tr>


    </tbody>
  </table>
</div>
<div class="product-section-wrapper">
  <h3 class="section-name">May 26-29: A Hero’s Quest</h3>
  <table class="products-table">
    <tbody>


    <tr>
      <td class="description">
        test camp2
      </td>
      <td class="ages">
        Ages 5 - 8
      </td>
      <td class="price">
        $12.00
      </td>

      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-69-child-0">
          <input type="checkbox" id="edit-step1-products-69-child-0" name="step1[products][69][child_0]" value="1"
                 class="form-checkbox">
        </div>
      </td>
      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-69-child-1">
          <input type="checkbox" id="edit-step1-products-69-child-1" name="step1[products][69][child_1]" value="1"
                 checked="checked" class="form-checkbox">
        </div>
      </td>

    </tr>


    <tr>
      <td class="description">
        test camp2
      </td>
      <td class="ages">
        Ages 5 - 8
      </td>
      <td class="price">
        $12.00
      </td>

      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-70-child-0">
          <input type="checkbox" id="edit-step1-products-70-child-0" name="step1[products][70][child_0]" value="1"
                 class="form-checkbox">
        </div>
      </td>
      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-70-child-1">
          <input type="checkbox" id="edit-step1-products-70-child-1" name="step1[products][70][child_1]" value="1"
                 class="form-checkbox">
        </div>
      </td>


    </tr>

    <tr>
      <td class="description">
        test camp2
      </td>
      <td class="ages">
        Ages 5 - 8
      </td>
      <td class="price">
        $12.00
      </td>

      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-70-child-0">
          <input type="checkbox" id="edit-step1-products-70-child-0" name="step1[products][70][child_0]" value="1"
                 class="form-checkbox">
        </div>
      </td>
      <td class="child">
        <div class="form-item form-type-checkbox form-item-step1-products-70-child-1">
          <input type="checkbox" id="edit-step1-products-70-child-1" name="step1[products][70][child_1]" value="1"
                 class="form-checkbox">
        </div>
      </td>


    </tr>


    </tbody>
  </table>
</div>
</div>


</div>
</div>
</fieldset>
<input type="hidden" name="form_build_id" value="form-TL0jDn2cyERN7_EiKkawAPYqL_Wtyfve_zmse4i3d5I">
<input type="hidden" name="form_id" value="oct_store_cc_form">
</div>
</form>
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