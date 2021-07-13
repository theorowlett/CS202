/* Theo Rowlett
 * CS202-Winter 2021
 * Project 1
 * Create an application for a distribution center to manage inventory, incoming and outgoing orders.
 * 	Required to use inheritence and recursion.
 * order.h: Header file for order class. If order list was finished this would also contain node_o and
 * 	a class for order list.
 */



#ifndef ORDER
#define ORDER

#include "item.h"
#include "address.h"

class order
{
	public:
		order();
		order(const order & copy_order);
		order(int a_num,item * a_item,int a_quant,address *& a_destination);
		~order();
		void display();
	protected:
		int order_num;
		item * item_order;
		int quantity;
		//int order_type;
		address * destination;
};

#endif
