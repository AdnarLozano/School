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

  <title>Subscribers</title>
  
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

      <h3><p>Newsletter Subscribers</p></h3>

<?php
include("newsletter.php");
if ($DBConnect !== FALSE) {
     $TableName = "subscribers";
     $SQLstring = "SELECT * FROM $TableName";
     $QueryResult = @mysql_query($SQLstring, $DBConnect);
     echo "<table width='100%' border='1'>\n";
     echo "<tr><th>Subscriber ID</th>" .
          "<th>Name</th><th>City</th>" .
          "<th>State</th><th>Country</th>" .
          "<th>Email</th><th>Comments</th>" .
          "<th>Subscribe Date</th>" .
          "<th>Confirm Date</th></tr>\n";
     while (($Row = mysql_fetch_assoc($QueryResult)) !== FALSE) {
          echo "<tr><td>{$Row['subscriberID']}</td>";
          echo "<td>{$Row['name']}</td>";
          echo "<td>{$Row['city']}</td>";
          echo "<td>{$Row['state']}</td>";
          echo "<td>{$Row['country']}</td>";
          echo "<td>{$Row['email']}</td>";
          echo "<td>{$Row['comments']}</td>";
          echo "<td>{$Row['subscribe_date']}</td>";
          echo "<td>{$Row['confirmed_date']}</td></tr>\n";
     };
     echo "</table>\n";
     $NumRows = mysql_num_rows($QueryResult);
     $NumFields = mysql_num_fields($QueryResult);
     echo "<br/>";
     echo "<p>Your query returned the above "
          . mysql_num_rows($QueryResult)
          . " rows and ". mysql_num_fields($QueryResult)
          . " fields:</p>";
     mysql_free_result($QueryResult);
     mysql_close($DBConnect);
     echo "<br/>";
}
?>
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