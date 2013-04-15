<?php
// $Id: node.tpl.php,v 1.5 2007/10/11 09:51:29 goba Exp $
?>
<? if($teaser){ ?>
  <div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">

  <?php print $picture ?>

  <?php if ($page == 0): ?>
    <h4><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h4>
  <?php endif; ?>

    <div class="user-data">
      <?php if($user_image){ ?>
      <div class="user-picture">
        <?php print $user_image ?>
      </div>
      <? } ?>
      <?php if ($submitted): ?>
        <span class="submitted"><?php print $submitted; ?></span>
      <?php endif; ?>
    </div>

    <div class="content clear-block">
      <div class="session-meta">
        <?=$node->content["field_skill_level"]["#children"];?>
        <?=$node->content["field_track"]["#children"];?>
      </div>
      <div class="session-description">
        <?php print $node->content["body"]["#value"]; ?>
      </div>
    </div>

    <div class="clear-block">
      <div class="meta">
      <?php if ($taxonomy): ?>
        <div class="terms"><?php print $terms ?></div>
      <?php endif;?>
      </div>

      <?php if ($links): ?>
        <div class="links"><?php print $links; ?></div>
      <?php endif; ?>
    </div>

  </div>
<? } else { ?>
  <div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">

  <?php print $picture ?>

  <?php if ($page == 0): ?>
    <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  <?php endif; ?>
  
    <div class="user-data">
      <?php if($user_image){ ?>
      <div class="user-picture">
        <?php print $user_image ?>
      </div>
      <? } ?>
      <?php if ($submitted): ?>
        <span class="submitted"><?php print $submitted; ?></span>
      <?php endif; ?>
    </div>

    <div class="content clear-block">
      <?php print $content ?>
    </div>

    <div class="clear-block">
      <div class="meta">
      <?php if ($taxonomy): ?>
        <div class="terms"><?php print $terms ?></div>
      <?php endif;?>
      </div>

      <?php if ($links): ?>
        <div class="links"><?php print $links; ?></div>
      <?php endif; ?>
    </div>

  </div>
<? } ?>