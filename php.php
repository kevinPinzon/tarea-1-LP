<html>
<head>
<title>PHP</title>
</head>

<body>
	<h1>Suma de 3 numeros</h1>
	<form name="form1" method="post" action="index.php">
		valor1: <input name="digito1" >
		valor2: <input name="digito2" >
		valor3: <input name="digito3" >
		<input type="submit" name="submit" value="sumar" >
	</form>
	
<p>Suma total :</p>
<?php

$digito1=$_POST['digito1'];
$digito2=$_POST['digito2']; 
$digito3=$_POST['digito3']; 

$suma=$digito1 + $digito2 + $digito3;

echo $suma;

?> 
</body>
</html>