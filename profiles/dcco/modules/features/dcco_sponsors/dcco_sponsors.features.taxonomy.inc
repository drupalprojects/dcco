<?php
/**
 * @file
 * dcco_sponsors.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dcco_sponsors_taxonomy_default_vocabularies() {
  return array(
    'sponsorship_levels' => array(
      'name' => 'Sponsorship Levels',
      'machine_name' => 'sponsorship_levels',
      'description' => '',
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
