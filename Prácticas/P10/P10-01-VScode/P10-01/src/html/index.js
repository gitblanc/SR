//We will use https://www.mappity.org for free markers images 
const image = "./img/Microchip_2.png";
const imagebug = "./img/Bug_2.png";

//State of the robot (works or not)
var state3 = false;

//Descriptions
const descrip1 = '<div id="content">' +
    '<div id="siteNotice">' +
    "</div>" +
    '<h1 id="firstHeading" class="firstHeading">Robot 1</h1>' +
    '<div id="bodyContent">' +
    "<p><b>Funciona</b>, 23 ºC <b>Calle Foncalada</b></p>" +
    '<p>Attribution: Robot 1, <a href="https://es.wikipedia.org/wiki/Oviedo">' +
    "https://en.wikipedia.org/w/index.php?title=Oviedo</a></p>" +
    "</div>" +
    "</div>";
const descrip2 = '<div id="content">' +
    '<div id="siteNotice">' +
    "</div>" +
    '<h1 id="firstHeading" class="firstHeading">Robot 2</h1>' +
    '<div id="bodyContent">' +
    "<p><b>Funciona</b>, 21 ºC <b>Calle Salesas</b></p>" +
    '<p>Attribution: Robot 1, <a href="https://es.wikipedia.org/wiki/Oviedo">' +
    "https://en.wikipedia.org/w/index.php?title=Oviedo</a></p>" +
    "</div>" +
    "</div>";
    //El robot real con los datos reales
const descrip3 = hacerPeticion();
const descrip4 = '<div id="content">' +
    '<div id="siteNotice">' +
    "</div>" +
    '<h1 id="firstHeading" class="firstHeading">Robot 4</h1>' +
    '<div id="bodyContent">' +
    "<p><b>Funciona</b>, 22 ºC <b>Calle Parque Astur</b></p>" +
    '<p>Attribution: Robot 1, <a href="https://es.wikipedia.org/wiki/Oviedo">' +
    "https://en.wikipedia.org/w/index.php?title=Oviedo</a></p>" +
    "</div>" +
    "</div>";

function hacerPeticion(){
  
}

// The location of Oviedo
const oviedo = { lat: 43.36029, lng: -5.84476 };
//Robots coordinates
const robot1 = { lat: 43.36029, lng: -5.84476 };
const robot2 = { lat: 43.36129, lng: -5.84576 };
const robot3 = { lat: 43.36329, lng: -5.84376 };
const robot4 = { lat: 43.36429, lng: -5.84776 };
// This example displays a marker at the center of Australia.
// When the user clicks the marker, an info window opens.
function initMap() {
  const map = new google.maps.Map(document.getElementById("map"), {
    zoom: 15,
    center: oviedo,
  });
    
  const infowindow1 = new google.maps.InfoWindow({
    content: descrip1,
    ariaLabel: "Robot 1",
  });
  const infowindow2 = new google.maps.InfoWindow({
    content: descrip2,
    ariaLabel: "Robot 2",
  });
  const infowindow3 = new google.maps.InfoWindow({
    content: descrip3,
    ariaLabel: "Robot 3",
  });
  const infowindow4 = new google.maps.InfoWindow({
    content: descrip4,
    ariaLabel: "Robot 4",
  });
  const marker1 = new google.maps.Marker({
    position: robot1,
    map,
    title: "Oviedo (robot 1)",
    icon: image,
  });

  const marker2 = new google.maps.Marker({
    position: robot2,
    map,
    title: "Oviedo (robot 2)",
    icon: image,
  });

  const marker3 = new google.maps.Marker({
    position: robot3,
    map,
    title: "Oviedo (robot 3)",
  });
  if(state3){
    marker3.setIcon(image);
  }else{
    marker3.setIcon(imagebug);
  }

  const marker4 = new google.maps.Marker({
    position: robot4,
    map,
    title: "Oviedo (robot 4)",
    icon: image,
  });

  marker1.addListener("click", () => {
    infowindow1.open({
      anchor: marker1,
      map,
    });
  });

  marker2.addListener("click", () => {
    infowindow2.open({
      anchor: marker2,
      map,
    });
  });

  marker3.addListener("click", () => {
    infowindow3.open({
      anchor: marker3,
      map,
    });
  });

  marker4.addListener("click", () => {
    infowindow4.open({
      anchor: marker4,
      map,
    });
  });
}

window.initMap = initMap;