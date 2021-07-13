/* Theo Rowlett
 * CS202 Project 2 Winter 21
 * calendar_item.cpp
 * 	.cpp for abstract base class calendar_node and all derived classes.
 * 	Calendar_node serves as ABC and node class.
 *
 *
 *
 */
#include "calendar_item.h"

using namespace std;

calendar_node::calendar_node():next(nullptr),time(0),busy_status(0)
{
}

calendar_node::calendar_node(int a_time, bool a_status):next(nullptr),time(a_time),busy_status(a_status)
{
}

calendar_node::calendar_node(const calendar_node & to_copy):next(nullptr),time(to_copy.time),busy_status(to_copy.busy_status)
{
}

calendar_node::~calendar_node()
{
}

calendar_node *& calendar_node::go_next()
{
	return next;
}

int calendar_node::get_time()
{
	int a_time = 0;
	cout << "Time(Military Format HHMM: ";
	cin >> a_time;
	if (a_time > 2400 || a_time < 0)
	{
		cout << "Invalid. Time cannot be greater than 2400 or less than 0. Try again." << endl;
		a_time = get_time();
	}
	return a_time;
}

bool calendar_node::get_status()
{
	bool status = false;
	cout << "Status (1 for busy 0 for available): ";
	cin >> status;
	return status;
}


//ZOOM
zoom::zoom():zoom_id(0),zoom_pw(nullptr)
{
}


zoom::zoom(const zoom & to_copy):calendar_node(to_copy)
{
	zoom_id = to_copy.zoom_id;
	zoom_pw = new char[strlen(to_copy.zoom_pw)+1];
	strcpy(zoom_pw,to_copy.zoom_pw);
}

zoom::zoom(int id, char * pw, int a_time, bool a_status):calendar_node(a_time,a_status)
{
	zoom_id = id;
	zoom_pw = new char[strlen(pw)+1];
	strcpy(zoom_pw,pw);
}

zoom::~zoom()
{
	if (zoom_pw)
	{
		delete zoom_pw;
		zoom_pw =  nullptr;
	}
}

void zoom::display()
{
	cout << "Time (HHMM): " << setfill('0') << setw(4) << time << endl;
	cout << "Busy status: " << busy_status << endl;
	cout << "Zoom ID: " << zoom_id << endl;
	cout << "Zoom PW: " << zoom_pw << endl;
}

void zoom::change_item()
{
	char pw[25];
	time = get_time();
	busy_status = get_status();
	cout << "Enter the new Zoom ID:" << endl;
	cin >> zoom_id;
	cout << "Enter the new Zoom password:" << endl;
	cin.getline(pw,25,'\n');
	cin.ignore();
	delete zoom_pw;
	zoom_pw = nullptr;
	zoom_pw = new char[strlen(pw)+1];
	strcpy(zoom_pw,pw);
}


//TASK
task::task():completion_status(0),task_name(nullptr)
{
}

task::task(bool completion,char * t_name, int a_time, bool a_status):calendar_node(a_time,a_status),completion_status(completion)
{
	task_name = new char[strlen(t_name)+1];
	strcpy(task_name,t_name);
}

task::task(const task & to_copy):calendar_node(to_copy),completion_status(to_copy.completion_status)
{
	task_name = new char[strlen(to_copy.task_name)+1];
	strcpy(task_name,to_copy.task_name);
}

task::~task()
{
	if (task_name)
	{
		delete task_name;
		task_name = nullptr;
	}
}

void task::display()
{
	cout << "Time (HHMM): " << setfill('0') << setw(4) << time << endl;
	cout << "Busy status: " << busy_status << endl;
	cout << "Task name: " << task_name << endl;
	
}

void task::change_item()
{
	char name[25];
	time = get_time();
	busy_status = get_status();
	cout << "Enter the new task name:" << endl;
	cin.getline(name,25,'\n');
	cin.ignore();
	delete task_name;
	task_name = nullptr;
	task_name = new char[strlen(name)+1];
	strcpy(task_name,name);
}

//EVENT
event::event():event_name(nullptr)
{
}

event::event(char * name, int a_time, bool a_status):calendar_node(a_time,a_status)
{
	event_name= new char[strlen(name)+1];
	strcpy(event_name,name);
}

event::event(const event & to_copy):calendar_node(to_copy)
{
	event_name= new char[strlen(to_copy.event_name)+1];
	strcpy(event_name,to_copy.event_name);
}

event::~event()
{
	if (event_name)
	{
		delete event_name;
		event_name = nullptr;
	}
}

void event::display()
{
	cout << "Time (HHMM): " << setfill('0') << setw(4) << time << endl;
	cout << "Busy status: " << busy_status << endl;
	cout << "Event name: " << event_name<< endl;
}

void event::change_item()
{
	char name[25];
	time = get_time();
	busy_status = get_status();
	cout <<"Enter the new Event Name:" << endl;
	cin.getline(name,25,'\n');
	cin.ignore();
	delete event_name;
	event_name = nullptr;
	event_name = new char[strlen(name)+1];
	strcpy(event_name,name);
}


