'use strict';

// coding challenge #4

/* 
Write a program that receives a list of variable names written in underscore_case and convert them to camelCase.
The input will come from a textarea inserted into the DOM (see code below), and conversion will happen when the button is pressed.
THIS TEST DATA (pasted to textarea)
underscore_case
 first_name
Some_Variable 
  calculate_AGE
delayed_departure
SHOULD PRODUCE THIS OUTPUT (5 separate console.log outputs)
underscoreCase      ✅
firstName           ✅✅
someVariable        ✅✅✅
calculateAge        ✅✅✅✅
delayedDeparture    ✅✅✅✅✅
HINT 1: Remember which character defines a new line in the textarea 😉
HINT 2: The solution only needs to work for a variable made out of 2 words, like a_b
HINT 3: Start without worrying about the ✅. Tackle that only after you have the variable name conversion working 😉
HINT 4: This challenge is difficult on purpose, so start watching the solution in case you're stuck. Then pause and continue!
Afterwards, test with your own test data!
GOOD LUCK 😀
*/

// document.body.append(document.createElement('button'));
const textbox=document.querySelector("#textbox");
const btn=document.querySelector("#btn");

btn.addEventListener("click", function(){
  let textArr=textbox.value.split("\n");
  console.log(textbox.value);
  console.log(textArr);

  for(const [i,ele] of textArr.entries()){
    
    textArr[i]=ele.trim().toLowerCase();
    let n=textArr[i].indexOf("_");
    textArr[i]=textArr[i].slice(0,n)+textArr[i][n+1].toUpperCase()+textArr[i].slice(n+2);
    textArr[i]=textArr[i].replace("_","").padEnd(20)+"✅".repeat(i+1);
  }

let result=textArr.join("\n");
console.log(result);
textbox.value=result;
});

// udemy solution

// document.querySelector('button').addEventListener('click', function () {
//   const text = document.querySelector('textarea').value;
//   const rows = text.split('\n');

//   for (const [i, row] of rows.entries()) {
//     const [first, second] = row.toLowerCase().trim().split('_');

//     const output = `${first}${second.replace(
//       second[0],
//       second[0].toUpperCase()
//     )}`;
//     console.log(`${output.padEnd(20)}${'✅'.repeat(i + 1)}`);
//   }
// });


// coding challenge #5
// Data needed for a later exercise
const flights =
  '_Delayed_Departure;fao93766109;txl2133758440;11:25+_Arrival;bru0943384722;fao93766109;11:45+_Delayed_Arrival;hel7439299980;fao93766109;12:05+_Departure;fao93766109;lis2323639855;12:30';

let flightArr=flights.split("+");
for(const ele of flightArr){
  let [status,from ,to , time]=ele.split(";");
  // while(status.indexOf("_")!==-1)
  // {
  //   status=status.replace("_"," ");
  // }
  status=status.replaceAll("_"," ");
  if(status.includes("Delayed"))
    status="⏳"+status;
  
  from=from.slice(0,3).toUpperCase();
  to=to.slice(0,3).toUpperCase();
  time=time.replace(":","h");

  console.log(`${status} from ${from} to ${to} (${time})`.padStart(45));
}  
// Data needed for first part of the section
const restaurant = {
  name: 'Classico Italiano',
  location: 'Via Angelo Tavanti 23, Firenze, Italy',
  categories: ['Italian', 'Pizzeria', 'Vegetarian', 'Organic'],
  starterMenu: ['Focaccia', 'Bruschetta', 'Garlic Bread', 'Caprese Salad'],
  mainMenu: ['Pizza', 'Pasta', 'Risotto'],

  openingHours: {
    thu: {
      open: 12,
      close: 22,
    },
    fri: {
      open: 11,
      close: 23,
    },
    sat: {
      open: 0, // Open 24 hours
      close: 24,
    },
  },
};
