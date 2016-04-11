#ifndef _SIMPLE_OBJECTS_H_
#define _SIMPLE_OBJECTS_H_

class Simple_Objects{
public:
	char* name; 
	bool moved;
	Simple_Objects(bool open, char* name2){
		moved = open; 

		int length = strlen(name2);
		name = new char[length + 1]; 
		strcpy_s(name, length + 1, name2); 
	}
};

#endif