/* Theo Rowlett
 * CS202 Winter 21
 * Project 2
 * Main.cpp: Front End/UI/Load function
 *
 * Known bugs:
 * 	while trying to modify an entry, the program exits. Was unable to reproduce in GDB but it happens with all derived classes.
 *
 */

#include "weekly_calendar.h"
#include "calendar_item.h"

using namespace std;
void load(weekly_calendar *& calendar);
int menu();

int get_time();
bool get_status();
char get_day();

event * add_event();
task * add_task();
zoom * add_zoom();

int main()
{
	const int MAX_CHAR = 8;
	char day[MAX_CHAR];
	int selection = 0;
	weekly_calendar * calendar = new weekly_calendar();
	load(calendar);

	do
	{
		selection = menu();
		switch(selection)
		{
			case 1:
				calendar->display_week();
				break;
			case 2:
				{

					event * a_event = add_event();
					cout << "Enter Weekday (M-Sun):" << endl;
					cin >> day;
					cin.ignore();
					cin.clear();
					calendar->add_item(a_event,day);
				}
				break;
			case 3:
				{
					zoom * a_zoom = add_zoom();
					cout << "Enter Weekday (M-Sun):" << endl;
					cin >> day;
					cin.ignore();
					cin.clear();
					calendar->add_item(a_zoom,day);
				}

				break;
			case 4:
				{
					task * a_task = add_task();
					cout << "Enter Weekday (M-Sun):" << endl;
					cin >> day;
					cin.ignore();
					cin.clear();
					calendar->add_item(a_task,day);
				}
				break;
			case 5:
				{
					cout << "Enter Weekday (M-Sun):" << endl;
					cin >> day;
					cin.ignore();
					cin.clear();
					calendar->clear_day(day);
				}
				break;
			case 6:
				calendar->clear_week();
				break;
			case 7:
				{
					cout << "Enter Weekday (M-Sun):" << endl;
					cin >> day;
					cin.ignore();
					cin.clear();
					calendar->modify_entry(day);
				}
				break;
			case 0:
				break;
			default:
				cout << "Invalid menu input." << endl;
				break;
		}
		cin.clear();
		cin.ignore();
	} while (selection != 0);

	calendar->clear_week();
	calendar->delete_all();
	delete calendar;
	calendar = nullptr;

	return 0;
}


void load(weekly_calendar *& calendar)
{
	char first_day[] = "Monday";
	char second_day[] = "Tuesday";
	char third_day[] = "Wednesday";
	char fourth_day[] = "Thursday";
	char fifth_day[] = "Friday";
	char sixth_day[] = "Saturday";
	char seventh_day[] = "Sunday";
	
	calendar->add_day(first_day);
	calendar->add_day(second_day);
	calendar->add_day(third_day);
	calendar->add_day(fourth_day);
	calendar->add_day(fifth_day);
	calendar->add_day(sixth_day);
	calendar->add_day(seventh_day);
}

int menu()
{
	int selection=0;
	cout << "1." <<'\t' << "Display full calendar." << endl;
	cout << "2." <<'\t' << "Add an event." << endl;
	cout << "3." <<'\t' << "Add a zoom meeting" << endl;
	cout << "4." <<'\t' << "Add a task." << endl;
	cout << "5." <<'\t' << "Clear a day." << endl;
	cout << "6." <<'\t' << "Clear the entire week." << endl;
	cout << "7." <<'\t' << "Change an entry." << endl;
	cout << "0." <<'\t' << "Exit the application." << endl;

	cin >> selection;
	cin.clear();
	cin.ignore();

	return selection;
}

int get_time()
{
	int time = 0;
	cout << "Time(Military Format HHMM: ";
	cin >> time;
	if (time > 2400 || time < 0)
	{
		cout << "Invalid. Time cannot be greater than 2400 or less than 0. Try again." << endl;
		time = get_time();
	}
	return time;
}

bool get_status()
{
	bool status = false;
	cout << "Status (1 for busy 0 for available): ";
	cin >> status;
	return status;
}

event * add_event()
{
	char name[] = "Event Name";
	int time = get_time();
	bool status = get_status();
	
	event * a_event = new event(name,time,status);

	if (a_event)
		return a_event;
	return nullptr;
}

task * add_task()
{
	char name[] = "Task Name";
	int time = get_time();
	bool status = get_status();
	bool completion = 0;
	
	task * a_task = new task(completion,name,time,status);
	if (a_task)
		return a_task;
	return nullptr;
}

zoom * add_zoom()
{
	char pw[] = "hunter2";
	int time = get_time();
	bool status = get_status();
	int zoom_id;

	cout << "Enter the numerical zoom ID" << endl;
	cin >> zoom_id;

	zoom * a_zoom = new zoom(zoom_id,pw,time,status);
	if (a_zoom)
		return a_zoom;
	return nullptr;
}
