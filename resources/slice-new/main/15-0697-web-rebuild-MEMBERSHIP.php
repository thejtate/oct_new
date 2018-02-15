<?php $title = 'Membership'; ?>
<?php include 'tpl/includes/head.inc'; ?>
<body class="page page-membership">
<div class="outer-wrapper">
  <?php include 'tpl/layout/header.inc'; ?>
  <div class="inner-wrapper site-container">
    <div class="title"><h2>Annual Pass</h2></div>
    <div class="content-wrapper">
      <div class="cols cols-2">
        <div class="col">
          <div class="img">
            <img src="theme/images/tmp/membership-img-1.png" alt="">
          </div>
          <p>
            An Annual Pass allows the holder admission to all of our shows for 12 months. An additional guest to either
            Pass can be purchased for $25, and all Passes are valid for one full year from date of purchase.
          </p>

          <p>

            For more infomation or to purchase please contact our Box Office at (405) 951-0011. Box Office Hours are
            Tuesday - Friday, 1:00pm - 5:00pm.
          </p>
        </div>
        <div class="col">
          <div class="form form-style-a">
            <fieldset>
              <div class="fieldset-wrapper">
                <p><strong>Select a pass</strong></p>
                <div class="form-item form-type-radio">
                  <input type="radio" id="radio1" name="radio" value="Medium" class="form-radio">
                  <label class="option" for="radio1"><strong>Family $100</strong>1 adult and up to 3 guests</label>
                </div>

                <div class="form-item form-type-radio">
                  <input type="radio" id="radio1" name="radio" value="Medium" class="form-radio">
                  <label class="option" for="radio1"><strong>Single $60</strong> 1 adult </label>
                </div>
              </div>
            </fieldset>
            <fieldset>
              <div class="fieldset-wrapper">
                <div class="form-item form-type-textfield width-50 style-a">
                  <label><strong>First Name</strong> </label>
                  <input type="text" class="form-text">
                </div>

                <div class="form-item form-type-textfield width-50">
                  <label><strong>Last Name</strong> </label>
                  <input type="text" class="form-text">
                </div>

                <div class="form-item form-type-textfield">
                  <label><strong>Address</strong></label>
                  <input type="text" class="form-text">
                </div>

                <div class="form-item form-type-textfield form-text-city">
                  <label><strong>City</strong></label>
                  <input type="text" class="form-text">
                </div>

                <div class="form-item form-type-textfield form-text-state">
                  <label><strong>State</strong></label>
                  <input type="text" class="form-text">
                </div>

                <div class="form-item form-type-textfield form-text-zip">
                  <label><strong>ZIP</strong></label>
                  <input type="text" class="form-text">
                </div>

                <div class="form-item form-type-textfield  width-50 style-a">
                  <label><strong>Phone</strong></label>
                  <input type="text" class="form-text">
                </div>

                <div class="form-item form-type-textfield  width-50">
                  <label><strong>Email</strong></label>
                  <input type="text" class="form-text">
                </div>
              </div>
            </fieldset>
            <fieldset>
              <div class="fieldset-wrapper">
                <p><strong>Names of people on Pass:</strong></p>
                <div class="form-item form-type-textfield width-50 style-a">
                  <label><strong>First Name</strong> </label>
                  <input type="text" class="form-text">
                </div>

                <div class="form-item form-type-textfield width-50">
                  <label><strong>Last Name</strong> </label>
                  <input type="text" class="form-text">
                </div>

                <div class="form-item form-type-radio">
                  <input type="radio" id="radio3" name="radio" value="Medium" class="form-radio">
                  <label class="option" for="radio3"><strong>Add a guest — $25</strong></label>
                </div>
              </div>
            </fieldset>
          </div>

          <div class="btn-wrap with-arrow style-c">
            <div class="form-actions">
              <input type="submit" class="form-submit" value="Add to cart">
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <?php include 'tpl/layout/footer.inc'; ?>
</div>
<div class="btn-top">
  <a href="#site-header">top</a>
</div>
<div class="region-footer-bottom">
  <ul>
    <li class="soc-1"><a href="#">Facebook</a></li>
    <li class="soc-2"><a href="#">Newsletter</a></li>
    <li class="soc-3"><a href="#">Memberships</a></li>
    <li class="soc-4"><a href="#">Donate</a></li>
  </ul>
</div>
</body>
</html>