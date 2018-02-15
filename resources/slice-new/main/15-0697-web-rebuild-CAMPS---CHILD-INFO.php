<?php $title = 'Info'; ?>
<?php include 'tpl/includes/head.inc'; ?>
<body class="page page-store">
<div class="outer-wrapper">
<?php include 'tpl/layout/header.inc'; ?>
<div class="inner-wrapper site-container">
<div class="content-wrapper">
<div class="content-inner">
<div class="region region-content">
<div id="block-system-main" class="block block-system">


<div class="content">
<div id="oct-store-camps-form-wrapper">
<div></div>
<form action="/store/camps" method="post" id="oct-store-cc-form--4" accept-charset="UTF-8">
<div>
<fieldset class="form-wrapper" id="edit-step2">
<div class="fieldset-wrapper">
<fieldset class="form-wrapper" id="edit-step2-parents">
  <legend><span class="fieldset-legend">Parent`s Information</span></legend>
  <div class="fieldset-wrapper">
    <fieldset class="form-wrapper" id="edit-step2-parents-primary">
      <legend><span class="fieldset-legend">Primary Contact</span></legend>
      <div class="fieldset-wrapper">
        <div class="form-item form-type-textfield form-item-step2-parents-primary-first-name">
          <label for="edit-step2-parents-primary-first-name">First Name </label>
          <input type="text" id="edit-step2-parents-primary-first-name"
                 name="step2[parents][primary][first_name]" value="" size="60" maxlength="128"
                 class="form-text">
        </div>
        <div class="form-item form-type-textfield form-item-step2-parents-primary-last-name">
          <label for="edit-step2-parents-primary-last-name">Last Name </label>
          <input type="text" id="edit-step2-parents-primary-last-name"
                 name="step2[parents][primary][last_name]" value="" size="60" maxlength="128"
                 class="form-text">
        </div>
        <div class="form-item form-type-masked-input form-item-step2-parents-primary-phone">
          <label for="edit-step2-parents-primary-phone">Daytime Phone </label>
          <input type="text" id="edit-step2-parents-primary-phone"
                 name="step2[parents][primary][phone]" value="" size="60" maxlength="128"
                 class="form-text masked_input-processed">
        </div>
        <div class="form-item form-type-masked-input form-item-step2-parents-primary-cellphone">
          <label for="edit-step2-parents-primary-cellphone">Cell Phone </label>
          <input type="text" id="edit-step2-parents-primary-cellphone"
                 name="step2[parents][primary][cellphone]" value="" size="60" maxlength="128"
                 class="form-text masked_input-processed">
        </div>
        <div class="form-item form-type-emailfield form-item-step2-parents-primary-email">
          <label for="edit-step2-parents-primary-email">Email Address </label>
          <input type="email" id="edit-step2-parents-primary-email"
                 name="step2[parents][primary][email]" value="" size="60" maxlength="128"
                 class="form-text form-email">
        </div>
      </div>
    </fieldset>
    <fieldset class="form-wrapper" id="edit-step2-parents-alternate">
      <legend><span class="fieldset-legend">Alternate Contact</span></legend>
      <div class="fieldset-wrapper">
        <div class="form-item form-type-textfield form-item-step2-parents-alternate-first-name">
          <label for="edit-step2-parents-alternate-first-name">First Name </label>
          <input type="text" id="edit-step2-parents-alternate-first-name"
                 name="step2[parents][alternate][first_name]" value="" size="60" maxlength="128"
                 class="form-text">
        </div>
        <div class="form-item form-type-textfield form-item-step2-parents-alternate-last-name">
          <label for="edit-step2-parents-alternate-last-name">Last Name </label>
          <input type="text" id="edit-step2-parents-alternate-last-name"
                 name="step2[parents][alternate][last_name]" value="" size="60" maxlength="128"
                 class="form-text">
        </div>
        <div class="form-item form-type-masked-input form-item-step2-parents-alternate-phone">
          <label for="edit-step2-parents-alternate-phone">Daytime Phone </label>
          <input type="text" id="edit-step2-parents-alternate-phone"
                 name="step2[parents][alternate][phone]" value="" size="60" maxlength="128"
                 class="form-text masked_input-processed">
        </div>
        <div
          class="form-item form-type-masked-input form-item-step2-parents-alternate-cellphone">
          <label for="edit-step2-parents-alternate-cellphone">Cell Phone </label>
          <input type="text" id="edit-step2-parents-alternate-cellphone"
                 name="step2[parents][alternate][cellphone]" value="" size="60" maxlength="128"
                 class="form-text masked_input-processed">
        </div>
        <div class="form-item form-type-emailfield form-item-step2-parents-alternate-email">
          <label for="edit-step2-parents-alternate-email">Email Address </label>
          <input type="email" id="edit-step2-parents-alternate-email"
                 name="step2[parents][alternate][email]" value="" size="60" maxlength="128"
                 class="form-text form-email">
        </div>
      </div>
    </fieldset>
  </div>

    <a href="test.pdf"><span><strong>Parent Information Packet</strong> (PDF)</span>
      This packet will give you all the information you need to ensure your child has a great
      time at camp.</a>

</fieldset>
<fieldset class="form-wrapper" id="edit-step2-emergency">
  <legend><span class="fieldset-legend">Emergency Medical Release</span></legend>
  <div class="fieldset-wrapper">
    <fieldset class="form-wrapper">
      <legend><span class="fieldset-legend">Emergency Contact</span></legend>
      <div class="fieldset-wrapper">
        <div class="form-item form-type-textfield form-item-step2-emergency-first-name">
          <label for="edit-step2-emergency-first-name">First Name </label>
          <input type="text" id="edit-step2-emergency-first-name"
                 name="step2[emergency][first_name]" value="" size="60" maxlength="128"
                 class="form-text">
        </div>
        <div class="form-item form-type-textfield form-item-step2-emergency-last-name">
          <label for="edit-step2-emergency-last-name">Last Name </label>
          <input type="text" id="edit-step2-emergency-last-name"
                 name="step2[emergency][last_name]"
                 value="" size="60" maxlength="128" class="form-text">
        </div>
        <div class="form-item form-type-masked-input form-item-step2-emergency-phone">
          <label for="edit-step2-emergency-phone">Daytime Phone </label>
          <input type="text" id="edit-step2-emergency-phone" name="step2[emergency][phone]"
                 value=""
                 size="60" maxlength="128" class="form-text masked_input-processed">
        </div>
        <div class="form-item form-type-textfield form-item-step2-emergency-textfield">
          <label for="edit-step2-emergency-textfield">Relationship to child. </label>
          <input type="text" id="edit-step2-emergency-textfield"
                 name="step2[emergency][textfield]"
                 value="" size="60" maxlength="128" class="form-text">
        </div>
        <p>
          NOTE: We issue a <strong>safety code</strong> during camp enrollment so that only
          authorized persons
          may pick up campers. You will be required to have this code to pick up any camper.
        </p>
      </div>
    </fieldset>
    <fieldset class="form-wrapper">
      <div class="fieldset-wrapper">
        <p><strong>
            Is there any other information which Oklahoma Children’s Theatre should be aware of
            before allowing any children listed above to attend programming?
          </strong></p>

        <div class="form-item form-type-radios form-item-step2-emergency-is-other-information">
          <label for="edit-step2-emergency-is-other-information">Other information. <span
              class="form-required" title="This field is required.">*</span></label>


        </div>
        <div id="edit-step2-emergency-is-other-information" class="form-radios">
          <div class="form-item form-type-radio form-item-step2-emergency-is-other-information">
            <input type="radio" id="edit-step2-emergency-is-other-information-yes"
                   name="step2[emergency][is_other_information]" value="yes" class="form-radio">
            <label class="option"
                   for="edit-step2-emergency-is-other-information-yes">Yes </label>

          </div>
          <div class="form-item form-type-radio form-item-step2-emergency-is-other-information">
            <input type="radio" id="edit-step2-emergency-is-other-information-no"
                   name="step2[emergency][is_other_information]" value="no" checked="checked"
                   class="form-radio"> <label class="option"
                                              for="edit-step2-emergency-is-other-information-no">No </label>

          </div>
        </div>

        <div class="form-item form-type-textarea form-item-step2-emergency-other-information">
          <label for="edit-step2-emergency-other-information">If YES, please explain
            below </label>

          <div class="form-textarea-wrapper resizable textarea-processed resizable-textarea">
            <textarea id="edit-step2-emergency-other-information"
                      name="step2[emergency][other_information]" cols="60" rows="5"
                      class="form-textarea"></textarea>

            <div class="grippie"></div>
          </div>
        </div>
      </div>
    </fieldset>
  </div>
</fieldset>

<div class="text">
  <div class="left-part">

    <span><strong>Medical</strong></span>

    <p>
      The child listed above has my permission to participate in all camp activities and is in good health.
      I give permission for the designated person to administer over the counter or prescription medication
      as directed.
    </p>

    <p>
      I hereby, and for my heirs, executors, and administrators, assigns and all legal guardians, waive and
      release any and all rights and claims of any nature I may have against Oklahoma Children’s Theatre,
      its Directors, employees, Board of Directors, volunteers, campers and cooperating entities for and
      against any and all injuries and damages of any nature, which my child may suffer while taking part in
      camp or other activities associated with this camp.
    </p>

    <p>
      In case of a medical emergency, after every reasonable effort has been made to contact me or the child
      s physician, I hereby give my permission to the Emergency Medical personnel contacted by Oklahoma
      Children’s Theatre to secure treatment for, hospitalize and order injection, anesthesia or surgery for
      my child. I also authorize Oklahoma Children’s Theatre to provide a copy of this form to proper
      medical personnel for purposes of treating my child. In the event that any such treatment is not
      covered by insurance applicable to the activities, I agree to pay all expenses incurred in such
      emergency treatment.</p>
  </div>
  <div class="right-part">
    <span><strong>Policies & Proceedures</strong></span>

    <p>
      As a parent, I have read all information concerning Oklahoma Children’s Theatre camps and give my child permission
      to be active as a participant in the camp. I understand that my child will be asked to participate fully in all
      activities and will be expected to abide by all rules and policies, as stated in the parent packet, of the camp. I
      understand that Oklahoma Children’s Theatre are not responsible for lost, stolen or damage of personal property
      while my child is at camp.
    </p>

    <p>
      I give my permission for my child to have photographic and/or video images taken while at Oklahoma Children’s
      Theatre camps for fundraising & publicity purposes. Consent is give to Oklahoma Children’s Theatre, its Directors,
      employees, agents and cooperating entities to use the child's name, picture, likeness, artwork, and recordings for
      use in any media for editorial, educational, promotional or advertising purposes in furtherance of the purposes
      and
      objectives of Oklahoma Children’s Theatre without compensation for such usage. I waive the right to inspect or
      approve finished product including written copy.
    </p>
  </div>
</div>
<div class="bottom-form">
  <span class="info">* Required fields</span>
  <div class="desc">
    <p>By clicking SUBMIT, the parent or guardian listed above agrees to all the terms conditions of this form.</p>
  </div>
  <div class="btn-wrap style-a not-alone">
    <div class="form-actions">
      <input type="submit" id="edit-step2-previous" name="prev" value="Previous"
             class="form-submit ajax-processed">
    </div>
    <div class="form-actions">
      <input type="submit" id="edit-step2-submit" name="add"
             value="Add to cart" class="form-submit">
    </div>
  </div>
</div>
</div>
</fieldset>
<input type="hidden" name="form_build_id" value="form-aZtngRJo8TcDBLZfM1e1uqcS7RgneWhMBRoVlUW0bzc">
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