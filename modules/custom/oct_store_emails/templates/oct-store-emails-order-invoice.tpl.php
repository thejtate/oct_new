<?php
/**
 * Order invoice email template.
 * Based on old site email template
 *
 * @variables
 *    $order
 *    $cart
 */
?>
<?php $show_user_info = FALSE; ?>

<style> table a{border-bottom: 1px dashed; color: #A93B43;} </style>
<table width="95%" cellspacing="0" cellpadding="0" align="center"  style="font-family: verdana, arial, helvetica; font-size: small; border: 16px solid #FCEA79; color: #3B5F94; font: 16px;">
  <tr>
    <td>
      <table width="100%" border="0" cellspacing="0" cellpadding="5" align="center" bgcolor="#EEC951" style="font-family: verdana, arial, helvetica; font-size: small;">
          <tr valign="top" >
            <td style="border-right: 6px solid #D7A625; border-top: 6px solid #D7A625;">
              <table width="100%" style="font-family: verdana, arial, helvetica; font-size: small;">
                <tr>
                  <td>

                  </td>
                  <td width="98%" style="text-align: center;">
                    <?php echo $site_logo; ?>
                  </td>
                  <td nowrap="nowrap">
                  </td>
                </tr>
              </table>
            </td>
          </tr>

        <tr valign="top">
          <td style="border-right: 6px solid #D7A625;">
              <?php if(!empty($order->data['checkout_values']['user']['purchaser'])): ?>
                <p><b><?php echo t('Thanks for your order, !name!', array('!name' => check_plain($order->data['checkout_values']['user']['purchaser']))); ?></b></p>
              <?php endif; ?>


              <?php if ($show_user_info && !empty($order->data['user_created']) && $is_email) { ?>
                <p><b><?php echo t('An account has been created for you with the following details:'); ?></b></p>
                <p><b><?php echo t('Username:'); ?></b> <?php echo $order->data['user_created']['name']; ?><br />
                  <b><?php echo t('Password:'); ?></b>  <?php echo $order->data['user_created']['password']; ?></p>
              <?php } ?>


            <p><b><?php print t('Please print off this receipt and present it at the Box Office.'); ?></b></p>

            <table cellpadding="4" cellspacing="0" border="0" width="100%" style="font-family: verdana, arial, helvetica; font-size: small;">
              <tr>
                <td colspan="2" bgcolor="#E6BC3A" style="color: #CF760F;">
                  <b><?php echo t('Purchasing Information:'); ?></b>
                </td>
              </tr>
              <tr>
                <td nowrap="nowrap">
                  <b><?php echo t('E-mail Address:'); ?></b>
                </td>
                <td width="98%">
                  <?php fnl_store_print($order->data['checkout_values']['user']['email']); ?>
                </td>
              </tr>
              <tr>
                <td colspan="2">

                  <table width="100%" cellspacing="0" cellpadding="0" style="font-family: verdana, arial, helvetica; font-size: small;">
                    <tr>
                      <td valign="top" width="50%">
                        <b><?php echo t('Billing Address:'); ?></b><br />
                        <?php fnl_store_print($order->data['checkout_values']['user']['address']); ?><br />
                        <?php fnl_store_print($order->data['checkout_values']['user']['state']); ?> <?php fnl_store_print($order->data['checkout_values']['user']['zip']); ?> <br />
                        <?php fnl_store_print($order->data['checkout_values']['user']['city']); ?><br />
                        <br />
                        <b><?php echo t('Billing Phone:'); ?></b><br />
                        <?php fnl_store_print($order->data['checkout_values']['user']['phone']); ?><br />
                      </td>
                    </tr>
                  </table>

                </td>
              </tr>
              <tr>
                <td nowrap="nowrap">
                  <b><?php echo t('Order Grand Total:'); ?></b>
                </td>
                <td width="98%">
                  <b><?php echo fnl_store_format_amount($order->amount); ?></b>
                </td>
              </tr>
              <tr>
                <td nowrap="nowrap">
                  <b><?php echo t('Payment Method:'); ?></b>
                </td>
                <td width="98%">
                  <?php fnl_store_print($order->data['checkout_values']['payment']['method']); ?>
                </td>
              </tr>

              <tr>
                <td colspan="2" bgcolor="#E6BC3A" style="color: #CF760F;">
                  <b><?php echo t('Order Summary:'); ?></b>
                </td>
              </tr>


              <tr>
                <td colspan="2">

                  <table border="0" cellpadding="1" cellspacing="0" width="100%" style="font-family: verdana, arial, helvetica; font-size: small;">
                    <tr>
                      <td nowrap="nowrap">
                        <b><?php echo t('Order #:'); ?></b>
                      </td>
                      <td width="98%">
                        <?php echo $order->oid; ?>
                      </td>
                    </tr>

                    <tr>
                      <td nowrap="nowrap">
                        <b><?php echo t('Order Date: '); ?></b>
                      </td>
                      <td width="98%">
                        <?php echo fnl_store_db_date_format($order->created); ?>
                      </td>
                    </tr>


                    <tr>
                      <td nowrap="nowrap">
                        <?php echo t('Products Subtotal:'); ?>&nbsp;
                      </td>
                      <td width="98%">
                        <?php echo fnl_store_format_amount($order->subtotal_amount); ?>
                      </td>
                    </tr>

                    <?php if(!empty($order->data['amount_modifications']['fees'])): ?>
                      <?php foreach($order->data['amount_modifications']['fees'] as $item): ?>
                        <tr>
                          <td nowrap="nowrap">
                            <?php echo $item['title']; ?>:
                          </td>
                          <td>
                            <?php print fnl_store_format_amount($item['value']); ?>
                          </td>
                        </tr>
                      <?php endforeach; ?>
                    <?php endif; ?>
                    <?php if(!empty($order->data['amount_modifications']['discounts'])): ?>
                      <?php foreach($order->data['amount_modifications']['discounts'] as $item): ?>
                        <tr>
                          <td nowrap="nowrap">
                            <?php echo $item['title']; ?>:
                          </td>
                          <td>
                            <?php print fnl_store_format_amount($item['value']); ?>
                          </td>
                        </tr>
                      <?php endforeach; ?>
                    <?php endif; ?>

                    <tr>
                      <td>&nbsp;</td>
                      <td>------</td>
                    </tr>

                    <tr>
                      <td nowrap="nowrap">
                        <b><?php echo t('Total for this Order:'); ?>&nbsp;</b>
                      </td>
                      <td>
                        <b><?php echo fnl_store_format_amount($order->amount); ?></b>
                      </td>
                    </tr>

                    <tr>
                      <td colspan="2">
                        <br /><br /><b><?php echo t('Products:'); ?>&nbsp;</b>

                        <table width="100%" style="font-family: verdana, arial, helvetica; font-size: small;">

                          <?php if (!empty($cart['products'])) {
                            foreach ($cart['products'] as $product) {
                              ?>
                              <tr>
                                <td valign="top" nowrap="nowrap">
                                  <b><?php echo $product->qty; ?> x </b>
                                </td>
                                <td width="98%">
                                  <b><?php echo $product->name .' - '. fnl_store_format_amount($product->amount); ?></b>
                                  <br />
                                  <?php if(!empty($product->properties_list)):?>
                                    <ul>
                                      <?php foreach ($product->properties_list as $prop): ?>
                                        <li>

                                          <?php if (!empty ($prop) && is_array($prop)):?>
                                                <p style="margin: 0px; padding: 0px;">
                                                  <?php print (!empty($prop['title']) ? $prop['title'] . ':' : ''); ?>
                                                  <?php print (!empty($prop['value']) ? $prop['value']: ''); ?>
                                                </p>
                                          <?php endif;  ?>
                                        </li>
                                      <?php endforeach; ?>
                                    </ul>
                                  <?php endif; ?>
                                  <br />
                                </td>
                              </tr>
                            <?php }
                          }?>
                        </table>

                      </td>
                    </tr>
                  </table>

                </td>
              </tr>

              <?php if ($is_email) { ?>
                <tr>
                  <td colspan="2">
                    <hr noshade="noshade" size="1" /><br />

                      <p><?php echo t('Please note: This e-mail message is an automated notification. Please do not reply to this message.'); ?></p>

                      <p><?php echo t('Thanks again for shopping with us.'); ?></p>

                      <?php if(!empty($store_link)): ?>
                    <p><b><?php echo $store_link; ?></b>
                      <?php endif; ?>

                  </td>
                </tr>
              <?php } ?>

            </table>
          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
