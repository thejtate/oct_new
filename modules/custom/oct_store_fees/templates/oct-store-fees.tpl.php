<?php
/**
 *  Render order fees for views
 **/

?>

<?php if(!empty($data['amount_modifications']['fees'])): ?>
    <?php foreach($data['amount_modifications']['fees'] as $fee): ?>
        $<?php print $fee['value']?>
    </br>
    <?php endforeach; ?>
<?php endif; ?>
