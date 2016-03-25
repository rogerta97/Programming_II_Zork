#include <string.h>
#include <iostream> 
#include <stdio.h>
#include <string>

#include "world.h"

#define ROOMS_NUMB 18
#define EXITS_NUMB 17

void world::CreateWorld(){

	room = new Rooms[ROOMS_NUMB];

	for (int i = 0; i < ROOMS_NUMB; i++){
		room[i].rooms_entity = new Entity[1]; 
	}

	//Actually there are 14 rooms, 4 of of them are "corridors" without any item or functionallity
	//they just exist in order to be able to select one of the 3 doors inside a element. 

	//Allocating dinamically the space for the data lines above, then setting the data.
	//Setting names of the rooms:

	strcpy_s(room[0].rooms_entity->name, 50, "WEIRD BEDROOM");
	strcpy_s(room[1].rooms_entity->name, 50, "FIRE CORRIDOR");
	strcpy_s(room[2].rooms_entity->name, 50, "BURNER");
	strcpy_s(room[3].rooms_entity->name, 50, "EMPTY ROOM");
	strcpy_s(room[4].rooms_entity->name, 50, "OLD DAD ROOM");
	strcpy_s(room[5].rooms_entity->name, 50, "WIND CORRIDOR");
	strcpy_s(room[6].rooms_entity->name, 50, "OLD MUM ROOM");
	strcpy_s(room[7].rooms_entity->name, 50, "STDUYING ROOM");
	strcpy_s(room[8].rooms_entity->name, 50, "BIG WINDOW ROOM");
	strcpy_s(room[9].rooms_entity->name, 50, "WATER CORRIDOR");
	strcpy_s(room[10].rooms_entity->name, 50, "AQUARIUM");
	strcpy_s(room[11].rooms_entity->name, 50, "STICK CONTAINER ROOM");
	strcpy_s(room[12].rooms_entity->name, 50, "LONELY BATHTUB");
	strcpy_s(room[13].rooms_entity->name, 50, "EARTH CORRIDOR");
	strcpy_s(room[14].rooms_entity->name, 50, "MINE");
	strcpy_s(room[15].rooms_entity->name, 50, "BLACK HOLE");
	strcpy_s(room[16].rooms_entity->name, 50, "DRAWING ROOM");
	strcpy_s(room[17].rooms_entity->name, 50, "FINAL BOSS ROOM");

	//Setting descriptions of the rooms:

	strcpy_s(room[0].rooms_entity->description, 350, "You are in the middle of a dark room, it seems that the only think you conserve with you is your bed, you wake up in another place and you listen to some sinester music as background.\n");
	strcpy_s(room[1].rooms_entity->description, 350, "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n");
	strcpy_s(room[2].rooms_entity->description, 350, "In the north of the room there is a fireplace with the fire on, there is a closet on the east and a wall full of old photographies of a unknown family at south.\n");
	strcpy_s(room[3].rooms_entity->description, 350, "In this room there is anything but a carpet on the floor, and the high sound hits your ears harder, it seems you'are getting closer to something.\n");
	strcpy_s(room[4].rooms_entity->description, 350, "What? This is something familiar for you, you suddently entered into your dad's room and everything is like normally, you left the door at west, on the north there is your dad's bed, on the east there is his closet and there is a TV with his favourite series at the south,\n"); //there is a strange way made of fuel on the floor.\n");
	strcpy_s(room[5].rooms_entity->description, 350, "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n");
	strcpy_s(room[6].rooms_entity->description, 350, "Things don't make sense, now you entered to your old mum's room, lefting the entrance on south, on the north of the room there is a mirror with some make up and a fan, in the east there is the bed, but there are some weird scratches on the wall.\n");
	strcpy_s(room[7].rooms_entity->description, 350, "This room contains a very big desktop with pens, papers and folders at the east, there is anything else. What is this terrible sound...?\n");
	strcpy_s(room[8].rooms_entity->description, 350, "You entered to a room lefting the entrance at north, on south there is a window that seems to be closed, on west and east there are 2 other windows, one for each wall.\n");
	strcpy_s(room[9].rooms_entity->description, 350, "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n");
	strcpy_s(room[10].rooms_entity->description, 350, "You appered into an aquarium, you left the entrance on the west, you can see a fishbowl full of sharks on the north, on the east there is the same fishbowl than the one with sharks, but they are separated between a huge metalic wall.\n");
	strcpy_s(room[11].rooms_entity->description, 350, "There is a big container with sticks inside in the south of the room that seems to be needed for something, at the west the is a table full of buttons.\n");
	strcpy_s(room[12].rooms_entity->description, 350, "You are seen the exit of the bathroom on the east, and there is a bathtub on the north, something strange happens, you start to feel vibrations on the floor and something wakes up from the watter.\n");
	strcpy_s(room[13].rooms_entity->description, 350, "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n");
	strcpy_s(room[14].rooms_entity->description, 350, "You entered and you suddently appear in a mine, the door is on the north and the wall on the south seems to be a little bit softer, east and weast walls are full of insects\n");				//This room will be dark at the begining, the player will need to light up something 
	strcpy_s(room[15].rooms_entity->description, 350, "This is such a rude way to go in, but you did it. You left the broken wall at the south and there is a door on the east, at west it seems to be a hole on the wall, the sound is higher when you're closer to the hole.\n");
	strcpy_s(room[16].rooms_entity->description, 350, "You entered to a drawing room with the walls made of stone, the exit is on the south and there is a human figure made of rock on the north of the room.\n");
	strcpy_s(room[17].rooms_entity->description, 350, "it seems you teleported to a open space, you are in the middle of an open field in the mountain, the sky is dark and it seems it will rain, but wait... there is something comming? OMG! A huge omnster is comming!");

	//Setting flatten array of integers for the rooms.

	for (int i = 0; i < ROOMS_NUMB; i++){
		room[i].room_numb = i;
	}

	strcpy_s(room[0].help, 100, "It would be fine if you enter some of those doors.\n\n");
	strcpy_s(room[1].help, 100, "There is not much I can tell you, just enter some room.\n\n");
	strcpy_s(room[2].help, 100, "Sometimes is good giving watter to your enemies.\n\n");
	strcpy_s(room[3].help, 100, "Search something, there is a secret door somewhere.\n\n");
	strcpy_s(room[4].help, 100, "Sometimes is better to light it up!\n\n");
	strcpy_s(room[5].help, 100, "There is not much I can tell you, just enter some room.\n\n");
	strcpy_s(room[6].help, 100, "Search through the personal objects, wind is your friend!\n\n");
	strcpy_s(room[7].help, 100, "Check if someone have wrote something important.\n\n");
	strcpy_s(room[8].help, 100, "Make the wind blow.\n\n");
	strcpy_s(room[9].help, 100, "There is not much I can tell you, just enter some room.\n\n");
	strcpy_s(room[10].help, 100, "You won't do anything here, must to find a way to pull up the wall.\n\n ");
	strcpy_s(room[11].help, 100, "Make things spin!\n\n ");
	strcpy_s(room[12].help, 100, "Face the enemy!\n\n ");
	strcpy_s(room[13].help, 100, "There is not much I can tell you, just enter some room.\n\n");
	strcpy_s(room[14].help, 100, "Just hit something! But maybe you need... something:)\n\n");
	strcpy_s(room[15].help, 100, "The answer is on the deepness.\n\n");
	strcpy_s(room[16].help, 100, "Attack the stone!\n\n");
	strcpy_s(room[17].help, 100, "Just kill this monster and you will be the final king!\n\n");

	//Setting names of the exits. 

	exit = new exits[EXITS_NUMB];

	for (int i = 0; i < EXITS_NUMB; i++){
		exit[i].exits_entity = new Entity[1];
	}

	strcpy_s(exit[0].exits_entity->name, 50, "final boss teleport");
	strcpy_s(exit[1].exits_entity->name, 50, "fire door");
	strcpy_s(exit[2].exits_entity->name, 50, "burner door");
	strcpy_s(exit[3].exits_entity->name, 50, "empty room door");
	strcpy_s(exit[4].exits_entity->name, 50, "old dad door");
	strcpy_s(exit[5].exits_entity->name, 50, "wind door");
	strcpy_s(exit[6].exits_entity->name, 50, "old mum room door");
	strcpy_s(exit[7].exits_entity->name, 50, "studying room door");
	strcpy_s(exit[8].exits_entity->name, 50, "big window room door");
	strcpy_s(exit[9].exits_entity->name, 50, "water door");
	strcpy_s(exit[10].exits_entity->name, 50, "aquarium door");
	strcpy_s(exit[11].exits_entity->name, 50, "container stick door");
	strcpy_s(exit[12].exits_entity->name, 50, "lonely bathtub door");
	strcpy_s(exit[13].exits_entity->name, 50, "earth corridor");
	strcpy_s(exit[14].exits_entity->name, 50, "mine door");
	strcpy_s(exit[15].exits_entity->name, 50, "black hole room door");
	strcpy_s(exit[16].exits_entity->name, 50, "drawing room door");

	//Setting the description of the exits. 

	strcpy_s(exit[0].exits_entity->description, 350, "this is a door that suddently apeared on the wall, it has a blue electric color");
	strcpy_s(exit[1].exits_entity->description, 350, "this door adresses to a long corridor with some torches on the wall.");
	strcpy_s(exit[2].exits_entity->description, 350, "this is a door made of metal girds.");
	strcpy_s(exit[3].exits_entity->description, 350, "it's a varnished brown woden door.");
	strcpy_s(exit[4].exits_entity->description, 350, "this is like your dad's old room door, white wood door.");
	strcpy_s(exit[5].exits_entity->description, 350, "this door adresses to a long corridor with some windows on the wall.");
	strcpy_s(exit[6].exits_entity->description, 350, "this is like your mum's old room door, white wood door.");
	strcpy_s(exit[7].exits_entity->description, 350, "this is a dor with a note on it, silence!");
	strcpy_s(exit[8].exits_entity->description, 350, "this is a normal metalic door.");
	strcpy_s(exit[9].exits_entity->description, 350, "this door adresses to a long corridor with waterfall of watter on the each wall.");
	strcpy_s(exit[10].exits_entity->description, 350, "this is a big gate with old used wood.");
	strcpy_s(exit[12].exits_entity->description, 350, "this is a gate maded of blue wood, it has golden door knob");
	strcpy_s(exit[13].exits_entity->description, 350, "this door adresses to a long corridor with tha walls made of stone.");
	strcpy_s(exit[14].exits_entity->description, 350, "this is a tiny door maded by the holes of the stones on the wall.");
	strcpy_s(exit[15].exits_entity->description, 350, "this is a door with a hole on the middle!");
	strcpy_s(exit[16].exits_entity->description, 350, "this is an elegant door, tipical of luxury drawing rooms");

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
	for (int i = 1; i < EXITS_NUMB - 1; i++){
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

	main_character = new player[1];

	main_character->current_room = 0;

	//Here is printed the information of the character

	printf("%s\n", room[main_character->current_room].rooms_entity->name);
	printf("%s\n", room[main_character->current_room].rooms_entity->description);

}

void world::Chek_input(){
	int gameloop = 0;
	do{
		char comand[20];
		char move[20];

		bool action_done = false;
		bool& ref_move_permision = action_done;  //this exist in order to show the description just when the user can move, sometimets he makes and action but he don't move! 
		bool moved = false;
		bool& ref_moved = moved; //this variable holded by reference that exist in order to not show the description everytime the player inserts a command, just when the player changes of room. 

		printf(">: ");

		scanf_s("%s", &comand, 20);
		if (strcmp("go", comand) != 0 && strcmp("open", comand) != 0 && strcmp("close", comand) != 0){		
			if (strcmp("quit", comand) == 0){
				//if the user wants to quit
				gameloop = 1;
				action_done = true;
			}
			else if (strcmp("help", comand) == 0)
				//if the user wants some help
				printf("%s", room[main_character->current_room].help);
			else if (strcmp("look", comand) == 0)
				//if the user wants to look
				printf("%s", room[main_character->current_room].description);
			else
				printf("\nI don't undestrand you, insert comands like <action> <direction/item>\n\n");		
		}
		else{
			scanf_s("%s", &move, 20);

			printf("\n");
			char open_direc[10];
			if (strcmp("go", comand) == 0)
				move_character(move, moved, action_done);
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
						if ((strcmp("north", open_direc)) == 0 && exit[1].open == false){
							exit[1].open = true;
							action_done = true;
						}
						printf("You opened the %s!\n\n", exit[1].exits_entity->name);
						break;
					case 1:
						if ((strcmp("south", open_direc)) == 0 && exit[1].open == false){
							exit[1].open = true;
							action_done = true;
						}
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
						if ((strcmp("north", open_direc)) == 0 && exit[1].open == true) {
							exit[1].open = false;
							action_done = true;
						}
						printf("You closed the %s!\n\n", exit[1].exits_entity->name);

						break;
					case 1:
						if ((strcmp("south", open_direc)) == 0 && exit[1].open == true) {
							exit[1].open = false;
							action_done = true;
						}
						printf("You closed the %s!\n\n", exit[1].name);
						break;
					}
				}
			}
			else
				printf("I can't understand you.\n\n");
			if (moved == true){
				printf("%s\n", room[main_character->current_room].rooms_entity->name);
				printf("%s\n", room[main_character->current_room].rooms_entity->description);
			}
			else if (action_done == false)
				printf("There is any door on that direction, just a wall!");
		}
	} while (gameloop == 0); 
}

