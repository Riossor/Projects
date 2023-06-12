<?php include '../view/header.php'; ?>


<main>
    <h1>View/Update Customer</h1>
    <form action="index.php" method="post" id="update_customer">
        <input type="hidden" name="customerAccount" value="<?php echo $customer["customerAccount"] ?>"/>

        <label>First Name:</label>
        <input type="text" name="firstName" value="<?php echo $customer["firstName"] ?>"/>
        <br>

        <label>Last Name:</label>
        <input type="text" name="lastName" value='<?php echo $customer["lastName"] ?>'/>
        <br>

        <label>Phone:</label>
        <input type="text" name="phone" value='<?php echo $customer["phone"] ?>'/>
        <br>

        <label>Email:</label>
        <input type="text" name="email" value='<?php echo $customer["email"] ?>'/>
        <br>

        <label>Username:</label>
        <input type="text" name="username" value='<?php echo $customer["username"] ?>'/>
        <br>

        <label>Password:</label>
        <input type="text" name="password" value='<?php echo $customer["password"] ?>'/>
        <br>

        <label>&nbsp;</label>
        <input type="submit" name="action" value="Update" />
        <br>

    </form>
    <h2>Vehicles</h2>
    <form action="index.php" method="post" id="view_customer">
    <input type="hidden" name="vehicleID" value="<?php echo $vehicles["vehicleID"] ?>"/>

    <label>Vin:</label>
    <input type="text" name="vin" value="<?php echo $vehicles["vin"] ?>"/>
    <br>

    </form>

    <p class="last_paragraph">
        <a href="index.php?action=customer_search">Search Customer</a>
    </p>
</main>

<?php include '../view/footer.php'; ?>