
$("input").eq(0).click(function(){      // screen width 1440px
  $("div").animate({left: '250px'});     // move right 250px
  $("div").animate({bottom: '-=250px'}); // move down 
  $("div").animate({left: '-=250px'});   // move left
  $("div").animate({bottom: '+=250px'}); // move up
});

$("input").eq(1).click(function(){
  var div = $("div");
  div.animate({height: '300px', opacity: '0.4'}, "slow");
  div.animate({width: '300px', opacity: '0.8'}, "slow");
  div.animate({height: '100px', opacity: '0.4'}, "slow");
  div.animate({width: '100px', opacity: '1'}, "slow");
});

