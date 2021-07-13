/* Theo Rowlett
 * CS202-Winter 2021
 * Project 1
 * Create an application for a distribution center to manage inventory, incoming and outgoing orders.
 * 	Required to use inheritence and recursion.
 * transit.cpp: transit code. Header is in address.h. This code is not implemented in the build that is being
 * 	submitted.
 */
#include "address.h"
using namespace std;

transit::transit():address(),tracking_number(0),carrier(nullptr),status(false)
{
}

transit::transit(const transit & a_transit)
{

	copy_address(a_transit);
	tracking_number = a_transit.tracking_number;
	carrier = new char (strlen(a_transit.carrier)+1);
	strcpy(carrier,a_transit.carrier);
	status = a_transit.status;
}

transit::~transit()
{
	if (carrier)
	{
		delete carrier;
		carrier = nullptr;
	}
}

void transit::display()
{
	address::display();
	cout << tracking_number << endl;
	cout << carrier << endl;
	cout << status << endl;

}


node_t::node_t():next(nullptr)
{
}

node_t::node_t(const transit & a_transit):transit(a_transit),next(nullptr)
{
}

node_t::~node_t()
{
	if (next)
	{
		delete next;
		next = nullptr;
	}
}

node_t *& node_t::go_next()
{
	return next;
}
