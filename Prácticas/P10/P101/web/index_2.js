//We will use https://www.mappity.org for free markers images 
const image = "./img/Microchip_2.png";
const imagebug = "./img/Bug_2.png";
const ip_direccion = "192.168.61.203";

function inicializar() {
    const mapa = new google.maps.Map(document.getElementById("map"), {zoom: 6, center: {lat: 43.35548, lng: -5.85098}});
}