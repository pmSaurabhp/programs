// var t=document.querySelectorAll("td");
// var f=0;
// var r=document.querySelector("#set");
// function set(){
//   for(var i=0;i<t.length;i++)
//    { t[i].textContent=""; }
//    j="2";
//    document.querySelector("h2").textContent="J = "+j;
// }

// function choose()
// { if(f==0)
//   { this.textContent="X" ;
//     f=1;
//   }
//   else {
//     this.textContent="O";
//     f=0;
//   }
// }

//  var j=0;
//  for(var i=0;i<t.length;i++){
//  t[i].addEventListener("click",choose);
//   j++;
//  }
// document.querySelector("h2").textContent="J = "+j+" addEventListener () registers th element with click function choose()";

// r.addEventListener("click",set);


const ele=document.querySelectorAll("td");
const reset=document.querySelector("#set");
const table=document.querySelector(".tab");
const result=document.querySelector("h2");

let flag=true;
let matrix= Array(3).fill( Array(3).fill(-1) );

table.addEventListener("click",function(e){
  let box=e.target.closest("td");
  if(box === null)  
      return;

  console.log(box.textContent);
  if(box.textContent === "" && flag != -1){
      box.textContent = flag===false? "O":"X";
      flag = !flag;
      let message = check();
      if( message != "")
      {
        result.textContent = `${message} Wins`;
        flag =-1;
      }
  }
});

const check = function(){
   if(ele[0].textContent === ele[1].textContent && ele[1].textContent === ele[2].textContent)
      return ele[0].textContent;
   else if(ele[0].textContent === ele[3].textContent && ele[3].textContent === ele[6].textContent)
      return ele[0].textContent;
    else if(ele[0].textContent === ele[4].textContent && ele[4].textContent === ele[8].textContent)
    return ele[0].textContent;
    else if(ele[3].textContent === ele[4].textContent && ele[4].textContent === ele[5].textContent)
    return ele[3].textContent;
 else if(ele[6].textContent === ele[7].textContent && ele[7].textContent === ele[8].textContent)
 return ele[6].textContent;
else if(ele[6].textContent === ele[4].textContent && ele[4].textContent === ele[2].textContent)
return ele[6].textContent;
else if(ele[1].textContent === ele[4].textContent && ele[4].textContent === ele[7].textContent)
return ele[1].textContent;
else if(ele[2].textContent === ele[5].textContent && ele[5].textContent === ele[8].textContent)
return ele[2].textContent;
else 
  return "";

};

reset.addEventListener("click", function(){
    // ele.map( (e) => {e.textContent =""}); does not works as ele is not an array .its a node list
    for(let i=0;i<9;i++){
        ele[i].textContent = "";
    }
    flag = true;
    result.textContent = "";
});
