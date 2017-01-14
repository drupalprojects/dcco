<?php
/**
 * @file Additional settings for 2016.drupalcampcolorado.org.
 * Database connection and other settings are stored in prepend.php by Pantheon.
 */

/**
 * Implements HTTPS redirect for each environment in the development chain.
 */
if (isset($_SERVER['PANTHEON_ENVIRONMENT'])) {
  switch ($_SERVER['PANTHEON_ENVIRONMENT']) {
    case 'live':
      if (!isset($_SERVER['HTTP_X_SSL']) || (isset($_SERVER['HTTP_X_SSL']) && $_SERVER['HTTP_X_SSL'] != 'ON')) {
        header('HTTP/1.0 301 Moved Permanently');
        header('Location: https://2017.drupalcampcolorado.org'. $_SERVER['REQUEST_URI']);
        exit();
      }
      break;
    case 'dev':
      if (!isset($_SERVER['HTTP_X_SSL']) || (isset($_SERVER['HTTP_X_SSL']) && $_SERVER['HTTP_X_SSL'] != 'ON')) {
        header('HTTP/1.0 301 Moved Permanently');
        header('Location: https://dev-2017drupalcampcoloradoorg.pantheonsite.io'. $_SERVER['REQUEST_URI']);
        exit();
      }
      break;
    case 'test':
      if (!isset($_SERVER['HTTP_X_SSL']) || (isset($_SERVER['HTTP_X_SSL']) && $_SERVER['HTTP_X_SSL'] != 'ON')) {
        header('HTTP/1.0 301 Moved Permanently');
        header('Location: https://test-2017drupalcampcoloradoorg.pantheonsite.io'. $_SERVER['REQUEST_URI']);
        exit();
      }
      break;
  }
}
else {
  $databases['default']['default'] = array(
    'driver' => 'mysql',
    'database' => 'dcco',
    'username' => 'root',
    'password' => 'redhead21',
    'host' => '127.0.0.1',
  );
}

// Load local settings.php files.
$local_settings = __DIR__ . '/local.settings.php';
if (file_exists($local_settings)) {
  include $local_settings;
}

$conf['THEME_DEBUG'] = TRUE;

/**
 * Implements Redis cache on Pantheon.
 */
// All Pantheon Environments.
//if (defined('PANTHEON_ENVIRONMENT')) {
//  // Use Redis for caching.
//  $conf['redis_client_interface'] = 'PhpRedis';
//  $conf['cache_backends'][] = 'sites/all/modules/redis/redis.autoload.inc';
//  $conf['cache_default_class'] = 'Redis_Cache';
//  $conf['cache_prefix'] = array('default' => 'pantheon-redis');
//  // Do not use Redis for cache_form (no performance difference).
//  $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
//  // Use Redis for Drupal locks (semaphore).
//  $conf['lock_inc'] = 'sites/all/modules/redis/redis.lock.inc';
//}
