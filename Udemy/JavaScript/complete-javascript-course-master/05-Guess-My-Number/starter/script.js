'use strict';

// console.log(document.querySelector('.message'));
// console.log(document.querySelector('.message').textContent);

let n=Math.floor(Math.random()*20+1);
let s= Number(document.querySelector('.score').textContent);

document.querySelector('.check').addEventListener('click',function (){
    // let n=document.querySelector('.number').textContent;
    let g=document.querySelector('.guess').value;
    console.log(!g, typeof g);
    if(s-1==0)
    { document.querySelector('.message').textContent='😌 Game Over';
        document.querySelector('body').style.backgroundColor='red';
        document.querySelector('.score').textContent=0;
        return;
    }
    if(!g)
    {document.querySelector('.message').textContent='No Number';
    }
    else if(n===g)
    {   document.querySelector('.number').textContent=n;
        document.querySelector('.message').textContent='🎉 Correct Number';
        
        let h=Number(document.querySelector('.highscore').textContent);
        
        if(s>h)
             document.querySelector('.highscore').textContent=s;
        document.querySelector('body').style.backgroundColor='green';
    }
    else
    {
      s--;
      document.querySelector('.score').textContent=s;

      if(g<n)
      document.querySelector('.message').textContent='📉Too Less';
      else
      document.querySelector('.message').textContent='📈Too High';
    }
});

document.querySelector('.again').addEventListener('click',function (){
    n=Math.floor(Math.random()*20+1);
    document.querySelector('.number').textContent='?';
    document.querySelector('.message').textContent='Start Guessing...';
    document.querySelector('.score').textContent=20;
    s=20;
    document.body.style.backgroundColor='#222';
});