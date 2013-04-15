if (Drupal.ACDB) {
  /**
   * Performs a cached and delayed search
   * *** Copied from /misc/autocomplete.js, commented out error message ***
   */
  Drupal.ACDB.prototype.search = function (searchString) {
    var db = this;
    this.searchString = searchString;
  
    // See if this key has been searched for before
    if (this.cache[searchString]) {
      return this.owner.found(this.cache[searchString]);
    }
  
    // Initiate delayed search
    if (this.timer) {
      clearTimeout(this.timer);
    }
    this.timer = setTimeout(function() {
      db.owner.setStatus('begin');
  
      // Ajax GET request for autocompletion
      $.ajax({
        type: "GET",
        url: db.uri +'/'+ Drupal.encodeURIComponent(searchString),
        dataType: 'json',
        success: function (matches) {
          if (typeof matches['status'] == 'undefined' || matches['status'] != 0) {
            db.cache[searchString] = matches;
            // Verify if these are still the matches the user wants to see
            if (db.searchString == searchString) {
              db.owner.found(matches);
            }
            db.owner.setStatus('found');
          }
        },
        error: function (xmlhttp) {
          //alert(Drupal.ahahError(xmlhttp, db.uri));
        }
      });
    }, this.delay);
  };

} // if
