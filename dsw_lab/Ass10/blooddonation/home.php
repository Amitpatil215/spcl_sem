<?php
session_start();
include("connection.php");
include("functions.php");

// is user pressed log in button
if (isset($_POST['findByCity'])) {

    if (!empty($_POST['checkArr'])) {
        // foreach ($_POST['checkArr'] as $checked) {
        //     echo $checked . "</br>";
        // }
    }
    $imploded_arr = implode(',', $_POST['checkArr']);
    // something was posted
    $query = "SELECT d.* , p.name as campName from donor d, camp P WHERE d.camp_id=p.camp_id and p.city IN('$imploded_arr')";
    $result = mysqli_query($con, $query);
}

if (isset($_POST['FindByGroup'])) {

    // something was posted
    $Bloodgroup = $_POST['bloodGroup'];
    $query = "SELECT d.* , p.city from donor d, camp P WHERE d.camp_id=p.camp_id and d.blood_grp='$Bloodgroup'";
    $resultBloodGroup = mysqli_query($con, $query);
}

?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home Page</title>
</head>

<body>

    <style type="text/css">
        #text {

            height: 25px;
            border-radius: 5px;
            padding: 4px;
            border: solid thin #aaa;
            width: 100%;
        }

        #button {

            padding: 10px;
            width: 100px;
            color: white;
            background-color: lightblue;
            border: none;
        }

        #box {

            background-color: grey;
            margin: auto;
            width: 300px;
            padding: 20px;
        }
    </style>
    <div id="box">

        <form method="post">
            <h2>City wise donars</h2>
            <label for="city">Choose a city:</label>
            <br>
            <input type="checkbox" id="Mumbai" name="checkArr[]" value="Mumbai">
            <label for="Mumbai"> Mumbai</label><br>

            <input type="checkbox" id="Delhi" name="checkArr[]" value="Delhi">
            <label for="Delhi"> Delhi</label><br>

            <input id="button" name="findByCity" type="submit" value="Find"><br><br>
            <table>
                <?php

                while (!empty($result) && $data = mysqli_fetch_array($result)) {
                ?>
                    <tr>
                        <td><?php echo $data['donor_id']; ?></td>
                        <td><?php echo $data['name']; ?></td>
                        <td><?php echo $data['blood_grp']; ?></td>
                        <td><?php echo $data['campName']; ?></td>
                    </tr>
                <?php
                }

                ?>
            </table>
            <h2>Blood Group wise donars</h2>
            <select id="bloodGroup" name="bloodGroup">
                <option value="A+">A+</option>
                <option value="B+">B+</option>
            </select>
            <input id="button" name="FindByGroup" type="submit" value="Choose Option"><br><br>
            <table>
                <?php

                while (!empty($resultBloodGroup) && $data = mysqli_fetch_array($resultBloodGroup)) {
                ?>
                    <tr>
                        <td><?php echo $data['donor_id']; ?></td>
                        <td><?php echo $data['name']; ?></td>
                        <td><?php echo $data['blood_grp']; ?></td>
                        <td><?php echo $data['city']; ?></td>
                    </tr>
                <?php
                }

                ?>
            </table>

        </form>

    </div>
</body>

</html>