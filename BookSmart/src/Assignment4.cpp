/*
 * main.cpp
 *
 *  Created on: Jan 25, 2023
 *      Author: Ruben Rios
 *      	Cheyenne Westbrook
 *      	David McMahon
 *      	Connor Schaffer
 *
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include "Database.h"
#include "Book.h"
#include "Login.h"
#include "Menu.h"


using namespace std;

int main () {


	Login login = Login();
	login.LoadUsers("src/Users.csv");

	login.Validate();
	if (login.IsValidated()) {
		Database DB = Database();
		DB.LogFile("Successful database operation");
		DB.LogFile("User has logged into application");
		 // FIX , Load from database
		DB.LoadFile("src/books.csv", 4000);
		DB.LoadDatabase();

		int selection = 1;
		int menuOption = 1;
		string title;

		while (selection != 0) {
			PrintMainMenu();
			selection = GetMenuOption();
			switch (selection) {
			case 1:	// Search titles
			{

				cout << "Search by book Title:" << endl;
				cin >> title;
				DB.SearchTitles(title);
				break;
			}
			case 2:	//Add book to inventory
			{

				string ISBN;
				string title;
				string author;
				string publisher;
				string pubYear;
				string description;
				string genre;
				string MSRP;
				cin.ignore(1, '\n');
				cout << "Enter Book ISBN: ";
				getline(cin, ISBN);
				while (ISBN.length() != 13) {
				    cout << "Invalid input. ISBN must be 13 digits. Please enter again: ";
				    getline(cin, ISBN);
				}
				cout << "Enter Book Title: ";
				getline(cin, title);
				cout << "Enter Book Author: ";
				getline(cin, author);
				cout << "Enter Book Publisher: ";
				getline(cin, publisher);
				cout << "Enter Book Publication Year: ";
				getline(cin, pubYear);
				cout << "Enter Book Description/Plot: ";
				getline(cin, description);
				cout << "Enter Book Genre: ";
				getline(cin, genre);
				cout << "Enter Book MSRP: ";
				getline(cin, MSRP);

				if(genre.compare("") == 0 && description.compare("") == 0) {
					DB.AddBook(ISBN, title, author, publisher, pubYear, MSRP);
				} else
					DB.AddBook(ISBN, title, author, publisher, pubYear, description, genre, MSRP);

				break;
			}
			case 3: // Create User Book List
			{
				string exit = "0";
				string userString;
				string name;

				if (DB.IsShopperInDatabase()== true) {
				    cout << "Shopper found" << endl;
				}
				else {
					cout << "No Shopper found. Add Shopper" << endl;
					break;
				}
				cout << "Add Books to list by ISBN or 0 to end: " << endl;

				cin >> userString;
				while( userString.compare(exit) != 0) {
					if (DB.IsISBNinDatabase(userString)){
						DB.AddBookToListByISBN(userString);
					}
					cout << "Next Book or 0 to end: " << endl;
					cin >> userString;
				}

				break;
			}
			case 4: //Print UserList to Screen
			{
				DB.PrintUserList();
				break;
			}
			case 5: //delete list from inventory
			{
				DB.RemoveListFromInventory();
				break;
			}
			case 6: //Export Shopping List to csv
			{
				DB.ExportCSVFile();
				//DB.ExportToDatabase();
				cout << "File: UserBookList.csv has been created." << endl;
				break;
			}
			case 7: //Add Shopper
			{

				DB.CreateShoppersTable();
				DB.AddShopper();
				break;
			}
			case 8: //sales receipt
			{

				DB.loadShoppersTable();
				DB.CreateReceipt();
				break;
			}
			case 9: // Admin menu
			{
				menuOption = 1;
				while(menuOption != 0) {
					PrintAdminMenu();
					menuOption = GetMenuOption();
					switch(menuOption) {
					case 1: // Add user
					{
						string userName = "";
						string password = "";
						cout << "Enter New User First Name:" << endl;
						cin >> userName;
						cout << "Enter New User Password:" << endl;
						cin >> password;
						login.AddUser("src/Users.csv", userName, password);
						cout << "New User Added!" << endl;
						break;
					}
					case 2: // Change Password
					{
						string userName = "";
						string password = "";
						cout << "Enter User Name:" << endl;
						cin >> userName;
						cout << "Enter New Password:" << endl;
						cin >> password;
						login.ChangePassword("src/Users.csv", userName, password);
						break;
					}
					case 3: // ImportFile
					{
						DB.ImportFile();
						break;
					}
					case 4: //create database
					{
						cout << "Database Loading..." << endl;
						DB.CreateLibraryDatabase();
						DB.LoadLibraryDatabase();


						break;
					}
					case 5:// Database Stats
					{
						cout << DB.GetDatabaseCount() << " Book Records available" << endl;
						break;
					}
					case 6: //clear database
					{
						DB.ClearDatabase();
						break;
					}
					case 7: //view shopper profile
					{
						string name;
						cout << "Enter The Shoppers Name: " << endl;
						cin.ignore(1,'\n');
						getline(cin,name);
						DB.DisplayProfile(name);
						break;
					}
					case 8: //add card on file
					{

						DB.AddCardOnFile();
						break;
					}
					case 0: // Exit to Main Menu
					{
						break;
					}
					default:
					{
						cout << "Please select from the menu" << endl;
						break;
					}
					}
				}
				break;
			}
			case 0:
			{
				cout << "Thank you for using Book Database" << endl;
				DB.LogFile("User has logged out of application");
				break;
			}
			default:
			{
				cout << "Please select from the menu" << endl;
			}
			}
		}
	}
	else {
		cout << "Sorry, check your login information" << endl;
	}





}


