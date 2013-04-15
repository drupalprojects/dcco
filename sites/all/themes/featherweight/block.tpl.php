<div class="<?php print "block block-$block->module" ?>" id="<?php print strtolower("block-$block->module-$block->delta"); ?>">
  <?php if($block->subject) : ?>
  <h2><?php print $block->subject ?></h2>
  <?php endif; ?>
  <div class="content"><?php print $block->content ?></div>
</div>