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
	my_world = new world[1];

	printf("**WELCOME TO ZORK**\n\n");
	printf("Before starting: Comands must be inserted like <action> <item>, if the comand is not recognized nothing will happen.\n\nAlmost all the objects are hidden by some simple object that you will have to move, open, press some button, insert some pasword, etc\n Possible actions: go, open, close, move, pick, drop, stats, equip, unquip, look, help, press, hit, attack, buy, sell.\n\n");

	printf("(For testing combat mode without solving the puzzles you can teleport them using <teleport> + A or B or C or D, once you beat all the monsters you can go back to the initial room (<teleport> + E) to be teleported and face the final boss. I recommend taking some resources first)\n\n"); 

	my_world->CreateWorld();	
	my_world->Check_input();
	my_world->Destroy_World(); 

	//delete[] my_world; 

	getchar();
	return 0;
}