var t=document.querySelectorAll("td");
var f=0;
var r=document.querySelector("#set");
function set(){
  for(var i=0;i<t.length;i++)
   { t[i].textContent=""; }
   j="2";
   document.querySelector("h2").textContent="J = "+j;
}

function choose()
{ if(f==0)
  { this.textContent="X" ;
    f=1;
  }
  else {
    this.textContent="O";
    f=0;
  }
}

 var j=0;
for(var i=0;i<t.length;i++)
{ t[i].addEventListener("click",choose);
  j++;
}
document.querySelector("h2").textContent="J = "+j+" addEventListener () registers th element with click function choose()";

r.addEventListener("click",set);
