import icons from '../img/icons.svg';
//console.log(icons);  // path for icons in dist folder

// import 'fracty';

const recipeContainer = document.querySelector('.recipe');
const resultsContainer = document.querySelector('.results');
const inputSearch = document.querySelector(".search__field");
const btnSearch  = document.querySelector(".search__btn");

const timeout = function (s) {
  return new Promise(function (_, reject) {
    setTimeout(function () {
      reject(new Error(`Request took too long! Timeout after ${s} second`));
    }, s * 1000);
  });
};

// https://forkify-api.herokuapp.com/v2

///////////////////////////////////////

const API_URL = "https://forkify-api.herokuapp.com/api/v2/recipes/";
const apiKey = "60f6e168-e9bd-4408-9380-91d327badfe3";
    // api_Key		key used when we make a post call
		//            in get call key is used to show self made data using post call
// const apiKey = "f0d3cd8b-b9d7-4c53-bf8e-282b7006999b";

const renderSpinner= function(parentEle){
  const html =`<div class="spinner">
  <svg>
    <use href="${icons}#icon-loader"></use>
  </svg>
</div>
  `;
  parentEle.innerHTML = "";
  parentEle.insertAdjacentHTML("afterbegin", html);
};

const renderMessage = function(parentEle, message) {
  const markup = `
    <div class="message">
      <div>
        <svg>
          <use href="${icons}#icon-smile"></use>
        </svg>
      </div>
      <p>${message}</p>
    </div>
  `;
  parentEle.innerHTML = "";
  parentEle.insertAdjacentHTML('afterbegin', markup);
}
let recipe;
let btnBookmark ;
let bookmarkList = document.querySelector(".bookmarks__list");;


