var header=document.querySelector("#one");
header.style.color="red";
var head2=document.querySelector("#two");
head2.textContent=":)";
var i=0;
function getRandomColor()
{ var letter="0123456789ABCDEF";
   var color="#";
   for(var i=0;i<6;i++)
  { color=color+letter[Math.floor(Math.random()*16)]; }
  return color;
}
function getRandomText()
{  var dict={ 1:"<pre>:)</pre>",2:"<pre>  :o</pre>",3:"<pre>	:p</pre>",4:"<pre>	  ;D</pre>",5:"<pre>	  :<</pre>",6:"<pre>	  :D</pre>" };
     i++;
   if(i==7)
   { i=1;}
  return head2.innerHTML=dict[i];
}  

function setColor()
{
   header.style.color=getRandomColor();
}

setInterval("setColor()",500);
setInterval("getRandomText()",500);