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

Write "equip + object" to hit something.

Write "inventory" to check your inventory.

Write "stats" to chek your combat stats.

Write "put + item + into + destination" to put something inside something.

Write "get + item + from + destination" to get an object from somewhere
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
##0.4

4: In the fourth commit I made the following improvements: 
v0.4

	- I crated the action of put an object inside another object, that can be used to for taking use of the objects, for example, put figure into table.
	- I improved the constructor of the items, now they accept a bool depending on if the object can storage other objects inside. 
	- I created a class and a file for the inventory, it's the base class of player and items, carrying it's respective objects, with it's respective contstructor. 
	

##0.5
v0.5

	- I completed the game putting all the items in its place. 
	- I implemented the dynamic array in order to make a Push_Back for allocating the rooms, exits and items. 
	- I fully integrated the game with the use of Srting class.
	- I implemented operators for not using strcmp or strcpy, just methods done by us. 
	- I integrated all the simple object, as the messages on the walls, the password, the electricity... 
	- I implemented a combat class for the player in order to hold his stats, they are made of HP, attack and defense. 
	- The special feature implemented was this one, make the player able to have a different attack damage depending on the weapon he is carying, moreover I implemented
		some attack, defense, and hp card that will give you an EXTRA damage or defense. 

v0.6

	- I implemented a class called creature, now this class is the base class for the player and the enemies. 
	- I'm implementing the combat mechanics for the enemies (it's in developement yet). 
	- I added 4 more items, one for each enemy, that the player can pick up if he wins the battle.
	- I implemented the concept of coins. 
 
v0.7

	- I implemented the entire part of the combat mechanics.
	- Inside the combat mechanics, i implemented the cappability for the player to change weapons, if he has something in the inventory. 
	- I implemented an special attack, that will give some random but higher attack. 
	- I implemented the shop, now the user is able to buy and sell items with the creaures. 

v0.9

In this step the functionality of the game is done. 

	- I implemented the final boss with his habilities. 
	- Now when the creature dies it throws coins and a special weapon caracteristic of the element.
        - Coins ar traspassed automatically to the player but the item has to be picked up. 
	- I inserted a price to each item, so when you buy you lose coins and the reverse with selling. 
        - I corrected some bugs lefting in the combat mechanics. 



	- 