const getData = async function(id){
  
  try{
    // spinner
    renderSpinner(recipeContainer);

  // const response = await fetch(`https://forkify-api.herokuapp.com/api/v2/recipes/${id}?key=${apiKey}`);
  // console.log(response);
  // if(!response.ok)  throw new Error("📕 not found");

  // let responseData = await response.json();
  const responseData = await get_or_post(`${API_URL}${id}?key=${apiKey}`);

    // API_key		key used when we make a post call
		//            in get call key is used to show self made data using post call

  recipe = responseData.data.recipe;
  
  recipe = {
    id: recipe.id,
    title: recipe.title,
    publisher: recipe.publisher,
    sourceUrl: recipe.source_url,
    image: recipe.image_url,
    servings: recipe.servings,
    cookingTime: recipe.cooking_time,
    ingredients: recipe.ingredients,
    ...(recipe.key && { key: recipe.key }),  // if(recipe.key) spread { key: recipe.key }
  };                                          // = key: recipe.key

  const html=` <figure class="recipe__fig">
      <img src="${recipe.image}" alt="${recipe.title}" class="recipe__img" />
      <h1 class="recipe__title">
        <span>${recipe.title}</span>
      </h1>
    </figure>

    <div class="recipe__details">
      <div class="recipe__info">
        <svg class="recipe__info-icon">
          <use href="${icons}#icon-clock"></use>
        </svg>
        <span class="recipe__info-data recipe__info-data--minutes">${recipe.cookingTime}</span>
        <span class="recipe__info-text">minutes</span>
      </div>
      <div class="recipe__info">
        <svg class="recipe__info-icon">
          <use href="${icons}#icon-users"></use>
        </svg>
        <span class="recipe__info-data recipe__info-data--people">${recipe.servings}</span>
        <span class="recipe__info-text">servings</span>

        <div class="recipe__info-buttons">
          <button class="btn--tiny btn--increase-servings" data-update-to="${recipe.servings-1}">
            <svg>
              <use href="${icons}#icon-minus-circle"></use>
            </svg>
          </button>
          <button class="btn--tiny btn--increase-servings" data-update-to="${recipe.servings+1}">
            <svg>
              <use href="${icons}#icon-plus-circle"></use>
            </svg>
          </button>
        </div>
      </div>

      <div class="recipe__user-generated">
        <svg>
          <use href="${icons}#icon-user"></use>
        </svg>
      </div>
      <button class="btn--round">
        <svg class="">
          <use href="${icons}#icon-bookmark-fill"></use>
        </svg>
      </button>
    </div>

    <div class="recipe__ingredients">
      <h2 class="heading--2">Recipe ingredients</h2>
      <ul class="recipe__ingredient-list">
  
      ${recipe.ingredients.map(ele => {
        return `<li class="recipe__ingredient">
        <svg class="recipe__icon">
          <use href="${icons}#icon-check"></use>
        </svg>
        <div class="recipe__quantity"> ${ele.quantity}</div>
        <div class="recipe__description">
          <span class="recipe__unit"> ${ele.unit}</span>
          ${ele.description}
        </div>
      </li>`
      }).join("")}
  
      </ul>
    </div>

    <div class="recipe__directions">
      <h2 class="heading--2">How to cook it</h2>
      <p class="recipe__directions-text">
        This recipe was carefully designed and tested by
        <span class="recipe__publisher">${recipe.publisher}</span>. Please check out
        directions at their website.
      </p>
      <a
            class="btn--small recipe__btn"
            href="${recipe.sourceUrl}"
            target="_blank"
          >
            <span>Directions</span>
            <svg class="search__icon">
              <use href="${icons}#icon-arrow-right"></use>
            </svg>
          </a>
        </div>
  `;
 
  recipeContainer.innerHTML = "";

  recipeContainer.insertAdjacentHTML('afterbegin', html);
  getLocalStorage();
  btnBookmark = document.querySelector(".btn--round");
 

  btnBookmark.addEventListener("click", function(){
    if(!bookmarkRecipes.find(ele => ele === recipe))
        bookmarkRecipes.push(recipe);
    setLocalStorage();
    renderBookmark();
  });
  }
  catch(err){
    console.error(err);
  }
  const changeServings = document.querySelector(".recipe__info-buttons");
const servings = document.querySelector(".recipe__info-data--people");
const list = document.querySelector(".recipe__ingredient-list");


changeServings.addEventListener("click", function(e){
try {
  const change = e.target.closest(".btn--increase-servings");
  let newServing = Number.parseInt(servings.textContent);

  if(Number.parseInt(change.dataset.updateTo) > newServing) {
    newServing++;
    change.dataset.updateTo++;
  }
  if(Number.parseInt(change.dataset.updateTo) < newServing) {
    newServing--;
    change.dataset.updateTo--;
  }
  servings.textContent = newServing;
  const html = `
  ${recipe.ingredients.map(ele => {
    //console.log(ele.description ,(newServing)*ele.quantity/recipe.servings);
    const newQuantity = (newServing)*ele.quantity/recipe.servings;
    let serv1 = Math.floor((newServing)*ele.quantity/recipe.servings);
    let serv2 = (newServing)*ele.quantity % recipe.servings;
    if(serv1 === 0) serv1 ="";
    if(serv2 === 0) serv2 = "";
    else  serv2 = `${serv2}/${recipe.servings}`;
    // console.log('starter');
    // console.log(serv1, serv2 , recipe.servings);

    return `<li class="recipe__ingredient">
    <svg class="recipe__icon">
      <use href="${icons}#icon-check"></use>
    </svg>
    <div class="recipe__quantity">${serv1} ${serv2}</div>
    <div class="recipe__description">
      <span class="recipe__unit"> ${ele.unit}</span>
      ${ele.description}
    </div>
  </li>`
  }).join("")}
  `;
 // console.log(html);
 // console.log(list);
    list.innerHTML = "";
    list.insertAdjacentHTML("afterbegin", html);
}
catch(err){
  console.log(err);
}
});

};

let page=1 , totalPages;
let start = (page - 1)*10;
let end = page*10;
let recipes=[];
let pageContainer = document.querySelector(".pagination");
console.log(pageContainer);

