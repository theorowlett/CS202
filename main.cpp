/* Theo Rowlett
 * CS202-Winter 2021
 * Project 1
 * Create an application for a distribution center to manage inventory, incoming and outgoing orders.
 * 	Required to use inheritence and recursion.
 * main.cpp: Front end/and test application
 *
 * Known Bugs/Issues:
 * *Tracking: Not Implemented
 * *Open Order List: Not Implemented
 * *Can only order one item at a time.
 * *There's no handling of invalid inputs.
 * *There's probably a lot of memory leaks.
 *
 */


#include "item.h"
#include "address.h"
#include "order.h"
//#include<fstream>

using namespace std;
address * load(inventory & warehouse);
address * get_address();
order * create_order(inventory & warehouse);
int menu();
int main()
{
	inventory warehouse;
	address * warehouse_address = load(warehouse);
	int selection = 0;

	//address * customer = get_address();
	//customer->display();
	
	do {
		selection = menu();

		switch(selection){
			case 1:
				{
				//cout <<"This is where you'll order an item." << endl;
				order * new_order = create_order(warehouse);
				if (new_order != nullptr)
					new_order->display();
				}
				break;
			case 2:
				warehouse.display_all();
				break;
			case 3:
				cout <<"Show open orders. Coming Soon." << endl;
				break;
			case 4:
				break;
		}
	}while (selection !=4);
	
	return 0;
}
address * load(inventory & warehouse)
{
	char warehouse_street[30] ="15000 N Lombard St";
	char warehouse_state[3] = "OR";
	int warehouse_zip = 97203;

	//This was originally read in from a txt file 
	//but it kept breaking things so now it's 
	//hardcoded. Might fix if I have time.
	item first_item(1001,12.99,0,1000);
	item second_item(1002,39.99,0,600);
	item third_item(1003,16.47,0, 85);
	item fourth_item(1004,129.99,1,50);
	item fifth_item(1005,699.99,1,0);
	item sixth_item(1006,9.89,1,200);
	item seventh_item(1007,1.69,2,55);
	item eighth_item(1008,3.59,2,100);
	item ninth_item(1009,2.79,2,25);
	warehouse.add_item(first_item,0);
	warehouse.add_item(second_item,0);
	warehouse.add_item(third_item,0);
	warehouse.add_item(fourth_item,1);
	warehouse.add_item(fifth_item,1);
	warehouse.add_item(sixth_item,1);
	warehouse.add_item(seventh_item,2);
	warehouse.add_item(eighth_item,2);
	warehouse.add_item(ninth_item,2);
	return new address(warehouse_street,warehouse_state,warehouse_zip);
}

address * get_address()
{
	const int MAX_LENGTH = 100;
	char a_street[MAX_LENGTH];
	char a_state[MAX_LENGTH];
	int a_zip;
	
	cout << "Enter street address: ";
	cin.get(a_street,MAX_LENGTH,'\n');
	cin.ignore();
	cout << "State: ";
	cin.get(a_state,MAX_LENGTH,'\n');
	cin.ignore();
	cout << "ZIP Code: ";
	cin >> a_zip;
	cin.ignore();

	return new address(a_street,a_state,a_zip);
}

int menu()
{
	int selection = 0;
	cout << "1."<<'\t' << "Order an item." << endl;
	cout << "2."<<'\t' << "Display inventory." << endl;
	cout << "3."<<'\t' << "Show open orders." << endl;
	cout << "4."<<'\t' << "Exit the program." << endl;

	cin >> selection;

	return selection;
}

order * create_order(inventory & warehouse)
{
	int order_num;
	int item_select;
	int item_category;
	int item_quantity;

	warehouse.display_all();
	cout <<"Create an order number(0-9 only).";
	cin >> order_num;
	cout <<"Enter the item number that is being ordered. :";
	cin >> item_select;
	cout <<"Enter the category number for the item being ordered.";
	cin >> item_category;
	cout <<"Enter the quantity being ordered: ";
	cin >> item_quantity;
	cin.ignore();
	cout << "Enter the address information to ship to.";
	address * customer = get_address();
	item * order_item = warehouse.customer_order(item_select,item_category,item_quantity);
	if (order_item == nullptr)
	{
		cout << "Order canceled due to low inventory." << endl;
		delete customer;
		customer = nullptr;
		return nullptr;
	}

	return new order(order_num,order_item,item_quantity,customer);
}
