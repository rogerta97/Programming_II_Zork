#ifndef _ROOMS_H_
#define _ROOMS_H_

#include <string>

class Rooms : public Entity{
public: 
	Rooms(const char* name2, const char*  desc2) : Entity(name2, desc2){}
	String help;
	int room_numb;

};

#endif // !_ROOMS_H_




