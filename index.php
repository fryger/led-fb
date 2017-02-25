<!DOCTYPE html>
<html>
<head>
	<title>Led Control</title>
	<meta charset="utf-8">
</head>
<body>
<form action="" method="post" accept-charset="utf-8">
<p>RED</p>
	<input type="text" name="red">
<p>GREEN</p>
	<input type="text" name="green">
<p>BLUE</p>
	<input type="text" name="blue">	
	<button type="">Kolor</button>
</form>

<?php
error_reporting(0);
	$combine= $_POST['funkcja'];
   $red= $_POST['red'];
   $green= $_POST['green'];
   $blue= $_POST['blue'];
   $combine .= $red;
   $combine .= ",";
   $combine .= $green;
   $combine .= ",";
   $combine .= $blue;
   $tmp = exec("python led.py $combine");
?>
</body>
</html>