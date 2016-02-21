#include <stdio.h> 
#include <stdlib.h>
#include <time.h>



int pick_up_object_numb(int x, int y, int** objects_map, char* carrying_objects[5], char* objects[5], char*house[][4]){
	
	int count = 0, keeper_count;
	
	char Yes_Not;

	int object_found = objects_map[x][y]; 
	if (objects_map[x][y] != 6 && house[x][y] != "//"){
		printf("You found a %s! Do you want to pick it up? (Y/N)\n", objects[object_found]);
		scanf_s(" %c", &Yes_Not, 1);
		getchar();

		if (Yes_Not == 'Y'){
				objects[count++] = objects[object_found]; //Adding the object to the array of the objects that you are carrying. 
				objects_map[x][y] = 6;
				printf("Object taken.\n");
				return 1;
		}
		else if (Yes_Not == 'N'){
			printf("Not taken.\n");
			return 0;
		}
	}
	
	
}
void moving(char* house[][4], int** objects_map, int x, int y, char* carrying_objects[5], char* objects[5]){
	int quit = 0, total_objects = 0;

	while (quit == 0){
		char move;
		printf("Next move:"); 
		scanf_s("%c", &move, 1);
		switch (move){
		case 'n':
			x -= 1;
			if (house[x][y] == "//" || house[x][y] == "pantry"){
				printf("You can't pass through the walls.\n");
				x += 1;}
			printf("You are in the %s.\n", house[x][y]);
			if (objects_map[x][y] != 6) //If there is an object will ask for picking it up (6 == No item). 
				total_objects = total_objects + pick_up_object_numb(x, y, objects_map, carrying_objects, objects, house); //If you pick 1 item up it will return 1. 
			break;

		case 's':
			x += 1;
			if (house[x][y] == "//" || house[x][y] == "bathroom"){
				printf("You can't pass through the walls.\n");
				x -= 1;}
			printf("You are in the %s.\n", house[x][y]);
			if (objects_map[x][y] != 6)
				total_objects = total_objects + pick_up_object_numb(x, y, objects_map, carrying_objects, objects, house);
			break;

		case 'e':
			y += 1;
			if (house[x][y] == "//"){
				printf("You can't pass through the walls.\n");
				y -= 1;
			}
			printf("You are in the %s.\n", house[x][y]);
			if (objects_map[x][y] != 6)
				total_objects = total_objects + pick_up_object_numb(x, y, objects_map, carrying_objects, objects, house);
			break;

		case 'w':
			y -= 1;
			if (house[x][y] == "//"){
				printf("You can't pass through the walls.\n");
				y += 1;}
			printf("You are in the %s.\n", house[x][y]);
			if (objects_map[x][y] != 6)
				total_objects = total_objects + pick_up_object_numb(x, y, objects_map, carrying_objects, objects, house);
			break;

		case 'q':
			quit = 1;
			break;

		default:
			printf("Invalid imput.\n");
			}
		getchar();
	}
	printf("You exit the house.\nYou collected %d items.\n", total_objects);
	int i; 
	for (i = 0; i < total_objects; i++){
		printf("%d. %s\n", (i+1), objects[i]); 
	}
}
int** place_objects(void){
	int i, j; 
	srand(time(NULL)); 
	int** objects_map = (int**)malloc(5*sizeof(int)); 

	for (i = 0; i < 4; i++){
		objects_map[i] = (int*)malloc(4 * sizeof(int));
		for (j = 0; j < 3; j++){ 
			if ((i == 1 && j == 1) || (i == 2 && j == 1) || (i == 3 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 2))
				objects_map[i][j] = rand() % 5;
			else
				objects_map[i][j] = 6; //No item
		}
	}

	return objects_map; 
}
