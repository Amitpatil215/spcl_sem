<?php
$dbhost = "localhost";
$dbuser = "root";
$dbpass = "";
$dbname = "blood_donation";

if (!$con = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname)) {

    die("Failed to connect");
};
