<?php
/**
 * @file
 * stanford_sweeteners.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function stanford_sweeteners_taxonomy_default_vocabularies() {
  return array(
    'sweetener_audience' => array(
      'name' => 'Sweetener Audience',
      'machine_name' => 'sweetener_audience',
      'description' => 'Sweetener Audience',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'sweetener_category' => array(
      'name' => 'Sweetener Category',
      'machine_name' => 'sweetener_category',
      'description' => 'A category for grouping sweetener types',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
