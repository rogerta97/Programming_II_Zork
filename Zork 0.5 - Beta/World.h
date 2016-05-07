#include <iostream>
#include "Vector.h"
#include "Inventory.h"
#include "Player.h"
#include "Entity.h"
#include "Item.h"
#include "Exits.h"
#include "Strings.h"
#include "Simple_Objects.h"
#include "Rooms.h"

#define ROOMS_NUMB 18
#define EXITS_NUMB 17
#define ITEMS_NUMB 12
#define SIMPLE_NUMB 5

class world{
private:

	void move_character(const String&, bool&, bool&);
	void Move_Simple_Obj(const String&);

	void Pick_Item(const String&, int);	
	void Drop_item(const String&, int);
	void look_item(const String&);
	bool isin_item(const String&, const String&); 
		
	void Open_Stuff(int current_room, bool& action_done, int object_open, const String&);
	void Close_Stuff(int current_room, bool& action_done, int object_open, const String&);

	void Full_inventory(int);
	void empty_inventory(int);
	void Show_inventory() const;
	bool isin_inventory(const String&);

	void Equip_item(const String&);
	void Unequip_item(const String&);

	void Put_Objects(const String&, int);
	void put_object_into_object(const String&, int);
	void Get_object_from_object(const String&, int); 
	void Show_object_content(int); 

	int Get_Num(const String&) const;
	int Get_Simple_Num(const String&) const;
	int Get_Item_Room(int item_num) const;
	unsigned int Carried_Obj_Numb();
	void Hit_Stuff(const String&);
	void Empty_item(const String&, const String&);


	enum rooms{
		WEIRD_BEDROOM,
		FIRE_CORRIDOR,
		BURNER,
		EMPTY_ROOM,
		OLD_DAD_ROOM,
		WIND_CORRIDOR,
		OLD_MUM_ROOM,	
		STDUYING_ROOM, 
		BIG_WINDOW_ROOM,
		WATER_CORRIDOR,
		AQUARIUM,
		STICK_CONTAINER,
		LONELY_BATHTUB,
		EARTH_CORRIDOR,
		MINE,
		BLACK_HOLE,
		DRAWING_ROOM,
		FINAL_BOSS_ROOM,
	};
	enum items{
		ITEM_GLASS,
		ITEM_KEY,
		ITEM_MATCHSTICK,
		ITEM_SWORD,
		ITEM_CHEST,
		ITEM_ATTACK_CARD,
		ITEM_HAMMER,
		ITEM_NOTE,
		ITEM_SHIELD,
		ITEM_PEAK,
		ITEM_GUNPOWDER_CONTAINER,
		ITEM_DEFENSE_CARD,
		ITEM_STRONGBOX,
		ITEM_WICK,
		ITEM_BOMB,
		ITEM_FAN,
		ITEM_HP_CARD,
	};
	enum open_or_close_type{
		INTERACT_DOOR,
		INTERACT_DRAWER,
		INTERACT_CLOSET,
		INTERACT_CHEST,
		INTERACT_STRONGBOX,
		INTERACT_WINDOW,
	};
	enum simple_objects{
		SIMPLE_SHELV,
		SIMPLE_FIREPLACE,
		SIMPLE_DRAWER,
		SIMPLE_CLOSET,
		SIMPLE_CHEST,
		SIMPLE_FISHGATE,
		SIMPLE_LEVER,
		SIMPLE_CONTAINER, 
		SIMPLE_STRONGBOX,
		SIMPLE_DUST, 
		SIMPLE_WINDOW1,
		SIMPLE_WINDOW2,
		SIMPLE_WINDOW3,

	};


public:
	void CreateWorld();
	void Check_input();
	void Destroy_World(); 

	Vector <Rooms*> room;
	Vector <exits*> exit;
	player* main_character;
	Vector <item*> items;
	Vector <Simple_Objects*> simple_obj;
};