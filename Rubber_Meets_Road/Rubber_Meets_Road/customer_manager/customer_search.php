<?php include '../view/header.php'; ?>

<main>
    <h2>Customer Search</h2>
    
    <form action = "index.php" method="post" id="customer_search">
        <input type="hidden" name="action" value="customer_search">
        <label>Username:</label>
        <input type="text" name="username">
        <label>Password:</label>
        <input type="text" name="password">
        <input type='submit' name='action' value='Login' >
        <br>

    </form> 
</main>

<?php include '../view/footer.php'; ?>