<?php
session_start();
include("connection.php");
include("functions.php");


if (isset($_POST['submit'])) {

    // something was posted
    $name = $_POST['name'];
    $price = $_POST['price'];
    $description = $_POST['description'];
    $query = "insert into cakes (name,price,description) values('$name','$price','$description')";
    $isSuccess = mysqli_query($con, $query);
}

if (isset($_POST['show'])) {

    // something was posted

    $query = "Select * from cakes";
    $resultRows = mysqli_query($con, $query);
}


?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cup Cake</title>
</head>

<body>
    <h1>Cupcake World</h1>
    <h2>Add a new cupcake</h2>

    <form method="post">
        <!-- Name Field -->
        <label for="name">Name</label>
        <input type="text" name="name" id="">
        <br>
        <?php echo "The value name is required" ?>
        <br><br>

        <!-- Image Field -->
        <label for="image">Image</label>
        <input type='file' name="image" />
        <br>
        <?php
        echo "field is missings" ?>
        <br><br>

        <!-- Price -->
        <label for="price">Price</label>
        <input type="text" name="price" id="">
        <br>
        <?php echo "This value price is required" ?>
        <br><br>

        <!-- Description -->
        <label for="description">Description</label>
        <input type="textarea" name="description" id="">
        <br>
        <?php echo "This value description is required" ?>
        <br><br>

        <!-- Submit Button -->
        <input type="submit" value="Submit" name="submit">

        <!-- Show Button -->
        <input type="submit" value="show" name="show">
    </form>
    <table>

        <?php

        while (!empty($resultRows) && $data = mysqli_fetch_array($resultRows)) {
        ?>
            <tr>
                <td><?php echo $data["name"]?></td>
                <td><?php echo $data["price"]?></td>
                <td><?php echo $data["description"]?></td>
            </tr>
        <?php
        }
        ?>

    </table>
</body>

</html>