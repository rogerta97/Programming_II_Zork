#include <string.h>
#include <windows.h>
#include <iostream> 
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>

#include "world.h"

//Inserted activate comand.
//Inserted a lot of items and simple objects.

#define ROOMS_NUMB 18
#define EXITS_NUMB 17
#define ITEMS_NUMB 28
#define SIMPLE_NUMB 12
#define CREATURES_NUMB 6 
#define MAX_OBJECTS 10
#define _CRT_SECURE_NO_WARNINGS_
typedef unsigned int uint; 
using namespace std; 

// Simple objects are those that are needed for advancing the game and just need to be true or false, like a on or off generator, a on or off fireplace, check if the user moved the carpet...


void world::CreateWorld(){
	//Actually there are 14 rooms, 4 of of them are "corridors" without any item or functionallity
	//they just exist in order to be able to select one of the 3 doors inside a element. 
	room.push_back(new Rooms("WEIRD BEDROOM", "You are in the middle of a dark room, it seems that the only think you conserve with you is your bed, you wake up in\nanother place and you listen to some sinester music as background.\n"));
	room.push_back(new Rooms("FIRE CORRIDOR", "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n"));
	room.push_back(new Rooms("BURNER", "In the north of the room there is a fireplace with the fire on, there is a shelving on the west and a wall full of old\nphotographies of a unknown family at south.\n"));
	room.push_back(new Rooms("EMPTY ROOM", "You are now facing with BOMBOCLATS! this is the fire boss! Go face him! (It's a really weird game so you can now be \nfriend with the monster and buy or sell thing, write <attack> + <creature name> then you can start fighting, no questions).\n"));
	room.push_back(new Rooms("OLD DAD ROOM", "What ? This is something familiar for you, you suddently entered into your dad's room and everything is like normally,\nyou left the door at west, on the north there is your dad's bed, on the east there is his closet\n and there is a TV with his favourite series at the south, there is a strange way made of fuel on the floor.\n"));
	room.push_back(new Rooms("WIND CORRIDOR", "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n"));
	room.push_back(new Rooms("OLD MUM ROOM", "Things don't make sense, now you entered to your old mum's room, lefting the entrance on south, on the north of the \nroom there is a mirror with some make up and a fan, in the east there is the bed, but there are some weird \nscratches on the wall that is at west.\n"));
	room.push_back(new Rooms("STDUYING ROOM", "This room contains a very big desktop with pens, papers and folders at the east, but the floor starts to break and a creature called BETEP now stands in front of you! (It's a really weird game so you can now be \nfriend with the monster and buy or sell thing, write <attack> + <creature name> then you can start fighting, no questions).\n"));
	room.push_back(new Rooms("BIG WINDOW ROOM", "You entered to the room lefting the entrance at north, on south there is a huge closed window, on west and east there\n are 2 more windows, those normal in size and both closed, one for each wall.\n"));
	room.push_back(new Rooms("WATER CORRIDOR", "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n"));
	room.push_back(new Rooms("AQUARIUM", "You appered into an aquarium, you left the entrance on the west, on the north you can see a wall of glass, behind, a fishbowl\n full of sharks, on the east there is the same type of fishbowl than the one with sharks, they are separated between a huge metalic wall, on south there is just a wall with paintings, in front of this wall there is a red chest.\n"));
	room.push_back(new Rooms("STICK CONTAINER ROOM", "You left the entrance at north and there is a big container with sticks inside and there is a button next to \nthe container, in the south of the room, at the west the is a table full of buttons with a \nleaver, all the buttons are turned off.\n"));
	room.push_back(new Rooms("LONELY BATHTUB", "You are seen the exit of the bathroom on the east, and there is a bathtub on the north, something strange happens,\n you start to feel vibrations on the floor and something wakes up from the watter, it's BANYU, the water boss. (It's a really weird game so you can now be \nfriend with the monster and buy or sell thing, write <attack> + <creature name> then you can start fighting, no questions).\n"));
	room.push_back(new Rooms("EARTH CORRIDOR", "You are at the end of a corridor, there are 3 doors, one in each wall direction.\n"));
	room.push_back(new Rooms("MINE", "You entered and you suddently appear in a mine, the door is on the north, and the wall on the west seems to be a little bit \,softer, the rest of the walls are full of insects, and due to the bad conditions of the mine, the rocks are breaking and there is some rock dust\n"));
	room.push_back(new Rooms("BLACK HOLE", "This is such a rude way to go in, but you did it. You left the broken wall at the south and there is a door on the \neast, at west it seems to be a hole on the wall, the sound is higher when you're closer to the hole, you look through it and something starts comming, it's BUMI, the earth boos. (It's a really weird game so you can now be \nfriend with the monster and buy or sell thing, write <attack> + <creature name> then you can start fighting, no questions).\n"));
	room.push_back(new Rooms("DRAWING ROOM", "You entered to a drawing room with the walls made of white stone stone, it's a long room and the exit is on the\nsouth, on the west there is a table with a strongbox on it, there is a red scarf on the floor with two cavalier figures made of iron at the end of the room, one holds a shield and the other one holds a peak, don't be scared!.\n"));
	room.push_back(new Rooms("FINAL BOSS ROOM", "it seems you teleported to a open space, you are in the middle of an open field in the mountain, the sky is dark \nand it seems it will rain, but wait... there is something comming? OMG! A huge omnster is comming!\n"));

	//Setting flatten array of integers for the rooms.
	for (int i = 0; i < ROOMS_NUMB; i++){
		room[i]->numb = i;
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

	exit.push_back(new exits("final boss teleport", "this is a door that suddently apeared on the wall, it has a blue electric color"));
	exit.push_back(new exits("fire door", "this door adresses to a long corridor with some torches on the wall."));
	exit.push_back(new exits("burner door", "this is a door made of metal girds."));
	exit.push_back(new exits("empty room door", "it's a varnished brown woden door."));
	exit.push_back(new exits("old dad door", "this is like your dad's old room door, white wood door."));
	exit.push_back(new exits("wind door", "this door adresses to a long corridor with some windows on the wall."));
	exit.push_back(new exits("old mum room door", "this is like your mum's old room door, white wood door."));
	exit.push_back(new exits("studying room door", "this is a dor with a note on it, silence!"));
	exit.push_back(new exits("big window room door", "this is a normal metalic door."));
	exit.push_back(new exits("water door", "this door adresses to a long corridor with waterfall of watter on the each wall."));
	exit.push_back(new exits("aquarium door", "this is a big gate with old used wood."));
	exit.push_back(new exits("container stick door", "this is a door that suddently apeared on the wall, it has a blue electric color"));
	exit.push_back(new exits("lonely bathtub door", "this is a gate maded of blue wood, it has golden door knob"));
	exit.push_back(new exits("earth corridor", "this door adresses to a long corridor with tha walls made of stone."));
	exit.push_back(new exits("mine door", "this is a tiny door maded by the holes of the stones on the wall."));
	exit.push_back(new exits("black hole room door", "this is a door with a hole on the middle!"));
	exit.push_back(new exits("drawing room door", "this is an elegant door, tipical of luxury drawing rooms"));

	//Setting an array of integers for the exits.

	for (int i = 0; i < EXITS_NUMB; i++){
		exit[i]->exit_numb = i;
	}

	//Setting state of the doors. (I made a loop beacuse the case is making all the doors stay open exept one,
	//in the case of the zork isegment that need it, i will assign the status for every room)

	for (int i = 0; i < EXITS_NUMB; i++){
		if (exit[i]->exit_numb == 1 || exit[i]->exit_numb == 14 || exit[i]->exit_numb == 15)
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

	//main_character = new player;

	creatures.push_back(new player("Sunyol", "a big head", WEIRD_BEDROOM, -1, 250,300, 5, rand() % 100 + 150)); //this is the player creature

	int objects = 0;
	while (objects < MAX_OBJECTS){
		creatures[PLAYER]->inventory[objects] = -1;      //we will set -1 for empty object.	
		objects++;
	}

	//Here we create the enemies
	creatures.push_back(new NPC("bomboclats", "this is the fire boss!", EMPTY_ROOM, ITEM_FLAMETHROWER, 150, rand() % 10 + 5 , rand() % 7 + 5, rand() % 100 + 150));
	creatures.push_back(new NPC("betep", "this is the wind boss!", STUDYING_ROOM, ITEM_CANONBOUX, 150, rand() % 10 + 5, rand() % 7 + 5, rand() % 100 + 150));
	creatures.push_back(new NPC("banyu", "this is the water boss!", LONELY_BATHTUB, ITEM_WATERWALL, 150, rand() % 10 + 5, rand() % 7 + 5, rand() % 100 + 150));
	creatures.push_back(new NPC("bumi", "this is the earth boss!", BLACK_HOLE, ITEM_TNT, 150, rand() % 10 + 5, rand() % 7 + 5, rand() % 100 + 150));
	creatures.push_back(new NPC("rock", "this is the final boss!", FINAL_BOSS_ROOM, ITEM_FLAMETHROWER, 150, rand() % 10 + 5, rand() % 7 + 5, rand() % 100 + 150));
	creatures.push_back(new NPC("seller", "this is the man that will give you some stuff if you find them!", AQUARIUM, NO_ITEM, 100, 0, 0, 1000)); 
	
	objects = 0;
	while (objects < MAX_OBJECTS){
		creatures[FIRE_CREATURE]->inventory[objects] = -1;
		creatures[WIND_CREATURE]->inventory[objects] = -1;
		creatures[WATER_CREATURE]->inventory[objects] = -1;
		creatures[EARTH_CREATURE]->inventory[objects] = -1;
		creatures[FINAL_BOSS]->inventory[objects] = -1; //we will set -1 for empty object.	
		objects++;
	}

	//Setting fire creature
	creatures[FIRE_CREATURE]->item= ITEM_FLAMETHROWER;
	creatures[FIRE_CREATURE]->inventory.push_back(ITEM_ATTACK_BELT);
	creatures[WIND_CREATURE]->item= ITEM_CANONBOUX;
	creatures[WIND_CREATURE]->inventory.push_back(ITEM_COIN_BOX);
	creatures[WIND_CREATURE]->inventory.push_back(ITEM_UZY);
	creatures[EARTH_CREATURE]->item = ITEM_TNT;
	creatures[EARTH_CREATURE]->inventory.push_back(ITEM_KNIFE);
	creatures[WATER_CREATURE]->item = ITEM_WATERWALL;
	creatures[FIRE_CREATURE]->inventory.push_back(ITEM_POSION);
	creatures[FIRE_CREATURE]->inventory.push_back(ITEM_ARMOR);

	//Setting the final boss. 
	creatures[FINAL_BOSS]->current_room = FINAL_BOSS_ROOM;
	creatures[FINAL_BOSS]->item = ITEM_DIPLOMA;
	creatures[FINAL_BOSS]->special_card = 0;
	creatures[FINAL_BOSS]->hp = 200;
	creatures[FINAL_BOSS]->attack = rand() % 10 + 5;
	creatures[FINAL_BOSS]->defense = rand () % 6 + 4;
	creatures[FINAL_BOSS]->coins = 30000000;
	creatures[FINAL_BOSS]->damage = 0;
	
	

	//We set the stats of the enemies 

	//Before setting the items, we first set the simple objects status. 
	simple_obj.push_back(new Simple_Objects(false, "shelving", BURNER));
	simple_obj.push_back(new Simple_Objects(false, "fireplace", BURNER));
	simple_obj.push_back(new Simple_Objects(false, "drawer", OLD_DAD_ROOM));
	simple_obj.push_back(new Simple_Objects(false, "closet", OLD_DAD_ROOM));
	simple_obj.push_back(new Simple_Objects(false, "chest", AQUARIUM));
	simple_obj.push_back(new Simple_Objects(false, "fishgate", AQUARIUM));
	simple_obj.push_back(new Simple_Objects(false, "lever", STICK_CONTAINER));
	simple_obj.push_back(new Simple_Objects(false, "conatiner", STICK_CONTAINER));
	simple_obj.push_back(new Simple_Objects(false, "strongbox", DRAWING_ROOM));
	simple_obj.push_back(new Simple_Objects(true, "dust", MINE));
	simple_obj.push_back(new Simple_Objects(false, "window1", BIG_WINDOW_ROOM));
	simple_obj.push_back(new Simple_Objects(true, "window2", BIG_WINDOW_ROOM));
	simple_obj.push_back(new Simple_Objects(true, "window3", BIG_WINDOW_ROOM));
	

	//Setting the items information with a constructor. 
	items.push_back(new item("glass", "This is a simple glass of watter, but a big one!", false, BURNER));
	items.push_back(new item("key", "This is an old golden key that seems to be the key of some old door too, the door is close.", false, BURNER));
	items.push_back(new item("matchstick", "A matchstick! Light it up!", false, OLD_DAD_ROOM));
	items.push_back(new item("sword", "What can you do with a sword? This sword has a magical energy that will increase your shield too! Attack = 30 \nHP +10.\n\n", false, OLD_DAD_ROOM));
	items.push_back(new item("chest", "This is a red chest with golden edges, it seems that needs a code for being opened :)", true, AQUARIUM));
	items.push_back(new item("AttackCard", "This card will give you an EXTRA 5 points of attack.", false, AQUARIUM));
	items.push_back(new item("hammer", "That is a strong hammer! Attack = 40 // hp +10.", false, AQUARIUM));
	items.push_back(new item("note", "The key is on Burner, just search better.\n\n", false, AQUARIUM));
	items.push_back(new item("shield", "This is the shield of the cavalier. Shield = + 10", false, DRAWING_ROOM));
	items.push_back(new item("peak", "The peak of the cavalier is a strong one! Take care of it! Attack = 40 // Shield = + 5 // hp = + 5", false, DRAWING_ROOM));
	items.push_back(new item("gunpowder", "A little bit of gunpowder, it seems it have to match with something else.", true, DRAWING_ROOM));
	items.push_back(new item("DefenseCard", "This card will give you an EXTRA 10 points of defense.", false, DRAWING_ROOM));
	items.push_back(new item("strongbox", "A little bit of gunpowder, it seems it have to match with something else.", true, DRAWING_ROOM));
	items.push_back(new item("wick", "This weak can be mixed with something? mmm... \n\n", false, MINE));
	items.push_back(new item("bomb", "This is a strong bomb that can break walls!\n\n", false, MINE));
	items.push_back(new item("fan", "This fan will help you to achieve your CORRIENTE DE AIRE\n\n", false, OLD_MUM_ROOM));
	items.push_back(new item("HPCard", "You're getting close to the final boss, so here you have a card that will raise 20 HP points.\n\n", false, OLD_MUM_ROOM));
	items.push_back(new item("flamethrower", "This is the flamehtrower of bomboclats! Attack = 30.\n\n", false, EMPTY_ROOM));
	items.push_back(new item("canonboux", "This weapon is special from the wind boss, it throws vortex of wind to your enemies. Attack = 25\n\n", false, STUDYING_ROOM));
	items.push_back(new item("waterwall", "This is a special shield that you can use 3 times, once you're carrying it your oponent won't be able to cause you any damage.\n\n", false, LONELY_BATHTUB));
	items.push_back(new item("TNT", "This is a special granade that you can use twice. Damage = 50\n\n", false, BLACK_HOLE));
	items.push_back(new item("diploma", "Congartulations! You got a diploma for playing this silly game.\n\n", false, FINAL_BOSS_ROOM));
	items.push_back(new item("belt", "this belt will increase your damage", false, EMPTY_ROOM));
	items.push_back(new item("coins", "This is a box full of coins. Value = 100\n\n", false, STUDYING_ROOM));
	items.push_back(new item("uzy", "This is an automatic handgun, but you can only shot 3 bullets each turn. Attack = 35; \n\n", false, STUDYING_ROOM));
	items.push_back(new item("knife", "This is a melee weapon, grey knife with golden hold. Damage = 20\n\n", false, LONELY_BATHTUB));
	items.push_back(new item("posion", "This posion increase x2 your current hp.\n\n", false, BLACK_HOLE));
	items.push_back(new item("armor", "this armor will decrease the enemy attack. Defense = 5", false, BLACK_HOLE));

	//Setting the number of the items and the carriage. 
	for (int i = 0; i < ITEMS_NUMB; i++){
		items[i]->item_num = i; 
		items[i]->carried = false; 
	}


	//Setting inventory for the items that can have objects inside.

	for (int i = 0; i < ITEMS_NUMB; i++){
		if (items[i]->item_num == ITEM_CHEST){
			for (int j = 2; j < MAX_ITEMS_STORAGE; j++){
				items[i]->prov_inv[0] = ITEM_HAMMER;
				items[i]->prov_inv[1] = ITEM_ATTACK_CARD;
				items[i]->prov_inv[j] = -1;
			}
		}
		else if (items[i]->item_num == ITEM_STRONGBOX){
			for (int j = 2; j < MAX_ITEMS_STORAGE; j++){
				items[i]->prov_inv[0] = ITEM_GUNPOWDER_CONTAINER;
				items[i]->prov_inv[1] = ITEM_DEFENSE_CARD;
				items[i]->prov_inv[j] = -1;
			}
		}

		else if (items[i]->item_num == ITEM_GUNPOWDER_CONTAINER){
			for (int j = 0; j < MAX_ITEMS_STORAGE; j++){
				items[i]->prov_inv[j] = -1;
			}
		}
	}

	items[ITEM_SWORD]->attack = 10; items[ITEM_SWORD]->shield_plus = 10; items[ITEM_SWORD]->hp_plus = 0, items[ITEM_SWORD]->cost = 30;
	items[ITEM_ATTACK_CARD]->attack = 5; items[ITEM_ATTACK_CARD]->shield_plus = 0; items[ITEM_ATTACK_CARD]->hp_plus = 0, items[ITEM_ATTACK_CARD]->cost = 10;
	items[ITEM_HAMMER]->attack = 20; items[ITEM_HAMMER]->shield_plus = 0; items[ITEM_HAMMER]->hp_plus = 10, items[ITEM_HAMMER]->cost = 20;
	items[ITEM_SHIELD]->attack = 0; items[ITEM_SHIELD]->shield_plus = 50; items[ITEM_SHIELD]->hp_plus = 25, items[ITEM_SHIELD]->cost = 15;
	items[ITEM_PEAK]->attack = 15; items[ITEM_PEAK]->shield_plus = 0; items[ITEM_PEAK]->hp_plus = 0, items[ITEM_PEAK]->cost = 15;
	items[ITEM_DEFENSE_CARD]->attack = 0; items[ITEM_DEFENSE_CARD]->shield_plus = 20; items[ITEM_DEFENSE_CARD]->hp_plus = 20, items[ITEM_DEFENSE_CARD]->cost = 10;
	items[ITEM_HP_CARD]->attack = 0; items[ITEM_HP_CARD]->shield_plus = 0; items[ITEM_HP_CARD]->hp_plus = 50, items[ITEM_HP_CARD]->cost = 10;
	items[ITEM_FLAMETHROWER]->attack = 30; items[ITEM_FLAMETHROWER]->shield_plus = 0; items[ITEM_FLAMETHROWER]->hp_plus = 0, items[ITEM_FLAMETHROWER]->cost = 40;
	items[ITEM_CANONBOUX]->attack = 25; items[ITEM_CANONBOUX]->shield_plus = 0; items[ITEM_CANONBOUX]->hp_plus = 0, items[ITEM_CANONBOUX]->cost = 40;
	items[ITEM_WATERWALL]->attack = 0; items[ITEM_WATERWALL]->shield_plus = 0; items[ITEM_WATERWALL]->hp_plus = 0, items[ITEM_WATERWALL]->cost = 40;
	items[ITEM_TNT]->attack = 50; items[ITEM_TNT]->shield_plus = 0; items[ITEM_TNT]->hp_plus = 0, items[ITEM_TNT]->cost = 10;
	items[ITEM_DIPLOMA]->attack = 0; items[ITEM_DIPLOMA]->shield_plus = 0; items[ITEM_DIPLOMA]->hp_plus = 0, items[ITEM_DIPLOMA]->cost = 0;
	items[ITEM_ATTACK_BELT]->attack = 10; items[ITEM_ATTACK_BELT]->shield_plus = 0; items[ITEM_ATTACK_BELT]->hp_plus = 0, items[ITEM_ATTACK_BELT]->cost = 20;
	items[ITEM_COIN_BOX]->attack = 0; items[ITEM_COIN_BOX]->shield_plus = 0; items[ITEM_COIN_BOX]->hp_plus = 0, items[ITEM_COIN_BOX]->cost = 0;
	items[ITEM_UZY]->attack = 35; items[ITEM_UZY]->shield_plus = 0; items[ITEM_UZY]->hp_plus = 0, items[ITEM_UZY]->cost = 40;
	items[ITEM_KNIFE]->attack = 15; items[ITEM_KNIFE]->shield_plus = 0; items[ITEM_KNIFE]->hp_plus = 0, items[ITEM_KNIFE]->cost = 30;
	items[ITEM_POSION]->attack = 0; items[ITEM_POSION]->shield_plus = 0; items[ITEM_POSION]->hp_plus = 40, items[ITEM_POSION]->cost = 20;
	items[ITEM_ARMOR]->attack = 0; items[ITEM_ARMOR]->shield_plus = 10; items[ITEM_ARMOR]->hp_plus = 0, items[ITEM_ARMOR]->cost = 50;

	//Here is printed the information of the character
	printf("%s\n", room[creatures[PLAYER]->current_room]->name);
	printf("%s\n", room[creatures[PLAYER]->current_room]->description);

}
void world::Check_input(){
	bool gameloop_end = 0;
	do{	
		char command_c[20];
		char move_c[20];
		
		bool button_pressed = false;
		bool action_done = false;
		bool& ref_move_permision = action_done;  //this exist in order to show the description just when the user can move, sometimets he makes and action but he don't move! 
		bool moved = false;
		bool& ref_moved = moved; //this variable holded by reference that exist in order to not show the description everytime the player inserts a command, just when the player changes of room. 
		static bool object_moved = false; 
		// this if checks if all monsters are death, if they do, the player will be teleported to the final boss, once he has killed all the other bosses.
		if (creatures[PLAYER]->current_room == WEIRD_BEDROOM && creatures[FIRE_CREATURE]->death == true &&	creatures[WIND_CREATURE]->death == true &&	creatures[WATER_CREATURE]->death == true && creatures[EARTH_CREATURE]->death == true){
			printf("You are almost a legend, you killed all the 4 monsters but that not the end of the story, every game has its final boss right? Go face him!"); 
			creatures[PLAYER]->current_room = FINAL_BOSS_ROOM;
			Sleep(1500);
			printf("\n\n"); 
			printf("Yoy're being teleported");
			Sleep(1500); 
			printf("."); 
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			printf("\n\n"); 
			printf("%s \n You apeared to the final boss room, you are facing with ROCK, here is where you have to give everything, it will be a difficult battle!\n\n >: ", room[FINAL_BOSS_ROOM]->name);
			scanf_s("%s %s", &command_c, 20, &move_c, 20);
			String command(command_c);
			String move(move_c);
			if (move == "rock"){
				if (command == "buy"){
					printf("This is not able on the final boss dude, you go alone.\n\n");
				}
				else if (command == "sell"){
					if (!creatures[PLAYER]->inventory.isempty())
						Sell_Item(move, FINAL_BOSS);
					else
						printf("Your inventory is empty, you can't sell dude.\n\n"); 
				}
				else if (command == "attack")
					gameloop_end = Enter_Battle(FINAL_BOSS);
			}		
		}
		
		printf(">: ");
		scanf_s("%s", &command_c, 20);

		String command(command_c); 

		if (command != "go" && command != "open" && command != "close" && command != "move" && command != "teleport" && command != "pick" && command != "drop" && command != "equip" && command != "unequip" && command != "look" && command != "get" && command != "press" && command != "hit" && command != "win" && command != "attack" && command != "buy" && command != "sell"){
			if (command == "quit"){
				//if the user wants to quit
				gameloop_end = true;
				action_done = true;
			}
			else if (command == "help")
				//if the user wants some help
				printf("%s", room[creatures[PLAYER]->current_room]->help);
			else if (command == "look"){
				printf("%s", room[creatures[PLAYER]->current_room]->description.c_str());
				//if the user wants to look					   
			}
			else if (command == "inventory")
				Show_inventory();
			else if (command == "stats")
				printf("\nHP: %d\nAttack: %d\nDefense: %d\nCoins: %d\n\n", creatures[PLAYER]->hp, creatures[PLAYER]->attack, creatures[PLAYER]->defense, creatures[PLAYER]->coins);
			else
				printf("\nI don't undestrand you, insert comands like <action> <direction/item>\n\n");		
			std::cin.clear(); 
		}
		else{
			scanf_s("%s", &move_c, 20);
			String move(move_c); 
			printf("\n");

			
			
			if (command == "teleport"){
				if (move == "A"){
					creatures[PLAYER]->current_room = EMPTY_ROOM;
					goto Start; 
				}
				else if (move == "B"){
					creatures[PLAYER]->current_room = STUDYING_ROOM;
					goto Start;
				}
				else if (move == "C"){
					creatures[PLAYER]->current_room = LONELY_BATHTUB;
					goto Start;
				}
				else if (move == "D"){
					creatures[PLAYER]->current_room = BLACK_HOLE;
					goto Start;
				}
				else if (move == "E"){
					creatures[PLAYER]->current_room = WEIRD_BEDROOM;
					goto Start;
				}
				}
			if (command == "go")
				move_character(move, moved, action_done, PLAYER);
			else if (command == "open"){
				//if the user wants to open something
				int object_open;

				if (move == "drawer")
					object_open = INTERACT_DRAWER;
				else if (move == "door")
					object_open = INTERACT_DOOR;
				else if (move == "closet")
					object_open = INTERACT_CLOSET;
				else if (move == "chest" || move == "box")
					object_open = INTERACT_CHEST;
				else if (move == "strongbox")
					object_open = INTERACT_STRONGBOX;
				else if (move == "window" || move == "windows")
					object_open = INTERACT_WINDOW;
					
				Open_Stuff(creatures[PLAYER]->current_room, action_done, object_open, move);
				//here will be placed other things that can be opened: "window", "box"...	
			}
			else if (command == "close"){
				//if the user wants to close something
				int object_open; 
				if (move == "drawer")
					object_open = INTERACT_DRAWER;
				else if (move == "door")
					object_open = INTERACT_DOOR;
				else if (move == "closet")
					object_open = INTERACT_CLOSET;
				else if (move == "chest" || move == "box")
					object_open = INTERACT_CHEST;
				else if (move == "strongbox")
					object_open = INTERACT_STRONGBOX;
				else if (move == "window" || move == "windows")
					object_open = INTERACT_WINDOW;
				Close_Stuff(creatures[PLAYER]->current_room, action_done, object_open, move);
				
			}
			else if (command == "look"){
					look_item(move); 
				action_done = true;
			}
			else if (command == "move"){
				//if the user wants to move something (objects that can be moved and don't have no more functionality are in Simple_Objects class).
				//This function is for printing what happens when de user moves some object: i.e: You moved a carpet and you discovered a trapdoor!
				Move_Simple_Obj(move);
				action_done = true; 
			}
			else if (command == "equip"){
				Equip_item(move);
				action_done = true; 
			}
			else if (command == "unequip"){
				Unequip_item(move);
				action_done = true;
			}
			else if (command == "sell"){
				if (!creatures[PLAYER]->inventory.isempty()){
					if (creatures[PLAYER]->current_room == EMPTY_ROOM) Sell_Item(move, FIRE_CREATURE);
					else if (creatures[PLAYER]->current_room == STUDYING_ROOM) Sell_Item(move, WIND_CREATURE);
					else if (creatures[PLAYER]->current_room == LONELY_BATHTUB) Sell_Item(move, WATER_CREATURE);
					else if (creatures[PLAYER]->current_room == BLACK_HOLE) Sell_Item(move, EARTH_CREATURE);
					else if (creatures[PLAYER]->current_room == FINAL_BOSS_ROOM) Sell_Item(move, FINAL_BOSS);
					action_done = true;
				}			
			}
			else if (command == "hit"){
				Hit_Stuff(move); 
				action_done = true;
			}
			else if (command == "attack"){

				if ((move == "bomboclats" || move == "betep" || move == "banyu" || move == "bumi")){
					if (move == "bomboclats" && creatures[PLAYER]->current_room == EMPTY_ROOM && creatures[FIRE_CREATURE]->death == false)
						gameloop_end = Enter_Battle(FIRE_CREATURE);
					else if (move == "betep" && creatures[PLAYER]->current_room == STUDYING_ROOM && creatures[WIND_CREATURE]->death == false)
						gameloop_end = Enter_Battle(WIND_CREATURE);
					else if (move == "banyu" && creatures[PLAYER]->current_room == LONELY_BATHTUB && creatures[WATER_CREATURE]->death == false)
						gameloop_end = Enter_Battle(WATER_CREATURE);
					else if (move == "bumi" && creatures[PLAYER]->current_room == BLACK_HOLE && creatures[EARTH_CREATURE]->death == false)
						gameloop_end = Enter_Battle(EARTH_CREATURE);
					else
						printf("This enemy is death dude.\n");
				}
				else
					printf("You can't attack.\n\n");
				action_done = true;
			}
			else if (command == "press"){
				if (move == "button" && creatures[PLAYER]->current_room == STICK_CONTAINER && simple_obj[SIMPLE_LEVER]->moved == true){
					simple_obj[SIMPLE_FISHGATE]->moved = true; 
					printf("You pressed the button of the stick container, making the sticks twist and generating enough force to raise something.Go and see it!\n\n");
					button_pressed = true; 
				}				
				action_done = true;
			}
			else if (command == "pick"){
				Pick_Item(move, creatures[PLAYER]->current_room, PLAYER, false);
				if (creatures[PLAYER]->inventory.is_in_vector(ITEM_DIPLOMA) != -1){
					printf("CONGRATULATIONS! You picked up the final diploma! Press any button to close the game...");
					getchar();
					gameloop_end = true; 
				}
				action_done = true;
			}
			else if (command == "drop"){
				Drop_item(move, creatures[PLAYER]->current_room, PLAYER, false);
				action_done = true;
			}
			else if (command == "get"){
				Get_object_from_object(move, creatures[PLAYER]->current_room);
				action_done = true;
			}
			else if (command == "put"){
				Put_Objects(move, creatures[PLAYER]->current_room);
				action_done = true;
			}
			else if (command == "buy"){
				if (creatures[PLAYER]->current_room == EMPTY_ROOM) BuyItem(FIRE_CREATURE);
				else if (creatures[PLAYER]->current_room == STUDYING_ROOM) BuyItem(WIND_CREATURE);
				else if (creatures[PLAYER]->current_room == LONELY_BATHTUB) BuyItem(WATER_CREATURE);
				else if (creatures[PLAYER]->current_room == BLACK_HOLE) BuyItem(EARTH_CREATURE);
				else if (creatures[PLAYER]->current_room == FINAL_BOSS_ROOM) BuyItem(FINAL_BOSS);
				action_done = true; 
			}		
				
			else
				printf("I can't understand you.\n\n");

			if (moved == true){
				Start: 
				printf("%s\n", room[creatures[PLAYER]->current_room]->name);
				if (simple_obj[SIMPLE_FISHGATE]->moved == false && creatures[PLAYER]->current_room != AQUARIUM)
					printf("%s\n", room[creatures[PLAYER]->current_room]->description);
				else
					printf("When pressing the container button you raised the fishgate, sharks that were separated started to fight and they broke the glass, now there is one shark on the floor with a note on the fin.\n\n");
			}
			else if (action_done == false && command == "go")
				printf("There is any door on that direction, just a wall!\n\n");
			else if (command != "look" && action_done == false)
				printf("You can't do that.\n\n"); 

			int direction = rand() % 3;
			if (direction == 0)
				move = "north";
			else if (direction == 1)
				move = "south";
			else if (direction == 2)
				move = "east";
			else if (direction == 3)
				move = "west";

			move_character(move, moved, action_done, SELLER);
		}

		if (creatures[PLAYER]->current_room == creatures[SELLER]->current_room){
			printf("WOW! You found a person that is walking through the map and giving some money! Your earned 100 coins from him!\n\n"); 
			creatures[PLAYER]->coins += 100; 
			creatures[SELLER]->coins -= 100;
		}
	} while (gameloop_end == false); 
}
void world::Destroy_World(){

	//I dont know hoe to do them...

	//delete[] room;
	//delete[] exit;
	//delete[] items.buffer; 
	//delete[] simple_obj.buffer; 
	//delete creatures[PLAYER];
	 
}

void world::move_character(const String& move, bool& moved, bool& permission, int creature_moving){
	// if the user inserts the comand go: 
	if (move == "north"){
		// if the user wants to go north
		switch (creatures[creature_moving]->current_room){
		case 0:
			permission = true;
			if (exit[1]->open){
				permission = true;
				creatures[creature_moving]->current_room = 1;
				moved = true; 
			}		
			else
				printf("There is a closed door there.\n\n");
			break;
		case 1:
			permission = true;
			creatures[creature_moving]->current_room = 3;
			moved = true;
			break;
		case 13:
			permission = true;
			creatures[creature_moving]->current_room = 16;
			moved = true;
			break;
		case 9:
			permission = true;
			creatures[creature_moving]->current_room = 0;
			moved = true;
			break;
		case 11:
			permission = true;
			creatures[creature_moving]->current_room = 9;
			moved = true;
			break;
		case 8:
			permission = true;
			creatures[creature_moving]->current_room = 5;
			moved = true;
			break;
		case 5:
			permission = true;
			creatures[creature_moving]->current_room = 6;
			moved = true;
			break;
		case 14:
			permission = true;
			creatures[creature_moving]->current_room = 13;
			moved = true;
			break;
		}
	}
	else if (move == "south"){
		//if the user wants to go south
		switch (creatures[creature_moving]->current_room){
		case 3:
			permission = true;
			creatures[creature_moving]->current_room = 1;
			moved = true; 
			break;
		case 1:
			permission = true; 
			if (exit[1]->open){
				creatures[creature_moving]->current_room = 0;
				moved = true;
			}				
			else
				printf("There is a closed door there.\n\n");
			break;
		case 0:
			permission = true;
			creatures[creature_moving]->current_room = 9;
			moved = true;
			break;
		case 9:
			permission = true;
			creatures[creature_moving]->current_room = 11;
			moved = true;
			break;
		case 6:
			permission = true;
			creatures[creature_moving]->current_room = 5;
			moved = true;
			break;
		case 5:
			permission = true;
			creatures[creature_moving]->current_room = 8;
			moved = true;
			break;
		case 16:
			permission = true;
			creatures[creature_moving]->current_room = 13;
			moved = true;
			break;
		case 13:
			permission = true;
			if (exit[14]->open == true){
				creatures[creature_moving]->current_room = 14;
				moved = true;
			}
			else
				printf("There is a wall made of rocks that's blocking the door.\n\n");
		
			break;
		}
	}
	else if (move == "east"){
		//if the user wants to go east
		switch (creatures[creature_moving]->current_room){
		case 2:
			permission = true;
			creatures[creature_moving]->current_room = 1;
			moved = true;
			break;
		case 1:
			permission = true;
			creatures[creature_moving]->current_room = 4;
			moved = true;
			break;
		case 0:
			permission = true;
			creatures[creature_moving]->current_room = 5;
			moved = true;
			break;
		case 5:
			permission = true;
			creatures[creature_moving]->current_room = 7;
			moved = true;
			break;
		case 9:
			permission = true;
			creatures[creature_moving]->current_room = 10;
			moved = true;
			break;
		case 15:
			permission = true;
			creatures[creature_moving]->current_room = 13;
			moved = true;
			break;
		case 12:
			permission = true;
			creatures[creature_moving]->current_room = 9;
			moved = true;
			break; 
		case 13:
			permission = true;
			creatures[creature_moving]->current_room = 0;
			moved = true;
			break;
		}
	}

	else if (move == "west"){
		//if the user wants to go west
		switch (creatures[creature_moving]->current_room){
		case 4:
			permission = true;
			creatures[creature_moving]->current_room = 1;
			moved = true;
			break;
		case 1:
			permission = true;
			creatures[creature_moving]->current_room = 2;
			moved = true;
			break;
		case 0:
			permission = true;
			creatures[creature_moving]->current_room = 13;
			moved = true;
			break;
		case 13:
			permission = true;
			if (exit[15]->open == true){
				creatures[creature_moving]->current_room = 15;
				moved = true;
			}
			else
				printf("There is a door that will never be opened.\n\n"); 
		
			break;
		case 10:
			permission = true;
			creatures[creature_moving]->current_room = 9;
			moved = true;
			break;
		case 9:
			permission = true;
			creatures[creature_moving]->current_room = 12;
			moved = true;
			break;
		case 7:
			permission = true;
			creatures[creature_moving]->current_room = 5;
			moved = true;
			break;
		case 5:
			permission = true; 
			creatures[creature_moving]->current_room = 0;
			moved = true;
			break;
		}
	}
}
void world::Move_Simple_Obj(const String& move){
	int item_num = Get_Simple_Num(move.string);
	if (item_num != -1){
		switch (item_num){
		case SIMPLE_SHELV:
		{
			   if (creatures[PLAYER]->current_room == items[item_num]->item_room){
			  	 if (simple_obj[SIMPLE_SHELV]->moved == false){
			  		 simple_obj[SIMPLE_SHELV]->moved = true;
			  		 printf("You moved the shelving, revealing a little hole on the wall with a glass full of watter!\n\n");
			  	 }
			  	 else {
			  		 printf("You moved the shelving to it's original place.\n\n");
			  		 simple_obj[SIMPLE_SHELV]->moved = false;
			  	 }
			   }
			   break;
		}
		case SIMPLE_LEVER:
			char password[10];
			printf("Electricity lever is blocked by a set of characters: Insert pasword: ");
			scanf_s("%s", &password, 10);
			printf("\n");
			String password_str(password);
			if (password_str == "boom"){
				if (creatures[PLAYER]->current_room == simple_obj[item_num]->current_room){
					if (simple_obj[SIMPLE_LEVER]->moved == false){
						simple_obj[SIMPLE_LEVER]->moved = true;
						printf("You turned on the electricity!\n\n");
					}
					else {
						printf("Electircity is already turned on.\n\n");
						simple_obj[SIMPLE_LEVER]->moved = false;
					}
				}
			}
			else
				printf("Incorrect password.\n\n");
			break;
		}
	}
	else
		printf("I can't recognize that.\n\n"); 
	
}

void world::Pick_Item(const String& move, int current_room, int creature, bool combat_mode){
	if (combat_mode == false){
		bool quit_for = false;
		for (int i = 0; i < ITEMS_NUMB && quit_for == false; i++){
			if (creatures[creature]->inventory[i] == -1){
				if (Get_Item_Room(Get_Num(move)) == creatures[creature]->current_room){
					//It's hardcoded because it don't follows a pattern, every object has simple objects and every objects acts different.
					switch (Get_Num(move)){
					case ITEM_GLASS:
						quit_for = true;
						if (simple_obj[SIMPLE_SHELV]->moved == true){
							items[ITEM_GLASS]->carried = true;
							printf("You picked up the %s\n\n", move.string);
							Full_inventory(items[ITEM_GLASS]->item_num);
						}
						else
							printf("There is no %s here.\n\n", move.string);
						break;

					case ITEM_KEY:
						quit_for = true;
						if (simple_obj[SIMPLE_FIREPLACE]->moved == true){
							items[ITEM_KEY]->carried = true;
							printf("You picked up the %s\n\n", move.string);
							Full_inventory(items[ITEM_KEY]->item_num);
						}
						else
							printf("There is no %s here.\n\n", move.string);
						break;

					case ITEM_MATCHSTICK:
						quit_for = true;
						if (simple_obj[SIMPLE_DRAWER]->moved == true){
							items[ITEM_MATCHSTICK]->carried = true;
							printf("You picked up the %s\n\n", move.string);
							Full_inventory(items[ITEM_MATCHSTICK]->item_num);
						}
						else
							printf("There is no %s here.\n\n", move.string);
						break;

					case ITEM_SWORD:
						quit_for = true;
						if (simple_obj[SIMPLE_CLOSET]->moved == true){
							items[ITEM_SWORD]->carried = true;
							printf("You picked up the %s\n\n", move.string);
							Full_inventory(items[ITEM_SWORD]->item_num);
						}
						else
							printf("There is no %s here.\n\n", move.string);
						break;

					case ITEM_NOTE:

						quit_for = true;
						if (simple_obj[SIMPLE_FISHGATE]->moved == true){
							items[ITEM_NOTE]->carried = true;
							printf("You picked up the %s\n\n", move.string);
							Full_inventory(items[ITEM_NOTE]->item_num);
						}
						else
							printf("There is no %s here.\n\n", move.string);
						break;

					case ITEM_CHEST:

						quit_for = true;
						items[ITEM_CHEST]->carried = true;
						printf("You picked up the %s\n\n", move.string);
						Full_inventory(items[ITEM_CHEST]->item_num);

						break;

					case ITEM_SHIELD:

						quit_for = true;
						items[ITEM_SHIELD]->carried = true;
						printf("You picked up the %s\n\n", move.string);
						Full_inventory(items[ITEM_SHIELD]->item_num);

						break;

					case ITEM_PEAK:
						quit_for = true;
						items[ITEM_PEAK]->carried = true;
						printf("You picked up the %s.\n\n", move.string);
						Full_inventory(items[ITEM_PEAK]->item_num);
						break;

					case ITEM_GUNPOWDER_CONTAINER:
						quit_for = true;
						if (simple_obj[SIMPLE_STRONGBOX]->moved == true){
							items[ITEM_GUNPOWDER_CONTAINER]->carried = true;
							printf("You picked up the %s\n\n", move.string);
							Full_inventory(items[ITEM_GUNPOWDER_CONTAINER]->item_num);
						}
						else
							printf("There is no %s here.\n\n", move.string);
						break;

					case ITEM_STRONGBOX:
						quit_for = true;
						items[ITEM_GUNPOWDER_CONTAINER]->carried = true;
						printf("You picked up the %s\n\n", move.string);
						Full_inventory(items[ITEM_GUNPOWDER_CONTAINER]->item_num);
						break;

					case ITEM_WICK:
						quit_for = true;
						items[ITEM_WICK]->carried = true;
						printf("You picked up the %s\n\n", move.string);
						Full_inventory(items[ITEM_WICK]->item_num);
						break;

					case ITEM_FAN:
						quit_for = true;
						items[ITEM_FAN]->carried = true;
						printf("You picked up the %s\n\n", move.string);
						Full_inventory(items[ITEM_FAN]->item_num);
						break;

					case ITEM_HP_CARD:
						quit_for = true;
						items[ITEM_HP_CARD]->carried = true;
						printf("You picked up the %s\n\n", move.string);
						Full_inventory(items[ITEM_HP_CARD]->item_num);
						break;

					case ITEM_CANONBOUX:
						quit_for = true;
						items[ITEM_CANONBOUX]->carried = true;
						printf("You picked up the %s\n\n", move.string);
						Full_inventory(items[ITEM_CANONBOUX]->item_num);
						break;

					case ITEM_FLAMETHROWER:
						quit_for = true;
						items[ITEM_FLAMETHROWER]->carried = true;
						printf("You picked up the %s\n\n", move.string);
						Full_inventory(items[ITEM_FLAMETHROWER]->item_num);
						break;

					case ITEM_WATERWALL:
						quit_for = true;
						items[ITEM_WATERWALL]->carried = true;
						printf("You picked up the %s\n\n", move.string);
						Full_inventory(items[ITEM_WATERWALL]->item_num);
						break;

					case ITEM_TNT:
						quit_for = true;
						items[ITEM_TNT]->carried = true;
						printf("You picked up the %s\n\n", move.string);
						Full_inventory(items[ITEM_TNT]->item_num);
						break;

					case ITEM_DIPLOMA:
						quit_for = true;
						items[ITEM_DIPLOMA]->carried = true;
						printf("You picked up the %s\n\n", move.string);
						Full_inventory(items[ITEM_DIPLOMA]->item_num);
						break;
					}
				}
			}

		}
	}
	else{
		printf("You sold %s!\n\n", move);
		for (int i = 0; i < MAX_OBJECTS; i++){
			if (creatures[creature]->inventory[i] == -1){
				creatures[creature]->inventory[i] = Get_Num(move);
				return;
			}
		}
	}

}	
void world::Drop_item(const String& move, int current_room, int creature, bool combat_mode)
{
	int i = 0;
	int pos = creatures[creature]->inventory.is_in_vector(Get_Num(move));
		if (pos != -1)
		{			
			items[creatures[creature]->inventory[pos]]->item_room = creatures[creature]->current_room;
			items[creatures[creature]->inventory[pos]]->carried = false;
			if (combat_mode == false)
				printf("You left the %s!\n\n", creatures[creature]->item_name(creatures[creature]->inventory[pos]));
			creatures[creature]->inventory.erase(pos);		
	}
}

void world::look_item(const String& item_name){
	int item_num = Get_Num(item_name);
	//That's for looking photographies on BURNER.
	if (creatures[PLAYER]->current_room == items[ITEM_CHEST]->item_room)

	if (creatures[PLAYER]->current_room == BURNER && item_name == "photographies"){
		printf("Say booom!\n\n");
		return;
	}
	else if (creatures[PLAYER]->current_room == DRAWING_ROOM && item_name == "strongbox"){
		printf("%s\n\n", items[ITEM_STRONGBOX]->name);
		return;
	}
	else if (creatures[PLAYER]->current_room == MINE && item_name == "dust"){
		printf("This is dust of rock, searching trough it you found a wick.\n\n");
		return;
	}
	else if (creatures[PLAYER]->current_room == OLD_MUM_ROOM && item_name == "wall"){
		printf("The strength of the wind I so powerfull, think what you have to do in order to achieve a CORREINTE DE AIRE!\n\n");
		return;
	}
	else if (creatures[PLAYER]->current_room == OLD_MUM_ROOM && item_name == "table" || item_name == "mirror"){
		printf("The table is so dirty and full of make up, useless things, the only objects that would make you some service would be a +25-HpCard that is on the table and the fan\n\n");
		return;
	}

	if (item_num != -1 && isin_inventory(items[item_num]->name, PLAYER) == true){
		if (creatures[PLAYER]->current_room == items[item_num]->item_room)
			printf("%s", items[item_num]->description);
		else
			printf("There is no %s to look at.\n\n", items[item_num]->name);
	}
	else{
			printf("You can't look at an object that is not in your inventory.\n\n"); 
	}


}
bool world::isin_item(const String& item_name, const String& container){
	int item_num = Get_Num(item_name); 
	int container_num = Get_Num(container); 
	for (int i = 0; i < MAX_ITEMS_STORAGE; i++){
		if (item_num == items[container_num]->prov_inv[i]); 
			return true;
	}
	return false; 
}

void world::Open_Stuff(int current_room, bool& action_done, int open_type, const String& move){
	switch (open_type){
	case INTERACT_DOOR:
	{
					  //this is the function to open doors
					  char open_direc[10];
					  printf("What is the direction of the door that you want to open?\n\n");
					  printf(">: ");
					  scanf_s(" %s", &open_direc, 10);
					  String open_direc_str(open_direc); 
					  printf("\n");
					  switch (creatures[PLAYER]->current_room){
					  case 0:
						  if (open_direc_str == "north" && exit[1]->open == false){
							  exit[1]->open = true;
							  action_done = true;
						  }
						  printf("You opened the %s!\n", exit[1]->name);
						  break;
					  case 1:
						  if (open_direc_str == "south" && exit[1]->open == false){
							  exit[1]->open = true;
							  action_done = true;
						  }
						  printf("You opened the %s!\n\n", exit[1]->name);
						  break;
					  }
					  printf("\n");
	}
		break;

	case INTERACT_DRAWER:
		if (creatures[PLAYER]->current_room == 4 && simple_obj[SIMPLE_DRAWER]->moved == false){
			simple_obj[SIMPLE_DRAWER]->moved = true;
			printf("You opened the drawer, revealing a matchstick of your daddy!\n\n");
		}
		else
			printf("This is already opened!\n\n");
		action_done = true;
		break;

	case INTERACT_CLOSET:
		if (creatures[PLAYER]->current_room == 4 && simple_obj[SIMPLE_CLOSET]->moved == false){
			simple_obj[SIMPLE_CLOSET]->moved = true;
			printf("You opened the closet, and you discovered something you daddy didn't told you, he has a sword on the closet!\n\n");
		}
		else
			printf("The closet is already opened.\n\n");
		action_done = true;
		break;

	case INTERACT_CHEST:
		if (creatures[PLAYER]->current_room == items[Get_Num(move)]->item_room){
			simple_obj[SIMPLE_CHEST]->moved = true;
			printf("You opened the %s! Inside you found:\n", items[SIMPLE_CHEST]->name);
			Show_object_content(Get_Num(move));				
		}
		else
			printf("You can't do this now.\n\n");
		action_done = true;
		break;

	case INTERACT_STRONGBOX:
		if (creatures[PLAYER]->current_room == items[Get_Num(move)]->item_room){
			simple_obj[SIMPLE_STRONGBOX]->moved = true;
			printf("You opened the %s! Inside you found:\n", items[ITEM_STRONGBOX]->name);
			Show_object_content(Get_Num(move));
		}
		else
			printf("You can't do this now.\n\n");
		action_done = true;
		break;

	case INTERACT_WINDOW:
		char window_dir[10]; 
		printf("Where is the window?\n\n>:"); 
		scanf_s("%s", &window_dir, 10); 
		printf("\n"); 

		String window_str(window_dir); 

		if (window_str == "south" && simple_obj[SIMPLE_WINDOW1]->moved == false){
			simple_obj[SIMPLE_WINDOW1]->moved = true; 
			printf("You opened to south window!\n\n");
			return;
		}
		else if (window_str == "west" && simple_obj[SIMPLE_WINDOW2]->moved == false){
			simple_obj[SIMPLE_WINDOW2]->moved = true;
			printf("You opened to west window!\n\n");
			return;
		}
		else if (window_str == "east" && simple_obj[SIMPLE_WINDOW3]->moved == false){
			simple_obj[SIMPLE_WINDOW3]->moved = true;
			printf("You opened to east window!\n\n");
			return;
		}
		else
			printf("You can't open anything like this now.\n\n");
		action_done = true;
		break;
	}
}
void world::Close_Stuff(int current_room, bool& action_done, int open_type, const String& move){
	switch (open_type){
	case INTERACT_DOOR:
	{
					  //this is the function to open doors
					  char open_direc[10];
					  printf("What is the direction of the door that you want to close?\n\n");
					  printf(">: ");
					  scanf_s(" %s", &open_direc, 10);
					  String open_direc_str(open_direc); 
					  printf("\n");
					  switch (creatures[PLAYER]->current_room){
					  case WEIRD_BEDROOM:
						  if (open_direc_str == "north" && exit[1]->open == true){
							  exit[1]->open = false;
							  action_done = true;
						  }
						  printf("You closed the %s!\n", exit[1]->name);
						  break;
					  case FIRE_CORRIDOR:
						  if (open_direc_str == "south" && exit[1]->open == true){
							  exit[1]->open = false;
							  action_done = true;
						  }
						  printf("You closed the %s!\n\n", exit[1]->name);
						  break;
					  }
					  printf("\n");
	}
		break;

	case INTERACT_DRAWER:
		if (creatures[PLAYER]->current_room == 4 && simple_obj[SIMPLE_DRAWER]->moved == true){
			simple_obj[SIMPLE_DRAWER]->moved = false;
			printf("You closed the drawer.\n\n");
		}
		else
			printf("This is already closed!\n\n");
		action_done = true;
		break;

	case INTERACT_CLOSET:
		if (creatures[PLAYER]->current_room == 4 && simple_obj[SIMPLE_CLOSET]->moved == true){
			simple_obj[SIMPLE_CLOSET]->moved = false;
			printf("You closed the closet.\n\n");
		}
		else
			printf("The closet is already closed.\n\n");
		action_done = true;
		break;

	case INTERACT_CHEST:
		if (creatures[PLAYER]->current_room == items[SIMPLE_CHEST]->item_room && simple_obj[SIMPLE_CHEST]->moved == true){
			simple_obj[SIMPLE_CHEST]->moved = false;
			printf("You closed the %s.\n\n", items[SIMPLE_CHEST]->name);
		}
		else
			printf("The %s is already closed.\n\n", simple_obj[Get_Simple_Num(move)]->name);
		action_done = true;
		break;


	case INTERACT_STRONGBOX:
		if (creatures[PLAYER]->current_room == items[SIMPLE_STRONGBOX]->item_room && simple_obj[SIMPLE_STRONGBOX]->moved == true){
			simple_obj[SIMPLE_STRONGBOX]->moved = false;
			printf("You closed the %s.\n\n", simple_obj[SIMPLE_STRONGBOX]->name);
		}
		else
			printf("The %s is already closed.\n\n", simple_obj[Get_Simple_Num(move)]->name);
		action_done = true;
		break;

	case INTERACT_WINDOW:
		char window_dir[10];
		printf("Where is the window?\n\n>:");
		scanf_s("%s", &window_dir, 10);
		printf("\n");

		String window_str(window_dir);

		if (window_str == "south" && simple_obj[SIMPLE_WINDOW1]->moved == true){
			simple_obj[SIMPLE_WINDOW1]->moved = false;
			action_done = true;
			printf("You closed the south window!\n\n");
			return;
		}
		else if (window_str == "west" && simple_obj[SIMPLE_WINDOW2]->moved == true){
			simple_obj[SIMPLE_WINDOW2]->moved = false;
			action_done = true;
			printf("You closed the west window!\n\n");
			return;
		}
		else if (window_str == "east" && simple_obj[SIMPLE_WINDOW3]->moved == true){
			simple_obj[SIMPLE_WINDOW3]->moved = false;
			action_done = true;
			printf("You closed the east window!\n\n");
			return;
		}
		else
			printf("You can't close this!!.\n\n");
		action_done = true;
		break;
	}
}

void world::Full_inventory(int item_num){
	int i = 0;
	creatures[PLAYER]->inventory.push_back(item_num); 

	if (creatures[PLAYER]->inventory.size() > 10)
		printf("You can't carry more things!\n\n");
	}

void world::empty_inventory(int item_num){
	int i = MAX_OBJECTS;
	while (i > MAX_OBJECTS){
		if (creatures[PLAYER]->inventory[i] == item_num){
			creatures[PLAYER]->inventory[i] = -1;
			break;
		}
		i++;
	}
	if (i == MAX_OBJECTS)
		printf("You can't carry more things! Don't try to be impressive.");
}
void world::Show_inventory() const{

	if (creatures[PLAYER]->inventory.isempty()){
		printf("Your inventory is empty!\n\n");
	}
	else
		creatures[PLAYER]->inventory.print(); 
	
}
void world::Show_sell_inventory() const{
	bool isempty = true;
	for (uint i = 0; i < MAX_OBJECTS; i++){
		if (creatures[PLAYER]->inventory[i] != -1){
			isempty = false;
			break;
		}

	}
	if (isempty){
		printf("Your inventory is empty!\n\n");
	}

	for (uint i = 0; i < MAX_OBJECTS && !isempty; i++){
		if (creatures[PLAYER]->inventory[i] != -1)
			printf("- %s     Cost: %d coins\n", creatures[PLAYER]->item_name(creatures[PLAYER]->inventory[i]), items[creatures[PLAYER]->inventory[i]]->cost);
	}
}
bool world::isin_inventory(const String& item_name, int owner){
	int i = 0;
	bool isin = false;
	while (i < MAX_OBJECTS){
		if (creatures[owner]->inventory[i] == Get_Num(item_name))
			isin = true;
		i++;
	}
	return isin;
}

void world::Equip_item(const String& item_name){
	//This is for equiping weapons
	bool equiped = false;
	int i = 0;
	{
		if (creatures[PLAYER]->item != -1)
			printf("You can't equip more than one item.\n\n");
		else{
			if (creatures[PLAYER]->item == -1 && item_name == "sword" || item_name == "hammer" || item_name == "peak" || item_name == "uzy" && isin_inventory(item_name, PLAYER)){
				creatures[PLAYER]->item = Get_Num(item_name);
				equiped = true;
				creatures[PLAYER]->item = Get_Num(item_name); 
				printf("You equipped the %s!\n\n", item_name);
				creatures[PLAYER]->attack = items[creatures[PLAYER]->item]->attack; 

			}
			if (creatures[PLAYER]->item == -1 && item_name == "AttackCard" || item_name == "DefenseCard" || item_name == "HPCard" && isin_inventory(item_name, PLAYER)){
				creatures[PLAYER]->item = Get_Num(item_name);
				equiped = true;
				printf("You equipped the %s!\n\n", item_name);
				if (creatures[PLAYER]->special_card == ITEM_ATTACK_CARD){
					creatures[PLAYER]->attack += 5;
				}
				if (creatures[PLAYER]->item == ITEM_DEFENSE_CARD){
					creatures[PLAYER]->defense += 10;
				}
				if (creatures[PLAYER]->item == ITEM_HP_CARD){
					creatures[PLAYER]->hp += 20;
				}
			}
			if (creatures[PLAYER]->defense == -1 && item_name == "shield"  && isin_inventory(item_name, PLAYER)){
				creatures[PLAYER]->defense = Get_Num(item_name);
				equiped = true;
				printf("You equipped the %s!\n\n", item_name);
				if (creatures[PLAYER]->defense == ITEM_SHIELD){
					creatures[PLAYER]->defense += 50;
				}
			}

			if (equiped == false)
				printf("You can't equip that item.\n\n");
		}
		}
	
			

	
		}
void world::Unequip_item(const String& item_name){
	//This is for unquiping weapons
	if (item_name == "sword" || item_name == "hammer" || item_name == "peak"){
		creatures[PLAYER]->item = -1;
		creatures[PLAYER]->attack = 10;
	}		
	else if (item_name == "AttackCard" || item_name == "DefenseCard" || item_name == "HPCard"){
		creatures[PLAYER]->special_card = -1;
		creatures[PLAYER]->attack -= 5;
	}
	else if (item_name == "shield"){
		creatures[PLAYER]->defense = 5;

	}
		printf("You unequiped the %s.\n\n", item_name.string);
	
	}
void world::BuyItem(int creature){
	char item_to_buy[20]; 
	printf("%s shop: \n", creatures[creature]->name); 
	for (int i = 0; i < MAX_OBJECTS; i++){
		if (creatures[creature]->inventory[i] != -1)
			printf("- %s     Cost: %d\n", creatures[creature]->item_name(creatures[creature]->inventory[i]), items[creatures[creature]->inventory[i]]->cost);
	}
	printf("\n>: "); 
	scanf_s("%s", item_to_buy, 20); 
	String item_buy(item_to_buy); 
	if (item_buy == "stats"){
		printf("\nHP: %d\nAttack: %d\nDefense: %d\nCoins: %d\n\n", creatures[PLAYER]->hp, creatures[PLAYER]->attack, creatures[PLAYER]->defense, creatures[PLAYER]->coins);
	}
	else if (isin_inventory(item_to_buy, creature)){
		for (int i = 0; i < MAX_OBJECTS; i++){
			if (creatures[creature]->inventory[i] == Get_Num(item_buy) && items[creatures[creature]->inventory[i]]->cost < creatures[PLAYER]->coins){
				if (creatures[creature]->inventory[i] == Get_Num("coins"))
					creatures[PLAYER]->coins += items[creatures[creature]->inventory[i]]->cost;
				else
					creatures[PLAYER]->coins -= items[creatures[creature]->inventory[i]]->cost;

				printf("You bought %s!\n", creatures[creature]->item_name(creatures[creature]->inventory[i]));
				printf("\n"); 
				Full_inventory(Get_Num(item_buy));
				creatures[creature]->inventory[i] = -1;
			}				
		}
	};
}
void world::Sell_Item(const String& item_name, int creature_destination){
	char sell[20];
	char selling_weapon[20];
	char to[20]; 
	char monster[20]; 

	printf("This is your inventory (write 'sell <item> to <creature name>' to sell an object)\n"); 
	Show_sell_inventory(); 
	printf("\n>:"); 
	scanf_s("%s %s %s %s", &sell, 20, &selling_weapon, 20, &to, 20, &monster, 20);
	String selling_weapon_str(selling_weapon); 
	String to_str(to);
	String sell_str(sell);


	if (isin_inventory(selling_weapon, PLAYER) && sell_str == "sell" && to_str == "to"){
		Drop_item(selling_weapon, creatures[PLAYER]->current_room, PLAYER, true); 
		Pick_Item(selling_weapon, creatures[creature_destination]->current_room, creature_destination, true); 
		creatures[PLAYER]->coins += items[ITEM_SWORD]->cost; 
		//printf("You sold the %s and you recibed %d coins for that.", item_name, items[Get_Num(item_name)]->cost);
	}
}

bool world::Enter_Battle(int creature){
	printf("You entered to a battle with %s!!\n\n", creatures[creature]->name);
	int it = 1, special_attacks = 0, special_damage = 0;
	bool win = false;
	char change_Weapon[30];
	char weapon_selected[30];
	char switcher[30];
	bool player_turn = true;
	while (creatures[PLAYER]->hp >= 0 && creatures[creature]->hp >= 0){
		if (player_turn){
			player_turn = false;
			creatures[PLAYER]->damage = creatures[PLAYER]->attack - creatures[creature]->defense;
			if (creatures[PLAYER]->damage < 0)
				creatures[PLAYER]->damage = 0;
			creatures[creature]->hp -= creatures[PLAYER]->damage;
			printf("You hited %s and you did ", creatures[creature]->name);		
			printf("%d damage\n", creatures[PLAYER]->damage);
			Sleep(1500);
		}
		else {
			player_turn = true;
			srand(time(NULL));
			creatures[creature]->attack = rand() % 15;
			creatures[creature]->damage = creatures[creature]->attack - creatures[PLAYER]->defense;

			if (creatures[creature]->damage < 0)
				creatures[creature]->damage = 0;
			creatures[PLAYER]->hp -= creatures[creature]->damage;
			printf("%s hited you and did ", creatures[creature]->name);
			printf("%d damage.\n", creatures[creature]->damage);
			Sleep(1500);
		}
		
			if (creatures[creature]->hp <= 0){
				creatures[creature]->death = true; 
				printf("\nYou killed %s !! He left ", creatures[creature]->name);
				printf("%d", creatures[creature]->coins);
				printf(" coins and a %s", creatures[creature]->item_name(creatures[creature]->item));
				printf("\n\n");
				creatures[PLAYER]->coins += creatures[creature]->coins; 
				return false;
			}
			else if (creatures[PLAYER] <= 0){
				printf("\nYou lost the game because you died, the blame is on %s!!!TRY NEXT TIME :D \n \n <press anny button to close the game>", creatures[creature]->name);
				getchar();
				return true;
			}
		
		if (it == 5){
			printf("\n5 turns spended! Wanna take something from your backpack or throw an special attack? (write yes or no)");
			printf("\nActual battle state: You: %d    %s: //", creatures[PLAYER]->hp, creatures[creature]->name);
			printf("%d", creatures[creature]->hp);
			printf("\n\n>:");
			scanf_s("%s", &switcher, 30);
			printf("\n");
			String switch_str(switcher);
			if (switch_str == "yes" || switch_str == "Yes"){
				printf("This are your current items:\n");
				Show_inventory();
				printf("These are your special attacks (write special to use): %d \n\n>: ", special_attacks);
				scanf_s("%s", &weapon_selected, 30);
				printf("\n");
				String weapon_str(weapon_selected);
				if (weapon_str == "special" && special_attacks > 0){
					special_attacks--;
					special_damage = rand() % 20 + 30;
					printf("Critical hit! You did %d damage!\n", special_damage);
					creatures[creature]->hp -= (special_damage - creatures[creature]->defense);
					Sleep(1500);
				}
				else if (exist_item(weapon_str)){
					if (creatures[PLAYER]->item != -1)
						Unequip_item(creatures[PLAYER]->item_name(creatures[PLAYER]->item));
					Equip_item(weapon_str);
				}
				else
					printf("You can't do that");
			}

		}
		if (it == 10){
			printf("\n10 turns spended, you have an special attack available, pres U to use it, and S to save it.\n");
			printf("\nActual battle state: You: %d %s: ", creatures[PLAYER]->hp, creatures[creature]->name);
			printf("%d", creatures[creature]->hp);
			printf("\n\n>:");
			scanf_s("%s", &change_Weapon, 30);
			String weapon_str2(change_Weapon);
			if (weapon_str2 == "U"){
				printf("\nSpecial Attack");
				Sleep(1500);
				printf(". ");
				Sleep(1500);
				printf(" . ");
				Sleep(1500);
				printf(" .");
				Sleep(1500);
				special_damage = rand() % 40 + 30;
				printf("\nCritical hit! You did %d damage!\n", special_damage);
				Sleep(1500);
				creatures[creature]->hp -= (special_damage - creatures[creature]->defense);
			}
			else if (weapon_str2 == "S")
				special_attacks++;

			it = 0;
		}
		it++;
	}
	return false; 
}

void world::Put_Objects(const String & move, int current_room){
	char into[5];
	char destination[20];
	scanf_s("%s %s",&into, 5, &destination, 20);

	String into_str(into);
	String destination_str(destination);

	printf("\n");
	if (isin_inventory(move, PLAYER)){
		if ((move == "glass" && destination_str == "fireplace" && simple_obj[SIMPLE_FIREPLACE]->moved == false)){
			simple_obj[SIMPLE_FIREPLACE]->moved = true;
			printf("You turned off the fireplace, there is no burning now so you realize a little gold shining that seems to be a key!\n\n");
		}

		if ((move == "wick" && destination_str == "gunpowder" && isin_inventory(move, PLAYER) && isin_inventory(destination_str, PLAYER))){
			printf("You mixed those elements and you crafted a bomb!\n\n");
			for (int i = 0; i < MAX_OBJECTS; i++){
				if (creatures[PLAYER]->inventory[i] == ITEM_WICK || creatures[PLAYER]->inventory[i] == ITEM_GUNPOWDER_CONTAINER){
					creatures[PLAYER]->inventory[i] = -1;
				}
			}
			Full_inventory(ITEM_BOMB); 
		}		
	}
}
void world::Get_object_from_object(const String& item_name, int current_room){
	char from[5];
	char container[20];
	scanf_s("%s %s", &from, 5, &container, 20);
	String into_str(from); 
	String container_str(container); 

	if (isin_item(item_name, container_str) && items[Get_Num(item_name)]->item_room == creatures[PLAYER]->current_room){
		int item_num = Get_Num(item_name);
		int container_num = Get_Num(container_str); 
		Full_inventory(item_num); 
		Empty_item(item_name, container_str); 
		printf("You picked up the %s.\n\n", item_name); 
		}
	}

void world::Show_object_content(int item_num){
	int count = 0;
	for (int i = 0; i < MAX_ITEMS_STORAGE; i++){
		if (items[item_num]->prov_inv[i] != -1)
			printf("- %s.\n", items[item_num]->Get_Name(items[item_num]->prov_inv[count++]));
		else
			continue; 
	}
	printf("\n"); 
}
int world::Get_Num(const String& item_name) const{
	if (item_name == "glass")
		return ITEM_GLASS;
	else if (item_name == "key")
		return ITEM_KEY;
	else if (item_name == "matchstick")
		return ITEM_MATCHSTICK;
	else if (item_name == "sword")
		return ITEM_SWORD;
	else if (item_name == "chest")
		return ITEM_CHEST;
	else if (item_name == "AttackCard")
		return ITEM_ATTACK_CARD;
	else if (item_name == "hammer")
		return ITEM_HAMMER;
	else if (item_name == "note")
		return ITEM_HAMMER;
	else if (item_name == "shield")
		return ITEM_SHIELD;
	else if (item_name == "peak")
		return ITEM_PEAK;
	else if (item_name == "gunpowder")
		return ITEM_GUNPOWDER_CONTAINER;
	else if (item_name == "DefenseCard")
		return ITEM_DEFENSE_CARD;
	else if (item_name == "strongbox")
		return ITEM_STRONGBOX;
	else if (item_name == "wick")
		return ITEM_WICK;
	else if (item_name == "bomb")
		return ITEM_BOMB;
	else if (item_name == "fan")
		return ITEM_FAN;
	else if (item_name == "HPCard")
		return ITEM_HP_CARD;
	else if (item_name == "flamethrower")
		return ITEM_FLAMETHROWER;
	else if (item_name == "canonboux")
		return ITEM_CANONBOUX;
	else if (item_name == "waterwall")
		return ITEM_WATERWALL;
	else if (item_name == "TNT")
		return ITEM_TNT;
	else if (item_name == "diploma")
		return ITEM_DIPLOMA;
	else if (item_name == "belt")
		return ITEM_ATTACK_BELT;
	else if (item_name == "coins")
		return ITEM_COIN_BOX;
	else if (item_name == "uzy")
		return ITEM_UZY;
	else if (item_name == "knife")
		return ITEM_KNIFE;
	else if (item_name == "posion")
		return ITEM_POSION;
	else if (item_name == "armos")
		return ITEM_ARMOR;
	else
		return -1;

}
int world::Get_Simple_Num(const String& item_name) const{
	if (item_name== "shelving")
		return SIMPLE_SHELV;
	else if (item_name == "fireplace")
		return SIMPLE_FIREPLACE;
	else if (item_name == "drawer")
		return SIMPLE_DRAWER;
	else if (item_name == "closet")
		return SIMPLE_CLOSET;
	else if (item_name == "chest")
		return SIMPLE_CHEST;
	else if (item_name == "fishgate")
		return SIMPLE_FISHGATE;
	else if (item_name == "lever")
		return SIMPLE_LEVER;
	else if (item_name == "container")
		return SIMPLE_CONTAINER;
	else if (item_name == "strongbox")
		return SIMPLE_STRONGBOX;
	else if (item_name == "dust")
		return SIMPLE_DUST;
	else if (item_name == "window_s")
		return SIMPLE_WINDOW1;
	else if (item_name == "window_e")
		return SIMPLE_WINDOW2;
	else if (item_name == "window_w")
		return SIMPLE_WINDOW3;
	else
		return -1;

}
int world::Get_Item_Room(int item_num) const{
	switch (item_num){
	case ITEM_GLASS: return items[ITEM_GLASS]->item_room; break;
	case ITEM_KEY: return items[ITEM_KEY]->item_room; break;
	case ITEM_MATCHSTICK: return items[ITEM_MATCHSTICK]->item_room; break;
	case ITEM_SWORD: return items[ITEM_SWORD]->item_room; break;
	case ITEM_CHEST: return items[ITEM_CHEST]->item_room; break;
	case ITEM_ATTACK_CARD: return items[ITEM_ATTACK_CARD]->item_room; break;
	case ITEM_HAMMER: return items[ITEM_HAMMER]->item_room; break;
	case ITEM_NOTE: return items[ITEM_NOTE]->item_room; break;
	case ITEM_SHIELD: return items[ITEM_SHIELD]->item_room; break;
	case ITEM_PEAK: return items[ITEM_PEAK]->item_room; break;
	case ITEM_GUNPOWDER_CONTAINER: return items[ITEM_GUNPOWDER_CONTAINER]->item_room; break;
	case ITEM_DEFENSE_CARD: return items[ITEM_DEFENSE_CARD]->item_room; break;
	case ITEM_STRONGBOX: return items[ITEM_STRONGBOX]->item_room; break;
	case ITEM_WICK: return items[ITEM_WICK]->item_room; break;
	case ITEM_BOMB: return items[ITEM_BOMB]->item_room; break;
	case ITEM_FAN: return items[ITEM_FAN]->item_room; break;
	case ITEM_HP_CARD: return items[ITEM_HP_CARD]->item_room; break;
	case ITEM_FLAMETHROWER: return items[ITEM_FLAMETHROWER]->item_room; break;
	case ITEM_CANONBOUX: return items[ITEM_CANONBOUX]->item_room; break;
	case ITEM_WATERWALL: return items[ITEM_WATERWALL]->item_room; break;
	case ITEM_TNT: return items[ITEM_TNT]->item_room; break;
	case ITEM_DIPLOMA: return items[ITEM_DIPLOMA]->item_room; break;
	}
}
unsigned int world::Carried_Obj_Numb(){
	int obj_numb = 0; 
	for (int i = 0; i < ITEMS_NUMB; i++){
		if (items[i]->carried == true)
			obj_numb++; 
	}
	return obj_numb; 
}
void world::Hit_Stuff(const String& move){
	char item[20];
	char with[5];
	scanf_s("%s %s", &with, 5, &item, 20);

	String item_str(item);
	String with_str(with);

	if (creatures[PLAYER]->current_room == EARTH_CORRIDOR && (move == "rock" || move == "rocks") && item_str == "peak" && isin_inventory("peak", PLAYER)){
		exit[14]->open = true;
		printf("You hit the rock with the peak and you broke the wall, now you can go in.\n\n "); 
	}

}
void world::Empty_item(const String& item_name, const String& container_str){
	int item_num = Get_Num(item_name);
	int container_num = Get_Num(container_str);
	for (int i = 0; i < MAX_ITEMS_STORAGE; i++){
		if (item_num == items[container_num]->prov_inv[i])
			items[container_num]->prov_inv[i] = -1; 
	}
}
bool world::exist_item(const String& item_name) const{
	int returning = Get_Num(item_name); 
	return returning != -1; 
}
void move_NPC(creature* seller){
	int direction = rand() % 3; 

}










