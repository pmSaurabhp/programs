var one=document.querySelector("#one");
var two=document.querySelector("#two");
var p=document.querySelector("p");

one.addEventListener("mouseover",function(){
one.textContent="bhago chuha aya bhago";
one.style.color="red";
})
one.addEventListener("mouseout",function(){
one.textContent="I am not scared of Mouse";
one.style.color="black";
})

two.addEventListener("click",function(){
  two.textContent="I am clicked";
  two.style.color="blue";

})
two.addEventListener("mouseout",function(){
two.textContent="Click Me";
two.style.color="black";
})

p.addEventListener("mouseover",function(){
  p.style.color="green";
})
