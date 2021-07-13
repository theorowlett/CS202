/* Theo Rowlett
 * CS202-Winter 2021
 * Project 1
 * Create an application for a distribution center to manage inventory, incoming and outgoing orders.
 * 	Required to use inheritence and recursion.
 * address.cpp: address code. Address does have a child class, transit, that is written but not implemented
 * 	in transit.cpp.
 *
 */


#include "address.h"
using namespace std;
//ADDRESS
//Constructors
address::address():street(nullptr),state(nullptr),zip(0)
{
}

address::address(char * a_street, char * a_state, int a_zip):zip(a_zip)
{
	street = new char(strlen(a_street)+1);
	strcpy(street,a_street);

	state = new char(strlen(a_state)+1);
	strcpy(state,a_state);
}

address::address(const address & a_address)
{
	copy_address(a_address);
}

void address::copy_address(const address & a_address)
{
	street = new char(strlen(a_address.street)+1);
	strcpy(street,a_address.street);

	state = new char(strlen(a_address.state)+1);
	strcpy(state,a_address.state);

	zip = a_address.zip;
}
//Destructor
address::~address()
{
	if (street)
	{
		delete street;
		street = nullptr;
	}
	if (state)
	{
		delete state;
		state = nullptr;
	}
}

void address::change_street(char * new_street)
{
	delete street;
	street = nullptr;
	street = new char(strlen(new_street)+1);
	strcpy(street,new_street);
}


void address::change_state(char * new_state)
{
	delete state;
	state = nullptr;
	state = new char(strlen(new_state)+1);
	strcpy(state,new_state);
}

void address::change_zip(int new_zip)
{
	zip = new_zip;
}

void address::display()
{
	cout << street << " " << state << endl;
	cout << zip << endl;
}
