#include <stdio.h>

#ifndef _STRINGS_H_
#define	_STRINGS_H_

class String{
public:
	char* string;
	int max_value = 0; 
public:
	String();
	String(const char* str);
	String(char* str);
	String(const String& str);
	~String();

	unsigned int length();
	bool isempty();
	void empty();
	const char* c_str();
	


public:
	bool operator==(const String& str2) const;
	bool operator==(const char* str2) const;
	bool operator!=(const char* str2) const;
	String& operator=(char* str2);
	String& operator=(String*& str2);
};

#endif // !1


