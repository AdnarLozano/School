<!--
Adnar Lozano
CIS-12: PHP Programming
R. Casolaro
10/07/14
Homework #5
-->

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" 
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Paycheck</title>
<meta http-equiv="content-type" content="text/html; charset=iso-8859-1" />
</head>
<body>
<?php

function displayRequired($fieldName) 
{
     echo "The field \"$fieldName\" is required.<br />\n";
}

function validateInput($data, $fieldName) 
{
     global $errorCount;
     if (empty($data)) {
          displayRequired($fieldName);
          ++$errorCount;
          $retval = "";
     } else { // Only clean up the input if it isn't empty
          $retval = trim($data);
          $retval = stripslashes($retval);
     }
     return($retval);
}

$errorCount = 0;
$hoursWorked = validateInput($_POST['hoursWorked'], "Number of Hours Worked");
$hourlyWage = validateInput($_POST['hourlyWage'], "Hourly Wage");

if ($errorCount>0) 
{
     echo "Please go back and re-enter the information below.";
}

else if (isset($_POST['Submit']))
{
     $hoursWorked = $_POST['hoursWorked'];
     $hourlyWage = $_POST['hourlyWage'];

     if(!empty($hoursWorked) && is_numeric($hoursWorked))
     {
          echo "Your weekly hours worked is: ".$hoursWorked.".<br>" ."Your hourly wage is: $".$hourlyWage  . ".<br>";

          if ($hoursWorked <= 40 )
          {
              echo "Your Gross Salary is: $".$hoursWorked * $hourlyWage;
          }

          else 
          {
          $overTime = ((($hoursWorked - 40) * 1.5) * $hourlyWage);
          $total = $overTime + (40 * $hourlyWage);
          echo "Your Gross Salary with overtime is pay: $".$total;
          }
     }
     else
     {
     echo "<h4>There was an error with your input.<br>Please go back and re-enter a numerical value.</h4>";
     }

}
?>
</body>
</html>

