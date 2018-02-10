<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" 
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html>
	<head>
	<!--
	    5 Star Elite Cleaning All rights Reserved.
	-->

	<meta charset="UTF-8" />
	<meta name="author" content="5 Star Elite Cleaning" />
	<meta name="description" content="Professional cleaning services in upstate New York" />
	<meta name="keywords" content="home, cleaning, sanitizing, commercial, residential, services, New York" />

	<title>Newsletter</title>
	
	<link href="layout.css" rel="stylesheet" type="text/css" />
	<script src="modernizr-1.5.js"></script>
	<script type="text/javascript" src="js/jquery-1.3.2.min.js"></script>
	<script type="text/javascript" src="js/jquery.cycle.all.min.js"></script>
	<script type="text/javascript" src="js/superfish.js"></script>
	<script type="text/javascript" src="js/script.js"></script>

	</head>

	<div id="container">

<div id="container-inner">

	<div id="header">
    	<h1>5 Star Elite Cleaning</h1>

  		<p>Professional cleaning services in upstate New York</p>
        <div class="clear"></div>
    </div><!-- end header -->
    
    <div id="nav">
    	<ul>
        	<li><a href="index.htm">Home</a></li>
            <li><a href="about.htm">About Us</a></li>
            <li><a href="form.htm">Register</a></li>
            <li><a href="contact.htm">Contact</a></li>
        </ul>
    </div><!-- end nav -->
	
	  <div id="slider">
      <!-- start slideshow -->
      <div id="slideshow">
        <div class="slide-image"><a href="#"><img src="img1.jpg" alt="image" width="920" height="300" border="0" /></a></div>
        <div class="slide-image"><a href="#"><img src="img2.jpg" alt="image" width="920" height="300" border="0" /></a></div>
        <div class="slide-image"><a href="#"><img src="img3.jpg" alt="image" width="920" height="300" border="0" /></a></div>
        <div class="slide-image"><a href="#"><img src="img4.jpg" alt="image" width="920" height="300" border="0" /></a></div>
      </div>
      <!-- end #slideshow -->
      <div class="controls-outer">
        <div id="slide_controls">
          <ul id="slider_nav">
            <li><a href="#"></a></li>
            <!-- Slide 1 -->
            <li><a href="#"></a></li>
            <!-- Slide 2 -->
            <li><a href="#"></a></li>
            <!-- Slide 3 -->
			 <li><a href="#"></a></li>
            <!-- Slide 4 -->
          </ul>
        </div>
      </div>
      <div class="clr"></div>
    </div>
    <!--/slider -->

     <h3><p>Newsletter Subscription Notice</p></h3>

<?php
$errors = 0;
$email = "";

if (empty($_POST['email'])) {
     ++$errors;
     echo "<p>You need to enter an email address.</p>\n";
}
else {
     $email = stripslashes($_POST['email']);
     if (preg_match("/^[\w-]+(\.[\w-]+)*@" .
               "[\w-]+(\.[\w-]+)*(\.[a-zA-Z]{2,})$/i",
               $email) == 0) {
          ++$errors;
          echo "<p>You need to enter a valid " .
               " email address.</p>\n";
          $email = "";
     }
}
if (empty($_POST['password'])) {
     ++$errors;
     echo "<p>You need to enter a password.</p>\n";
     $password = "";
}
else
     $password = stripslashes($_POST['password']);
if (empty($_POST['password2'])) {
     ++$errors;
     echo "<p>You need to enter a confirmation password.</p>\n";
     $password2 = "";
}
else
     $password2 = stripslashes($_POST['password2']);
if ((!(empty($password))) && (!(empty($password2)))) {
     if (strlen($password) < 6) {
          ++$errors;
          echo "<p>The password is too short.</p>\n";
          $password = "";
          $password2 = "";
     }
     if ($password <> $password2) {
          ++$errors;
          echo "<p>The passwords do not match.</p>\n";
          $password = "";
          $password2 = "";
     }
}
if ($errors == 0) {
     $DBConnect = @mysql_connect("localhost", "joe5star", "5trujillanos");
     if ($DBConnect === FALSE) {
          echo "<p>Unable to connect to the database server. " .
               "Error code " . mysql_errno() . ": " .
               mysql_error() . "</p>\n";
          ++$errors;
     } 
     else {
          $DBName = "newsletter";
          $result = @mysql_select_db($DBName, $DBConnect);
          if ($result === FALSE) {
               echo "<p>Unable to select the database. " .
                    "Error code " . mysql_errno($DBConnect) . 
                    ": " . mysql_error($DBConnect) . "</p>\n";
               ++$errors;
          }
     } 
}
$TableName = "subscribers";
if ($errors == 0) {
     $SQLstring = "SELECT count(*) FROM $TableName" .
          "where email=$email";
     $QueryResult = @mysql_query($SQLstring, $DBConnect);
     if ($QueryResult !== FALSE) {
          $Row = mysql_fetch_row($QueryResult);
          if ($Row[0]>0) {
               echo "<p>The email address entered (" .
                    htmlentities($email) . 
                    ") is already registered.</p>\n";
               ++$errors;
          }
     }
}
if ($errors > 0) {
     echo "<p>Please use your browser's BACK button to return " .
          " to the form and fix the errors indicated.</p>\n";
     echo '<img align="center" src="error.jpg"/>';
     echo "<br />";
}
if ($errors == 0) {
     $name = stripslashes($_POST['name']);
     $city = stripslashes($_POST['city']);
     $state = stripslashes($_POST['state']);
     $country = stripslashes($_POST['country']);
     $email = stripslashes($_POST['email']);
     $interestedin = ($_POST['interestedin']);
     $mostlyfor = ($_POST['mostlyfor']);
     $informationon = ($_POST['informationon']);
     $comments = stripslashes($_POST['comments']);
     $subscriberDate = date("Y-m-d");
     $confirmedDate = date("Y-m-d");
     $SQLstring = "INSERT INTO $TableName " .
               " (name, city, state, country, email, password_md5, interestedin, mostlyfor, informationon, comments, subscribe_date, confirmed_date) " .
               " VALUES( '$name', '$city', '$state', '$country', '$email', " .
               " '" . md5($password) . "', '$interestedin', '$mostlyfor', '$informationon', '$comments', '$subscriberDate', '$confirmedDate')";
     $QueryResult = @mysql_query($SQLstring, $DBConnect);
     if ($QueryResult === FALSE) {
          echo "<p>Unable to save your registration " .
               " information. Error code " .
               mysql_errno($DBConnect) . ": " . 
               mysql_error($DBConnect) . "</p>\n";
          ++$errors;
     }
     else {
          $SubscriberID = mysql_insert_id($DBConnect);
     }
     mysql_close($DBConnect);
}
if ($errors == 0) {
     $SubscriberName = $name;
     echo "<p>Thank you, <strong>$SubscriberName</strong>. ";
     echo "Your new Subscriber ID is <strong>" .
          $SubscriberID . "</strong>.</p>\n";
     echo "<br />";
     echo '<img align="center" src="thankyou.png"/>';
}
?>
<hr>
<h3><p>Show Subscribers</p></h3>
<form method="POST" action="showSubscribers.php">
<input type="submit" value="Click to view" />
</form>
<br>
</div><!-- end content -->
</div><!-- end main -->
<div id="footer">
  <p><address>5 Star Elite Cleaning 2014 &copy; &bull; 
        <a href="mailto:support@5starelitecleaning.com">
        support@5starelitecleaning.com</a> &bull;
        White Plains, New York &bull;
        All rights reserved</address></p>
</div><!-- end footer -->
</body>
</html>
