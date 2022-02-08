'use strict';

// const age= function(birthyear){						// function Expression is used   &  function Declaration cannot be used
//     return console.log(fname)
//     }

// //console.log(fname);
// let fname="sks";

// console.log(x);

// console.log(lname);
// var lname="s";


const jonas = {
    firstName: 'Jonas',
    year: 1991,
    calcAge: function () {
      // console.log(this);
      console.log(2037 - this.year);
  
      // Solution 1
      // const self = this; // self or that
      // const isMillenial = function () {
      //   console.log(self);
      //   console.log(self.year >= 1981 && self.year <= 1996);
      // };
      // isMillenial();
  
      // Solution 2 using arrow function
      const isMillenial = () => {
        console.log(this);
        console.log(this.year >= 1981 && this.year <= 1996);
      };
      isMillenial();
    },
  
    greet: () => {
      console.log(this);
      console.log(`Hey ${this.firstName}`);
    },
  };
  jonas.greet();
  jonas.calcAge();
  

