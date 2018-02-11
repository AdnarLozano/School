<!--
Adnar Lozano
CIS-12: PHP
R. Casolaro
10/14/14
Chapter 5: Page 291 Exercise 5-3
-->

<?php

if(!isset($_POST['submit']))
{
	echo "Please submit the form";
}
else if(empty($_POST['name']) 
	|| empty($_POST['age'])
	|| empty($_POST['avg']))
{
	echo "One or more fields is empty.<br>Please try again";
}
else if(ctype_alpha(str_replace(' ', '',$_POST['name'])) == false)
{
	echo "The Name field must be letters only.";
}
else if(!is_numeric($_POST['age']))
{
	echo "The Age field must be numbers only.";
}
else if(!is_numeric($_POST['avg']))
{
	echo "The average field must be numbers only";
}
else
{
	$name = $_POST['name'];
	$age = $_POST['age'];
	$avg = $_POST['avg'];
	//echo $name, $age, $avg;
	$filename = "reg.txt";
	
	if(file_exists($filename))
	{
		$fileHandle = fopen($filename, "a+");
		$string = "\r\n$name, $age, $avg";
		fwrite($fileHandle, $string);
		fclose($fileHandle);
		echo "<h4>Success, you've submitted the form with the following info: </h4>";
		echo "<strong>Name: $name, Age: $age, Avg: $avg</strong>";
	}
	else
	{
		$fileHandle = fopen($filename, "a+");
		$string = "$name, $age, $avg";
		fwrite($fileHandle, $string);
		fclose($fileHandle);
		echo "Success, you've submitted the form with the following info: <br>";
		echo "Name: $name, Age: $age, Avg: $avg";
	}
}

?>