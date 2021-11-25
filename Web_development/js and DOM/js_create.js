var c=document.getElementById("container");

var btn = document.createElement("BUTTON");   // Create a <button> element
btn.innerHTML = "CLICK ME";                   // Insert text


for(var i=0;i<3;i++)
{ c.innerHTML=i;


var p1=document.createElement('p');
p1.innerHTML=i;
document.body.appendChild(p1);  

var b=document.createElement('div');
b.classList.add('block');
 b.style.height="100px";
 //b.style.left=i*100+"px";
 b.style.transform = `translate(${i * 60}px)`;
 b.innerHTML=i;
document.body.appendChild(b);
}


 document.body.appendChild(btn);  