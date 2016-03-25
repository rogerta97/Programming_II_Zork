# Programming_II_Zork
This is a repository in which I will be developing my own version of Zork text adventure.

You move with go + nort/south/east/west.

write "open" to open a door and "close" for closing it. 

write "quit game" for quiting the game. 

write "help me" for asking for help. 

write "look" to see what you have arround you. 

## 0.2

In the first delivering, the unique funciontallity of the game is moving arround the map and being able to open one door, the comands 
must be inserted like: (action)(direction/item). 

##0.3

2: In the second delivery I improved the following aspects: 
	- I deleted al the memory leaks. 
	- I split the program to the number of functions that were needed, not having all the program on CreateWorld();
	- I improved the general structure of the scanf_s in order to be more general. 
	- I made a new class called entity, this contains names and descrptions and each room and exit will have his own.  
