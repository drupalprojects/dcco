<?php

/**
 * Render a panel pane like a block.
 *
 * A panel pane can have the following fields:
 *
 * $pane->type -- the content type inside this pane
 * $pane->subtype -- The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * $content->title -- The title of the content
 * $content->content -- The actual content
 * $content->links -- Any links associated with the content
 * $content->more -- An optional 'more' link (destination only)
 * $content->admin_links -- Administrative links associated with the content
 * $content->feeds -- Any feed icons or associated with the content
 * $content->subject -- A legacy setting for block compatibility
 * $content->module -- A legacy setting for block compatibility
 * $content->delta -- A legacy setting for block compatibility
 */
function featherweight_panels_pane($content, $pane, $display) {
  if (!empty($content->content)) {
    $idstr = $classstr = '';
    if (!empty($content->css_id)) {
      $idstr = ' id="' . $content->css_id . '"';
    }
    if (!empty($content->css_class)) {
      $classstr = ' ' . $content->css_class;
    }

    if (user_access('view pane admin links') && !empty($content->admin_links)) {
      $output .= "<div class=\"admin-links panel-hide\">" . theme('links', $content->admin_links) . "</div>\n";
    }
    if (!empty($content->title)) {
      $output .= "<h3 class=\"title\">$content->title</h3>\n";
    }

    if (!empty($content->feeds)) {
      $output .= "<div class=\"feed\">" . implode(' ', $content->feeds) . "</div>\n";
    }

    $output .= $content->content;

    if (!empty($content->links)) {
      $output .= "<div class=\"links\">" . theme('links', $content->links) . "</div>\n";
    }


    if (!empty($content->more)) {
      if (empty($content->more['title'])) {
        $content->more['title'] = t('more');
      }
      $output .= "<div class=\"more-link\">" . l($content->more['title'], $content->more['href']) . "</div>\n";
    }
    return $output;
  }
}


/**
 * Return a themed list of items.
 *
 * @param $items
 *   An array of items to be displayed in the list. If an item is a string,
 *   then it is used as is. If an item is an array, then the "data" element of
 *   the array is used as the contents of the list item. If an item is an array
 *   with a "children" element, those children are displayed in a nested list.
 *   All other elements are treated as attributes of the list item element.
 * @param $title
 *   The title of the list.
 * @param $type
 *   The type of list to return (e.g. "ul", "ol")
 * @param $attributes
 *   The attributes applied to the list element.
 * @return
 *   A string containing the list output.
 */
function featherweight_item_list($items = array(), $title = NULL, $type = 'ul', $attributes = array('class' => 'item-list')) {
    
  $output = '';
  if (isset($title)) {
    $output .= '<div class="item-list">';    
    $output .= '<h3>'. $title .'</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type". drupal_attributes($attributes) .'>';
    $num_items = count($items);
    foreach ($items as $i => $item) {
      $attributes = array();
      $children = array();
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        $data .= theme_item_list($children, NULL, $type, $attributes); // Render nested list
      }
      if ($i == 0) {
        $attributes['class'] = empty($attributes['class']) ? 'first' : ($attributes['class'] .' first');
      }
      if ($i == $num_items - 1) {
        $attributes['class'] = empty($attributes['class']) ? 'last' : ($attributes['class'] .' last');
      }
      $output .= '<li'. drupal_attributes($attributes) .'>'. $data ."</li>\n";
    }
    $output .= "</$type>";
  }
  if (isset($title)) {
    $output .= '</div>';
  }
  return $output;
}


/**
 * Return a themed set of links.
 *
 * @param $links
 *   A keyed array of links to be themed.
 * @param $attributes
 *   A keyed array of attributes
 * @return
 *   A string containing an unordered list of links.
 */
function featherweight_links($links, $attributes = array('class' => 'links')) {
  
  $output = '';
  if (count($links) > 0) {
    $output = '<ul'. drupal_attributes($attributes) .'>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = _featherweight_css_safe($link['title']);
      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class .= ' first';
      }
      if ($i == $num_links) {
        $class .= ' last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))) {
        $class .= ' active';
      }
      if (strstr($key, 'active-trail')) {
        $class .= ' active-trail';
      }   
      /*
      $trail = menu_get_active_trail();   
      foreach ($trail as $menu_item) {
        if ($menu_item['href'] == $link['href']) {
          $class .= ' active-trail';
          break;
        }
      }
      */
      
      
      $link['attributes']['class'] = $class;
      $output .= '<li'. drupal_attributes(array('class' => $class)) .'>';


      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $link['html'] = TRUE;
        $output .= l('<span>'. $link['title'] .'</span>', $link['href'], $link);
      }
      else if (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span'. $span_attributes .'>'. $link['title'] .'</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}



