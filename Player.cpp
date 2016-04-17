#include "Player.h"

char* player::item_name(int item_num){
	switch (item_num){
	case 0: return "glass"; break;
	case 1: return "key"; break;
	case 2: return "match"; break;
	case 3: return "sword"; break;
	case 4: return "chest"; break;
	case 5: return "AttackCard"; break;
	case 6: return "hammer"; break; 
	case 7: return "note"; break;
	case 8: return "shield"; break;
	case 9: return "peak"; break;
	case 10: return "gunpowder"; break;
	case 11: return "DefenseCard"; break;
	case 12: return "strongbox"; break;
	case 13: return "wick"; break;
	case 14: return "bomb"; break;
	case 15: return "fan"; break;
	case 16: return "HPCard"; break;
	}
}