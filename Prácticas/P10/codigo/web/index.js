window.addEventListener('load', initMap, false);

const coordenadas = {lat: 43.3548049, lng: -5.8512892}

function initMap() { 
    const mapa = new google.maps.Map(document.getElementById("map"), {zoom: 15, center: coordenadas});

    $.getJSON('http://192.168.61.203/index?datos', function(data) {

        marker1 = new google.maps.Marker({
            position: coordenadas,
        content: mostrarDatos(data.temperature, data.humidity),
        map: mapa,
        title: "Robot 1",
        });

        new google.maps.Marker({ 
            position: {lat: 43.3634588, lng: -5.848301},
            map: mapa,
            title: "Robot 2",
        });

        new google.maps.Marker({ 
            position: {lat: 43.362815, lng: -5.854595},
            map: mapa,
            title: "Robot 3",
         });

        new google.maps.Marker({ 
            position: {lat: 43.36106983361769, lng: -5.856798692611246},
            map: mapa,
            title: "Robot 4",
        });

        new google.maps.Marker({
            position: {lat: 43.356687111410764, lng: -5.851929708070923},
            map: mapa,
            title: "Robot 4",
        });
    
        const infowindow1 = new google.maps.InfoWindow({
            content: mostrarDatos(data.humidity),
            ariaLabel: "Robot 1",
        });
    
        marker1.addListener("click", () => {
            infowindow1.open({
                anchor: marker1,
                map: mapa,
            });
        });
    
    });
    
}

function mostrarDatos(temperature, humidity) {
    return [
        'Escuela Ingeniería informática',
        'Oviedo, Asturias',
        'Latitud: " + coordenadas.lat',
        'Longitud: ' + coordenadas.lng,
        'Temperatura: ' + temperature,
        'Humedad: ' + humidity,
        '<button onclick="encenderLed()">Encender</button>',
        '<button onclick="apagarLed()">Apagar</button>'
      ].join("<br>");
}

function apagarLed() {
    $.getJSON('http://192.168.61.203/index?apagar', function(data) {
    });
}

function encenderLed() {
    $.getJSON('http://192.168.61.203/index?encender', function(data) {
    });
}




