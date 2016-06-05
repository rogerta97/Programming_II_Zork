#ifndef _VECTOR_H_
#define _VECTOR_H_ 

#define BLOCK 10

typedef unsigned int uint;

template <class TYPE>
class Vector{
private:
	TYPE* data = nullptr;
	int max_capacity = BLOCK;
	int num_elements = 0;

public:
	Vector(){
		Alloc(BLOCK);
	}
	void push_back(const TYPE& item){
		int count = 0;
		if (num_elements >= max_capacity){
			Alloc(max_capacity + BLOCK);
		}
		data[num_elements++] = item;
	}
	void insert(const TYPE& item, int position){
		if (position >= num_elements){
			push_back(item);
		}
		if (num_elements >= max_capacity){
			Alloc(max_capacity + BLOCK);
		}
		int i;
		for (i = num_elements; i > position - 1; i--){
			data[i] = data[i - 1];
		}
		data[i] = item;
		for (i; i >= 0; i--){
			data[i] = data[i];
		}
		num_elements++;
	}
	void insert(const Vector<TYPE> vect2, int pos){
		if ((num_elements + vect2.num_elements) >= max_capacity){
			Alloc(num_elements + vect2.num_elements + BLOCK);
		}
		int i, total_elements = num_elements + vect2.num_elements, j = 1;
		for (i = total_elements - 1; i > vect2.num_elements + pos - 2; i--){
			data[i] = data[num_elements - j++];
		}

		for (j = 1; j <= vect2.num_elements; j++){
			data[i] = vect2.data[(vect2.num_elements) - j];
			i--;
		}
		i--;
		unsigned int aux = 2;
		for (i; i >= 0; i--){
			data[i] = data[i];
		}

		num_elements += vect2.num_elements;

	}
	bool pop_back(TYPE& container){
		if (num_elements > 0){
			container = data[--num_elements];
			return true;
		}
		return false;
	}
	bool erase(int position){
		if (position <= num_elements){
			for (int i = position - 1; i < num_elements; i++){
				data[i] = data[i + 1];
			}
			num_elements--;
			return true;
		}
		return false;
	}
	bool erase_value(int value){
		int count = 0;
		int returner = false; 
		while (count < num_elements){
			if (data[count] == value){
				returner = true;
				erase(count); 
			}		
		}
		num_elements--;
		return returner; 
	}
	void insert_prefix(const Vector& vect2){
		if (vect2.num_elements + this->num_elements > max_capacity){
			Alloc(vect2.num_elements + this->num_elements + BLOCK);
		}
		insert(vect2, 1);
	}
	void remove_repeated(){
		Vector<TYPE> visited;
		visited.push_back(data[0]);
		for (int i = 1; i < this->num_elements; i++){
			if (visited.is_in_vector(data[i]))
				visited.push_back(data[i]);
		}
		*this = visited;
	}

	//Utils
	bool isempty(){
		return (num_elements == 0);
	}
	int capacity(){
		return max_capacity;
	}
	void clear(){
		num_elements = 0;
	}
	/*void print(){
		for (int i = 0; i < num_elements; i++){
			printf("%d ", data[i]);
		}
	}*/
	int is_in_vector(const TYPE& item){
		for (int i = 0; i < num_elements; i++){
			if (data[i] == item){
				return i;
			}
		}
		return -1;
	}
	int size(){
		return num_elements; 
	}
	void print(){
		int max = 10; 	
		for (uint i = 0; i < num_elements && !isempty(); i++){
			printf("- %s\n", item_name(data[i]));
		}
		printf("\n"); 
	}
	
	void operator=(const Vector& vect2){
		if (this->max_capacity < vect2.num_elements){
			Alloc(vect2.num_elements + BLOCK);
		}
		int i = 0;
		for (i; i < vect2.num_elements; i++){
			data[i] = vect2.data[i];
		}
		//This is the "chapuza"
		for (i; i < num_elements; i++){
			data[i] = '\0';
		}

	}
	TYPE operator[](int numb) const{
		return data[numb];
	}
	TYPE& operator[](int numb){
		return data[numb];
	}

	//Others
	void Alloc(int size){
		TYPE* tmp = data;
		data = new TYPE[size];

		max_capacity = size;
		for (int i = 0; i < num_elements; i++){
			data[i] = tmp[i];
		}
	}
	char* item_name(int item_num){
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
		case 17: return "firethrower"; break;
		case 18: return "canonboux"; break;
		case 19: return "waterwall"; break;
		case 20: return "TNT"; break;
		case 21: return "diploma"; break;
		case 22: return "belt"; break;
		case 23: return "coins"; break;
		case 24: return "uzy"; break;
		case 25: return "knife"; break;
		case 26: return "posion"; break;
		case 27: return "armor"; break;
		}
	}

};

#endif