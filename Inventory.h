#ifndef	 _INVENTORY_H_
#define	 _INVENTORY_H_

//diferent srotage for different items?

#define MAX_ITEMS_STORAGE 10

class inventorys{
public:
	inventorys(){
		inventory[0] = '\0'; 
	}
	int inventory[MAX_ITEMS_STORAGE]; 
};

#endif