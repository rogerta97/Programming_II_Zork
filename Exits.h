#ifndef _EXITS_H_
#define _EXITS_H_ 


class exits : public Entity{
public:
	int exit_numb;
	bool open;
	enum dir{ north, south, est, west };
	int source;
	int destination;
public:
	Entity* exits_entity; 
};

#endif


