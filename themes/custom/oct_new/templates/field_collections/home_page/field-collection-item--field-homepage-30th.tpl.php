<?php

/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
//dsm($content);
?>

<?php  
	if(!empty($content['field_home_30th_show']['#items'][0]['value'])):
?>

	<div class="anniversary">
		<div class="orange-bar"></div>

		<div class="cols-3">
			<div class="col">
			<div class="custom">
				<?php if(!empty($content['field_home_30th_title'])): ?>
					<h3>
						<?php print render($content['field_home_30th_title']); ?>	
					</h3>
				<?php endif; ?>
			</div>
			</div>

			<div class="col">
			<div class="custom">
				<?php if(!empty($content['field_home_30th_text'])): ?>
					<?php print render($content['field_home_30th_text']); ?>	
				<?php endif; ?>
			</div>
			</div>

			<div class="col">
			<div class="custom">
				<?php if(!empty($content['field_home_30th_image'])): ?>
					<?php print render($content['field_home_30th_image']); ?>	
				<?php endif; ?>
				<?php if(!empty($content['field_home_30th_button'])): ?>
					<?php print render($content['field_home_30th_button']); ?>	
				<?php endif; ?>
			</div>
			</div>
		</div>

	</div>

<?php 
	endif;
?>