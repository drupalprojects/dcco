<!DOCTYPE html>
<!--[if lt IE 7]> <html class="lt-ie9 lt-ie8 lt-ie7" lang="en"> <![endif]-->
<!--[if IE 7]>    <html class="lt-ie9 lt-ie8" lang="en"> <![endif]-->
<!--[if IE 8]>    <html class="lt-ie9" lang="en"> <![endif]-->
<!--[if gt IE 8]><!--> <html lang="en"> <!--<![endif]-->
<head>
  <title><?php print $head_title; ?></title>
  <meta http-equiv="x-ua-compatible" content="ie=edge">
  <?php print $head; ?>
  <link rel="apple-touch-icon" sizes="57x57" href="/profiles/dcco/themes/dcco2016/favicons/apple-icon-57x57.png">
  <link rel="apple-touch-icon" sizes="60x60" href="/profiles/dcco/themes/dcco2016/favicons/apple-icon-60x60.png">
  <link rel="apple-touch-icon" sizes="72x72" href="/profiles/dcco/themes/dcco2016/favicons/apple-icon-72x72.png">
  <link rel="apple-touch-icon" sizes="76x76" href="/profiles/dcco/themes/dcco2016/favicons/apple-icon-76x76.png">
  <link rel="apple-touch-icon" sizes="114x114" href="/profiles/dcco/themes/dcco2016/favicons/apple-icon-114x114.png">
  <link rel="apple-touch-icon" sizes="120x120" href="/profiles/dcco/themes/dcco2016/favicons/apple-icon-120x120.png">
  <link rel="apple-touch-icon" sizes="144x144" href="/profiles/dcco/themes/dcco2016/favicons/apple-icon-144x144.png">
  <link rel="apple-touch-icon" sizes="152x152" href="/profiles/dcco/themes/dcco2016/favicons/apple-icon-152x152.png">
  <link rel="apple-touch-icon" sizes="180x180" href="/profiles/dcco/themes/dcco2016/favicons/apple-icon-180x180.png">
  <link rel="icon" type="image/png" sizes="192x192"  href="/profiles/dcco/themes/dcco2016/favicons/android-icon-192x192.png">
  <link rel="icon" type="image/png" sizes="32x32" href="/profiles/dcco/themes/dcco2016/favicons/favicon-32x32.png">
  <link rel="icon" type="image/png" sizes="96x96" href="/profiles/dcco/themes/dcco2016/favicons/favicon-96x96.png">
  <link rel="icon" type="image/png" sizes="16x16" href="/profiles/dcco/themes/dcco2016/favicons/favicon-16x16.png">
  <link rel="manifest" href="/manifest.json">
  <meta name="msapplication-TileColor" content="#ffffff">
  <meta name="msapplication-TileImage" content="/profiles/dcco/themes/dcco2016/favicons/ms-icon-144x144.png">
  <meta name="theme-color" content="#ffffff">
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <script type="text/javascript" src="//use.typekit.net/tpk4uum.js"></script>
  <script type="text/javascript">try{Typekit.load();}catch(e){}</script>
</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php
    print $page_top;
    print $page;
    print $page_bottom;
  ?>
</body>
</html>
