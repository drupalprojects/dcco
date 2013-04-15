$(document).ready(function() {
  if($("#yeti").length > 0){
    $("#yeti").click(function(){
      $.scrollTo( $("#hipster-yeti"), 2000, {onAfter:function(){ showSpeech(); } } );
      return false;
    })
    //startMoving();
  }
  
});


function startMoving() {
  
  moveAround();
  
}

function moveAround() {
  
  var $left = 190;
  var $top = 100;
  var $distance = 20;
  
  var $p = $("#balloon-boy").position();
  
  var $l_distance = $left + Math.floor(Math.random()*$distance);
  var $t_distance = $top + Math.floor(Math.random()*$distance);
  
  var $l_difference = $p.left - $l_distance;
  var $t_difference = $p.top - $t_distance;
  
  var $m = Math.sqrt(Math.pow($l_difference, 2) + Math.pow($t_difference, 2));
  
  var $time = $m/4;
  
  $("#balloon-boy").animate({
    left: $l_distance,
    top: $t_distance
  },
  $time*1000,
  "easeInOutSine",
  function(){
    setTimeout("moveAround()", 2000);
  })
}

function showSpeech() {
  $("#hipster-yeti a").addClass("active")
  setTimeout("hideSpeech()", 2000);
}

function hideSpeech(){
  $("#hipster-yeti a").removeClass("active");
}