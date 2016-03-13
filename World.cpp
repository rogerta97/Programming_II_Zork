#include <string.h>
#include <iostream> 
#include <stdio.h>

#include "world.h"

#define ROOMS_NUMB 18
#define EXITS_NUMB 17

void world::CreateWorld(){

	Rooms* room;
	room = new Rooms[ROOMS_NUMB];

	//Actually there are 14 rooms, 4 of of them are "corridors" without any item or functionallity
	//they just exist in order to be able to select one of the 3 doors inside a element. 

	//Allocating dinamically the space for the data lines above, then setting the data.
	//Setting names of the rooms:

	strcpy_s((char*)room[0].name, 50, "WEIRD BEDROOM");
	strcpy_s((char*)room[1].name, 50, "FIRE CORRIDOR");
	strcpy_s((char*)room[2].name, 50, "BURNER");
	strcpy_s((char*)room[3].name, 50, "EMPTY ROOM");
	strcpy_s((char*)room[4].name, 50, "OLD DAD ROOM");
	strcpy_s((char*)room[5].name, 50, "WIND CORRIDOR");
	strcpy_s((char*)room[6].name, 50, "OLD MUM ROOM");
	strcpy_s((char*)room[7].name, 50, "STDUYING ROOM");
	strcpy_s((char*)room[8].name, 50, "BIG WINDOW ROOM");
	strcpy_s((char*)room[9].name, 50, "WATER CORRIDOR");
	strcpy_s((char*)room[10].name, 50, "AQUARIUM");
	strcpy_s((char*)room[11].name, 50, "------PISCINA CON PALAS------- ROOM");
	strcpy_s((char*)room[12].name, 50, "LONELY ----BANYERA----");
	strcpy_s((char*)room[13].name, 50, "EARTH CORRIDOR");
	strcpy_s((char*)room[14].name, 50, "--- MINA ---");
	strcpy_s((char*)room[15].name, 50, "BLACK HOLE");
	strcpy_s((char*)room[16].name, 50, "E3");
	strcpy_s((char*)room[17].name, 50, "FINAL BOSS ROOM");

	//Setting descriptions of the rooms:

	strcpy_s((char*)room[0].description, 350, "You are in the middle of a dark room, it seems that the only think you conserve with you is your bed, you wake up in another place and you listen to some sinester music as background.\n");
	strcpy_s((char*)room[1].description, 350, "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n");
	strcpy_s((char*)room[2].description, 350, "In the north of the room there is a fireplace with the fire on, there is a closet on the east and a wall full of old photographies of a unknown family at south.\n");
	strcpy_s((char*)room[3].description, 350, "In this room there is anything but a carpet on the floor, and the high sound hits your ears harder, it seems you'are getting closer to something.\n");
	strcpy_s((char*)room[4].description, 350, "What? This is something familiar for you, you suddently entered into your dad's room and everything is like normally, you left the door at west, on the north there is your dad's bed, on the east there is his closet and there is a TV with his favourite series at the south, there is a strange way made of fuel on the floor.\n");
	strcpy_s((char*)room[5].description, 350, "You are at the end of a corridor, there are 3 doors, one in each wall direction.");
	strcpy_s((char*)room[6].description, 350, "Things don't make sense, now you entered to your old mum's room, lefting the entrance on south, on the north of the room there is a mirror with some make up and a VENTILADOR, in the east there is the bed, but there are some weird MARCAS on the wall.\n");
	strcpy_s((char*)room[7].description, 350, "This room contains a very big desktop with pens, papers and folders at the east, there is anything else. What is this terrible sound...?\n");
	strcpy_s((char*)room[8].description, 350, "You entered to a room lefting the entrance at north, on south there is a window that seems to be closed, on west and east there are 2 other windows, one for each wall.\n");
	strcpy_s((char*)room[9].description, 350, "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n");
	strcpy_s((char*)room[10].description, 350, "You appered into an aquarium, you left the entrance on the west, you can see a PEZERA full of sharks on the north, on the east there is the same PECERA than the one with sharks, but they are separated between a huge metalic wall.\n");
	strcpy_s((char*)room[11].description, 350, "There is a big ------PISCINA CON PALAS------- in the south of the room that seems to be needed for something, at the west the is a table full of buttons.\n");
	strcpy_s((char*)room[12].description, 350, "You are seen the exit of the bathroom on the east, and there is a BANYERA on the north, something strange happens, you start to feel vibrations on the floor and something wakes up from the watter.\n");
	strcpy_s((char*)room[13].description, 350, "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n");
	strcpy_s((char*)room[14].description, 350, "You entered and you suddently appear in a MINA, the door is on the north and the wall on the south seems to be a little bit softer, east and weast walls are full of INSECTOS\n");				//This room will be dark at the begining, the player will need to light up something 
	strcpy_s((char*)room[15].description, 350, "This is such a rude way to go in, but you did it. You left the broken wall at the south and there is a door on the east, at west it seems to be a hole on the wall, the sound is higher when you're closer to the hole.\n");
	strcpy_s((char*)room[16].description, 350, "You entered to a RECIBIDOR with the walls made of stone, the exit is on the south and there is a human figure made of rock on the north of the room.\n");
	strcpy_s((char*)room[17].description, 350, "it seems you teleported to a open space, you are in the middle of an open field in the mountain, the sky is dark and it seems it will rain, but wait... there is something comming? OMG! A huge omnster is comming!");

	//Setting flatten array of integers for the rooms.

	for (int i = 0; i < ROOMS_NUMB; i++){
		room[i].room_numb = i;
	}

	strcpy_s((char*)room[0].help, 100, "It would be fine if you enter some of those doors.\n\n");
	strcpy_s((char*)room[1].help, 100, "There is not much I can tell you, just enter some room.\n\n");
	strcpy_s((char*)room[2].help, 100, "Sometimes is good to --QUITAR BRILLO--.\n\n");
	strcpy_s((char*)room[3].help, 100, "Search something, there is a secret door somewhere.\n\n");
	strcpy_s((char*)room[4].help, 100, "Sometimes is better to light it up!\n\n");
	strcpy_s((char*)room[5].help, 100, "There is not much I can tell you, just enter some room.\n\n");
	strcpy_s((char*)room[6].help, 100, "Search through the personal objects, wind is your friend!\n\n");
	strcpy_s((char*)room[7].help, 100, "Check if someone have wrote something important.\n\n");
	strcpy_s((char*)room[8].help, 100, "Make the wind blow.\n\n");
	strcpy_s((char*)room[9].help, 100, "There is not much I can tell you, just enter some room.\n\n");
	strcpy_s((char*)room[10].help, 100, "You won't do anything here, must to find a way to pull up the wall.\n\n ");
	strcpy_s((char*)room[11].help, 100, "Make things spin!\n\n ");
	strcpy_s((char*)room[12].help, 100, "Face the enemy!\n ");
	strcpy_s((char*)room[13].help, 100, "There is not much I can tell you, just enter some room.\n\n");
	strcpy_s((char*)room[14].help, 100, "Just hit something! But maybe you need... something:)\n\n");
	strcpy_s((char*)room[15].help, 100, "The answer is on the deepness.\n\n");
	strcpy_s((char*)room[16].help, 100, "Attack the stone!\n\n");
	strcpy_s((char*)room[17].help, 100, "Just kill this monster and you will be the final king!\n\n");

	//Setting names of the exits. 

	exits* exit;
	exit = new exits[EXITS_NUMB];

	strcpy_s((char*)exit[0].name, 50, "final boss teleport");
	strcpy_s((char*)exit[1].name, 50, "fire door");
	strcpy_s((char*)exit[2].name, 50, "burner door");
	strcpy_s((char*)exit[3].name, 50, "empty room door");
	strcpy_s((char*)exit[4].name, 50, "old dad door");
	strcpy_s((char*)exit[5].name, 50, "wind door");
	strcpy_s((char*)exit[6].name, 50, "old mum room door");
	strcpy_s((char*)exit[7].name, 50, "studying room door");
	strcpy_s((char*)exit[8].name, 50, "big windor woom door");
	strcpy_s((char*)exit[9].name, 50, "water door");
	strcpy_s((char*)exit[10].name, 50, "aquarium door");
	strcpy_s((char*)exit[11].name, 50, "--piscina con palas-- door");
	strcpy_s((char*)exit[12].name, 50, "--lonely banyera-- door");
	strcpy_s((char*)exit[13].name, 50, "earth corridor");
	strcpy_s((char*)exit[14].name, 50, "__mina__ door");
	strcpy_s((char*)exit[15].name, 50, "black hole room door");
	strcpy_s((char*)exit[16].name, 50, "--recibidor-- door");

	//Setting an array of integers for the exits.

	for (int i = 0; i < EXITS_NUMB; i++){
		exit[i].exit_numb = i;
	}

	//Setting state of the doors. (I made a loop beacuse the case is making all the doors stay open exept one,
	//in the case of the zork isegment that need it, i will assign the status for every room)

	for (int i = 0; i < EXITS_NUMB; i++){
		if (exit[i].exit_numb == 1)
			exit[i].open = false;
		else
			exit[i].open = true;
	}

	//Setting the diestinations of the exits.

	exit[0].destination = 17;
	for (int i = 0; i < EXITS_NUMB - 1; i++){
		exit[i].destination = i;
	}

	//Setting the source room of the exits.

	exit[0].source = 0;
	exit[1].source = 0;
	exit[2].source = 1;
	exit[3].source = 1;
	exit[4].source = 1;
	exit[5].source = 0;
	exit[6].source = 5;
	exit[7].source = 5;
	exit[8].source = 5;
	exit[9].source = 0;
	exit[10].source = 9;
	exit[11].source = 9;
	exit[12].source = 9;
	exit[13].source = 0;
	exit[14].source = 13;
	exit[15].source = 13;
	exit[16].source = 13;

	//Setting the player info.

	player* main_character = new player[1];

	main_character->current_room = 0;


	int quit_marker = 0, comand_numb, move_numb;
	do{
		//This would be the function of SHOWS
		printf("%s\n", room[main_character->current_room].name);
		printf("%s\n", room[main_character->current_room].description);
		//This would be the function of CHEK IMPUTS
		char comand[20];
		char move[20];

		printf(">: ");
		scanf_s("%s %s", &comand, 20, &move, 20);
		printf("\n");

		if ((strcmp("look", comand) == 0) || (strcmp("go", comand) == 0) || (strcmp("quit", comand) == 0) || (strcmp("open", comand) == 0) || (strcmp("close", comand) == 0) || (strcmp("help", comand) == 0)){
			if (strcmp("go", comand) == 0){
				// if the user inserts the comand go: 
				if (strcmp("north", move) == 0){
					// if the user wants to go north
					switch (main_character->current_room){
					case 0:
						if (exit[1].open)
							main_character->current_room = 1;
						else
							printf("There is a closed door there.\n\n");
						break;
					case 1:
						main_character->current_room = 3;
						break;
					case 13:
						main_character->current_room = 15;
						break;
					case 9:
						main_character->current_room = 0;
						break;
					case 11:
						main_character->current_room = 9;
						break;
					case 8:
						main_character->current_room = 5;
						break;
					case 5:
						main_character->current_room = 6;
						break;
					case 14:
						main_character->current_room = 13;
						break;
					}
				}
				else if (strcmp("south", move) == 0){
					//if the user wants to go south
					switch (main_character->current_room){
					case 3:
						main_character->current_room = 1;
						break;
					case 1:
						if (exit[1].open)
							main_character->current_room = 0;
						else
							printf("There is a closed door there.\n\n");
						break;
					case 0:
						main_character->current_room = 9;
						break;
					case 9:
						main_character->current_room = 11;
						break;
					case 6:
						main_character->current_room = 5;
						break;
					case 5:
						main_character->current_room = 8;
						break;
					case 16:
						main_character->current_room = 13;
						break;
					case 13:
						main_character->current_room = 14;
						break;
					}
				}
				else if (strcmp("east", move) == 0){
					//if the user wants to go east
					switch (main_character->current_room){
					case 2:
						main_character->current_room = 1;
						break;
					case 1:
						main_character->current_room = 4;
						break;
					case 0:
						main_character->current_room = 5;
						break;
					case 5:
						main_character->current_room = 7;
						break;
					case 12:
						main_character->current_room = 9;
						break;
					case 15:
						main_character->current_room = 13;
						break;
					case 13:
						main_character->current_room = 0;
						break;
					}
				}

				else if (strcmp("west", move) == 0){
					//if the user wants to go west
					switch (main_character->current_room){
					case 4:
						main_character->current_room = 1;
						break;
					case 1:
						main_character->current_room = 2;
						break;
					case 0:
						main_character->current_room = 13;
						break;
					case 13:
						main_character->current_room = 15;
						break;
					case 10:
						main_character->current_room = 9;
						break;
					case 9:
						main_character->current_room = 12;
						break;
					case 7:
						main_character->current_room = 5;
						break;
					case 5:
						main_character->current_room = 0;
						break;
					}
				}
			}
			char open_direc[10];

			if (strcmp("look", comand) == 0)
				//if the user wants to look
				continue;
			else if (strcmp("help", comand) == 0)
				//if the user wants some help
				printf("%s", room[main_character->current_room].help);
			else if (strcmp("open", comand) == 0){
				//if the user wants to open something
				if (strcmp("door", move) == 0){
					//this is the function to open doors
					printf("What is the direction of the door that you want to open?\n\n");
					printf(">: ");
					scanf_s(" %s", &open_direc, 10);
					printf("\n");
					switch (main_character->current_room){
					case 0:
						if ((strcmp("north", open_direc)) == 0 && exit[1].open == false)
							exit[1].open = true;
						printf("You opened the %s!\n", exit[1].name);
						break;
					case 1:
						if ((strcmp("south", open_direc)) == 0 && exit[1].open == false)
							exit[1].open = true;
						printf("You opened the %s!\n\n", exit[1].name);
						break;
					}
					printf("\n");
				}
				//here will be placed other things that can be opened: "window", "box"...	
			}
			else if (strcmp("close", comand) == 0){
				//if the user wants to close something
				if (strcmp("door", move) == 0){
					//this is the function for closing doors. 
					printf("What is the direction of the door that you want to close?\n\n");
					printf(">: ");
					scanf_s(" %s", &open_direc, 10);
					printf("\n");
					switch (main_character->current_room){
					case 0:
						if ((strcmp("north", open_direc)) == 0 && exit[1].open == true)
							exit[1].open = false;
						printf("You closed the %s!\n\n", exit[1].name);
						break;
					case 1:
						if ((strcmp("south", open_direc)) == 0 && exit[1].open == true)
							exit[1].open = false;
						printf("You closed the %s!\n\n", exit[1].name);
						break;

					}
				}
			}
			else if (strcmp("quit", comand) == 0){
				//if the user wants to quit
				quit_marker = 1;
			}
		}
		else
			printf("I can't understand you.\n\n"); 

		} while (quit_marker == 0);
	
	
		
	
	
}
void world::Show(){

	
}
void world::Chek_input(){
	
}
	




