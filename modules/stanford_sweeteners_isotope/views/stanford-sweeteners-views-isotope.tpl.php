<?php
/**
 * @file views-isotope.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

?>
<div class="isotope-container" id="<?php print $isotope_id; ?>">
  <?php foreach ( $rows as $id => $row ): ?>
  <?php $dac = !empty($classlist[$id]) ? $classlist[$id] : ""; ?>
    <div class="isotope-element isotope-element-<?php print $id; ?> <?php print $dac; ?>" data-category="<?php print $dac; ?>">
      <?php print $row; ?>
    </div>
  <?php endforeach; ?>
</div>


