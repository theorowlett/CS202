/* Theo Rowlett
 * CS202-Winter 2021
 * Project 1
 * Create an application for a distribution center to manage inventory, incoming and outgoing orders.
 * 	Required to use inheritence and recursion.
 * address.h: header file for address, transit, and node_t. Code for address is in address.cpp, transit
 * 	and node_t is in transit.cpp.
 */

#include "item.h"

#ifndef ADDRESS
#define ADDRESS

class address
{
	public:
		address();
		address(char * new_street, char * new_state, int new_zip);
		address(const address & a_address);
		~address();
		void copy_address(const address & a_address);
		void change_street(char * new_street);
		void change_state(char * new_state);
		void change_zip(int new_zip);
		void display();
	protected:
		char * street;
		char * state;
		int zip;
};

class transit: public address
{
	public:
		transit();
		transit(const transit & a_transit);
		~transit();
		void display();
	protected:
		int tracking_number;	//This is a tracking number
		char * carrier;		//UPS,FedEx,USPS
		bool status;		//Has it been delivered
};

class node_t: public transit
{
	public:
		node_t();
		node_t(const transit & transit_copy);
		~node_t();
		node_t *& go_next();
	private:
		node_t * next;
};




#endif