pageContainer.addEventListener("click", function(e){
  // if(page === 1)
  // e.target.closest(".pagination").querySelector(".pagination__btn--prev").classList.add(".hidden")
  const span = e.target.closest(".pagination").querySelectorAll("span");
  const btn = e.target.closest(".pagination").querySelectorAll(".btn--inline");
  
  //span[1].style.opacity = "1";

  if(e.target.closest(".btn--inline").classList.contains("pagination__btn--next"))
    {
      if(page+1 > totalPages) return ;
      page++;
    }
  if(e.target.closest(".btn--inline").classList.contains("pagination__btn--prev")){
    
    if(page-1 <= 0) return ;
    page--;
  }
  btn[0].style.opacity = 1;
  btn[1].style.opacity = 1;
  
  span[0].textContent =`Page ${page-1}`;
  if(page-1 <= 0) span[0].closest(".btn--inline").style.opacity = 0;
  
  span[1].textContent = `Page ${page+1}`;
  if(page+1 > totalPages) span[1].closest(".btn--inline").style.opacity = 0;

  start = (page - 1)*10;
  end = page*10;
  console.log(page , start , end);
  renderResults();
 
});

const renderResults = function(){
  let r = recipes.slice(start , end);
    console.log(recipes);
    console.log(r);
    const html = `${r.map(ele => {
      return `<li class="preview" data-id="${ele.id}">
      <a class="preview__link " href="#${ele.id}">
        <figure class="preview__fig">
          <img src="${ele.image_url}" alt="${ele.title}" />
        </figure>
        <div class="preview__data">
          <h4 class="preview__title"> ${ele.title}</h4>
          <p class="preview__publisher"> ${ele.publisher}</p>
          <div class="preview__user-generated">
            <svg>
              <use href="src/img/icons.svg#icon-user"></use>
            </svg>
          </div>
        </div>
      </a>
    </li>`
    }).join("")
  }
  `;
  //console.log(html);
    resultsContainer.innerHTML = ``;
    resultsContainer.insertAdjacentHTML('afterbegin' , html);
  
}
const searchResults = async function(item){
    try{
      // spinner
     renderSpinner(resultsContainer);
  
    // const response = await fetch(`https://forkify-api.herokuapp.com/api/v2/recipes?search=${item}`);
    
    // if(!response.ok)  throw new Error("📕 not found");
  
    // let responseData = await response.json();
    const responseData = await get_or_post(`${API_URL}?search=${item}&key=${apiKey}`);
    //console.log(responseData);
    recipes = responseData.data.recipes;
      console.log(recipes , recipes.length);
    totalPages = Math.ceil(recipes.length/10);
    
    //console.log(totalPages);
    if(!recipes.length){
      console.log('recipes 0');
      renderMessage(resultsContainer, "Oops! No Recipes Found 😅");
    }
    else  
      renderResults();
    
    
    }
    catch(err){
      console.log(err);
    }  

};
btnSearch.addEventListener("click", function(e){
  e.preventDefault();

  searchResults(inputSearch.value);
  
});

let activeElement;
resultsContainer.addEventListener("click", function(e){
// optimization  by storing the last active element in activeElement
if(activeElement){
  activeElement.classList.remove("preview__link--active");
   }

 const recipe = e.target.closest(".preview__link");
  //console.log(recipe.dataset.id);
  recipe.classList.add("preview__link--active");

  activeElement = recipe;
});

// event is called when there is hashchange in url or page loads
["hashchange","load"].forEach(ev => { window.addEventListener(ev, function(){

  const id= window.location.hash.slice(1);

  if(!id) return;
  console.log(id);
  getData(id);
  
  })
});


let bookmarkRecipes = [];

const renderBookmark = function(){
  const html = `${
    bookmarkRecipes.map(ele => {
     
      return `<li class="preview">
      <a class="preview__link" href="#${ele.id}">
        <figure class="preview__fig">
          <img src="${ele.image}" alt="Test" />
        </figure>
        <div class="preview__data">
          <h4 class="preview__name">
          ${ele.title}
          </h4>
          <p class="preview__publisher"> ${ele.publisher}</p>
        </div>
      </a>
    </li>
      `
    }).join("")
  }
  `;
  bookmarkList.innerHTML = "";
  bookmarkList.insertAdjacentHTML("afterbegin", html);
}

