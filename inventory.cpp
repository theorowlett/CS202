/* Theo Rowlett
 * CS202-Winter 2021
 * Project 1
 * Create an application for a distribution center to manage inventory, incoming and outgoing orders.
 * 	Required to use inheritence and recursion.
 * item.cpp: inventory code. Node is derived from item, and inventory has a node to create a table
 * 	of linearly linked lists of nodes. 
 *
 *
 */

#include "item.h"
using namespace std;

//INVENTORY

inventory::inventory():table(nullptr),categories(15)
{
	table = new node * [categories];
	for (int i = 0; i<categories; i++)
		table[i]=nullptr;
}

inventory::~inventory()
{
	if (table)
	{
		delete table;
		table = nullptr;
	}
		//delete_all(0);
}
void inventory::delete_all(int count)		//not implemented
{
	if (count < categories)
	{
		//delete_node(table[count]);
		delete_all(count++);
	}
	delete table[count];
	table[count] = nullptr;
}

void inventory::delete_node(node *& head)	//not implemented
{
	if (head != nullptr)
	{
		delete_node(head->go_next());
	}
	delete head;
	head = nullptr;
}

void inventory::add_item(item & to_copy, int category_num)
{
	if (table[category_num] == nullptr)
	{
		table[category_num] = new node(to_copy);
		//table[category_num]->display();
	}
	else
		add_item(table[category_num]->go_next(),to_copy);
}

void inventory::add_item(node *& head, item & to_copy)
{
	if (head == nullptr)
	{
		head = new node(to_copy);
		//head->display();
	}
	else
		add_item(head->go_next(),to_copy);
}
node * inventory::lookup(int lookup_number, int lookup_category,int quantity)
{
	return lookup(table[lookup_category],lookup_number,quantity);
}

node * inventory::lookup(node *& head, int lookup_number, int quantity)
{
	if (head->lookup(lookup_number))
	{
		//cout << "Success!" << endl;
		//head->display();
		if (head->customer_order(quantity) == false)
			return nullptr;
		return head;
	}
	else if (head->has_next())
		lookup(head->go_next(),lookup_number,quantity);

	//cout << "No match found" << endl;
	return nullptr;

	
}

item * inventory::customer_order(int lookup_number, int lookup_category, int quantity)
{
	//node * temp = new node;
	return lookup(lookup_number,lookup_category,quantity);
	/*if (temp == nullptr)
	{
		cout << "Item not found." << endl;
	}
	else
	{
		if (temp->customer_order(quantity) == false)
		{
			cout << "Item out of Stock." << endl;
			temp->warehouse_order();
			return nullptr;
		}
		else
		{
			cout << "Order success." << '\n';


	}

	if (temp)
	{
		
		delete temp;
		temp = nullptr;
	}*/
}

void inventory::display_all()
{
	cout <<"Item #" << '\t' << "Price" << '\t' << "Category" << '\t' << "Stock" << endl;
	if (table)
		display_table(0);
}

void inventory::display_table(int count)
{
	if (count < categories)
	{
		display_node(table[count]);
		display_table(count+1);
	}
}

void inventory::display_node(node *& head)
{
	if (head!= nullptr)
	{
		head->display();
		if (head->has_next())
			display_node(head->go_next());
	}
}
