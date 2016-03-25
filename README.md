# Programming_II_Zork
This is a repository in which I will be developing my own version of Zork text adventure.
___
You move with go + nort/south/east/west.

Write "open" to open a door and "close" for closing it. 

Write "quit game" for quiting the game. 

Write "help me" for asking for help. 

Write "look" to see what you have arround you. 
___
## 0.2

In the first delivering, the unique funciontallity of the game is moving arround the map and being able to open one door, the comands 
must be inserted like: (action)(direction/item). 

##0.3

In the second delivery I improved the following aspects: 
	- I deleted al the memory leaks. 
	- I split the program to the number of functions that were needed, not having all the program on CreateWorld();
	- I improved the general structure of the scanf_s in order to be more general. 
	- I made a new class called entity, this contains names and descrptions and each room and exit will have his own.  
