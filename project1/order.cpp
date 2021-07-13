/* Theo Rowlett
 * CS202-Winter 2021
 * Project 1
 * Create an application for a distribution center to manage inventory, incoming and outgoing orders.
 * 	Required to use inheritence and recursion.
 * order.cpp: Order class. Has functions top create and display orders. Header in order.h.
 */


#include "order.h"

using namespace std;

order::order():order_num(0),item_order(nullptr),quantity(0),destination(nullptr)
{
}

order::order(int a_num,item * a_item,int a_quant,address *& a_destination):order_num(a_num),quantity(a_quant)
{
	item_order = new item;
	item_order = a_item;

	destination = new address;
	destination = a_destination;
}

order::order(const order & copy_order):order_num(copy_order.order_num),quantity(copy_order.quantity)
{
	
	item_order = new item;
	item_order = copy_order.item_order;

	destination = new address;
	destination = copy_order.destination;
}

order::~order()
{
	if (item_order)
	{
		delete item_order;
		item_order = nullptr;
	}
	if (destination)
	{
		delete destination;
		destination = nullptr;
	}
}

void order::display()
{
	cout << "Order Number: " << order_num << endl;
	item_order->display();
	cout << "Quantity to order: " << quantity << endl;
	destination->display();
}
