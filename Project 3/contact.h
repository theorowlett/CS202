//Theo Rowlett
//contact.h
//CS202 Project 3
//contact.h: header file for contact. each contact contains a LLL of devices.

#ifndef CONTACT
#define CONTACT

#include "string.h"
#include "device.h"

class Contact
{
	public:
		Contact();
		Contact(const Contact & to_copy);
		Contact(String * a_name);
		Contact(String * a_name, Device * a_device);
		~Contact();
	
		void copy_device(Device * to_copy,Device *& dest);
		void insert(Device * to_copy, Device *& dest);
		void delete_devices(Device *& curr);
		void display();
		void display(Device * curr);
		//void remove_contact(const String * to_remove);

		Contact& operator = (const Contact & a_contact);
		bool operator == (const Contact & a_contact)const;
		bool operator != (const Contact & a_contact)const;
		bool operator > (const Contact & a_contact)const;
		bool operator < (const Contact & a_contact)const;
		Contact operator + (const Contact&)const;
		Contact& operator += (const Contact&);

		Contact *& go_left();
		Contact *& go_right();
		String * return_name()const;
		bool add_email();
		bool add_discord();
		bool add_phone();


	private:
		String * name;
		Device * head;
		Contact * left;
		Contact * right;
};
#endif
