/* Theo Rowlett
 * CS202 Winter 21 Project 2
 * weekly_calendar.cpp
 * 	Contains all code for weekday, weekday_node, and weekly_calendar classes.
 * 	The weekly calendar is a DLL of weekday_node and each weekday has head pointer for list
 * 	of calendar_item. Contains methods for adding, removing, and modifying enties into calendar.
 */

#include "weekly_calendar.h"
#include "calendar_item.h"

using namespace std;

//WEEKDAY
weekday::weekday():head(nullptr),day_of_week(nullptr)
{
}


weekday::weekday(char * day_tocopy):head(nullptr)
{
	day_of_week = new char[strlen(day_tocopy)+1];
	strcpy(day_of_week,day_tocopy);
}

weekday::weekday(const weekday & to_copy)
{
	day_of_week = new char[strlen(to_copy.day_of_week)+1];
	strcpy(day_of_week,to_copy.day_of_week);
}

weekday::~weekday()
{
	if (day_of_week)
	{
		delete day_of_week;
		day_of_week = nullptr;
	}
}
char * weekday::return_day()
{
	return day_of_week;
}
void weekday::add_item(calendar_node * to_add)
{
	add_item(head,to_add);
}

int weekday::add_item(calendar_node *& dest, calendar_node * src)
{
	if (dest == nullptr)
	{
		if (zoom * a_zoom = dynamic_cast<zoom*>(src))
		{
			dest = new zoom(*a_zoom);
			delete a_zoom;
			a_zoom = nullptr;
			return 1;
		}
		if (task * a_task = dynamic_cast<task*>(src))
		{
			dest  = new task(*a_task);
			delete a_task;
			a_task = nullptr;
			return 1;
		}
		if (event * a_event = dynamic_cast<event*>(src))
		{
			dest = new event(*a_event);
			delete a_event;
			a_event = nullptr;
			return 1;
		}
	}
	else
		return add_item(dest->go_next(),src);
	return 0;
}

void weekday::display_all()
{
	if (!head)
		cout << "Nothing on the calendar for " << day_of_week <<"." << endl;
	if (head)
		display_all(head);
}

void weekday::display_all(calendar_node * curr)
{
	if (curr)
	{
		curr->display();
		display_all(curr->go_next());
	}
}

void weekday::clear_day()
{
	if (head)
	{
		clear_day(head->go_next());
		delete head;
		head = nullptr;
	}
}

void weekday::clear_day(calendar_node *& curr)
{
	if (curr)
	{
		clear_day(curr->go_next());
		delete curr;
		curr = nullptr;
	}
}
void weekday::modify_entry()
{
	if (!head)
		cout << "Nothing on the calendar for " << day_of_week <<"." << endl;
	if (head)
		modify_entry(head);
}

void weekday::modify_entry(calendar_node *& curr)
{
	char response;
	if (curr)
	{
		curr->display();
		cout << "Is This the entry you would like to change (y/n)?" << endl;
		cin >> response;
		if (response == 'y')
			curr->change_item();
		if (response == 'n')
			modify_entry(curr->go_next());
		if (response != 'y' && response != 'n')
		{
			cout << "Invalid response." << endl;
			modify_entry(curr);
		}
	}
}

//WEEKDAY NODE
weekday_node::weekday_node():next(nullptr),prev(nullptr)
{
}

weekday_node::weekday_node(char * day_tocopy):weekday(day_tocopy),next(nullptr),prev(nullptr)
{
}

weekday_node::~weekday_node()
{
}

weekday_node *& weekday_node::go_next()
{
	return next;
}

weekday_node *& weekday_node::go_prev()
{
	return prev;
}



//WEEKLY CALENDAR
weekly_calendar::weekly_calendar():head(nullptr),tail(nullptr)
{
}

weekly_calendar::~weekly_calendar()
{
	if (head)
	{
		delete head;
		head = nullptr;
	}
	if (tail)
	{
		delete tail;
		tail = nullptr;
	}
}

void weekly_calendar::add_day(char * day)
{
	if (!head)
	{
		head = new weekday_node(day);
		head->go_prev() = nullptr;
		head->go_next() = nullptr;
	}
	else
		add_day(head,day);
}

void weekly_calendar::add_day(weekday_node *& curr, char * day)
{
	char sunday[] = "Sunday";

	if (curr->go_next() != nullptr)
		add_day(curr->go_next(),day);
	else
	{
		weekday_node * temp = new weekday_node(day);

		temp->go_prev() = curr;
		curr->go_next() = temp;
		
		if (strcmp(day,sunday)==0)
			tail = temp;
	}
}

void weekly_calendar::add_item(calendar_node * to_add, char * day)
{
	if (head)
	{
		if (strcmp(day,head->return_day())==0)
		{
			head->add_item(to_add);
		}
		else
			add_item(head->go_next(),to_add,day);
	}
}

void weekly_calendar::add_item(weekday_node *& curr, calendar_node * to_add, char * day)
{
	if (curr)
	{
		if (strcmp(day,curr->return_day())==0)
		{
			curr->add_item(to_add);
		}
		else
		{
			if (curr == tail)
			{
				cout << "The day you entered is not part of the Gregorian calendar." << endl
					<< "Enter a normal day of the week and try again." << endl;
			}
			else
				add_item(curr->go_next(),to_add,day);
		}
	}
}

void weekly_calendar::display_week()
{
	if (head)
		display_week(head);
}

void weekly_calendar::display_week(weekday_node * curr)
{
	curr->display_all();
	if (curr != tail)
		display_week(curr->go_next());

}

void weekly_calendar::clear_day(char * day)
{
	if (head)
		clear_day(head,day);
}

void weekly_calendar::clear_day(weekday_node *& curr, char * day)
{
	if (curr)
	{
		if (strcmp(day,curr->return_day())==0)
		{
			curr->clear_day();
		}
		else
		{
			if (curr == tail)
			{
				cout << "The day you entered is not part of the Gregorian calendar." << endl
					<< "Enter a normal day of the week and try again." << endl;
			}
			else
				clear_day(curr->go_next(),day);
		}
	}
}

void weekly_calendar::clear_week()
{
	if (head)
		clear_week(head);
}

void weekly_calendar::clear_week(weekday_node *& curr)
{
	if (curr != tail)
		clear_week(curr->go_next());
	curr->clear_day();
}

void weekly_calendar::delete_all()
{
	if (head)
		delete_all(head);
}

void weekly_calendar::delete_all(weekday_node *& curr)
{
	if (curr != tail)
		delete_all(curr->go_next());
	delete curr;
	curr = nullptr;
}

void weekly_calendar::modify_entry(char * day)
{
	if (head)
		modify_entry(head,day);
}

void weekly_calendar::modify_entry(weekday_node *& curr, char * day)
{
	if (curr)
	{
		if (strcmp(day,curr->return_day())==0)
		{
			curr->modify_entry();
		}
		else
		{
			if (curr == tail)
			{
				cout << "The day you entered is not part of the Gregorian calendar." << endl
					<< "Enter a normal day of the week and try again." << endl;
			}
			else
				modify_entry(curr->go_next(),day);
		}
	}
}
