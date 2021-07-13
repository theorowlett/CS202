/* Theo Rowlett
 * CS202-Winter 2021
 * Project 1
 * Create an application for a distribution center to manage inventory, incoming and outgoing orders.
 * 	Required to use inheritence and recursion.
 * item.h: Header file that contains the item, node, and inventory classes. node and item code is in
 * 	item.cpp, inventory is in inventory.cpp. Node is derived from item, and inventory has a node to
 * 	create a table of linearly linked lists of nodes. 
 *
 *
 */
#include <iostream>
#include <cstring>

#ifndef ITEM
#define ITEM

class item
{
	public:
		item();
		item(int copy_num, float copy_cost, int copy_category, int copy_stock);
		item(item & to_copy);
		~item();
		void copy_item(item & to_copy); 
		void display();
		bool lookup(int lookup_number);
		bool customer_order(int quantity);
		void warehouse_order();
	protected:
		int item_num;
		float item_cost;
		//char * item_description;
		int item_category;
		int item_stock;

};

class node: public item
{
	public:
		node();
		node(item & copy_item);
		~node();
		node *& go_next();
		bool has_next();
	private:
		node * next;
};

class inventory
{
	public:
		inventory();
		//inventory(node & to_copy);
		~inventory();
		void delete_all(int count);
		void delete_node(node *& head);

		void add_item(item & to_copy, int category_num);
		void add_item(node *& head, item & to_copy);
		node * lookup(int lookup_number, int lookup_category, int quantity);
		node * lookup(node *& head, int lookup_number,int quantity);
		item * customer_order(int lookup_number, int lookup_category, int quantity);
		void display_all();
		void display_table(int count);
		void display_node(node *& head);


	private:
		node ** table;
		int categories;
};

#endif

