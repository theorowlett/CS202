/* Theo Rowlett
 * CS202 Project 3
 * main.cpp - Front end for contact book application.
 */

#include "string.h"
#include "device.h"
#include "contact.h"
#include "tree.h"

using namespace std;

Contact * new_contact();
char menu();
char yesorno();

int main()
{
	Tree * contact_tree = new Tree();
	char selection;
	do
	{
		selection = menu();
		switch (selection){
			case '1':{
				contact_tree->display();
				break;
				 }
			case '2':{
					 Contact * a_contact = new_contact();
					 cout << "Does this contact have a Discord (y/n)? ";
					 selection = yesorno();
					 if (selection == 'y')
						 a_contact->add_discord();
					 cout << "Does this contact have an email (y/n)? ";
					 selection = yesorno();
					 if (selection == 'y')
						 a_contact->add_email();
					 cout <<"Does this contact have a phone (y/n)? ";
					 selection = yesorno();
					 if (selection == 'y')
					 	a_contact->add_phone();
					 contact_tree->insert(*a_contact);
					 delete a_contact;
					 a_contact=nullptr;
					 break;
				 }
			case '3':{
					 String * search = new String();
					 cout << "Who are you searching for? ";
					 cin >> *search;
					 contact_tree->search(search);
					 delete search;
					 search = nullptr;
					 break;
				 }
			case '4':{
					 //cout <<"This is where the removal stuff will go." << endl;
					 String * search = new String();
					 cout << "Who do you want to remove? ";
					 cin >> *search;
					 contact_tree->remove(search);
					 delete search;
					 break;
				 }
			case '0':
				 break;

			default:
				cout << "Invalid input. Returning to main menu." <<endl;
		}

	} while (selection != '0');
	
	delete contact_tree;
	contact_tree = nullptr;
	return 0;
}


Contact * new_contact()
{
	String * name = new String();
	cout << "Enter contact's first name: ";
	cin >> * name;
	Contact * a_contact = new Contact(name);
	delete name;
	name = nullptr;
	return a_contact;
}

char menu()
{
	char selection = '0';
	cout << "1." << '\t' << "Display the Contact book"  <<endl;
	cout << "2." << '\t' << "Add a new Contact" <<endl;
	cout << "3." << '\t' << "Search for a contact"<<endl;
	cout << "4." << '\t' << "Remove a contact."<<endl;
	cout << "0." << '\t' << "Exit the application"<<endl;

	cin >> selection;

	return selection;
}

char yesorno()
{
	char selection = '0';
	cin >> selection;
	if (selection != 'y' && selection != 'n')
	{
		cout << "Invalid input. Try again." << endl;
		return yesorno();
	}
	return selection;
}
