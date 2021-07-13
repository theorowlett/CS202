/* Theo Rowlett
 * CS202 Winter '21 Project 2
 * Calendar_item.h
 * 	Header files for abstract base class calendar_node and derived classes zoom, task, and event.
 */

#include <cstring>
#include <iostream>
#include <iomanip>

#ifndef CALENDAR_ITEM
#define CALENDAR_ITEM

class calendar_node
{
	public:
		calendar_node();
		calendar_node(int a_time, bool a_status);
		calendar_node(const calendar_node & to_copy);
		virtual	~calendar_node();

		calendar_node *& go_next();
		virtual void display()=0;
		virtual void change_item()=0;

		int get_time();
		bool get_status();

	protected:
		calendar_node * next;
		int time;
		bool busy_status;
};

class zoom:public calendar_node
{
	public:
		zoom();
		zoom(const zoom & to_copy);
		~zoom();
		zoom(int id, char * pw, int a_time, bool a_status);

		void display();
		void change_item();
	protected:
		int zoom_id;
		char * zoom_pw;

};

class task:public calendar_node
{
	public:
		task();
		task(bool completion, char * t_name, int a_time, bool a_status);
		task(const task & to_copy);
		~task();

		void display();
		void change_item();
	private:
		bool completion_status;
		char * task_name;
};

class event:public calendar_node
{
	public:
		event();
		event(char * name, int a_time, bool a_status);
		event(const event & to_copy);
		~event();

		void display();
		void change_item();
	private:
		char * event_name;

};

#endif

