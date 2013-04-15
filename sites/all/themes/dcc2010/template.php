<?php
// $Id: template.php,v 1.16.2.2 2009/08/10 11:32:54 goba Exp $

/**
 * Sets the body-tag class attribute.
 *
 * Adds 'sidebar-left', 'sidebar-right' or 'sidebars' classes as needed.
 */
/*
function dcc2010_body_class($left, $right) {
  if ($left != '' && $right != '') {
    $class = 'sidebars';
  }
  else {
    if ($left != '') {
      $class = 'sidebar-left';
    }
    if ($right != '') {
      $class = 'sidebar-right';
    }
  }

  if (isset($class)) {
    print ' class="'. $class .'"';
  }
}
*/

/**
 * Implements theme_preprocess_page().
 */
function dcc2010_preprocess_page(&$vars) {
  $vars['tabs2'] = menu_secondary_local_tasks();

  // Hook into color.module
  if (module_exists('color')) {
    _color_page_alter($vars);
  }
  
  $vars['sidebar'] = $vars['right'];
}

/**
 * Implements theme_preprocess_node().
 */
function dcc2010_preprocess_node(&$vars, $hook) {
  if ($vars['node']->type == 'session' && $teaser == FALSE) {
    $account = user_load($vars['node']->uid);
    if ($account->picture) {
      $vars['user_image'] = theme('imagecache', 'avatar_small', $account->picture);
    }
  }
}


function dcc2010_node_submitted($node) {
  return t('Posted by !username on !datetime',
    array(
      '!username' => theme('username', $node),
      '!datetime' => format_date($node->created, 'custom', 'F jS, Y')
    ));
}

function dcc2010_comment_submitted($comment) {
  return t('Posted by !username on !date at !time',
    array(
      '!username' => theme('username', $comment),
      '!date' => format_date($comment->timestamp, 'custom', 'F jS, Y'),
      '!time' => format_date($comment->timestamp, 'custom', 'g:ia')
    ));
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function phptemplate_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    $breadcrumb[] = drupal_get_title();
    return theme('item_list', $breadcrumb, NULL, 'ul', array('class' => 'breadcrumb'));
  }
}

/**
 * Add a "Comments" heading above comments except on forum pages.
 */

/*
function dcc2010_preprocess_comment_wrapper(&$vars) {
  if ($vars['content'] && $vars['node']->type != 'forum') {
    $vars['content'] = '<h2 class="comments">'. t('Comments') .'</h2>'.  $vars['content'];
  }
}

function dcc2010_comment_submitted($comment) {
  return t('!datetime — !username',
    array(
      '!username' => theme('username', $comment),
      '!datetime' => format_date($comment->timestamp)
    ));
}

function dcc2010_node_submitted($node) {
  return t('!datetime — !username',
    array(
      '!username' => theme('username', $node),
      '!datetime' => format_date($node->created),
    ));
}
*/

/**
 * Generates IE CSS links for LTR and RTL languages.
 */
/*
function dcc2010_get_ie_styles() {
  global $language;

  $iecss = '<link type="text/css" rel="stylesheet" media="all" href="'. base_path() . path_to_theme() .'/fix-ie.css" />';
  if ($language->direction == LANGUAGE_RTL) {
    $iecss .= '<style type="text/css" media="all">@import "'. base_path() . path_to_theme() .'/fix-ie-rtl.css";</style>';
  }

  return $iecss;
}
*/
