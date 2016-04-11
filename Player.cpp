#include "Player.h"

char* player::item_name(int item_num){
	switch (item_num){
	case 0: return "glass"; break;
	case 1: return "key"; break;
	case 2: return "match"; break;
	case 3: return "sword"; break;
	}
}