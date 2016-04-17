#include "Inventory.h"

/*template <class T>
inventorys<T>::inventorys(){
	inventory = new T[capacity];
}
template <class T>
inventorys<T>::inventorys(unsigned int memory) :capacity(memory){
}
template <class T>
inventorys<T>::inventorys(const inventorys& vector2) : capacity(vector2.capacity){
	num_elements = vector2.num_elements;
	capacity = vector2.capacity;
	inventory = new T[capacity];
	for (unsigned int i = 0; i < num_elements; i++){
		inventory[i] = vector2.inventory[i];
	}

}
template <class T>
void inventorys<T>::Push_Back(T numb){
	if (capacity == num_elements){
		capacity += 1;
		T* buffer2 = new T[capacity];
		int count = 0;
		for (count; count < num_elements; count++)
			buffer2[count] = inventory[count];
		buffer2[count] = numb;
		num_elements++;
		delete[] inventory;
		inventory = buffer2;
	}
	else
		inventory[num_elements++] = numb;
}
template <class T>
void inventorys<T>::Push_Front(T numb){
	if (capacity == num_elements){
		capacity += 1;
		T* buffer2 = new T[capacity];
		int count = 1;
		buffer2[0] = numb;
		for (count; count < num_elements + 1; count++)
			buffer2[count] = inventory[count - 1];
		num_elements++;
		delete[] inventory;
		inventory = buffer2;
	}
	else{
		num_elements++;
		inventory[0] = numb;
		for (int i = 0; i < capacity; i++){
			inventory[i + 1] = inventory[i];
		}
	}

}
template <class T>
int inventorys<T>::Pop_Back(){
	int number = inventory[--num_elements];
	T* buffer2 = new T[num_elements];
	int count = 0;

	for (count; count < num_elements; count++){
		buffer2[count] = inventory[count];
	}
	delete[] inventory;
	inventory = buffer2;
	return number;
}
template <class T>
bool inventorys<T>::isempty(){
	return(inventory[0] == '\0');
}
template <class T>
const String& inventorys<T>::Get_Name(int item_num){
	switch (item_num){
	case 0: return "glass"; break;
	case 1: return "key"; break;
	case 2: return "matchstick"; break;
	case 3: return "sword"; break;
	case 4: return "chest"; break;
	case 5: return "+5-AttackCard"; break;
	case 6: return "hammer"; break;
	}
}
template <class T>
inventorys<String>* inventorys<T>::Tokenize(String input){
	inventorys<String>* total_string = new inventorys<String>;
	String* word = new String[input.length()];
	uint i;
	char separator = ' ';
	for (i = 0; input.string[i] != '\0'; i++){
		if (input.string[i] != separator){
			if (isupper(input.string[i]))
				tolower(input.string[i]);

			if (!word->isempty()){
				total_string->Push_Back(word);
				word->empty();
			}
			else
				word->string[i] = input.string[i];
		}
	}
	return total_string;
}
template <class T>
T& inventorys<T>::operator[](int pos)const{
	return inventory[pos];
}
template <class T>
T& inventorys<T>::operator[](int pos){
	assert(pos < num_elements)
		return inventory[pos];
}
template <class T>
inventorys<T>::~inventorys(){

}*/