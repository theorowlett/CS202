//Theo Rowlett
//string.h
//CS202 Project 3
//
#ifndef STRING
#define STRING

#include <cstring>
#include <iostream>

class String
{
	public:
		String();
		String(char * a_string);
		String(const String & to_copy);
		~String();

		String operator + (const String & a_string) const;
		String& operator = (const String & a_string);
		bool operator == (const String & a_string) const;
		bool operator > (const String & to_compare) const;
		bool operator < (const String & to_copare) const;

		friend std::ostream& operator << (std::ostream& out, const String & a_string);
		friend std::istream& operator >> (std::istream& in, String& a_string);
	private:
		char * string;
};

#endif
