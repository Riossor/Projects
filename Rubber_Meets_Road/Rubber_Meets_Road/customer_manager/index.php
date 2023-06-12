<?php
require('../model/database.php');
require('../model/customer_db.php');

$action = filter_input(INPUT_POST, 'action');
if($action == NULL){
    $action = filter_input(INPUT_GET, 'action');
    if($action == NULL){
        $action = 'Open';
    }
}
switch($action){
    case 'Open' :
        include 'customer_search.php';
        break;
    case 'Login' :
        $username = htmlspecialchars(filter_input(INPUT_POST, 'username'));
        $customers = loginCustomer($username);
        include 'search_customer.php';
        break;
    case 'Search' :
        $phone = filter_input(INPUT_POST, 'phone');
        $customers = searchCustomer($phone);
        include 'search_customer.php';
        break;
    case 'Select' :
        $customerAccount = htmlspecialchars(filter_input(INPUT_POST, 'customerAccount'));
        $customer = getCustomer($customerAccount);
        include 'view_customer.php';
        break;
    case 'Update' :
        $customerID = htmlspecialchars(filter_input(INPUT_POST, 'customerID'));
        $firstName = htmlspecialchars(filter_input(INPUT_POST, 'firstName'));
        $lastName = htmlspecialchars(filter_input(INPUT_POST, 'lastName'));
        $address = htmlspecialchars(filter_input(INPUT_POST, 'address'));
        $city = htmlspecialchars(filter_input(INPUT_POST, 'city'));
        $state = htmlspecialchars(filter_input(INPUT_POST, 'state'));
        $postalCode = htmlspecialchars(filter_input(INPUT_POST, 'postalCode'));
        $countryCode = htmlspecialchars(filter_input(INPUT_POST, 'countryCode'));
        $phone = htmlspecialchars(filter_input(INPUT_POST, 'phone'));
        $email = htmlspecialchars(filter_input(INPUT_POST, 'email'));
        $password = htmlspecialchars(filter_input(INPUT_POST, 'password'));
        updateCustomer($customerID, $firstName, $lastName, $address, $city, $state, $postalCode, $countryCode, $phone, $email, $password);
        include 'customer_search.php';
        break;
}

?>