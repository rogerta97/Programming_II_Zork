# Programming_II_Zork
This is a repository in which I will be developing my own version of Zork text adventure.


1: In the first delivering, the unique funciontallity of the game is moving arround the map and being able to open one door, the comands 
must be inserted like: (action)(direction/item). 

2: In the second delivery I improved the following aspects: 
	- I deleted al the memory leaks. 
	- I split the program to the number of functions that were needed, not having all the program on CreateWorld();
	- I improved the general structure of the scanf_s in order to be more general. 
	- I made a new class called entity, this contains names and descrptions and each room and exit will have his own.  
=======
You move with nort/south/east/west.

write "open" to open a door and "close" for closing it. 

write "quit game" for quiting the game. 

write "help me" for asking for help. 

write "look" to see what you have arround you. 

=======
3: In the third commit I made the following implementations: 

	- I implemented space for the combat stats of the player (HP, Attack, defense, special habilities)
	- I improved the constructors of every part of the game. 
	- I placed some of the objects in the right place, the funcionality is almost done. 
	- Now the object is able to pick things and drop them, those will be saved into and inventory that I created. 
	- The player is able too to move some objects (need to be improved) in order to be able to find other ones. In less words, the player can interact with the envoirment. 
	- Now we use Strings instead of const char* for some cases. 
	- The player is able to equip and unequip things and to see the inventory and the actual stats. 

