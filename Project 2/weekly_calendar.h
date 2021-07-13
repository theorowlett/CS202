/* Theo Rowlett
 * CS202 Project 2 Winter '21
 * weekly_calendar.h
 * 	Header file containing weekday, weekday_node, weekly_calendar classses
 * 	Weekly_calendar is DLL of weekday_nodes, weekday contains head pointer for calendar_node
 */
#ifndef CALENDAR
#define CALENDAR

#include "calendar_item.h"

class weekday
{
	public:
		weekday();
		weekday(char * day_tocopy);
		weekday(const weekday & to_copy);
		~weekday();
		
		char * return_day();

		void add_item(calendar_node * to_add);
		int add_item(calendar_node *& dest, calendar_node * src);

		void display_all();
		void display_all(calendar_node * curr);

		void clear_day();
		void clear_day(calendar_node *& curr);

		void modify_entry();
		void modify_entry(calendar_node *& curr);

	protected:
		calendar_node * head;
		char * day_of_week;
};

class weekday_node : public weekday
{
	public:

		weekday_node();
		weekday_node(char * day_tocopy);
		~weekday_node();
		

		weekday_node *& go_next();
		weekday_node *& go_prev();
	private:
		weekday_node * next;
		weekday_node * prev;
};

class weekly_calendar
{
	public:
		weekly_calendar();
		//weekly_calendar(const weekly_calendar & to_copy);
		~weekly_calendar();
		//The add_day functinos initialize loading of calendar
		void add_day(char * day);
		void add_day(weekday_node *& curr, char * day);
		//add_item is used to populate the calendar
		void add_item(calendar_node * to_add, char * day);
		void add_item(weekday_node *& curr, calendar_node * to_add, char * day);
		//This function displays the entire week.
		void display_week();
		void display_week(weekday_node * curr);
		//This funcation clears the entire day.
		void clear_day(char * day);
		void clear_day(weekday_node *& curr, char * day);
		//Clears the entire week
		void clear_week();
		void clear_week(weekday_node *& curr);
		//Deletes everything, used upon exit for memory leaks
		void delete_all();
		void delete_all(weekday_node *& curr);
		
		void modify_entry(char * day);
		void modify_entry(weekday_node *& curr, char * day);

	private:
		weekday_node * head;
		weekday_node * tail;
};

#endif
