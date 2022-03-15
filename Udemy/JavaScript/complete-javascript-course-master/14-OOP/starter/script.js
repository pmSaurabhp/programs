'use strict';

///////////////////////////////////////
// Constructor Functions and the new Operator
// const Person = function (firstName, birthYear) {
//     // Instance properties
//     this.firstName = firstName;
//     this.birthYear = birthYear;
  
//     // Never do this! otherwise every object will have its own copy 
//     // hence will use more memory 
//     // instead add functions to prototype object

//     // this.calcAge = function () {
//     //   console.log(2037 - this.birthYear);
//     // };
//   };
  
//   const jonas = new Person('Jonas', 1991);
//   console.log(jonas);
  
//   // 1. New {} is created
//   // 2. function is called, this = {}
//   // 3. {} linked to prototype
//   // 4. function automatically return {}
  
//   const matilda = new Person('Matilda', 2017);
//   const jack = new Person('Jack', 1975);
  
//   console.log(jonas instanceof Person);
  
// //   Person.hey = function () {
// //     console.log('Hey there 👋');
// //     console.log(this);
// //   };
// //   Person.hey();
  
//   ///////////////////////////////////////
//   // Prototypes
//  // console.log(Person.prototype);
  
//   Person.prototype.calcAge = function () {
//     console.log(2037 - this.birthYear);
//   };
  
//   jonas.calcAge();
//   matilda.calcAge();
  
//   jonas.sum= function(){
//   console.log('sum function');
//   };

//   console.log(Person.prototype);
//   console.log(jonas.__proto__);
//   console.log(jonas.__proto__ === Person.prototype);
  
//   console.log(Person.prototype.isPrototypeOf(jonas));  // true
//   console.log(Person.prototype.isPrototypeOf(matilda));  // true
//   console.log(Person.prototype.isPrototypeOf(Person));  // false

//   // .prototyeOfLinkedObjects

// Person.prototype.species = 'Homo Sapiens';
// console.log(jonas.species, matilda.species);

// console.log(jonas.hasOwnProperty('firstName'));
// console.log(jonas.hasOwnProperty('species'));


// ///////////////////////////////////////
// // Prototypal Inheritance on Built-In Objects
// console.log(jonas.__proto__);
// // Object.prototype (top of prototype chain)
// console.log(jonas.__proto__.__proto__);
// console.log(jonas.__proto__.__proto__.__proto__);

// console.dir(Person.prototype.constructor);

// const arr = [3, 6, 6, 5, 6, 9, 9]; // new Array === []
// console.log(arr.__proto__);
// console.log(arr.__proto__ === Array.prototype);

// console.log(arr.__proto__.__proto__);

// Array.prototype.unique = function () {
//   return [...new Set(this)];
// };

// console.log(arr.unique());

// const h1 = document.querySelector('h1');
// console.dir(x => x + 1);

///////////////////////////////////////
// Encapsulation: Protected Properties and Methods
// Encapsulation: Private Class Fields and Methods

// 1) Public fields
// 2) Private fields
// 3) Public methods
// 4) Private methods
// (there is also the static version)

class Account {
  // 1) Public fields (instances)
  locale = navigator.language;

  // 2) Private fields (instances)
  #movements = [];
  #pin;

  constructor(owner, currency, pin) {
    this.owner = owner;
    this.currency = currency;
    this.#pin = pin;

    // Protected property
    // this._movements = [];
    // this.locale = navigator.language;

    console.log(`Thanks for opening an account, ${owner}`);
  }

  // 3) Public methods

  // Public interface
  getMovements() {
    return this.#movements;
  }

  deposit(val) {
    this.#movements.push(val);
    return this;
  }

  withdraw(val) {
    this.deposit(-val);
    return this;
  }

  requestLoan(val) {
    // if (this.#approveLoan(val)) {
    if (this._approveLoan(val)) {
      this.deposit(val);
      console.log(`Loan approved`);
      return this;
    }
  }

  static helper() {
    console.log('Helper');
  }

  // 4) Private methods
  // #approveLoan(val) {
  _approveLoan(val) {
    return true;
  }
}

const acc1 = new Account('Jonas', 'EUR', 1111);

// acc1._movements.push(250);
// acc1._movements.push(-140);
// acc1.approveLoan(1000);

acc1.deposit(250);
acc1.withdraw(140);
acc1.requestLoan(1000);
console.log(acc1.getMovements());
console.log(acc1);
Account.helper();

//console.log(acc1.#movements);
// console.log(acc1.#pin);
// console.log(acc1.#approveLoan(100));