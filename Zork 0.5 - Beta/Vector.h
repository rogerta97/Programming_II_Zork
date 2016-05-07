typedef unsigned int uint;

#define BLOCK 4

template <class T>
class Vector{
public:
	T* buffer = nullptr;

private:
	uint capacity = BLOCK;
	uint num_elements = 0;

public:
	Vector(){
		buffer = new T[capacity];
	}

	Vector(unsigned int memory) :capacity(memory){
	}

	Vector(const Vector& vector2) : capacity(vector2.capacity){
		num_elements = vector2.num_elements;
		capacity = vector2.capacity;
		buffer = new T[capacity];
		for (unsigned int i = 0; i < num_elements; i++){
			buffer[i] = vector2.buffer[i];
		}

	}
	void Push_Back(T numb){
		if (capacity == num_elements){
			capacity += 1;
			T* buffer2 = new T[capacity];
			int count = 0;
			for (count; count < num_elements; count++)
				buffer2[count] = buffer[count];
			buffer2[count] = numb;
			num_elements++;
			delete[] buffer;
			buffer = buffer2;
		}
		else
			buffer[num_elements++] = numb;
	}
	void Push_Front(int numb){
		if (capacity == num_elements){
			capacity += 1;
			T* buffer2 = new T[capacity];
			int count = 1;
			buffer2[0] = numb;
			for (count; count < num_elements + 1; count++)
				buffer2[count] = buffer[count - 1];
			num_elements++;
			delete[] buffer;
			buffer = buffer2;
		}
		else{
			num_elements++;
			buffer[0] = numb;
			for (int i = 0; i < capacity; i++){
				buffer[i + 1] = buffer[i];
			}
		}

	}
	int Pop_Back(){
		int number = buffer[--num_elements];
		T* buffer2 = new T[num_elements];
		int count = 0;

		for (count; count < num_elements; count++){
			buffer2[count] = buffer[count];
		}
		delete[] buffer;
		buffer = buffer2;
		return number;
	}
	T operator[](int numb) const{ 
		return buffer[numb]; 
	}
	T& operator[](int numb){
		return buffer[numb];
	}

	~Vector() {
		delete[] buffer; 
	}
};