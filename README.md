# Programming_II_Zork
This is a repository in which I will be developing my own version of Zork text adventure.
___
You move with go + nort/south/east/west.

Write "open" + item / "close" + item for open something. 

Write "quit" for quiting the game. 

Write "help" for having some extra help. 

Write "look" to see what you have arround you. 

Write "pick + item" to pick something to your inventory. 

Write "put <item> into <item/object>" to put something inside and object, or use something against something"

Write "equip + item" to equip something.

Write "inventory" to check your inventory.

Write "stats" to chek your combat stats. (will crash on v0.3.3)
___
## 0.2

In the first delivering, the unique funciontallity of the game is moving arround the map and being able to open one door, the comands 
must be inserted like: (action)(direction/item). 


2: In the second delivery I improved the following aspects: 
=======
##0.3

In the second delivery I improved the following aspects: 

	- I deleted al the memory leaks. 
	- I split the program to the number of functions that were needed, not having all the program on CreateWorld();
	- I improved the general structure of the scanf_s in order to be more general. 
	- I made a new class called entity, this contains names and descrptions and each room and exit will have his own.  

=======

3: In the third commit I made the following implementations: 
v 0.3.2

	- I implemented space for the combat stats of the player (HP, Attack, defense, special habilities)
	- I improved the constructors of every part of the game. 
	- I placed some of the objects in the right place, the funcionality is almost done. 
	- Now the object is able to pick things and drop them, those will be saved into and inventory that I created. 
	- The player is able too to move some objects (need to be improved) in order to be able to find other ones. In less words, the player can interact with the envoirment. 
	- Now we use Strings instead of const char* for some cases. 
	- The player is able to equip and unequip things and to see the inventory and the actual stats. 

=======

4: In the fourth commit I made the following improvements: 
v0.3.3 (althoug there are all the comands working, there is no 0.4 since I have to place all the objects, but the funciontallity is done)

	- I crated the action of put an object inside another object, that can be used to for taking use of the objects, for example, put figure into table.
	- I improved the constructor of the items, now they accept a bool depending on if the object can storage other objects inside. 
	- I created a class and a file for the inventory, it's the base class of player and items, carrying it's respective objects, with it's respective contstructor. 
	-

