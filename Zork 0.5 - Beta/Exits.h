#ifndef _EXITS_H_
#define _EXITS_H_ 

class exits : public Entity{
public:
	exits(const char* name2, const char* desc2) : Entity(name2, desc2){}

	int exit_numb;
	bool open;
	enum dir{ north, south, est, west };
	int source;
	int destination; 
};

#endif


