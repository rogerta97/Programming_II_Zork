#include <stdio.h> 
#include <string.h>

#include "world.h"


int main(){

	world* my_world; 
	my_world = new world[1]; 	

	printf("**WELCOME TO ZORK**\n\nComands must be inserted following (action) (direction/item)\n\n");
	int gameploop = 0; 
	my_world[0].CreateWorld();

	
	getchar();
	return 0; 
}