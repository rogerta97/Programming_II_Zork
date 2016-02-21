#include <stdio.h> 
#include <stdlib.h>
#include "Header.h"

int main(){

	//I declared a multidimentional array and assigned a name to each room, then I used a function to move the player.
	//Extra features: I've placed random objects trough the rooms
	//that the player can pick up, once the user exits the house the program will tell the amount of object he has and.

	//after picking an object or not, you must press intro before doing the next move.

	char* house[5][4] = {
		{ "//",             "//",           "//",      "//"},
		{ "//",          "kitchen",       "pantry",    "//"},
		{ "//",         "dinning room",   "bathroom",  "//"},
		{ "//",           "bedroom",        "//",       "//"},
		{ "//",             "//",            "//",      "//"},
	};

	printf("Whitch direction you want to go? (n/s/e/w/q)\n"); 
	printf("You are initially at the dinning room!\n");	

	char* possible_objects[5];			//This is an array of possible objects that can be found.
	possible_objects[0] = "lamp";
	possible_objects[1] = "book";
	possible_objects[2] = "glass";
	possible_objects[3] = "sword";
	possible_objects[4] = "knife";

	int** objects = place_objects();  //place objects to the rooms.
	char* carrying_objects[5]; 
	
	int x_pos = 2, y_pos = 1;
	moving(house, objects, x_pos, y_pos, carrying_objects, possible_objects); //I've placed a wall between the bathroom and the pantry.

	
	free(objects); 
	system("pause"); 
	return 0; 
}