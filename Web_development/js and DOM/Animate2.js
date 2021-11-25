
$("input").eq(0).click(function(){      // screen width 1440px
    $("#b1").animate({left: '+=200px'});     // move right 250px
    $("#b2").animate({left: '-=200px'});   // move left
  });

 // how to run animate inside for loop one by one
  // https://stackoverflow.com/questions/51429566/run-animation-on-items-inside-loop-one-by-one-javascript
  
  $("input").eq(1).click(function(){      // screen width 1440px
    
   var h=0;
    for(var i=1;i<6;i++)
    { 
    h=h+100;
    var s= h +'px';
    var k=0;
    if(i>=3)
     { k=2; }
    
      $("div").eq(i-k).animate({bottom :  s },1000);
      console.log(s);
    
    }
    
  });

