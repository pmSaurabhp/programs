var v="vehicle"
var stuff="global Stuff"
var j=0;
function fun(stuff)    // here stuff is local variable   
{ console.log(v);      // if function fun() then stuff would be global variable 
   stuff="hello world"
   j=2;
}
fun()
console.log(stuff)
console.log(j)
