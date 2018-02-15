<?php
/**
 * @file
 * Save, loading, updating transactions.
 */

function fnl_store_payment_transaction_load($transaction_id) {

  return db_select('fnl_store_payment_transactions', 't')
    ->condition('transaction_id', $transaction_id)
    ->fields('t')
    ->execute()
    ->fetchObject();
}


function fnl_store_payment_transaction_save($transaction) {
  global $user;

  module_invoke_all('fnl_store_payment_transaction_before_save', $transaction);

  if (!empty($transaction->transaction_id)) {
    //update transaction

    $transaction->changed = gmdate(DATE_FORMAT_DATETIME, REQUEST_TIME);
    drupal_write_record('fnl_store_payment_transactions', $transaction, 'transaction_id');

    //add new history revision
    $transaction_revision = clone $transaction;
    $transaction_revision->created = gmdate(DATE_FORMAT_DATETIME, REQUEST_TIME);
    $transaction_revision->uid = $user->uid;
    drupal_write_record('fnl_store_payment_transactions_history', $transaction_revision);
  }
  else {
    //add new transaction

    $transaction->created = gmdate(DATE_FORMAT_DATETIME, REQUEST_TIME);
    $transaction->changed = gmdate(DATE_FORMAT_DATETIME, REQUEST_TIME);
    $transaction->uid = $user->uid;
    drupal_write_record('fnl_store_payment_transactions', $transaction);

    //add new history revision
    $transaction_revision = clone $transaction;
    drupal_write_record('fnl_store_payment_transactions_history', $transaction_revision);
  }

  module_invoke_all('fnl_store_payment_transaction_after_save', $transaction);

  return $transaction;
}

