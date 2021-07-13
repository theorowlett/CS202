//Theo Rowlett
//device.cpp
//CS202 Project 3
//device.cpp: Contains all code for inherited hierarchy of device types.

#include "device.h"

using namespace std;
//DEVICE
Device::Device():next(nullptr)
{
}

Device::Device(const Device & to_copy):next(nullptr)
{
}

Device::~Device()
{
}

Device *& Device::go_next()
{
	return next;
}


//CELL PHONE
Cell_phone::Cell_phone():Device(),provider(nullptr),phone_num(0),textable(false),paid_status(false)
{
}

Cell_phone::Cell_phone(const Cell_phone & to_copy):Device(to_copy),phone_num(to_copy.phone_num),textable(to_copy.textable),paid_status(to_copy.paid_status)
{
	provider = new String(*to_copy.provider);
}

Cell_phone::Cell_phone(String * a_provider, int a_num, bool text, bool pd):phone_num(a_num),textable(text),paid_status(pd)
{
	provider = new String(*a_provider);
}

Cell_phone::~Cell_phone()
{
	if (provider)
	{
		delete provider;
		provider = nullptr;
	}
}

Cell_phone& Cell_phone::operator = (const Cell_phone & a_phone)
{
	if(this!=&a_phone)
	{
		if (provider)
		{
			delete provider;
			provider = nullptr;
		}
		provider = a_phone.provider;	//Deep copy
		phone_num = a_phone.phone_num;
		paid_status = a_phone.paid_status;
		textable = a_phone.textable;
	}
	return *this;
}

void Cell_phone::display()
{
	cout << "Cell Phone: " << phone_num << " Carrier:  " << *provider << " Paid status: ";
	if (paid_status)
		cout << "Paid. Text plan:  ";
	else
		cout <<"Unpaid. Text plan:  ";
	if (textable)
		cout << "Available." << endl;
	else
		cout << "Unavailable." << endl;

}

void Cell_phone::change_device()
{
	display();
	phone_num = change_num();
	provider = change_provider();
	textable = change_text();
	paid_status = change_status();
}

int Cell_phone::change_num()
{
	int number = 0;
	cout << "Enter the new phone number: ";
	cin >> number;
	return number;
}

String * Cell_phone::change_provider()
{
	String * Carrier = new String();
	if (provider)
	{
		delete provider;
		provider = nullptr;
	}
	cout << "Enter the new phone carrier: ";
	cin >> *Carrier;
	return Carrier;
}

bool Cell_phone::change_text()
{
	char selection = 'n';
	cout << "Does this line have an active text message plan(y/n)? ";
	cin >> selection;
	if (selection == 'y')
		return true;
	return false;
}

bool Cell_phone::change_status()
{
	char selection = 'n';
	cout << "Is this account balance paid(y/n)? ";
	cin >> selection;
	if (selection == 'y')
		return true;
	return false;
}


//DISCORD
Discord::Discord():Device(),username(nullptr),nitro_status(false)
{
}

Discord::Discord(const Discord & to_copy):Device(to_copy),nitro_status(to_copy.nitro_status)
{
	username = new String(*to_copy.username);
}

Discord::Discord(String * a_name, bool status):Device(),nitro_status(status)
{
	username = new String(*a_name);
}

Discord::~Discord()
{
	if (username)
	{
		delete username;
		username = nullptr;
	}
}

Discord& Discord::operator = (const Discord & a_discord)
{
	if(this!=&a_discord)
	{
		if (username)
		{
			delete username;
			username = nullptr;
		}
		username = a_discord.username;	//Deep copy
		nitro_status = a_discord.nitro_status;
	}
	return *this;

}
void Discord::display()
{
	cout << "Discord: " << *username << " Nitro status: ";
	if (nitro_status)
		cout <<"Nitro member." << endl;
	else
		cout<< "Regular member." << endl;
}

void Discord::change_device()
{
	display();
	username =change_username();
	nitro_status = change_status();
}

String * Discord::change_username()
{
	String * new_name = new String();
	if (username)
	{
		delete username;
		username = nullptr;
	}
	cout << "Enter the new username: ";
	cin >> *new_name;
	return new_name;
}

bool Discord::change_status()
{
	char selection;
	cout << "Is this user a nitro member(y/n)? ";
	cin >> selection;
	if (selection == 'y')
		return true;
	return false;
}


//Email
Email::Email():Device(),provider(nullptr),username(nullptr)
{
}

Email::Email(const Email & to_copy):Device(to_copy)
{
	provider = new String(*to_copy.provider);
	username = new String(*to_copy.username);
}

Email::Email(String * a_username,String * a_provider)
{
	provider = new String(*a_provider);
	username = new String(*a_username);
}

Email::~Email()
{
	if (provider)
	{
		delete provider;
		provider = nullptr;
	}
	if (username)
	{
		delete username;
		username = nullptr;
	}
}

Email& Email::operator = (const Email & an_email)
{
	if(this!=&an_email)
	{
		if (username)
		{
			delete username;
			username = nullptr;
		}
		if (provider)
		{
			delete provider;
			provider = nullptr;
		}
		username = an_email.username;	//Deep copy
		provider = an_email.provider;
	}
	return *this;
}

void Email::display()
{
	cout << "Email: " << *username << "@" << *provider << endl;
}

void Email::change_device()
{
	display();
	username = change_username();
	provider = change_provider();
}
String * Email::change_provider()
{
	String * bing = new String();
	if (provider)
	{
		delete provider;
		provider = nullptr;
	}
	cout << "Enter the new Email provider (ex. yahoo.com): ";
	cin >> *bing;
	return bing;
}

String * Email::change_username()
{
	String * a_name = new String();
	if (username)
	{
		delete username;
		username = nullptr;
	}
	cout << "Enter the new username: ";
	cin >> *a_name;
	return a_name;
}
