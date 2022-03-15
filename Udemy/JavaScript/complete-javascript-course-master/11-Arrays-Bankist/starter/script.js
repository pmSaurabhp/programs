'use strict';

/////////////////////////////////////////////////
/////////////////////////////////////////////////
// BANKIST APP

// Data

const account1 = {
  owner: 'Jonas Schmedtmann',
  movements: [200, 455.23, -306.5, 25000, -642.21, -133.9, 79.97, 1300],
  interestRate: 1.2, // %
  pin: 1111,

  movementsDates: [
    '2019-11-18T21:31:17.178Z',
    '2019-12-23T07:42:02.383Z',
    '2020-01-28T09:15:04.904Z',
    '2020-04-01T10:17:24.185Z',
    '2020-05-08T14:11:59.604Z',
    '2020-07-26T17:01:17.194Z',
    '2020-07-28T23:36:17.929Z',
    '2020-08-01T10:51:36.790Z',
  ],
  currency: 'EUR',
  locale: 'pt-PT', // de-DE
};

const account2 = {
  owner: 'Jessica Davis',
  movements: [5000, 3400, -150, -790, -3210, -1000, 8500, -30],
  interestRate: 1.5,
  pin: 2222,

  movementsDates: [
    '2019-11-01T13:15:33.035Z',
    '2019-11-30T09:48:16.867Z',
    '2019-12-25T06:04:23.907Z',
    '2020-01-25T14:18:46.235Z',
    '2020-02-05T16:33:06.386Z',
    '2020-04-10T14:43:26.374Z',
    '2020-06-25T18:49:59.371Z',
    '2020-07-26T12:01:20.894Z',
  ],
  currency: 'USD',
  locale: 'en-US',
};

const account3 = {
  owner: 'Steven Thomas Williams',
  movements: [200, -200, 340, -300, -20, 50, 400, -460],
  interestRate: 0.7,
  pin: 3333,
};

const account4 = {
  owner: 'Sarah Smith',
  movements: [430, 1000, 700, 50, 90],
  interestRate: 1,
  pin: 4444,
};

const accounts = [account1, account2, account3, account4];

// Elements
const labelWelcome = document.querySelector('.welcome');
const labelDate = document.querySelector('.date');
const labelBalance = document.querySelector('.balance__value');
const labelSumIn = document.querySelector('.summary__value--in');
const labelSumOut = document.querySelector('.summary__value--out');
const labelSumInterest = document.querySelector('.summary__value--interest');
const labelTimer = document.querySelector('.timer');

const containerApp = document.querySelector('.app');
const containerMovements = document.querySelector('.movements');

const btnLogin = document.querySelector('.login__btn');
const btnTransfer = document.querySelector('.form__btn--transfer');
const btnLoan = document.querySelector('.form__btn--loan');
const btnClose = document.querySelector('.form__btn--close');
const btnSort = document.querySelector('.btn--sort');

const inputLoginUsername = document.querySelector('.login__input--user');
const inputLoginPin = document.querySelector('.login__input--pin');
const inputTransferTo = document.querySelector('.form__input--to');
const inputTransferAmount = document.querySelector('.form__input--amount');
const inputLoanAmount = document.querySelector('.form__input--loan-amount');
const inputCloseUsername = document.querySelector('.form__input--user');
const inputClosePin = document.querySelector('.form__input--pin');



const createUsernames=function(){
  for(const ele of accounts){
    ele.username = ele.owner.toLowerCase().split(" ")
    .map((e) => e[0]).join("");
  }  
 // console.log(accounts);
 
 // my code without using map()
 //   for(const [i,ele] of accounts.entries())
 //   { let ownerArr = ele.owner.toLowerCase().split(" ");
  //    let ownerShort="";
  //    for(const oa of ownerArr){
  //     ownerShort += oa[0];
  //    }
  //    console.log(`owner ${ownerShort}`);
  //  }
}
createUsernames();


