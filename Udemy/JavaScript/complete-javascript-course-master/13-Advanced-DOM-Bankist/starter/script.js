'use strict';

///////////////////////////////////////

// Modal window from modal lecture

const modal = document.querySelector('.modal');
const overlay = document.querySelector('.overlay');
const btnCloseModal = document.querySelector('.btn--close-modal');
const btnsOpenModal = document.querySelectorAll('.btn--show-modal');

const btnScrollTo = document.querySelector('.btn--scroll-to');
const section1 = document.querySelector('#section--1');
const nav = document.querySelector('.nav');

const tabs = document.querySelectorAll('.operations__tab');
const tabsContainer = document.querySelector('.operations__tab-container');
const tabsContent = document.querySelectorAll('.operations__content');

const openModal = function (e) {
  e.preventDefault();
  modal.classList.remove('hidden');
  overlay.classList.remove('hidden');
};

const closeModal = function () {
  modal.classList.add('hidden');
  overlay.classList.add('hidden');
};

for (let i = 0; i < btnsOpenModal.length; i++)
  btnsOpenModal[i].addEventListener('click', openModal);

btnCloseModal.addEventListener('click', closeModal);
overlay.addEventListener('click', closeModal);

document.addEventListener('keydown', function (e) {
  if (e.key === 'Escape' && !modal.classList.contains('hidden')) {
    closeModal();
  }
});


///////////////////////////////////////
// scrolling on clicking   Learn more
btnScrollTo.addEventListener('click', function (e) {
  const s1coords = section1.getBoundingClientRect();
  console.log(s1coords);

  console.log(e.target.getBoundingClientRect());

  console.log('Current scroll (X/Y)', window.pageXOffset, window.pageYOffset);

  console.log('height/width viewport',
    document.documentElement.clientHeight,
    document.documentElement.clientWidth
  );

  section1.scrollIntoView({ behavior: 'smooth' });
});

///////////////////////////////////////
// Page navigation scrolling

// document.querySelectorAll('.nav__link').forEach(function (el) {
//   el.addEventListener('click', function (e) {
//     e.preventDefault();
//     const id = this.getAttribute('href');
//     console.log(id);
//     document.querySelector(id).scrollIntoView({ behavior: 'smooth' });
//   });
// });

// adding events takes memory & adding events to each element uses more memory  

// instead use event delegation 
// 1. Add event listener to common parent element
// 2. Determine what element originated the event

document.querySelector('.nav__links').addEventListener('click', function (e) {
  e.preventDefault();

  // Matching strategy
  if (e.target.classList.contains('nav__link')) {
    const id = e.target.getAttribute('href');  // href="#section--1"
    document.querySelector(id).scrollIntoView({ behavior: 'smooth' });
  }
});

//////////////////////////////////
// select tab page
let previousTab=1;
tabsContainer.addEventListener("click", function(e){
  const clicked_tab=e.target.closest(".operations__tab"); // if we click on span
 // tag even then we get parent button otherise clicking on span produce an event 
 // and this span (e.target) does not have " data-tab "
  
  let tabNumber=Number(clicked_tab.getAttribute('data-tab'));
  // or let tabNumber=[...tabs].indexOf(clicked_tab); tabNumber++;
  //console.log(typeof tabNumber);

  if(clicked_tab === null || tabNumber===previousTab) return;  //  if(!clicked_tab) return;

  clicked_tab.classList.add("operations__tab--active");
  
  tabs[previousTab-1].classList.remove("operations__tab--active");
 // console.log(tabs[previousTab-1]);

 // tabsContent & [...tabsContent]  both works
  tabsContent[tabNumber-1].classList.add("operations__content--active");
  [...tabsContent][previousTab-1].classList.remove("operations__content--active");
  
  previousTab=tabNumber;

});

///////////////////////////////////////
// Menu fade animation

// const handleHover = function (e,opacity) {
//   if (e.target.classList.contains('nav__link')) {
//     const link = e.target;
//     const siblings = link.closest('.nav').querySelectorAll('.nav__link');
//     const logo = link.closest('.nav').querySelector('img');

//     siblings.forEach(el => {
//       if (el !== link) el.style.opacity = opacity;
//     });
//     logo.style.opacity = opacity;
//   }
// };

// // Passing "argument" into handler
// nav.addEventListener('mouseover',function(e){
//   handleHover(e,0.5);
// });
// nav.addEventListener('mouseout', function(e){
//   handleHover(e,1);
//  });

 // using   bind()  else see above simple method
const handleHover = function (e) {
  if (e.target.classList.contains('nav__link')) {
   
  // console.log(this);
   //console.log(e);

    const link = e.target;
    const siblings = link.closest('.nav').querySelectorAll('.nav__link');
    const logo = link.closest('.nav').querySelector('img');

    siblings.forEach(el => {
      if (el !== link) el.style.opacity = this;
    });
    logo.style.opacity = this;
  }
};

