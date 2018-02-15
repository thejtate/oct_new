<?php
/**
 * Checkout complete page template
 *
 * @variables:
 *  $order
 * $cart - Cart views
 */
?>

<h3 class="complete-head">
<?php print t('Payment complete!');?>
</h3>
<div class="invoice">

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
                            <p><b><?php print t('Your payment complete for !amount.' , array('!amount' => fnl_store_format_amount($order->data['partial_payment']['last_payed_amount']))); ?></b></p>
                            <p><?php print t('You should pay full amount until !date or order will be canceled.', array('!date' => '<b>' . fnl_store_db_date_format_no_timezone($order->data['partial_payment']['due_date']) . '</b>')); ?></p>
<!--                            <h4><b>--><?php //print t('') l(); ?><!--</b></h4>-->
                            <p><b><?php print t('You can view and finish your payments !here.' , array('!here' => l('HERE', 'user', array('attributes' => array('target' => '_blank'))))); ?></b></p>

                            <table cellpadding="4" cellspacing="0" border="0" width="100%" style="font-family: verdana, arial, helvetica; font-size: small;">
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
                                                  <?php echo t('Order Total:'); ?>&nbsp;
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

                                        </table>

                                    </td>
                                </tr>


                            </table>
                        </td>
                    </tr>
                </table>
            </td>
        </tr>
    </table>
</div>