const displayMovements=function(sort=false){
  containerMovements.innerHTML='';
  
  let sortMov=sort===true ? [...currentAccount.movements].sort((a,b)=> a-b) : currentAccount.movements;
  console.log(sortMov);
  sortMov.forEach(function(ele,i) {
    // currentAccount.movementsDates[i] is passed in Date() to get date object 
    // & then use getDate() , getMonth(), getFullYear()
  const movementDate=new Date(currentAccount.movementsDates[i]); 
  // can use it instead d,m,y const displayDate = formatMovementDate(movementDate, acc.locale);
  const d=`${movementDate.getDate()}`.padStart(2,0);
  const m=`${movementDate.getMonth() + 1 }`.padStart(2,0); // jan means 0 month
  const y=movementDate.getFullYear();

    let transaction= ele > 0 ? "deposit" : "withdrawal";
    let sign=ele > 0? "+" : "";
    let html=`<div class="movements__row">
    <div class="movements__type movements__type--${transaction}">${i} ${transaction}</div>
    <div class="movements__date">${d}/${m}/${y}</div>
    <div class="movements__value">${sign} ${ele}</div>
  </div>`;
  containerMovements.insertAdjacentHTML('afterbegin',html);
  });
};
const displaySummary=function(){
  const totalDeposit=currentAccount.movements.filter((e)=> e>0)
  .reduce((acc,mov)=> acc+mov,0);
  labelSumIn.textContent=`${totalDeposit}💲`;

  const totalWithdrawl=currentAccount.movements.filter((e)=> e<0)
  .reduce((acc,mov)=> acc+mov,0);
  labelSumOut.textContent=`${totalWithdrawl}💲`;

  const interest = currentAccount.movements
    .filter(mov => mov > 0)
    .map(deposit => (deposit * account1.interestRate) / 100)
    .filter((int, i, arr) => {
      // console.log(arr);
      return int >= 1;
    })
    .reduce((acc, int) => acc + int, 0);
  labelSumInterest.textContent = `${interest}💲`;

  labelBalance.textContent=totalDeposit+totalWithdrawl;
  const currentDate=new Date();
  const d=`${currentDate.getDate()}`.padStart(2,0);
  const m=`${currentDate.getMonth() + 1 }`.padStart(2,0); // jan means 0 month
  const y=currentDate.getFullYear();

  const hrs=`${currentDate.getHours()}`.padStart(2,0);
  const mints=`${currentDate.getMinutes()}`.padStart(2,0);
  labelDate.textContent=`${d}/${m}/${y}   ${hrs}:${mints}`;
};

const updateUI=function(){
  displayMovements();
  displaySummary();
}
// let userIndex;   // i used this to locate current account
let currentAccount, receiverAccount;
let timerName;

// login from start
// currentAccount=account1
// updateUI();
// containerApp.style.opacity=100;
console.log(" htrhrh "+Number(containerApp.style.opacity));
const logout=function(){
  labelWelcome.textContent = 'Log in to get started';
  containerApp.style.opacity = 0;

  // so that previous loged in user details are removed
  // otherwise user details will be visible from chromes developer tools
  currentAccount={
    owner: '',
    movements: [],
    interestRate: 0, // %
    pin: 0,
    movementsDates: [],
    currency: 'EUR',
    locale: 'pt-PT', // de-DE
  };
  updateUI();
};
const timerFunc = function(){
  let mins=0,sec=60;
  timerName = setInterval(function(){
    if(sec===0){
      mins=mins-1;
      sec=59;
    }
    else{
      sec=sec-1;
    }
    //console.log(`${mins}`.padStart(2,0)+`:`+`${sec}`.padStart(2,0));
    labelTimer.textContent=`${mins}`.padStart(2,0)+`:`+`${sec}`.padStart(2,0);

    if(mins===0 && sec===0) {
      clearInterval(timerName);
      logout();
    }
  },1000);
   
};


