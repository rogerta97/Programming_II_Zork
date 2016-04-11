#include <stdio.h> 
#include <string.h>

#include "world.h"
#include "MemLeaks.h"

//Free exits brakpoint.
//Make a good scanf of the actions. 
//Separate in functions.
//Add entity. 

int main(){
	ReportMemoryLeaks(); 

	world* my_world;
	my_world = new world;

	printf("**WELCOME TO ZORK**\n\nComands must be inserted following (action) (direction/item)\n\n");

	my_world[0].CreateWorld();	
	my_world[0].Check_input();
	my_world[0].Destroy_World(); 

	delete my_world; 

	getchar();
	return 0;
}