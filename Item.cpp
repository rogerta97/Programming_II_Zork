#include "Item.h"
#include <string.h>

#define MAX_OBJECTS 10

int item::Get_Room(int item_num){
	switch (item_num){
		case 0: return 2; break;
		case 1: return 2; break; 
		case 2: return 4; break;
		case 3: return 4; break; 		
	}
}
char* item::Get_Name(int item_num) const{
switch (item_num){
	case 0: return "glass"; break;
	case 1: return "key"; break;
	case 2: return "matchstick"; break;
	case 3: return "sword"; break;
	}
}
