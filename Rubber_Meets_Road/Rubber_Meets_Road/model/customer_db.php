<?php
function loginCustomer($username){
    global $db;
    $query = 'SELECT * FROM customers
              WHERE username = :username';
    $statement = $db->prepare($query);
    $statement->bindValue(':username', $username);
    $statement->execute();
    $customers=$statement->fetchAll();
    $statement->closeCursor();
    return $customers;
}
function searchCustomer($phone){
    global $db;
    $query = 'SELECT * FROM customers
              WHERE phone = :phone';
    $statement = $db->prepare($query);
    $statement->bindValue(':phone', $phone);
    $statement->execute();
    $customers=$statement->fetchAll();
    $statement->closeCursor();
    return $customers;
}
function getCustomer($customerAccount){
    global $db;
    $query = 'SELECT * FROM customers
              WHERE customerAccount = :customerAccount';
    $statement = $db->prepare($query);
    $statement->bindValue(':customerAccount', $customerAccount);
    $statement->execute();
    $customer=$statement->fetch();
    $statement->closeCursor();
    return $customer;
}
function updateCustomer($firstName, $lastName, $address, $city, $state, $postalCode, $countryCode, $phone, $email, $password){
    global $db;
    $query = 'UPDATE customer SET
                firstName = :firstName ,
                lastName = :lastName ,
                address = :address,
                city = :city,
                state = :state,
                postalCode = :postalCode, 
                countryCode = :countryCode,
                email = :email,
                phone = :phone,
                password = :passwords,
                WHERE email = :email';
    $statement = $db->prepare($query);
    $statement->bindValue(':firstName', $firstName);
    $statement->bindValue(':lastName', $lastName);
    $statement->bindValue(':address', $address);
    $statement->bindValue(':city', $city);
    $statement->bindValue(':state', $state);
    $statement->bindValue(':postalCode', $postalCode);
    $statement->bindValue(':countryCode', $countryCode);
    $statement->bindValue(':phone', $phone);
    $statement->bindValue(':email', $email);
    $statement->bindValue(':password', $password);
    $statement->execute();
    $statement->closeCursor();

}


?>