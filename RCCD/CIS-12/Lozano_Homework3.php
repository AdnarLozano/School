<!--
Adnar Lozano
CIS-12 PHP
R. Casolaro
09/16/14
Homework #3
-->

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Temperature Conversion</title>
<meta http-equiv="content-type" content="text/html; charset=iso-8859-1" />
</head>
<body>
<h2>Temperature Conversion</h2> 
<h3>Farenheit to Celsius</h3>
<?php
for ($fTemp=0; $fTemp<=100; $fTemp++) {
	$cTemp = ($fTemp - 32) * 5/9;
	echo "<strong>$fTemp</strong> Degrees Farenheit is:  " ,"<strong>", round($cTemp,2), "</strong> ", "Degrees Celsius <br />";
}
?>
</body>
</html>
