    <?php foreach ($items as $delta => $item): ?>
      <span class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?> </span>
    <?php endforeach; ?>