btnLogin.addEventListener('click', function(e){
  // when button is used inside form then clicking it reloads the page
  // so to Prevent forms default action of submitting & reloading use
  e.preventDefault();

  // my code
  // const username=inputLoginUsername.value;
  // const password=Number(inputLoginPin.value);
  
  // console.log(`huhaha ${username} & ${password}`);
  // for(const [i,ele] of accounts.entries())
  // {

  //   if(username===ele.username && password ===ele.pin)
  //     { containerApp.style.opacity=100;
  //       userIndex=i;
  //       displayMovements();
  //       displaySummary();
        
  //       labelWelcome.textContent=`Welcome back, ${ele.owner.split(" ")[0]}`;
  //       console.log('logged in');
  //       break;
  //     }
  // }
  
 currentAccount = accounts.find((acc)=> acc.username === inputLoginUsername.value);

    if( currentAccount!='undefined' && currentAccount.pin === Number(inputLoginPin.value))
      { 
        inputLoginUsername.value='';
        inputLoginPin.value="";
        inputLoginPin.blur();

        containerApp.style.opacity=100;
        updateUI();
        
        labelWelcome.textContent=`Welcome back, ${currentAccount.owner.split(" ")[0]}`;
        console.log('logged in');
      }
    
    // if timer started by previous user then clear it
   if(timerName){
     clearInterval(timerName);
     timerFunc();
   }
   else timerFunc();
    
});

btnTransfer.addEventListener("click",function(e){
  e.preventDefault();

  let transferAmount=Number(inputTransferAmount.value);
  receiverAccount = accounts.find((acc)=> acc.username === inputTransferTo.value);

  if( transferAmount>0 && receiverAccount!=='undefined' &&
  receiverAccount!==currentAccount && labelBalance.textContent >= transferAmount)
      {  
        currentAccount.movements.push(-transferAmount)
        receiverAccount.movements.push(transferAmount);

        inputTransferTo.value='';
        inputTransferAmount.value="";
        inputTransferAmount.blur();

         // Add transfer date
        currentAccount.movementsDates.push(new Date().toISOString());
        receiverAccount.movementsDates.push(new Date().toISOString());

        updateUI();
        
        console.log('transfer money');
      }
});

btnClose.addEventListener('click', function (e) {
  e.preventDefault();

  if (
    inputCloseUsername.value === currentAccount.username &&
    Number(inputClosePin.value) === currentAccount.pin
  ) {
    // const index = accounts.findIndex(
    //   acc => acc.username === currentAccount.username
    // );
    // console.log(index);
    // .indexOf(23)
    const i=accounts.indexOf(currentAccount.username);
    // Delete account
    accounts.splice(i, 1);

    // Hide UI
    containerApp.style.opacity = 0;
  }

  inputCloseUsername.value = inputClosePin.value = '';
});
let sorted=false;
btnSort.addEventListener('click', function () {
  sorted=!sorted;
  displayMovements(sorted);
});

// wrong btnSort.addEventListener('click',displayMovements(sorted)); 
// wrong as displayMovements without bracket should be passed


btnLoan.addEventListener('click', function (e) {
  e.preventDefault();

  const amount = Math.floor(inputLoanAmount.value);

  if (amount > 0 && currentAccount.movements.some(mov => mov >= amount * 0.1)) {
    setTimeout(function () {
      // Add movement
      currentAccount.movements.push(amount);

      // Add loan date
      currentAccount.movementsDates.push(new Date().toISOString());

      // Update UI
      updateUI(currentAccount);

      // Reset timer
      clearInterval(timerName);
      timerFunc();
    }, 2500);
  }
  inputLoanAmount.value = '';
});

/////////////////////////////////////////////////
/////////////////////////////////////////////////
// LECTURES

// const currencies = new Map([
//   ['USD', 'United States dollar'],
//   ['EUR', 'Euro'],
//   ['GBP', 'Pound sterling'],
// ]);

//  const movements = [200, 450, -400, 3000, -650, -130, 70, 1300];

//  console.log(movements.sort((a,b)=> a-b) );
// const balance = movements.reduce((acc, cur) => acc + cur, 0);
// console.log(balance);



labelBalance.addEventListener('click', function () {

  const movementsUI3 = document.querySelectorAll('.movements__value');
  console.log(movementsUI3);
  // gives error  // console.log(movementsUI3.map((ele)=> 1));

  // document.querySelectorAll() gives Node list not array 
  // so it should be converted to array to use inbuilt functions
  // using Array.from() 
  const movementsUI = Array.from(
    document.querySelectorAll('.movements__value')
  ).map(el => Number(el.textContent.replace('+ ', '')));
  console.log(movementsUI);

  // using destructuring ...
  const movementsUI2 = [...document.querySelectorAll('.movements__value')].map(el => Number(el.textContent.replace('+ ', '')));
  console.log(movementsUI2);
  
});
/////////////////////////////////////////////////
