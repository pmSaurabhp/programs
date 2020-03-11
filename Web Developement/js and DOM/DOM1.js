var header=document.querySelector("h1");
header.style.color="red";

function getRandomColor()
{ var letter="0123456789ABCDEF";
   var color="#";
   for(var i=0;i<6;i++)
  { color=color+letter[Math.floor(Math.random()*16)]; }
  return color;
}

function setColor()
{
   header.style.color=getRandomColor();
}

setInterval("setColor()",500);
