/* Theo Rowlett
 * CS202-Winter 2021
 * Project 1
 * Create an application for a distribution center to manage inventory, incoming and outgoing orders.
 * 	Required to use inheritence and recursion.
 * item.cpp: node and item code. Node is derived from item, and inventory has a node to create a table
 * 	of linearly linked lists of nodes. 
 *
 *
 */

#include "item.h"

using namespace std;

item::item():item_num(0),item_cost(0.00),item_category(0),item_stock(0)
{}

item::item(int copy_num, float copy_cost,int copy_category, int copy_stock):item_num(copy_num),item_cost(copy_cost),item_category(copy_category),item_stock(copy_stock)
{
}

item::item(item & to_copy)
{
	copy_item(to_copy);
}

void item::copy_item(item & to_copy)
{
	item_num = to_copy.item_num;
	item_cost = to_copy.item_cost;
	item_category = to_copy.item_category;
	item_stock = to_copy.item_stock;
}

item::~item()
{}

void item::display()
{
	cout << item_num << '\t'  << "$" <<  item_cost << '\t' << item_category << '\t' << '\t' << item_stock << endl;
}

bool item::lookup(int lookup_number)
{
	if (item_num == lookup_number)
		return true;
	else
		return false;
}

bool item::customer_order(int order_quantity)
{
	if (order_quantity > item_stock)
	{
		cout << "Item out of Stock." << endl;
		warehouse_order();
		return false;
	}

	item_stock = item_stock - order_quantity;
	return true;
}

void item::warehouse_order()
{
	int reorder = 0;
	cout<<"How much should the warehouse order? ";
	cin >> reorder;
	item_stock = item_stock + reorder;
}


//NODE
node::node():next(nullptr)
{}

node::node(item & copy_item):item(copy_item),next(nullptr)
{
}

node::~node()
{
	if (next)
	{
		delete next;
		next = nullptr;
	}
}


node *& node::go_next()
{
	return next;
}

bool node::has_next()
{
	if (next == nullptr)
		return false;
	else
		return true;
} 
