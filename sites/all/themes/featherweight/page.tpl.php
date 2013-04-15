<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
	<title><?=$head_title?></title>
	<?=$head?>
	<?=$styles?>
	<?=$scripts?>
</head>

<body class="<?=$body_classes?>">
<div class="container_12">
  <div class="grid_3">
    <?=$left?>
  </div>
  <div class="grid_6 content">
    <h1><?=$title?></h1>    
    <?=$messages?>
    <?=$tabs?>
    <?=$content?>
  </div>
  <div class="grid_3">
    <?=$right?>
  </div>
</div>

</body>
</html>
