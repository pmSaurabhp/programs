var v="vehicle";
var stuff="global Stuff";
var j=0;
function fun(stuff)
{ console.log(v);
   stuff="hello world";
   j=2;
}
fun();
console.log(stuff);
console.log(j)
