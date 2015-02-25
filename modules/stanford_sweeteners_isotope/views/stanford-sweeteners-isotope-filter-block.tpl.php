<?php
/**
 * @file views-isotope-filter-block.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates

 */
// remove characters that cause problems with classes

?>
<!-- RENDER AS CHECKBOXES -->
<?php if (!$options['render_as_checkboxes']) { ?>

  <div id="isotope-options">
    <ul id="filters" class="option-set clearfix" data-option-key="filter">
      <?php foreach ( $rows as $id => $row ): ?>
        <?php $dataoption = stanford_sweeteners_isotope_trim($row);    ?>
        <li><a class="filterbutton" data-option-value=".<?php print $dataoption; ?>" href="#filter"><?php print trim($row); ?></a></li>
      <?php endforeach; ?>

    </ul>
  </div>
<?php } else { ?>
<!-- RENDER AS LINKS -->
 <div id="isotope-checkbox-options">
  <div class="option-set clearfix" data-group="1">
  <?php foreach ( $rows as $id => $row ): ?>
     <?php $dataoption = stanford_sweeteners_isotope_trim($row);  ?>
       <label for="<?php print $dataoption; ?>"> <input type="checkbox" checked value=".<?php print $dataoption; ?>" id="<?php print $dataoption; ?>" /><?php print trim($row) ?></label>
  <?php endforeach; ?>
    </div>
  </div>
  <p id="filter"></p>
<?php } ?>