const setLocalStorage = function() {
  localStorage.setItem('bookmarkRecipes', JSON.stringify(bookmarkRecipes)); 
              // local storage takes {key ,value} pair
              //  JSON.stringify converts object to string 
              // but this  breaks the protype chain
              // so we cannot access functions present in workout class 
}

const getLocalStorage= function() {
  const data = JSON.parse(localStorage.getItem('bookmarkRecipes'));
              // parse converts string to objects   
  if (!data) return;

  bookmarkRecipes = data;
  renderBookmark();
 
}

// or type  localStorage.clear() in console & refresh
const reset= function() {               // use app.reset() in terminal to reset
  localStorage.removeItem('bookmarkRecipe');
  location.reload();
}
 
const overlay = document.querySelector(".overlay");
const recipeWindow = document.querySelector(".add-recipe-window");
const btnAddRecipe = document.querySelector(".nav__btn--add-recipe");
const btnCloseRecipe = document.querySelector(".btn--close-modal");
const form = document.querySelector(".upload");
// not needed as submit eventListener is used 
// const btnSubmit = document.querySelector(".upload__btn"); 

console.log('huuhahhsah 123456');

[btnAddRecipe, btnCloseRecipe, overlay].forEach(ele => ele.addEventListener("click", function(){
  overlay.classList.toggle("hidden");
  recipeWindow.classList.toggle("hidden");
}));

// get data from form
let formHtml = form.innerHTML; // store form html as it is over written by spinner 
                               // & successfull message 
// get data from form
form.addEventListener('submit', function (e) {
  e.preventDefault();
  
  // get data from form without manually selecting all elements 
  const dataArr = [...new FormData(this)];
  const data = Object.fromEntries(dataArr); // convert array to JSON
  console.log(data);

  // spinner
  renderSpinner(form);
 
  // upload data
  uploadRecipe(data);

});

const uploadRecipe = async function (newRecipe) {
  try {
  // cobmine all ingredients & make ingredients array of [quantity,unit,descript]
    const ingredients = Object.entries(newRecipe)   // convert JSON to array
      .filter(entry => entry[0].startsWith('ingredient') && entry[1] !== '')
      .map(ing => {
        const ingArr = ing[1].split(',').map(el => el.trim());
        // const ingArr = ing[1].replaceAll(' ', '').split(',');
        if (ingArr.length !== 3)
          throw new Error(
            'Wrong ingredient fromat! Please use the correct format :)'
          );

        const [quantity, unit, description] = ingArr;

        return { quantity: quantity ? +quantity : null, unit, description };
      });

    // get desired recipe format 
    const recipe = {
      title: newRecipe.title,
      source_url: newRecipe.sourceUrl,
      image_url: newRecipe.image,
      publisher: newRecipe.publisher,
      cooking_time: +newRecipe.cookingTime,
      servings: +newRecipe.servings,
      ingredients,
    };

    // make a POSt call
    const data = await get_or_post(`${API_URL}?key=${apiKey}`, recipe);

    // API_key		key used when we make a post call
		//            in get call key is used to show self made data using post call

    //state.recipe = createRecipeObject(data);
   // addBookmark(state.recipe);

   // show message
  renderMessage(form,"Recipe Successfully uploaded !!");
  
  setTimeout(function(){    // so that renderMessage is shown & instanly not over write by form.innerHTML
    overlay.classList.add("hidden");
    recipeWindow.classList.add("hidden");

    form.innerHTML = formHtml; // restore form body to original
  }, 2000)

  } catch (err) {
    throw err;
  }
};

// make a POSt & get call
const get_or_post = async function (url, uploadData = undefined) {
  try {
    const fetchPro = uploadData
      ? fetch(url, {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
          },
          body: JSON.stringify(uploadData),
        })
      : fetch(url);
      
      console.log(url);
    const res = await Promise.race([fetchPro, timeout(10)]);
    const data = await res.json();
    
    if (!res.ok) throw new Error(`${data.message} (${res.status})`);
    return data;
  } catch (err) {
    throw err;
  }
};
