<?php include '../view/header.php'; ?>

<main>
    <h2>Customer Search</h2>
    
    <form action = "index.php" method="post" id="search_customer">
        <input type="hidden" name="action" value="search_customer">
        <label>Phone:</label>
        <input type="text" name="phone">
        <input type='submit' name='action' value='Search' >
        <br>

        <table>
            <tr>
                <th>Name</th>
                <th>Email</th>
                <th>&nbsp;</th>
            </tr>
            <?php foreach($customers as $customer) : ?>
                <tr>
                    <td><?php echo $customer['firstName']." ".$customer['lastName']; ?></td>
                    <td><?php echo $customer['email']; ?></td>
                    <td><input type='submit' name='action' value='Select'></td>
                    <input type='hidden' name='customerAccount' value='<?php echo $customer['customerAccount'] ?>' >
                </tr>
            <?php endforeach ?>
        </table>

    </form> 
</main>

<?php include '../view/footer.php'; ?>