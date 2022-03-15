'use strict';


class Workout {
  date = new Date();
  id = (Date.now() + '').slice(-10);
  clicks = 0;

  constructor(coords, distance, duration) {
    // this.date = ...
    // this.id = ...
    this.coords = coords; // [lat, lng]
    this.distance = distance; // in km
    this.duration = duration; // in min
  }

  _setDescription() {
    // prettier-ignore
    const months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'];

    this.description = `${this.type[0].toUpperCase()}${this.type.slice(1)} on ${
      months[this.date.getMonth()]
    } ${this.date.getDate()}`;
  }

  click() {
    this.clicks++;
  }
}

class Running extends Workout {
  type = 'running';

  constructor(coords, distance, duration, cadence) {
    super(coords, distance, duration);
    this.cadence = cadence;
    this.calcPace();
    this._setDescription();
  }

  calcPace() {
    // min/km
    this.pace = this.duration / this.distance;
    return this.pace;    // makes it a class variable
  }
}

class Cycling extends Workout {
  type = 'cycling';

  constructor(coords, distance, duration, elevationGain) {
    super(coords, distance, duration);
    this.elevationGain = elevationGain;
    // this.type = 'cycling';
    this.calcSpeed();
    this._setDescription();
  }

  calcSpeed() {
    // km/h
    this.speed = this.distance / (this.duration / 60);
    return this.speed;     // makes it a class variable
  }
}

// const run1 = new Running([39, -12], 5.2, 24, 178);
// const cycling1 = new Cycling([39, -12], 27, 95, 523);
// ////console.log(run1, cycling1);

// prettier-ignore
const months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'];

const form = document.querySelector('.form');
const containerWorkouts = document.querySelector('.workouts');
const inputType = document.querySelector('.form__input--type');
const inputDistance = document.querySelector('.form__input--distance');
const inputDuration = document.querySelector('.form__input--duration');
const inputCadence = document.querySelector('.form__input--cadence');
const inputElevation = document.querySelector('.form__input--elevation');

// https://leafletjs.com/examples/quick-start/

class App {
  #map; 
  #mapEvent;
  #workouts = [];        // we can initialize variables here also
  #workoutEl;

  constructor(){
    // Get user's position
    this._getPosition();

    // Get data from local storage
    this._getLocalStorage();

    // Attach event handlers 
    form.addEventListener("submit", this._new_or_edit_Workout.bind(this));
    inputType.addEventListener("change", this._toggleElevationField);
    containerWorkouts.addEventListener("click",this._moveToPopup.bind(this));
    
  }

