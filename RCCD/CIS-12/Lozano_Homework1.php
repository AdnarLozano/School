<!--
Adnar Lozano
CIS-12: PHP
R. Casolaro
9/4/14
Chapter 1: Page 68 Exercise 1-1
-->

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" 
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Interest Array</title>
<meta http-equiv="content-type" content="text/html; charset=iso-8859-1" />
</head>
<body>
<p>
<h2><u>Interest Rates</u></h2>
<?php
$InterestRate1 = .0725;
$InterestRate2 = .0750;
$InterestRate3 = .0775;
$InterestRate4 = .0800;
$InterestRate5 = .0825;
$InterestRate6 = .0850;
$InterestRate7 = .0875;

$RatesArray = array($InterestRate1, $InterestRate2, $InterestRate3, $InterestRate4, $InterestRate5, $InterestRate6, $InterestRate7);
echo "<h3>The following ", count($RatesArray), " rates are:</h3>";
echo "Interest rate 1 is: $RatesArray[0]<br />";
echo "Interest rate 2 is: $RatesArray[1]<br />";
echo "Interest rate 3 is: $RatesArray[2]<br />";
echo "Interest rate 4 is: $RatesArray[3]<br />";
echo "Interest rate 5 is: $RatesArray[4]<br />";
echo "Interest rate 6 is: $RatesArray[5]<br />";
echo "Interest rate 7 is: $RatesArray[6]<br /><br>";
print_r($RatesArray);
?>
</p>
</body>
</html>