// Passing "argument" into handlerm       mouseEnter does not do event bubbling 
nav.addEventListener('mouseover', handleHover.bind(0.5));  // makes opacity 0.5 grey except target
nav.addEventListener('mouseout', handleHover.bind(1));     // makes opacity 1 dark 

///////////////////////////////////////
// makes nav bar fixed at top after some scrolling 
// Sticky navigation: Intersection Observer API

const header = document.querySelector('.header');
const navHeight = nav.getBoundingClientRect().height;

const stickyNav = function (entries) {
  const [entry] = entries;
  // console.log(entry);

  if (!entry.isIntersecting) nav.classList.add('sticky');
  else nav.classList.remove('sticky');
};

const headerObserver = new IntersectionObserver(stickyNav, {
  root: null,
  threshold: 0,
  rootMargin: `-${navHeight}px`,
});

headerObserver.observe(header);


///////////////////////////////////////
// Reveal sections
// NOTE : when refresh is done at a section that section does not load 
const allSections = document.querySelectorAll('.section');

const revealSection = function (entries, observer) {
  //console.log(entries);   // entries is array of section
  const [entry] = entries;  // entry = entries[0]
 // console.log(entry);
  if (!entry.isIntersecting) return;  // otherwise hidden removed even though not intersecting 

  entry.target.classList.remove('section--hidden');
  observer.unobserve(entry.target);// to remove observe so that animation 
                                   // happens only once
};

const sectionObserver = new IntersectionObserver(revealSection, {
  root: null,
  threshold: 0.15,
});

allSections.forEach(function (section) {
 sectionObserver.observe(section);// to add observe to each element of allSections
 section.classList.add('section--hidden');
});

///////////////////////////////////////
// Lazy loading images
// NOTE : when refresh is done at a section that section does not load 
const allImages = document.querySelectorAll('.features img');

const revealImage = function (entries, observer) {
 
   const [entry] = entries;  // entry = entries[0]
  // console.log(entries);   // entries is array of section
  // console.log(entry);
  
  if (!entry.isIntersecting) return;  // otherwise hidden removed even though not intersecting 

  entry.target.src=entry.target.getAttribute("data-src");

  entry.target.addEventListener('load', function () {  // load event
    entry.target.classList.remove('lazy-img');
  });
  observer.unobserve(entry.target);// to remove observe so that animation 
                                   // happens only once
};

const imageObserver = new IntersectionObserver(revealImage, {
  root: null,
  threshold: 0,
  rootMargin:'200px' // loads image when image margin is 200px distance from scroll window 
});

allImages.forEach(function (image) {
  imageObserver.observe(image);// to add observe to each element of allSections
});

//////////////////////////////
// slider 

const sliderBtnLeft=document.querySelector('.slider__btn--left');
const sliderBtnRight=document.querySelector('.slider__btn--right');
const slide=document.querySelectorAll(".slide");
const dotContainer = document.querySelector('.dots');

//console.log(slide);
// create dots
const createDots = function () {
  slide.forEach(function (_, i) {
    dotContainer.insertAdjacentHTML(
      'beforeend',
      `<button class="dots__dot" data-slide="${i}"></button>`
    );
  });
};
 createDots();
const activateDot = function (slide) {
  document
    .querySelectorAll('.dots__dot')
    .forEach(dot => dot.classList.remove('dots__dot--active'));

  document
    .querySelector(`.dots__dot[data-slide="${slide}"]`)
    .classList.add('dots__dot--active');
};
const changeSlide=function(){
  slide.forEach(function(ele,i){   
    ele.style.transform=`translateX(${100 * i - 100*index}%) `;
  });
};
let index=0;
changeSlide(); // initialize slides with 0%, 100%, 200%
activateDot(index); // activate 1st dot

console.log(sliderBtnRight);
sliderBtnRight.addEventListener("click", function(){
  if(index===slide.length-1)  index=0;
  else index++;

  changeSlide();
  activateDot(index);
});

sliderBtnLeft.addEventListener("click", function(){
  if(index===0) index=slide.length-1;
  else index--;
  changeSlide();
  activateDot(index);
});

document.addEventListener('keydown', function (e) {
  if (e.key === 'ArrowLeft') changeSlide();
  e.key === 'ArrowRight' && changeSlide();
});

dotContainer.addEventListener('click', function (e) {

  // prevents error if user clicks in between 2 dots
  if (e.target.classList.contains('dots__dot')) {
     index = e.target.dataset.slide;
   // console.log(index);
    changeSlide(index);
    activateDot(index);
  }
});
// const logo = document.querySelector('.nav__logo');
// console.log(logo.src);
// console.log(logo.getAttribute('src'));