  _getPosition(){
    navigator.geolocation.getCurrentPosition( this._loadMap.bind(this) ,
      function(){
          alert(" please allow location to see current position")
      }
    );
  }
  _loadMap(position){

      const {latitude}=position.coords;
      const {longitude}=position.coords;
  
      // ////console.log(`https://www.google.com/maps/@${latitude},${longitude}`);
      const coordinates=[latitude,longitude];
      this.#map = L.map('map').setView(coordinates, 13);
  
      L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
      attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
      }).addTo(this.#map);
  
      // L.marker(coordinates).addTo(map)
      // .bindPopup('A pretty CSS3 popup.<br> Easily customizable.')
      // .openPopup();

       // map.on is like event listener
       this.#map.on("click", this._showForm.bind(this) );
      
       this.#workouts.forEach((workout) => this._renderMarker(workout) );
       
  }

  _showForm(mapE){
    this.#mapEvent = mapE;
     form.classList.remove("hidden");
      
      // clear form
      inputDistance.value = inputDuration.value = inputCadence.value = inputElevation.value = "";
      
      inputDistance.focus();
      //console.log(this.#workoutEl);
  }

  _closeForm(){
    form.style.display = "none";    // to stop animation
    form.classList.add("hidden");
   //  form.style.display = "grid";  // instantly changes to grid which does not stop animation

    setTimeout(() => (form.style.display = 'grid'), 1000);
  }

  _toggleElevationField(){
    inputCadence.closest(".form__row").classList.toggle("form__row--hidden");
    inputElevation.closest(".form__row").classList.toggle("form__row--hidden");
  }

  _new_or_edit_Workout(e){
    //console.log(this);
    //console.log(e);
    let edit=false;
    if(!this.#mapEvent) { 
      edit = true;  
    }
    //console.log(this.#workoutEl);
      // validate input data
      const validInputs = (...inputs) =>
      inputs.every(inp => Number.isFinite(inp));
    const allPositive = (...inputs) => inputs.every(inp => inp > 0);

    // always start with preventDefault when working with forms
    e.preventDefault();

    // Get data from form
    let type = inputType.value;
    const distance = +inputDistance.value; // convert to string
    const duration = +inputDuration.value;

    
    const { lat, lng } = edit == false ? this.#mapEvent.latlng : 0;
    
    let workout;

      // If workout running, create running object
    if (type === 'running') {
      const cadence = +inputCadence.value;

      // Check if data is valid
      if (
        // !Number.isFinite(distance) ||
        // !Number.isFinite(duration) ||
        // !Number.isFinite(cadence)
        !validInputs(distance, duration, cadence) ||
        !allPositive(distance, duration, cadence)
      )
        return alert('Inputs have to be positive numbers!');

      workout = edit == false ? new Running([lat, lng], distance, duration, cadence) : null;
    }
 
    // If workout cycling, create cycling object
    if (type === 'cycling') {
      const elevation = +inputElevation.value;

      if (
        !validInputs(distance, duration, elevation) ||
        !allPositive(distance, duration)
      )
        return alert('Inputs have to be positive numbers!');

      workout = edit == false ? new Cycling([lat, lng], distance, duration, elevation) : null;
    }

 // if (e.key === 'Enter')  instead used submit containerWorkouts.addEventListener("submit", this._new_or_edit_Workout.bind(this));
 
    //console.log(workout);
    // Add new object to workout array
   if(edit == false )
    this.#workouts.push(workout);
 
      if(edit == false ) {
        // display workout
        this._addWorkout(workout);

        // render or create marker in map
        this._renderMarker(workout);
      }
      else{

        // update object in workout array
        const w = this.#workouts.find(
          work => work.id === this.#workoutEl.dataset.id
          );
          type = w.type;
          //console.log(type);
          inputType.value = type ;
          w.distance = distance;
          w.duration = duration;
      
          let speed ,cad_or_elev ;
          if(w.type == "running" ){
            w.pace = w.duration / w.distance;
            speed = w.pace;

           w.cadence =  +inputCadence.value 
           cad_or_elev = w.cadence;
          }
          else{
           w.speed = w.distance / w.duration ;
           speed = w.speed;

           w.elevation = +inputElevation.value;
           cad_or_elev = w.elevation;
          }

        
        //console.log(type , inputType.value);
        //console.log(' update work container');
        // update work container
         const workDetails = this.#workoutEl.querySelectorAll(".workout__value");
         
         workDetails[0].textContent = distance ;
         workDetails[1].textContent = duration ;
         workDetails[2].textContent = speed;
         workDetails[3].textContent = cad_or_elev;
             
      }
      // close form
      this._closeForm();

      // add data to local storage
      this._setLocalStorage()
    
  }

