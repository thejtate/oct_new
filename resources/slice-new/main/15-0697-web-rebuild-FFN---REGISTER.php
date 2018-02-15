<?php $title = 'Register'; ?>
<?php include 'tpl/includes/head.inc'; ?>
<body class="page page-register">
<div class="outer-wrapper">
  <?php include 'tpl/layout/header.inc'; ?>
  <div class="inner-wrapper site-container">

    <div class="title"><h2>Friday Fun Nights</h2></div>
    <div class="content-wrapper">
      <div class="left-part">
        <table class="table">
          <thead>
          <tr>
            <td> Date</td>
            <td> Price</td>
            <td> quantity</td>
            <td> Subtotal</td>
          </tr>
          </thead>
          <tr>
            <td><strong>“End of Summer Lock-In”	</strong>Friday, August 21, 2015</td>
            <td> $25</td>
            <td>
              <select>
                <option>1</option>
                <option>2</option>
              </select>
            </td>
            <td>$50</td>

          </tr>

          <tr>
            <td><strong>“Hank’s Cowdog Round-Up”</strong>
              Friday, September 26, 2015
            </td>
            <td> $25</td>
            <td>
              <select>
                <option>1</option>
                <option>2</option>
              </select>
            </td>
            <td> $0</td>

          </tr>

          <tr>
            <td><strong>“Monster Mash”	</strong>
              Friday, October 23, 2015
            </td>
            <td> $25</td>
            <td>
              <select>
                <option>1</option>
                <option>2</option>
              </select>
            </td>
            <td> $0</td>

          </tr>

          <tr>
            <td><strong>“Let’s Get Glowing”</strong>
              Friday, November 20, 2015
            </td>
            <td> $25</td>
            <td>
              <select>
                <option>1</option>
                <option>2</option>
              </select>
            </td>
            <td> $0</td>

          </tr>

          <tr>
            <td colspan="3"> Handling fee for tickets
            </td>

            <td> $1.50</td>

          </tr>
        </table>
        <div class="total">

          <span><strong>Total</strong>	</span>
          <span><strong>$51.50</strong></span>
        </div>

        <div class="btn-wrap style-c with-arrow">
          <div class="form-actions">
            <input type="submit" class="form-submit" value="Add to cart">
          </div>
        </div>
      </div>

      <div class="right-part">
        <div class="item">
          <div class="img"><img src="theme/images/tmp/tickets-img-1.png" alt=""></div>
          <a href="#">Camps &
            Classes</a>
        </div>
        <div class="item">
          <div class="img"><img src="theme/images/tmp/photo-item-5.png" alt=""></div>
          <a href="#">Fairy Tale
            Ball</a>
        </div>

        <div class="item">
          <div class="img"><img src="theme/images/tmp/tickets-img-3.png" alt=""></div>
          <a href="#">Friday Fun
            Nights</a>
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