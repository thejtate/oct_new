<?php $title = 'Tickets'; ?>
<?php include 'tpl/includes/head.inc'; ?>
<body class="page page-tickets">
<div class="outer-wrapper">
  <?php include 'tpl/layout/header.inc'; ?>
  <div class="inner-wrapper site-container">

    <div class="title"><h2>Performance Tickets</h2></div>
    <div class="content-wrapper">
      <div class="left-part">
        <div class="webform-component-select">
          <label>Production</label>
          <select>
            <option>The Tortoise and the Hare</option>
            <option> Junie B in Jingle Bells,Batman Smells</option>
            <option> The Giver</option>
            <option> Go, Dog, Go!</option>
            <option> Red Vs. the Wolf</option>
            <option> Charlotte’s Web</option>
          </select>
        </div>
        <div class="webform-component-select">
          <label>Date & Time</label>
          <select>
            <option>Fri 2-12-2016 11:00 am</option>
            <option> Sat 2-13-2016 2:00 pm</option>
            <option> Sun 2-14-2016 2:00 pm</option>
            <option> Wed 2-17-2016 11:00 am</option>
            <option> Fri 2-19-2016 11:00 am</option>
            <option> Sat 2-20-2016 2:00 pm</option>
            <option> Sun 2-21-2016 2:00 pm</option>
          </select>
        </div>
        <table class="table">
          <thead>
          <tr>
            <td> Tickets</td>
            <td> Price</td>
            <td> quantity</td>
            <td> Subtotal</td>
          </tr>
          </thead>
          <tr>
            <td><strong>Adult</strong></td>
            <td> $10</td>
            <td>
              <select>
                <option>1</option>
                <option>2</option>
              </select>
            </td>
            <td>$20</td>

          </tr>

          <tr>
            <td><strong>Children</strong>
              (ages 2 – 12)
            </td>
            <td> $8</td>
            <td>
              <select>
                <option>1</option>
                <option>2</option>
              </select>
            </td>
            <td> $24</td>

          </tr>

          <tr>
            <td><strong>Group Children</strong>
              (20 to 49)
            </td>
            <td> $7</td>
            <td>
              <select>
                <option>1</option>
                <option>2</option>
              </select>
            </td>
            <td> $0</td>

          </tr>

          <tr>
            <td><strong>Group Children</strong>
              (50+)
            </td>
            <td> $6</td>
            <td>
              <select>
                <option>1</option>
                <option>2</option>
              </select>
            </td>
            <td> $0</td>

          </tr>

          <tr>
            <td><strong>Complimentary Adult</strong>
              (with every 20 children)
            </td>
            <td> $0</td>
            <td>
              <select>
                <option>1</option>
                <option>2</option>
              </select>
            </td>
            <td></td>

          </tr>

          <tr>
            <td colspan="3"> Handling fee for tickets
            </td>

            <td> $1.50</td>

          </tr>
        </table>
        <div class="total">

          <span><strong>Total</strong>	</span>
          <span><strong>$45.50</strong></span>
        </div>

        <a href="#" class="add-elem">Buy Tickets for Another Show</a>

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
          <div class="img"><img src="theme/images/tmp/tickets-img-2.png" alt=""></div>
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