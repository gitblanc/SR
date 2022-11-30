<?php

if(isset($_GET["temperatura"]) && isset($_GET["humedad"]) ) {
   $temperature = $_GET["temperatura"]; // peticion GET para el valor de la temperatura
   $humedad = $_GET["humedad"]; // peticion GET para el valor de la humedad

   $servername = "localhost";
   $username = "esp32";
   $password = "1234";
   $database_name = "servidor_iot_robots";

   // Creamos la conexión MYSQL de PHP a MySQL server
   $connection = new mysqli($servername, $username, $password, $database_name);
   // Comprobamos la conexión
   if ($connection->connect_error) {
      die("MySQL connection failed: " . $connection->connect_error);
   }

   $sql = "INSERT INTO datos_sensor (temperatura,humedad) VALUES ($temperatura,$humedad)";

   if ($connection->query($sql) === TRUE) {
      echo "Datos insertados correctamente";
   } else {
      echo "Error: " . $sql . " => " . $connection->error;
   }

   $connection->close();
} else {
   echo "Temperatura o humedad incorrectas";
}
?>