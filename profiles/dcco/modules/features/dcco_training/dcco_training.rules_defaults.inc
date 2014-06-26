<?php
/**
 * @file
 * dcco_training.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dcco_training_default_rules_configuration() {
  $items = array();
  $items['rules_redirect_training_to_cart'] = entity_import('rules_config', '{ "rules_redirect_training_to_cart" : {
      "LABEL" : "Redirect Training to Cart",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_order", "rules", "commerce_cart" ],
      "ON" : { "commerce_cart_product_add" : [] },
      "IF" : [
        { "commerce_order_contains_product_type" : {
            "commerce_order" : [ "commerce_order" ],
            "product_type" : { "value" : { "product_training" : "product_training" } },
            "operator" : "\\u003E=",
            "value" : "1"
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "cart" } } ]
    }
  }');
  return $items;
}
