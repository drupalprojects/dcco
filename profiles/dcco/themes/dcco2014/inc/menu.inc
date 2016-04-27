<?php
/**
 * @file
 * Menu hooks.
 */

/**
 * Overrides theme_menu_tree().
 */
function dcco2014_menu_tree__main_menu($variables) {
  return '<ul class="nav nav-inline">' . $variables['tree'] . '</ul>';
}

/**
 * Implements hook_preprocess_menu_link().
 */
function dcco2014_preprocess_menu_link(&$vars) {

  // Set shortcut variables. Hooray for less typing!
  $menu = $vars['element']['#original_link']['menu_name'];
  $mlid = $vars['element']['#original_link']['mlid'];
  $item_classes = &$vars['element']['#attributes']['class'];
  $link_classes = &$vars['element']['#localized_options']['attributes']['class'];

  // Add global classes to all menu links.
  $item_classes[] = 'nav-item';
  $link_classes[] = 'nav-link';
}

/**
 * Add menu title as a class
 */
function dcco2014_menu_link(array $variables) {

  $element = $variables['element'];
  $menu = $element['#original_link']['menu_name'];
  $sub_menu = '';
  $name_id = strtolower(strip_tags($element['#title']));
  
  // remove colons and anything past colons
  if (strpos($name_id, ':')) $name_id = substr ($name_id, 0, strpos($name_id, ':'));

  //Preserve alphanumerics, everything else goes away
  $pattern = '/[^a-z]+/ ';
  $name_id = preg_replace($pattern, '', $name_id);

  $element['#attributes']['class'][] = $name_id;
  $element['#localized_options']['attributes']['class'][] = "link-" . $name_id;

  if($name_id == "register" && $menu == "main-menu") :
    $element['#localized_options']['attributes']['class'][] = 'icon-user';
  endif;

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";

  


}
