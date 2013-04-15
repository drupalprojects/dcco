<!DOCTYPE html>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
	<title><?=$head_title?></title>
	<?=$head?>
	<?=$styles?>
	<?=$scripts?>
</head>

<body class="<?=$body_classes?>">
<div id="wrapper">
  <div id="wrapper-inner">
    <div id="container" class="clearfix">
      <div id="header">
        <h1 id="logo">
          <a href="/">DrupalCamp Colorado</a>
        </h1>
        <div id="twitter">
          <a href="http://twitter.com/drupalcolorado">Follow</a>
        </div>
        <div id="balloon-boy">
          <a href="/">June 26-27, 2010</a>
        </div>
        <?php print theme('links', $secondary_links, array('class' => 'links secondary-links')); ?>
        <?=$header?>
        <?php global $user; ?>
        <div id="global-login">
          <p>
        <?php if ($user->uid) : ?>
          <? print l(t('My Account'), 'user', array('attributes' => array('class' => 'my-account'), 'html' => true));?> &nbsp; <? print l(t('Logout'), 'logout', array('attributes' => array('class' => 'logout'), 'html' => true));?>
        <?php else : ?>
          <? print l(t('Login'), 'user/login', array('attributes' => array('class' => 'login'), 'html' => true));?> or <? print l(t('Create an Account'), 'user/register', array('attributes' => array('class' => 'register'), 'html' => true));?> to participate.
        <?php endif; ?>
          </p>
        </div>
        <?php print theme('links', $primary_links, array('class' => 'links primary-links')); ?>
      </div>
      <div id="main">
        <?php if($breadcrumb){?>
        <div id="breadcrumb">
          <?=$breadcrumb?>
        </div>
        <? } ?>
        <?=$tabs?>
        <div id="content">
          <?php if(!$is_front){?>
            <div id="content-inner">
          <? } ?>
            <?=$messages?>
            <?php if(!$is_front){?>
              <h1 class="page-title"><?=$title?></h1> 
            <? } ?>
            <?=$content?>
          <?php if(!$is_front){ // end content-inner ?>
            </div>
          <? } ?>
        </div>
        <?php if($sidebar){ ?>
          <div id="sidebar">
            <?=$sidebar?>
          </div>
        <? } ?>
      </div>
      <div id="footer">
        <?php if($footer){ ?>
          <div id="footer-content">
            <?=$footer?>
          </div>
        <? } ?>
        <div id="footer-links">
          <div id="volunteer-link"><?php print t("Thanks to our ").l(t("volunteers"), "volunteers")?></div>
          <?php print theme('links', $primary_links, array('class' => 'links primary-links')); ?>
          <?php print theme('links', $secondary_links, array('class' => 'links secondary-links')); ?>
        </div>
      </div>
      <div id="box-boy">
        <a href="http://en.wikipedia.org/wiki/Balloon_boy_hoax">Balloon Boy</a>
      </div>
    </div>
  </div>
</div>
<?php
print $closure;
?>
</body>
</html>