void world::Destroy_World(){

	for (int i = ROOMS_NUMB - 1; i >= 0; i--){
		delete room[i].rooms_entity;
	}

	delete room; 

	for (int i = EXITS_NUMB - 1; i >= 0; i--){
		delete exit[i].exits_entity;
	}

	delete exit; 
	delete main_character; 
}

void world::move_character(const char* move, bool& moved, bool& permission){
	// if the user inserts the comand go: 
	if (strcmp("north", move) == 0){
		// if the user wants to go north
		switch (main_character->current_room){
		case 0:
			permission = true;
			if (exit[1].open){
				permission = true;
				main_character->current_room = 1;
				moved = true; 
			}		
			else
				printf("There is a closed door there.\n\n");
			break;
		case 1:
			permission = true;
			main_character->current_room = 3;
			moved = true;
			break;
		case 13:
			permission = true;
			main_character->current_room = 15;
			moved = true;
			break;
		case 9:
			permission = true;
			main_character->current_room = 0;
			moved = true;
			break;
		case 11:
			permission = true;
			main_character->current_room = 9;
			moved = true;
			break;
		case 8:
			permission = true;
			main_character->current_room = 5;
			moved = true;
			break;
		case 5:
			permission = true;
			main_character->current_room = 6;
			moved = true;
			break;
		case 14:
			permission = true;
			main_character->current_room = 13;
			moved = true;
			break;
		}
	}
	else if (strcmp("south", move) == 0){
		//if the user wants to go south
		switch (main_character->current_room){
		case 3:
			permission = true;
			main_character->current_room = 1;
			break;
		case 1:
			permission = true;
			if (exit[1].open){
				main_character->current_room = 0;
				moved = true;
			}				
			else
				printf("There is a closed door there.\n\n");
			break;
		case 0:
			permission = true;
			main_character->current_room = 9;
			moved = true;
			break;
		case 9:
			permission = true;
			main_character->current_room = 11;
			moved = true;
			break;
		case 6:
			permission = true;
			main_character->current_room = 5;
			moved = true;
			break;
		case 5:
			permission = true;
			main_character->current_room = 8;
			moved = true;
			break;
		case 16:
			permission = true;
			main_character->current_room = 13;
			moved = true;
			break;
		case 13:
			permission = true;
			main_character->current_room = 14;
			moved = true;
			break;
		}
	}
	else if (strcmp("east", move) == 0){
		//if the user wants to go east
		switch (main_character->current_room){
		case 2:
			permission = true;
			main_character->current_room = 1;
			moved = true;
			break;
		case 1:
			permission = true;
			main_character->current_room = 4;
			moved = true;
			break;
		case 0:
			permission = true;
			main_character->current_room = 5;
			moved = true;
			break;
		case 5:
			permission = true;
			main_character->current_room = 7;
			moved = true;
			break;
		case 12:
			permission = true;
			main_character->current_room = 9;
			moved = true;
			break;
		case 15:
			permission = true;
			main_character->current_room = 13;
			moved = true;
			break;
		case 13:
			permission = true;
			main_character->current_room = 0;
			moved = true;
			break;
		}
	}

	else if (strcmp("west", move) == 0){
		//if the user wants to go west
		switch (main_character->current_room){
		case 4:
			permission = true;
			main_character->current_room = 1;
			moved = true;
			break;
		case 1:
			permission = true;
			main_character->current_room = 2;
			moved = true;
			break;
		case 0:
			permission = true;
			main_character->current_room = 13;
			moved = true;
			break;
		case 13:
			permission = true;
			main_character->current_room = 15;
			moved = true;
			break;
		case 10:
			permission = true;
			main_character->current_room = 9;
			moved = true;
			break;
		case 9:
			permission = true;
			main_character->current_room = 12;
			moved = true; 
			break;
		case 7:
			permission = true;
			main_character->current_room = 5;
			moved = true;
			break;
		case 5:
			permission = true; 
			main_character->current_room = 0;
			moved = true;
			break;
		}
	}
}
