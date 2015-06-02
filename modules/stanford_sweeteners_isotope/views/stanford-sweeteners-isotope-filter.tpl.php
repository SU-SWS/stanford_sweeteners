<?php
/**
 * @file views-isotope-filter-block.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates

 */
?>

<?php
if (!empty($options['render_label'])) {
  $id = "s" . md5(serialize(($rows)));
?>
<h3 class="form-label" id="<?php print $id; ?>"><?php print check_plain($options['render_label']); ?></h3>
<?php
}
?>

<?php if (!isset($options['render_filters']) || $options['render_filters'] == "links" ) {
  // LINKS
?>
  <div class="isotope-options">
    <ul class="filters option-set clearfix"  >
      <?php foreach ( $rows as $id => $row ): ?>
        <?php $dataoption = stanford_sweeteners_isotope_trim($row); ?>
        <li><a class="filter-button" data-option-value=".<?php print $dataoption; ?>" href="#filter"><?php print trim($row); ?></a></li>
      <?php endforeach; ?>

    </ul>
  </div>
<?php
  }
  else {
  // CHECKBOXES
?>
<div class="isotope-options isotope-filter-checkboxes">
  <form class="filters option-set clearfix" role="group" aria-labelledby="<?php print $id; ?>" tabindex="0">
  <?php foreach ( $rows as $id => $row ): ?>
    <?php $dataoption = stanford_sweeteners_isotope_trim($row); ?>
    <label><input type="checkbox" value=".<?php print $dataoption; ?>" class="<?php print $dataoption; ?>" name="<?php print $dataoption; ?>" role="checkbox" aria-checked="false" aria-hidden="false" /><?php print trim($row) ?></label>
  <?php endforeach; ?>
  </form>
</div>
<?php } ?>





