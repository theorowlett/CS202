//Theo Rowlett
//device.h
//CS202 Project 3
//device.h: Header file for devices. Each device type is inherited for ABC Device.

#ifndef DEVICE
#define DEVICE

#include "string.h"

class Device
{
	public:
		Device();
		Device(const Device & to_copy);
		virtual ~Device();
		virtual void display() = 0;
		virtual void change_device() = 0;
		Device *& go_next();
	protected:
		Device * next;
};

class Cell_phone:public Device
{
	public:
		Cell_phone();
		Cell_phone(const Cell_phone & to_copy);
		Cell_phone(String * a_provider, int a_num, bool text, bool pd);
		~Cell_phone();

		Cell_phone& operator = (const Cell_phone & a_phone);  

		void display();
		void change_device();
		int change_num();
		String * change_provider();
		bool change_text();
		bool change_status();
	private:
		String * provider;
		int phone_num;
		bool textable;
		bool paid_status;
};

class Discord:public Device
{
	public:
		Discord();
		Discord(const Discord & to_copy);
		Discord(String * a_name, bool status);
		~Discord();
		
		Discord& operator = (const Discord & a_discord);  

		void display();
		void change_device();
		String * change_username();
		bool change_status();
	private:
		String * username;
		bool nitro_status;
};

class Email:public Device
{
	public:
		Email();
		Email(const Email & to_copy);
		Email(String * a_username,String * a_provider);
		~Email();
		
		Email& operator = (const Email & an_email);  

		void display();
		void change_device();
		String * change_provider();
		String * change_username();
	private:
		String * provider;
		String * username;
};
#endif
