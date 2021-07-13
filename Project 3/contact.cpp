/*
 * Theo Rowlett
 * CS202 Winter '21
 * Project 3
 * Contact.cpp - each contact is a node in the BST, and each contact contains a head pointer to a LLL of devices.
 */

#include "contact.h"

using namespace std;

Contact::Contact():name(nullptr),head(nullptr),left(nullptr),right(nullptr)
{
}

Contact::Contact(const Contact & to_copy):left(nullptr),right(nullptr)
{
	head = nullptr;
	if (&to_copy.name != nullptr)
	{
		name = new String(*to_copy.name);
		if (&to_copy.head != nullptr)
			copy_device(to_copy.head,head);
	}
	else
	{
		name = nullptr;
		head = nullptr;
	}
}

Contact::Contact(String * a_name):head(nullptr),left(nullptr),right(nullptr)
{
	if (a_name)
		name = new String(*a_name);
}

Contact::Contact(String * a_name, Device * a_device):left(nullptr),right(nullptr)
{
	if (a_name)
		name = new String(*a_name);

	if (a_device)
		copy_device(a_device,head);
}

Contact::~Contact()
{
	if (name)
	{ 
		delete name;
		name = nullptr;
	}
	if (head)
		delete_devices(head);
}

void Contact::copy_device(Device * to_copy,Device *& dest)
{
	if (!dest)
	{
		if (Cell_phone * a_phone = dynamic_cast<Cell_phone*>(to_copy))
		{
			dest = new Cell_phone(*a_phone);
		}
		else if(Discord * a_dis = dynamic_cast<Discord*>(to_copy))
		{
			dest = new Discord(*a_dis);
		}
		else if(Email * an_email = dynamic_cast<Email*>(to_copy))
		{
			dest = new Email(*an_email);
		}
	}
	if (to_copy->go_next())
		copy_device(to_copy->go_next(),dest->go_next());
}

void Contact::insert(Device * to_copy,Device *& dest)
{
	if (dest!=nullptr)
		insert(to_copy,dest->go_next());
	else
	{
		if (Cell_phone * a_phone = dynamic_cast<Cell_phone*>(to_copy))
		{	
			dest = new Cell_phone(*a_phone);
		}
		else if(Discord * a_dis = dynamic_cast<Discord*>(to_copy))
		{
			dest = new Discord(*a_dis);
		}
		else if(Email * an_email = dynamic_cast<Email*>(to_copy))
		{
			dest = new Email(*an_email);
		}
	}
}



void Contact::delete_devices(Device *& curr)
{
	if (curr->go_next())
		delete(curr->go_next());
	delete curr;
	curr = nullptr;
}

void Contact::display()
{
	if (name)
	{
		cout << "Name: " << *name << endl;
		if (head)
			display(head);
	}
	else
		cout << "No one by that name!" << endl;
}

void Contact::display(Device * curr)
{
	curr->display();
	if (curr->go_next())
		display(curr->go_next());
}

Contact& Contact::operator = (const Contact & a_contact)
{

	if (this != &a_contact)
	{
		if (name)
		{
			delete name;
			name = nullptr;
		}
		if (head)
			delete_devices(head);

		name = new String(*a_contact.name);
		copy_device(a_contact.head,head);
	}
	return *this;
}


bool Contact::operator == (const Contact & a_contact)const
{
	if (&a_contact.name == nullptr || &name == nullptr)
		return false;
	if (*name == *a_contact.name)
		return true;
	return false;
}

bool Contact::operator != (const Contact & a_contact)const
{
	if (*name == *a_contact.name)
		return false;
	return true;
}

bool Contact::operator > (const Contact & a_contact)const
{
	if (*name > *a_contact.name)
		return true;
	return false;
}

bool Contact::operator < (const Contact & a_contact)const
{
	if (*name < *a_contact.name)
		return true;
	return false;
}

Contact Contact::operator + (const Contact& a_contact)const
{
	Contact return_contact;
	return return_contact;
}

Contact& Contact::operator += (const Contact& a_contact)
{
	*name = *a_contact.name + *name;
	copy_device(a_contact.head,head);
	return *this;
}

Contact *& Contact::go_left()
{
	return left;
}

Contact *& Contact::go_right()
{
	return right;
}

bool Contact::add_email()
{
	String * provider = new String();
	String * username = new String();
	
	cout << "Enter the provider (Ex. google.com): ";
	cin >> * provider;
	cout << "Enter the username: ";
	cin >> * username;
	Email * a_email = new Email(username,provider);
	delete username;
	username = nullptr;
	delete provider;
	provider = nullptr;
	insert(a_email,head);
	delete a_email;
	a_email = nullptr;
	return true;
}

bool Contact::add_discord()
{
	String * username = new String();
	bool status;
	char selection;

	cout <<"Enter the Discord username: ";
	cin >> * username;
	cout <<"Are they a paid Nitro member(y/n): ";
	cin >> selection;
	if (selection!='y' && selection!='n')
	{
		delete username;
		username = nullptr;
		return false;
	}
	if (selection== 'y')
		status = true;
	else
		status = false;
	Discord * a_dis = new Discord(username,status);
	delete username;
	username = nullptr;
	display(a_dis);
	insert(a_dis,head);
	delete a_dis;
	a_dis = nullptr;
	return true;
}

bool Contact::add_phone()
{
	String * provider = new String();
	int phone_num;
	bool textable;
	bool status;
	char selection;

	cout << "Enter your provider (Ex. T-Mobile): ";
	cin >> * provider;
	cout << "Enter the 7  digit (no area code) phone number, only numbers: ";
	cin >> phone_num;
	cout << "Does this person have a text message plan? (y/n)";
	cin >> selection;
	if (selection!='y' && selection!='n')
	{
		delete provider;
		provider = nullptr;
		return false;
	}
	if (selection== 'y')
		textable = true;
	else
		textable = false;
	cout << "Have they paid their bill (y/n)? ";
	cin >> selection;
	if (selection!='y' && selection!='n')
	{
		delete provider;
		provider = nullptr;
		return false;
	}
	if (selection== 'y')
		status = true;
	else 
		status = false;
	Cell_phone * a_phone = new Cell_phone(provider,phone_num,textable,status);
	delete provider;
	provider = nullptr;
	insert(a_phone,head);
	delete a_phone;
	a_phone = nullptr;
	return true;
}

String * Contact::return_name()const
{
	return name;
}

