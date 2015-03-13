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
?>
<h3 class="form-label"><?php print check_plain($options['render_label']); ?></h3>
<?php
}
?>

<!-- RENDER AS LINKS -->
<?php if (!isset($options['render_filters']) || $options['render_filters'] == "links" ) { ?>
  <div class="isotope-options">
    <ul class="filters option-set clearfix"  >
      <?php foreach ( $rows as $id => $row ): ?>
        <?php $dataoption = stanford_sweeteners_isotope_trim($row);    ?>
        <li><a class="filter-button" data-option-value=".<?php print $dataoption; ?>" href="#filter"><?php print trim($row); ?></a></li>
      <?php endforeach; ?>

    </ul>
  </div>
<?php
  }
  else {
?>
<!-- RENDER AS CHECKBOXES -->
 <div class="isotope-options isotope-filter-checkboxes">
  <div class="filters option-set clearfix" role="group">
  <?php foreach ( $rows as $id => $row ): ?>
     <?php $dataoption = stanford_sweeteners_isotope_trim($row);  ?>
       <label for="<?php print $dataoption; ?>"> <input type="checkbox" value=".<?php print $dataoption; ?>" class="<?php print $dataoption; ?>" name="<?php print $dataoption; ?>" role="checkbox" aria-checked="false" /><?php print trim($row) ?></label>
  <?php endforeach; ?>
    </div>
  </div>
<?php } ?>





