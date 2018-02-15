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

              <?php
              $to_pay = !empty($order->data['partial_payment']['to_pay_amount']) ? $order->data['partial_payment']['to_pay_amount'] : 0;
              $total_payed_and_payed_in_progress = $order->data['partial_payment']['total_payed_amount'] + $to_pay;
              $payment_left = $order->amount - $total_payed_and_payed_in_progress;
              ?>

                <tr valign="top">
                    <td style="border-right: 6px solid #D7A625;">
                        <p><b><?php print t('Your payment not complete. Amount Due: !amount.' , array('!amount' => fnl_store_format_amount($payment_left))); ?></b></p>
                        <p><?php print t('Please do not forget to pay until !date or order will be canceled.', array('!date' => '<b>' . fnl_store_db_date_format_no_timezone($order->data['partial_payment']['due_date']) . '</b>')); ?></p>
                        <p><?php print t('You can view and finish your payments !here using your email and password.' , array('!here' => l('HERE', 'user', array('attributes' => array('target' => '_blank'))))); ?></p>
                        <p><?php print t('If you forgot your password, you can reset it here: !here.' , array('!here' => l('Request new password', 'user/password', array('attributes' => array('target' => '_blank'))))); ?></p>
                        <table cellpadding="4" cellspacing="0" border="0" width="100%" style="font-family: verdana, arial, helvetica; font-size: small;">

                            <tr>
                                <td colspan="2" bgcolor="#E6BC3A" style="color: #CF760F;">
                                    <b><?php echo t('Payment Information:'); ?></b>
                                </td>
                            </tr>
                            <tr>
                                <td nowrap="nowrap">
                                  <?php echo t('Order Grand Total:'); ?>
                                </td>
                                <td width="98%">
                                  <?php echo fnl_store_format_amount($order->amount); ?>
                                </td>
                            </tr>

                            <tr>
                                <td nowrap="nowrap">
                                  <?php print t('Total payed')?>:
                                </td>
                                <td>
                                  <?php print fnl_store_format_amount(-$total_payed_and_payed_in_progress); ?>
                                </td>
                            </tr>
                            <tr>
                                <td>&nbsp;</td>
                                <td>------</td>
                            </tr>

                            <tr>
                                <td nowrap="nowrap">
                                    <b><?php echo t('Amount Due for this Order:'); ?>&nbsp;</b>
                                </td>
                                <td>
                                    <b><?php echo fnl_store_format_amount($payment_left); ?></b>
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
                                    <b><?php echo t('Purchasing Information:'); ?></b>
                                </td>
                            </tr>
                            <tr>
                                <td nowrap="nowrap">
                                    <b><?php echo t('E-mail Address:'); ?></b>
                                </td>
                                <td width="98%">
                                  <?php fnl_store_print($user_email); ?>
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

                        </table>
                    </td>
                </tr>
            </table>
        </td>
    </tr>
</table>
