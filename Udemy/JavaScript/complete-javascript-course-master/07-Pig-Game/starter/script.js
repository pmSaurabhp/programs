'use strict';

const score_0=document.querySelector("#score--0");
const currentScore_0=document.querySelector("#current--0");
const score_1=document.querySelector("#score--1");
const currentScore_1=document.querySelector("#current--1");


const player_0=document.querySelector(".player--0");
const player_1=document.querySelector(".player--1");

const roll=document.querySelector(".btn--roll");
const newGame=document.querySelector(".btn--new");
const hold=document.querySelector(".btn--hold");
const diceImg=document.querySelector(".dice");

// simple but does not follow DRY

// let number;
// let tempScore=0;
// console.log(currentScore_0);
// const changePlayer=function(){
//     if(player_0.classList.contains("player--active"))
//     { score_0.textContent = Number(score_0.textContent) + Number(currentScore_0.textContent);
//         currentScore_0.textContent=0;
//       player_0.classList.remove("player--active");
//       player_1.classList.add("player--active");
//     }
//     else{
//     score_1.textContent = Number(score_1.textContent) + Number(currentScore_1.textContent);
//     currentScore_1.textContent=0;
//     player_1.classList.remove("player--active");
//     player_0.classList.add("player--active");
//     }
//     tempScore=0;
// }
// roll.addEventListener("click", function(){
//     number=Math.floor(Math.random() * 6 + 1);
//     diceImg.src="dice-"+number+".png";
//     if(number===1)
//       { currentScore_0.textContent=0;
//         currentScore_1.textContent=0;
//         changePlayer();
//         return;
//       }
//     if(player_0.classList.contains("player--active")){
//         tempScore += number;
//         currentScore_0.textContent=tempScore;
//         console.log(currentScore_0);
//     }
//     else{
//         tempScore += number;
//         currentScore_1.textContent=tempScore;
//     }
// });

// hold.addEventListener("click", changePlayer );

// newGame.addEventListener("click", function(){
//  score_0.textContent=0;
//  score_1.textContent=0;
//  currentScore_0.textContent=0;
//  currentScore_1.textContent=0;
//  tempScore=0;
//  player_1.classList.remove("player--active");
//  player_0.classList.add("player--active");
// });

// some what complex but follows DRY
let number, score=0, currentScore=0, currentPlayer=0;
// console.log(currentScore_0);

// change player function
const changePlayer=function(){
    if(currentPlayer===-1)
        return;
    document.querySelector("#score--"+currentPlayer).textContent = score + currentScore;

    if(score + currentScore >= 20)
        { diceImg.classList.add('hidden');
        document.querySelector(`#name--${currentPlayer}`).textContent="🎉✨ Winner Player "+(currentPlayer+1)+" 🎁";
        document.querySelector(`.player--${currentPlayer}`).style.flex="80%";
        document.querySelector(`.player--${currentPlayer}`)
         .classList.add('player--winner');
  
         document.querySelector(`.player--${currentPlayer}`)
         .classList.remove('player--active');
         currentPlayer=-1;
            return;
        }
    document.querySelector("#current--"+currentPlayer).textContent=0;
    player_0.classList.toggle("player--active");
    player_1.classList.toggle("player--active");
    
    currentPlayer= currentPlayer === 0 ? 1 : 0;
    currentScore=0;
    score=Number(document.querySelector("#score--"+currentPlayer).textContent);
}

// roll dice
roll.addEventListener("click", function(){
    if(currentPlayer===-1)
        return;
    number=Math.floor(Math.random() * 6 + 1);
    diceImg.src="dice-"+number+".png";
    if(number===1)
      { 
        currentScore=0;
        changePlayer();
        return;
      }
        currentScore += number;
        document.querySelector("#current--"+currentPlayer).textContent=currentScore;
        console.log(currentScore_0);
});

// hold
hold.addEventListener("click", changePlayer );

// reset game
newGame.addEventListener("click", function(){
 score_0.textContent=0;
 score_1.textContent=0;
 currentScore_0.textContent=0;
 currentScore_1.textContent=0;

 currentPlayer=0;
 currentScore=0;
 score=0;
 
 // UI changes
 player_0.classList.add("player--active");
 diceImg.classList.remove('hidden');

 document.querySelector(`.player--0`).classList.remove("player--winner");
 document.querySelector(`.player--1`).classList.remove("player--winner");
 document.querySelector(`.player--0`).style="";
 document.querySelector(`.player--1`).style="";

document.querySelector(`#name--0`).textContent="Player 1";
document.querySelector(`#name--1`).textContent="Player 2";
});