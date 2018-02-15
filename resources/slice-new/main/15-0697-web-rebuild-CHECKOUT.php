<?php $title = 'Checkout'; ?>
<?php include 'tpl/includes/head.inc'; ?>
<body class="page page-checkout">
<div class="outer-wrapper">
  <?php include 'tpl/layout/header.inc'; ?>
  <div class="inner-wrapper site-container">
    <div class="title"><h2>Checkout</h2></div>
    <div class="content-wrapper">
      <p><i>Once your order is complete, you will receive an email confirmation / receipt with details of all your
          purchases. <strong>The email will serve as your ticket.</strong> Please bring it with you to the event.</i>
      </p>
      <a href="#" class="link-back">Return to Cart</a>

      <div class="form form-checkout">
        <fieldset>
          <div class="fieldset-wrapper">
            <h5><strong>Billing Information</strong></h5>

            <div class="form-item form-type-textfield style-a width-50">
              <label><strong>First Name</strong> </label>
              <input type="text" class="form-text">
            </div>

            <div class="form-item form-type-textfield width-50">
              <label><strong>Last Name</strong> </label>
              <input type="text" class="form-text">
            </div>

            <div class="form-item form-type-textfield">
              <label><strong>Address</strong> </label>
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
          </div>
        </fieldset>

        <fieldset>
          <h5><strong>Billing Information</strong></h5>

          <div class="fieldset-wrapper">


            <div class="form-item form-type-textfield style-a width-50">
              <label><strong>Phone</strong> </label>
              <input type="text" class="form-text">
            </div>

            <div class="form-item form-type-textfield style-a width-50">
              <label><strong>Email</strong> </label>
              <input type="text" class="form-text">
            </div>

            <div class="form-item form-type-textfield style-a width-50">
              <label><strong>Confirm Email*</strong> </label>
              <input type="text" class="form-text">
            </div>


            <!--            <div class="billing-form">-->
            <!--              <div class="form-item form-type-textfield">-->
            <!--                <label><strong>Phone</strong> </label>-->
            <!--                <input type="text" class="form-text">-->
            <!--              </div>-->
            <!---->
            <!--              <div class="form-item form-type-textfield">-->
            <!--                <label><strong>Email</strong> </label>-->
            <!--                <input type="text" class="form-text">-->
            <!--              </div>-->
            <!---->
            <!--              <div class="form-type-select">-->
            <!--                <select>-->
            <!--                  <option>MONTH</option>-->
            <!--                </select>-->
            <!--              </div>-->
            <!--              <div class="form-type-select">-->
            <!--                <select>-->
            <!--                  <option>YEAR</option>-->
            <!--                </select>-->
            <!--              </div>-->
            <!---->
            <!--              <div class="form-item form-type-textfield form-type-secure">-->
            <!--                <label><strong>Security Code* (CVC / CVV) </strong> </label>-->
            <!--                <input type="text" class="form-text">-->
            <!--              </div>-->
            <!--            </div>-->

          </div>
        </fieldset>
        <p><strong>Payment Method</strong></p>

        <div class="text">
          <img src="theme/images/icons/paypal.png">

          <p><i>Pay without sharing your financial information (no PayPal account required). Includes:</i></p>
          <img src="theme/images/icons/cards.png" alt="">
        </div>
      </div>

      <div class="btn-wrap style-c with-arrow">
        <div class="form-actions">
          <input type="submit" class="form-submit" value="Complete Order">
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