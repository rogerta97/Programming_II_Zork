#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Strings.h"

class Entity{
public: 
	Entity(const char* name2, const char*  desc2) : name(name2), description(desc2){}
	String name; 
	String description; 
};

#endif
