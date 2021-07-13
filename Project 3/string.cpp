#include "string.h"

using namespace std;

String::String():string(nullptr)
{
}

String::String(char * a_string)
{
	string = new char[strlen(a_string)+1];
	strcpy(string,a_string);
}

String::String(const String & to_copy)
{
	if(this!=&to_copy)
	{
		string = new char[strlen(to_copy.string)+1];
		strcpy(string,to_copy.string);
	}
}

String::~String()
{
	if (string)
	{
		delete [] string;
		string = nullptr;
	}
}

String String::operator + (const String & a_string) const
{
	String return_str;
	return_str.string = new char[strlen(string)+strlen(a_string.string)+1];
	strcpy(return_str.string,string);
	strcat(return_str.string,a_string.string);
	return return_str;
}

String& String::operator = (const String & a_string)
{
	if(this!=&a_string)
	{
		if (string)
		{
			delete string;
			string = nullptr;
		}
	string = new char[strlen(a_string.string)+1];
	strcpy(string,a_string.string);
	}
	return *this;
}

bool String::operator == (const String & a_string) const
{
	if (strcmp(this->string,a_string.string)==0)
		return true;
	return false;
}
bool String::operator > (const String & to_compare) const
{
	if (strcmp(string,to_compare.string)>0)
		return true;
	return false;
}

bool String::operator < (const String & to_compare) const
{
	if (strcmp(string,to_compare.string)<0)
		return true;
	return false;
}

ostream& operator << (ostream& out, const String & a_string)
{
	return out << a_string.string;
}

istream& operator >> (std::istream& in, String & a_string)
{
	char a_char[1000];
	in >> a_char;
	a_string = String(a_char);
	//delete a_char;
	//a_char = nullptr;

	return in;
}
