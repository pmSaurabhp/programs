'use strict';

// console.log(document.querySelector('.message'));
// console.log(document.querySelector('.message').textContent);

//console.log(document.querySelector('.guess').value);
let number = Math.floor(Math.random() * 20 + 1);
let score = Number(document.querySelector('.score').textContent);
let highscore = Number(document.querySelector('.highscore').textContent);

document.querySelector('.check').addEventListener('click', function () {
  // let n=document.querySelector('.number').textContent;
  let guess = Number(document.querySelector('.guess').value);
  console.log(!guess, typeof guess);
  if (score - 1 == 0) 
  {
    document.querySelector('.message').textContent = '😌 Game Over';
    document.querySelector('body').style.backgroundColor = 'red';
    document.querySelector('.score').textContent = 0;
    return;
  }
  if (!guess) {
    document.querySelector('.message').textContent = '🤨 No Number';
  } 
  if (number === guess) {
    document.querySelector('.number').textContent = number;
    document.querySelector('.message').textContent = '🎉 Correct Number';

    document.querySelector('body').style.backgroundColor = 'green';
    if (score > highscore)
        document.querySelector('.highscore').textContent = score;
    return;
  } 
  else if (guess < number) 
      document.querySelector('.message').textContent = '📉Too Less';
  else{
      document.querySelector('.message').textContent = '📈Too High';
  }

    score--;
    document.querySelector('.score').textContent = score;
  
});

document.querySelector('.again').addEventListener('click', function () {
  number = Math.floor(Math.random() * 20 + 1);
  document.querySelector('.number').textContent = '?';
  document.querySelector('.message').textContent = 'Start Guessing...';
  document.querySelector('.score').textContent = 20;
  score = 20;
  document.body.style.backgroundColor = '#222';
});
