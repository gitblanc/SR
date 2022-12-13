<html>
<body>

<?php

$dbname = 'servidor_iot_robots';
$dbuser = 'root';  
$dbpass = ''; 
$dbhost = 'localhost'; 

$connect = @mysqli_connect($dbhost,$dbuser,$dbpass,$dbname);

if(!$connect){
	echo "Error: " . mysqli_connect_error();
	exit();
}

echo "Connection Success!<br><br>";

$temperatura = $_GET["temperatura"];
$humedad = $_GET["humedad"]; 


$query = "INSERT INTO datos_sensor (temperatura, humedad) VALUES ('$temperatura', '$humedad')";
$result = mysqli_query($connect,$query);

echo "Insertion Success!<br>";

?>
</body>
</html>
