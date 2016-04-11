#include <string.h>
#include <iostream> 
#include <stdio.h>
#include <string>

#include "world.h"

//Quan faig look pr exemple pot ser agafant 1 o 2 strings. 
//When droping objects do i need to change the prinf of the room description? if i make a list of objects the game may not be so fun. 

#define ROOMS_NUMB 18
#define EXITS_NUMB 17
#define ITEMS_NUMB 4
#define SIMPLE_NUMB 5
#define MAX_OBJECTS 10
#define _CRT_SECURE_NO_WARNINGS_
using namespace std; 

// Simple objects are those that are needed for advancing the game and just need to be true or false, like a on or off generator, a on or off fireplace, check if the user moved the carpet...
// 0:glass 1:Key 2:matchstick 3:Sword

void world::CreateWorld(){

	//Actually there are 14 rooms, 4 of of them are "corridors" without any item or functionallity
	//they just exist in order to be able to select one of the 3 doors inside a element. 

	room[0] = new Rooms("WEIRD BEDROOM", "You are in the middle of a dark room, it seems that the only think you conserve with you is your bed, you wake up in another place and you listen to some sinester music as background.\n");
	room[1] = new Rooms("FIRE CORRIDOR", "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n"); 
	room[2] = new Rooms("BURNER", "In the north of the room there is a fireplace with the fire on, there is a shelving on the west and a wall full of old photographies of a unknown family at south.\n"); 
	room[3] = new Rooms("EMPTY ROOM", "In this room there is anything but a carpet on the floor, and the high sound hits your ears harder, it seems you'are getting closer to something.\n"); 
	room[4] = new Rooms("OLD DAD ROOM", "What ? This is something familiar for you, you suddently entered into your dad's room and everything is like normally, you left the door at west, on the north there is your dad's bed, on the east there is his closet and there is a TV with his favourite series at the south, there is a strange way made of fuel on the floor.\n"); 
	room[5] = new Rooms("WIND CORRIDOR", "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n");
	room[6] = new Rooms("OLD MUM ROOM", "Things don't make sense, now you entered to your old mum's room, lefting the entrance on south, on the north of the room there is a mirror with some make up and a fan, in the east there is the bed, but there are some weird scratches on the wall.\n"); 
	room[7] = new Rooms("STDUYING ROOM", "This room contains a very big desktop with pens, papers and folders at the east, there is anything else. What is this terrible sound...?\n");
	room[8] = new Rooms("BIG WINDOW ROOM", "You entered to a room lefting the entrance at north, on south there is a window that seems to be closed, on west and east there are 2 other windows, one for each wall.\n");
	room[9] = new Rooms("WATER CORRIDOR", "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n");
	room[10] = new Rooms("AQUARIUM", "You appered into an aquarium, you left the entrance on the west, you can see a fishbowl full of sharks on the north, on the east there is the same fishbowl than the one with sharks, but they are separated between a huge metalic wall.\n");
	room[11] = new Rooms("STICK CONTAINER ROOM", "There is a big container with sticks inside in the south of the room that seems to be needed for something, at the west the is a table full of buttons.\n");
	room[12] = new Rooms("LONELY BATHTUB", "You are seen the exit of the bathroom on the east, and there is a bathtub on the north, something strange happens, you start to feel vibrations on the floor and something wakes up from the watter.\n");
	room[13] = new Rooms("EARTH CORRIDOR", "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n");
	room[14] = new Rooms("MINE", "You entered and you suddently appear in a mine, the door is on the north and the wall on the south seems to be a little bit softer, east and weast walls are full of insects\n");
	room[15] = new Rooms("BLACK HOLE", "This is such a rude way to go in, but you did it. You left the broken wall at the south and there is a door on the east, at west it seems to be a hole on the wall, the sound is higher when you're closer to the hole.\n");
	room[16] = new Rooms("DRAWING ROOM", "You entered to a drawing room with the walls made of stone, the exit is on the south and there is a human figure made of rock on the north of the room.\n");
	room[17] = new Rooms("FINAL BOSS ROOM", "it seems you teleported to a open space, you are in the middle of an open field in the mountain, the sky is dark and it seems it will rain, but wait... there is something comming? OMG! A huge omnster is comming!\n");
	
	//Setting flatten array of integers for the rooms.
	for (int i = 0; i < ROOMS_NUMB; i++){
		room[i]->room_numb = i; 
	}

	//Setting the help. 
	room[0]->help.string = "It would be fine if you enter some of those doors.\n\n";
	room[1]->help.string = "There is not much I can tell you, just enter some room.\n\n";
	room[2]->help.string = "Sometimes is good giving watter to your enemies.\n\n";
	room[3]->help.string = "Search something, there is a secret door somewhere.\n\n";
	room[4]->help.string = "Sometimes is better to light it up!\n\n"; 
	room[5]->help.string = "There is not much I can tell you, just enter some room.\n\n"; 
	room[6]->help.string = "Search through the personal objects, wind is your friend!\n\n"; 
	room[7]->help.string = "Check if someone have wrote something important.\n\n"; 
	room[8]->help.string = "Make the wind blow.\n\n"; 
	room[9]->help.string = "There is not much I can tell you, just enter some room.\n\n"; 
	room[10]->help.string = "You won't do anything here, must to find a way to pull up the wall.\n\n ";
	room[11]->help.string = "Make things spin!\n\n ";
	room[12]->help.string = "Face the enemy!\n\n ";
	room[13]->help.string = "There is not much I can tell you, just enter some room.\n\n";
	room[14]->help.string = "Just hit something! But maybe you need... something:)\n\n";
	room[15]->help.string = "The answer is on the deepness.\n\n";
	room[16]->help.string = "Attack the stone!\n\n";
	room[17]->help.string = "Just kill this monster and you will be the final king!\n\n";

	//Setting names of the exits with a constructor. 

	exit[0] = new exits("final boss teleport", "this is a door that suddently apeared on the wall, it has a blue electric color"); 
	exit[1] = new exits("fire door", "this door adresses to a long corridor with some torches on the wall.");
	exit[2] = new exits("burner door", "this is a door made of metal girds.");
	exit[3] = new exits("empty room door", "it's a varnished brown woden door.");
	exit[4] = new exits("old dad door" , "this is like your dad's old room door, white wood door.");
	exit[5] = new exits("wind door" , "this door adresses to a long corridor with some windows on the wall.");
	exit[6] = new exits("old mum room door" , "this is like your mum's old room door, white wood door.");
	exit[7] = new exits("studying room door" , "this is a dor with a note on it, silence!");
	exit[8] = new exits("big window room door", "this is a normal metalic door.");
	exit[9] = new exits("water door", "this door adresses to a long corridor with waterfall of watter on the each wall.");
	exit[10] = new exits("aquarium door", "this is a big gate with old used wood.");
	exit[11] = new exits("container stick door" , "this is a door that suddently apeared on the wall, it has a blue electric color");
	exit[12] = new exits("lonely bathtub door" , "this is a gate maded of blue wood, it has golden door knob");
	exit[13] = new exits("earth corridor" , "this door adresses to a long corridor with tha walls made of stone.");
	exit[14] = new exits("mine door", "this is a tiny door maded by the holes of the stones on the wall.");
	exit[15] = new exits("black hole room door", "this is a door with a hole on the middle!");
	exit[16] = new exits("drawing room door" , "this is an elegant door, tipical of luxury drawing rooms");

	//Setting an array of integers for the exits.

	for (int i = 0; i < EXITS_NUMB; i++){
		exit[i]->exit_numb = i;
	}

	//Setting state of the doors. (I made a loop beacuse the case is making all the doors stay open exept one,
	//in the case of the zork isegment that need it, i will assign the status for every room)

	for (int i = 0; i < EXITS_NUMB; i++){
		if (exit[i]->exit_numb == 1)
			exit[i]->open = false;
		else
			exit[i]->open = true;
	}

	//Setting the diestinations of the exits.

	exit[0]->destination = 17;
	for (int i = 1; i < EXITS_NUMB - 1; i++){
		exit[i]->destination = i;
	}

	//Setting the source room of the exits.

	exit[0]->source = 0;
	exit[1]->source = 0;
	exit[2]->source = 1;
	exit[3]->source = 1;
	exit[4]->source = 1;
	exit[5]->source = 0;
	exit[6]->source = 5;
	exit[7]->source = 5;
	exit[8]->source = 5;
	exit[9]->source = 0;
	exit[10]->source = 9;
	exit[11]->source = 9;
	exit[12]->source = 9;
	exit[13]->source = 0;
	exit[14]->source = 13;
	exit[15]->source = 13;
	exit[16]->source = 13;

	//Setting the player info.

	main_character = new player;

	main_character->current_room = 0;
	main_character->weapon = -1;
	main_character->card_hability = -1; 
	main_character->hp = 100; 
	main_character->defense = 10; 
	main_character->attack = 3; 
	int objects = 0;
	while (objects < MAX_OBJECTS){
		main_character->inventory[objects] = -1;      //we will set -1 for empty object.	
		objects++;
	}	
		
	//Before setting the items, we first set the simple objects status. 
	simple_obj[0] = new Simple_Objects(false, "shelving");
	simple_obj[1] = new Simple_Objects(false, "fireplace");
	simple_obj[2] = new Simple_Objects(false, "drawer");
	simple_obj[3] = new Simple_Objects(false, "closet");

	//Setting the items information with a constructor. 
	items[0] = new item("glass", "This is a normal glass of watter, but a big one!"); 
	items[1] = new item("key", "This is an old golden key that seems to be the key of some old door too.");
	items[2] = new item("match", "A match! Light it up!");
	items[3] = new item("sword", "What can you do with a sword? ;)");

	//Setting the number of the items and the carriage. 
	for (int i = 0; i < ITEMS_NUMB; i++){
		items[i]->item_num = i;
		items[i]->carried = false; 
	}

	//Setting the special features (attack or shield) if they need it. 
	for (int i = 0; i < ITEMS_NUMB; i++){
		if (items[i]->item_num == 0 || items[i]->item_num == 1 || items[i]->item_num == 2)
			items[i]->attack_plus = items[i]->shield_plus = items[i]->hp_plus = 0;		
	}

	items[3]->attack_plus = 5; items[3]->shield_plus = 0; items[3]->hp_plus = 0;



	//Setting the room where the objects are placed. 
	for (int i = 0; i < ITEMS_NUMB; i++){
		items[i]->item_room = items[i]->Get_Room(i);
	}

	//Here is printed the information of the character
	printf("%s\n", room[main_character->current_room]->name);
	printf("%s\n", room[main_character->current_room]->description);
	

}
void world::Check_input(){
	int gameloop = 0;
	do{	
		char comand[10];
		char move[10];
		
		bool action_done = false;
		bool& ref_move_permision = action_done;  //this exist in order to show the description just when the user can move, sometimets he makes and action but he don't move! 
		bool moved = false;
		bool& ref_moved = moved; //this variable holded by reference that exist in order to not show the description everytime the player inserts a command, just when the player changes of room. 
		static bool object_moved = false; 

		printf(">: ");
		scanf_s("%s", &comand, 10); 

		if (strcmp("go", comand) != 0 && strcmp("open", comand) != 0 && strcmp("close", comand) != 0 && strcmp("move", comand) != 0 && strcmp("teleport", comand) != 0 && strcmp("pick", comand) != 0 && strcmp("drop", comand) != 0 && strcmp("equip", comand) != 0 && strcmp("unequip", comand) != 0){
			if (strcmp("quit", comand) == 0){
				//if the user wants to quit
				gameloop = 1;
				action_done = true;
			}
			else if (strcmp("help", comand) == 0)
				//if the user wants some help
				printf("%s", room[main_character->current_room]->help);
			else if (strcmp("look", comand) == 0)
				//if the user wants to look					   
				printf("%s", room[main_character->current_room]->description.c_str());
			else if (strcmp("inventory", comand) == 0)
				Show_inventory();
			else if (strcmp("stats", comand) == 0)
				printf("HP: %d\nWeapon: %s\nCard hability: In_Developement\nCurrent room: %d\nDamage: %d\nShield: %d\n", main_character->hp, main_character->item_name(main_character->weapon), main_character->current_room, main_character->attack, main_character->defense);
			else
				printf("\nI don't undestrand you, insert comands like <action> <direction/item>\n\n");		
		}
		else{
			scanf_s("%s", &move, 10);
			printf("\n");
			char open_direc[10];
			if (strcmp("teleport", comand) == 0){
				if (strcmp("BURNER", move) == 0){
					main_character->current_room = 2;
					goto Start; 
				}				
				}
			if (strcmp("go", comand) == 0)
				move_character(move, moved, action_done);
			else if (strcmp("open", comand) == 0){
				//if the user wants to open something
				Open_Stuff(move, main_character->current_room, action_done);
				//here will be placed other things that can be opened: "window", "box"...	
			}
			else if (strcmp("close", comand) == 0){
				//if the user wants to close something
				Close_Stuff(move, main_character->current_room, action_done);
				

			}
			else if (strcmp("move", comand) == 0){
				//if the user wants to move something (objects that can be moved and don't have no more functionality are in Simple_Objects class).
				//This function is for printing what happens when de user moves some object: i.e: You moved a carpet and you discovered a trapdoor!
				Move_Simple_Obj(move);
				action_done = true; 
			}
			else if (strcmp("equip", comand) == 0){
				Equip_item(move);
				action_done = true; 
			}
			else if (strcmp("unequip", comand) == 0){
				Unequip_item(move);
				action_done = true;
			}
			else if (strcmp("pick", comand) == 0){
				//if the user wants to pick up something.
				Pick_Item(move, main_character->current_room);
				action_done = true;
			}
			else if (strcmp("drop", comand) == 0){
				Drop_item(move, main_character->current_room);
				action_done = true;
			}
				
			else
				printf("I can't understand you.\n\n");
			if (moved == true){
				Start: 
				printf("%s\n", room[main_character->current_room]->name);
				printf("%s\n", room[main_character->current_room]->description);
			}
			else if (action_done == false)
				printf("There is any door on that direction, just a wall!\n\n");
		}
	} while (gameloop == 0); 
}
void world::Destroy_World(){

	/*delete[] room; 
	delete[] items; 
	delete[] exit; 
	delete[] simple_obj; 
	delete main_character; */
}
void world::move_character(const char* move, bool& moved, bool& permission){
	// if the user inserts the comand go: 
	if (strcmp("north", move) == 0){
		// if the user wants to go north
		switch (main_character->current_room){
		case 0:
			permission = true;
			if (exit[1]->open){
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
			if (exit[1]->open){
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
void world::Pick_Item(const char* item_name, const int current_room){
	for (int i = 0; i < ITEMS_NUMB; i++){
		if ((strcmp(items[i]->name.c_str(), item_name) == 0) && current_room == items[i]->item_room && items[i]->carried == false){
			switch (i){
			case 0:
				items[i]->carried = true;
				printf("You picked up the %s\n\n", item_name);
				Full_inventory(items[i]->item_num); 
				break;
			case 1:
				items[i]->carried = true;
				printf("You picked up the %s\n\n", item_name);
				Full_inventory(items[i]->item_num);
				break;
			case 2:
				items[i]->carried = true;
				printf("You picked up the %s\n\n", item_name);
				Full_inventory(items[i]->item_num);
				break;
			case 3:
				items[i]->carried = true;
				printf("You picked up the %s\n\n", item_name);
				Full_inventory(items[i]->item_num);
				break;

			}
		}	
	}
}
void world::Move_Simple_Obj(const char* move){
	if (strcmp(move, "shelving") == 0&& main_character->current_room == 2){ 
		if (simple_obj[0]->moved == false){
			simple_obj[0]->moved = true;
			printf("You moved the shelving, revealing a little hole on the wall with a glass full of watter!\n\n");
		}
		else{
			printf("You moved the shelving to it's original place.\n\n");
			simple_obj[0]->moved = false;
		}		
	}
	//This need to be changed into-> use glass. 
	else if (strcmp(move, "fireplace") == 0 && main_character->current_room == 2 && simple_obj[1]->moved == false){
		if (simple_obj[1]->moved == false){
			simple_obj[1]->moved = true;
			printf("You turned off the fireplace, there is no burning now so you realize a little gold shining that seems to be a key!\n\n");
		}		
	}
	else if (strcmp(move, "closet") == 0 && main_character->current_room == 4){
		if (simple_obj[3]->moved == false){
			simple_obj[3]->moved = true;
			printf("You opened the closet, and you discovered something you daddy didn't told you, he has a sword on the closet!\n\n");
		}
		else{
			printf("You closed the closet\n\n");
			simple_obj[3]->moved = false;
		}
	}
}
void world::Drop_item(const char* move, int current_room){
	int i = 0;
	while (i < MAX_OBJECTS){
		if (strcmp(main_character->item_name(main_character->inventory[i]), move) == 0){
			items[main_character->inventory[i]]->item_room = main_character->current_room;
			items[main_character->inventory[i]]->carried = false;
			printf("You left the %s!\n\n", main_character->item_name(main_character->inventory[i])); 
			main_character->inventory[i] = -1;
			break;
		}
		i++; 
	}
}
void world::Show_inventory() const{
	int i = 0; 
	bool empty_inv = true;
	while (i < MAX_OBJECTS){
		if (main_character->inventory[i] != -1){
			empty_inv = false;
			printf("- %s.\n", main_character->item_name(main_character->inventory[i])); 
		}
		i++; 
	}
	if (empty_inv == true){
		printf("You inventory is empty!\n"); 
	}
	printf("\n"); 
}
unsigned int world::Carried_Obj_Numb(){
	int obj_numb = 0; 
	for (int i = 0; i < ITEMS_NUMB; i++){
		if (items[i]->carried == true)
			obj_numb++; 
	}
	return obj_numb; 
}
void world::Open_Stuff(const char* move, int current_room, bool& action_done){
	if (strcmp("door", move) == 0){
		//this is the function to open doors
		char open_direc[10]; 
		printf("What is the direction of the door that you want to open?\n\n");
		printf(">: ");
		scanf_s(" %s", &open_direc, 10);
		printf("\n");
		switch (main_character->current_room){
		case 0:
			if ((strcmp("north", open_direc)) == 0 && exit[1]->open == false){
				exit[1]->open = true;
				action_done = true;
			}
			printf("You opened the %s!\n", exit[1]->name);
			break;
		case 1:
			if ((strcmp("south", open_direc)) == 0 && exit[1]->open == false){
				exit[1]->open = true;
				action_done = true;
			}
			printf("You opened the %s!\n\n", exit[1]->name);
			break;
		}
		printf("\n");
	}
	//opening the drawer. 
	else if (strcmp("drawer", move) == 0 && main_character->current_room == 4){
		if (simple_obj[2]->moved == false){
			simple_obj[2]->moved = true;
			printf("You opened the drawer, revealing a matchstick of your daddy!\n\n");
		}
		else
			printf("This is already opened!\n\n");

		action_done = true;
	}
	//opening the closet.
	else if (strcmp(move, "closet") == 0 && main_character->current_room == 4){
		if (simple_obj[3]->moved == false){
			simple_obj[3]->moved = true;
			printf("You opened the closet, and you discovered something you daddy didn't told you, he has a sword on the closet!\n\n");
		}
		else{
			printf("The closet is already opened.\n\n");

		}
		action_done = true;
	}
}
void world::Close_Stuff(const char* move, int current_room, bool& action_done){
	if (strcmp("door", move) == 0){
		char open_direc[10]; 
		//this is the function for closing doors. 
		printf("What is the direction of the door that you want to close?\n\n");
		printf(">: ");
		scanf_s(" %s", &open_direc, 10);
		printf("\n");
		switch (main_character->current_room){
		case 0:
			if ((strcmp("north", open_direc)) == 0 && exit[1]->open == true) {
				exit[1]->open = false;
				action_done = true;
			}
			printf("You closed the %s!\n\n", exit[1]->name);

			break;
		case 1:
			if ((strcmp("south", open_direc)) == 0 && exit[1]->open == true) {
				exit[1]->open = false;
				action_done = true;
			}
			printf("You closed the %s!\n\n", exit[1]->name);
			break;
		}
	}
	else if (strcmp("drawer", move) == 0 && main_character->current_room == 4){
		if (simple_obj[2]->moved == true){
			simple_obj[2]->moved = false;
			printf("You closed the drawer.\n\n");
		}
		action_done = true;
	}
	else if (strcmp("closet", move) == 0 && main_character->current_room == 4){
		if (simple_obj[3]->moved == true){
			simple_obj[3]->moved = false;
			printf("You closed the closet.\n\n");
		}
		action_done = true;
	}
}
void world::Full_inventory(int item_num){
	int i = 0; 
	while (i < MAX_OBJECTS){
		if (main_character->inventory[i] == -1){
			main_character->inventory[i] = item_num;
			break;
		}			
		i++; 
	}
	if (i == MAX_OBJECTS)
		printf("You can't carry more things!\n\n");
}
void world::empty_inventory(int item_num){
	int i = MAX_OBJECTS;
	while (i > MAX_OBJECTS){
		if (main_character->inventory[i] == item_num){
			main_character->inventory[i] = -1;
			break;
		}
		i++;
	}
	if (i == MAX_OBJECTS)
		printf("You can't carry more things! Don't try to be impressive.");
}
void world::Equip_item(const char* item_name){
	//This is for equiping weapons
	int i = 0; 
	{
		if (main_character->weapon == -1 && (strcmp(item_name, "sword") == 0) && isin_inventory(item_name)){
			main_character->weapon = Get_Num(item_name);
			printf("You equipped the %s!\n\n", item_name); 
		}
		else{
			if (main_character->weapon != -1)
				printf("You can't equip more than one item.\n\n");
			else if ((strcmp(item_name, "sword") != 0))
				printf("You can't equip this such of item!\n\n");
			else
				printf("You can't equip a object that is not in your inventory.\n\n"); 
		}
			
	}

}
void world::Unequip_item(const char* item_name){
	//This is for unquiping weapons
	if (main_character->weapon != -1){
		main_character->weapon = -1; 
		printf("You unequiped the %s.\n\n", item_name); 
	}

}
int world::Get_Num(const char* item_name) const{
	int i = 0;
	while (i < MAX_OBJECTS){
		if (strcmp(item_name, "glass") == 0)
			return 0;
		else if (strcmp(item_name, "key") == 0)
			return 1;
		else if (strcmp(item_name, "match") == 0)
			return 2;
		else if (strcmp(item_name, "sword") == 0)
			return 3; 
		i++;
	}
}
bool world::isin_inventory(const char* item_name){
	int i = 0; 
	bool isin = false; 
	while (i < MAX_OBJECTS){
		if (main_character->inventory[i] == Get_Num(item_name))
			isin = true; 
		i++;
	}
	return isin;	
}






