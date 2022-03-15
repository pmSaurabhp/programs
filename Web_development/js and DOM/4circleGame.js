'use strict';

let row=[...document.querySelectorAll("#r1 div")];
console.log(row);
console.log(String(row[1].style.width));
//row.forEach((ele)=>console.log(ele));











$(document).ready(function(){
  $("circle").click(function(){
    $(this).css("fill","red");
  })
});

var f=0;
var k=0;

function getColor(r,c){
 // console.log($("tr").eq(r).find("td").eq(c).find("div").css("background-color"));
 return $("tr").eq(r).find("td").eq(c).find("div").css("background-color");
};
function colorMatch(a,b,e,d){
  $("h1").html(a);
    $("h2").html(b);
      $("h3").html(e);
        $("h4").html("k="+k);
  if(a,b,e,d!=="rgb(128,128,128)"&&a===b&&a===e&&a===d&&a,b,e,d!==undefined)
  {return 1;}
  else {
    return 0;
  }

};

function checkHorizontal()
{  k=0;
  for(var i=0;i<7;i++)
   { for(var j=0;j<5;j++)
      {
        if(colorMatch(getColor(i,j),getColor(i,j+1),getColor(i,j+2),getColor(i,j+3)))
        {console.log("win");}
        else{
       continue;
        }
      }

   }

}
$(document).ready(function(){
  $("div").click(function(){
    if(f==0)
    { f=1;
      $(this).css("background","red");     
      checkHorizontal();
    }
    else {f=0;
      $(this).css("background","blue");  
    checkHorizontal();
    }
});


});