function featherweight_menu_item_link($link) {
  if (empty($link['localized_options'])) {
    $link['localized_options'] = array();
  }
  $css = _featherweight_css_safe($link['title']);
  if ($link['localized_options']['attributes']['class']) {
    $link['localized_options']['attributes']['class'] .= ' ' . $css;
  } else {
    $link['localized_options']['attributes']['class'] = $css;
  }  
  return l($link['title'], $link['href'], $link['localized_options']);
}


/**
 * Preprocessor for blocks
 */
function featherweight_preprocess_block(&$vars){
}

/**
 * Preprocessor for main views tpl
 */
function featherweight_preprocess_views_view(&$vars) {
  $display_name = $vars['view']->display[$vars['display_id']]->display_title;
  $vars['css_name'] = _featherweight_css_safe($vars['css_name']);
  $vars['css_name'] .= " " . $vars['css_name'] . "-" . _featherweight_css_safe($display_name);
}

/**
* Add more descriptive classes to form elements
**/
function featherweight_form_element($element, $value) {
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  $output = '<div class="form-item' . ($element['#title'] ? ' ' . _featherweight_css_safe($element['#title']) : '') . '"';
  if (!empty($element['#id'])) {
    $output .= ' id="'. $element['#id'] .'-wrapper"';
  }
  $output .= ">\n";
  $required = !empty($element['#required']) ? '<span class="form-required" title="'. $t('This field is required.') .'">*</span>' : '';

  if (!empty($element['#title'])) {
    $title = $element['#title'];
    if (!empty($element['#id'])) {
      $output .= ' <label for="'. $element['#id'] .'">'. $t('!title: !required', array('!title' => filter_xss_admin($title), '!required' => $required)) ."</label>\n";
    }
    else {
      $output .= ' <label>'. $t('!title: !required', array('!title' => filter_xss_admin($title), '!required' => $required)) ."</label>\n";
    }
  }

  $output .= " $value\n";

  if (!empty($element['#description'])) {
    $output .= ' <div class="description">'. $element['#description'] ."</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}




/**
 * Display the view as an HTML list element
 */
function featherweight_preprocess_views_view_list(&$vars) {
  featherweight_preprocess_views_view_unformatted($vars);
}

/**
 * Display the simple view of rows one after another
 */
function featherweight_preprocess_views_view_unformatted(&$vars) {
  $view     = $vars['view'];
  $rows     = $vars['rows'];
  
  $vars['classes'] = array();
  $vars['css_name'] = _featherweight_css_safe($vars['view']->name);
  // Set up striping values.
  foreach ($rows as $id => $row) {
    $vars['classes'][$id] = 'row-' . ($id + 1);
    $vars['classes'][$id] .= ' ' . ($id % 2 ? 'even' : 'odd');
    if ($id == 0) {
      $vars['classes'][$id] .= ' first';
    }
  }
  $vars['classes'][$id] .= ' last';
}

/**
 * Theme function for the 'generic' single file formatter.
 */
function featherweight_filefield_file($file) {
  $path = $file['filepath'];
  $url = file_create_url($path);
  $icon = theme('filefield_icon', $file);
  $parts = split('/', $file['filemime']);
  $css = _featherweight_css_safe($parts[count($parts)-1]);
  $name = $file['data']['description'] ? check_plain($file['data']['description']) : $file['filename'];
  return '<div class="filefield-file '. $css . '">'. l($name, $url, array('attributes' => array('class'=>$css))) .'</div>';
}

function _featherweight_css_safe($str) {
  return strtolower(strtr(trim(ereg_replace("[^A-Za-z0-9]+", ' ', $str)), ' ', '-'));  
}

/**
 * Remove duplicate content-type headers
 * Based on http://drupal.org/node/451304#comment-1711620
 */
function featherweight_preprocess_page(&$vars) {

  drupal_add_js(path_to_theme() .'/js/main.js');

  $vars['head'] = str_replace('<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />', '', $vars['head']);

} // featherweight_preprocess_page