_renderMarker(workout){           // render = create
    L.marker(workout.coords).addTo(this.#map)
    .bindPopup(
        L.popup({
            maxWidth:250,
            minWidth:100,
            autoClose: false,
            closeOnClick: false,
            className:`${workout.type}-popup`,
        })
    )
    .setPopupContent(`${ workout.description } `)
    .openPopup();
        ////console.log(workout); 
        this.#mapEvent = null;
  }
   _addWorkout(workout){
     //console.log(this);
     // //console.log(e);
    
    const type = workout.type[0].toUpperCase()+workout.type.slice(1);
    const symbol= type === 'Running'? '🏃‍♂️': '🚴‍♀️'; 
    const symbol_2= type === 'Running'? '🦶🏼': '⛰';
    const cad_or_elev= type === 'Running'? workout.cadence: workout.elevationGain;
    const speed= type === 'Running'? workout.pace.toFixed(1): workout.speed.toFixed(1);    
    const unitSpeed= type === 'Running'? "MIN/KM": "KM/H";    
    const unitDistance= type === 'Running'? "SPM": "M";  
    
    const html=`<li class="workout workout--${workout.type}" data-id="${workout.id }">
    <h2 class="workout__title">${workout.description}
    <button class="workout__edit" > Edit </button>
    </h2>
    <div class="workout__details">
      <span class="workout__icon">${symbol}</span>
      <span class="workout__value">${workout.distance}</span>
      <span class="workout__unit">km</span>
    </div>
    <div class="workout__details">
      <span class="workout__icon">⏱</span>
      <span class="workout__value">${workout.duration}</span>
      <span class="workout__unit">min</span>
    </div>
    <div class="workout__details">
      <span class="workout__icon">⚡️</span>
      <span class="workout__value">${speed}</span>
      <span class="workout__unit">${unitSpeed}</span>
    </div>
    <div class="workout__details">
      <span class="workout__icon">${symbol_2}</span>
      <span class="workout__value">${cad_or_elev}</span>
      <span class="workout__unit">${unitDistance}</span>
    </div>
  </li>`;

  form.insertAdjacentHTML("afterend",html);

  // edit     always add event listners to element when they are created
  const editButton=document.querySelector(".workout__edit");
  editButton.addEventListener("click",this._editWorkout.bind(this));
}

// no use of this & 
// attaching event after clicking makes the user click 2 times edit button
// _clickWorkout(e){
//   if(!e.target.closest(".workout")) return ;  // removing this gives error when we add new
//                                             // workout because the form block does not have
//                                             //  workout class so it returns null
//   //console.log('hey ');
//   const editButton = e.target.closest(".workout").querySelector(".workout__edit");
//   editButton.addEventListener("click",this._editWorkout.bind(this));
 
//   this._moveToPopup(e);
// }
_moveToPopup(e) {
  // BUGFIX: When we click on a workout before the map has loaded, we get an error. But there is an easy fix:
  //console.log(this );
  //console.log(e);
  if (!this.#map) return;

  if (!e.target.closest('.workout')) return;

  this.#workoutEl = e.target.closest('.workout');
  //console.log(this.#workoutEl);
  //console.log(this );
 

  // get workout data of element clicked
  const workout = this.#workouts.find(
    work => work.id === this.#workoutEl.dataset.id
  );

  this.#map.setView(workout.coords, 13, {
    animate: true,
    pan: {
      duration: 1,
    },
  });

  // using the public interface
  //  workout.click();     // gives error due to local storage which breaks
                           // the protype chain and click() is no longer present
  //  ////console.log(workout.clicks);
 
}

_editWorkout(e){
  //console.log(this );
  //console.log(e);

  this._showForm(this.#mapEvent);

    this.#workoutEl = e.target.closest('.workout');
  
    //console.log(this.#workoutEl);
    //console.log(this );
  if (!this.#workoutEl) return;

  // get workout data of element clicked
  const w = this.#workouts.find(
    work => work.id === this.#workoutEl.dataset.id
    );
    
    inputType.value = w.type;
    if( w.type == 'running'){
      inputCadence.closest(".form__row").classList.remove("form__row--hidden");
      inputElevation.closest(".form__row").classList.add("form__row--hidden");
    }
    else{
      inputCadence.closest(".form__row").classList.add("form__row--hidden");
    inputElevation.closest(".form__row").classList.remove("form__row--hidden");
    }

  // moved all editing functionality to _new_or_edit_Workout as all code here 
  // runs instantly with input values = blank & it was a big mess

 // }
 //console.log(this );
}

_setLocalStorage() {
  localStorage.setItem('workouts', JSON.stringify(this.#workouts)); 
              // local storage takes {key ,value} pair
              //  JSON.stringify converts object to string 
              // but this  breaks the protype chain
              // so we cannot access functions present in workout class 
}

_getLocalStorage() {
  const data = JSON.parse(localStorage.getItem('workouts'));
              // parse converts string to objects   
  if (!data) return;

  this.#workouts = data;

  this.#workouts.forEach(work => {
    this._addWorkout(work);
    // this._renderMarker();  // gives error as _getLocalStorage() is called in constructor
                              // and at that time map is not loaded so #map is undefined
                              // call it after map load is completed
  });
}

reset() {               // use app.reset() in terminal to reset
  localStorage.removeItem('workouts');
  location.reload();
}

};

const app= new App();





