#ifndef _LIST_H_
#define _LIST_H_

template <class TYPE>
class List{
public:
	struct node : List{
		friend class List;
		TYPE data;
		node* next = nullptr;
		node* prev = nullptr;
		node(){}
		node(TYPE data) : data(data){}
		node* prev_node(){
			return prev;
		}
		node* next_node(){
			return next;
		}
	};

	node* start = nullptr;

	//Constructor
	List() : size(0){}

	//Methods
	node* push_back(const TYPE& data){
		node* new_node = new node(data);

		if (is_empty()){
			start = new_node;
		}
		else{
			node* last = new node;
			last = back_node();
			last->next = new_node;
			new_node->prev = last;
		}
		size++;
		return new_node;
	}
	node* push_front(const TYPE& data){
		node* new_node = new node(data);
		if (is_empty()){
			start = new_node;
		}
		else{
			new_node->next = start;
			start->prev = new_node;
			start = new_node;;
		}
		size++;
		return new_node;
	}
	node* insert(const TYPE& data, int position){
		node* new_node = new node(data);
		if (!is_empty()){
			node* to_change = at(position);
			node* prev_node = to_change->prev_node();
			node* next_node = to_change->next_node();

			new_node->prev = prev_node;
			new_node->next = next_node;
			next_node->prev = new_node;
			prev_node->next = new_node;
		}
		else{
			start = new_node;
		}
		size++;
		return new_node;
	}
	void reverse(){
		List<TYPE> sltn;
		for (int i = 1; i <= size; i++){
			sltn.push_back(at(size - i)->data);
		}
		*this = sltn;
	}
	//void swap(int pos1, int pos2){
	//	node* temp; 
	//	node* first = at(pos1); 
	//	node* second = at(pos2); 
	//	temp->data = second->data; 
	//	second->data = first->data;
	//	first->data = temp->data;
	//}
	void erase(int position){
		node* to_erase = at(position);
		node* prev_node = to_erase->prev_node();
		node* next_node = to_erase->next_node();

		prev_node->next = next_node;
		next_node->prev = prev_node;
		delete to_erase;

	}
	void del_nodes(int numb_of_nodes, int starting_pos){
		for (int i = 0; i < size; i++){
			if (i == starting_pos - 1){
				int finished = 0;
				while (finished < numb_of_nodes){
					erase(i);
					finished++;
				}
				break;
			}
		}
	}

	//Utils
	inline bool is_empty(){
		return (start == nullptr);
	}
	node* back_node(){
		if (!is_empty()){
			node* last = new node;
			last = start;
			while (last->next != nullptr){
				last = last->next;
			}
			return last;
		}
	}
	node* at(int position){
		node* count = new node;
		count = start;
		int count_pos = 0;
		if (position + 1 == size){
			return back_node();
		}
		while (count_pos < position){
			count_pos++;
			count = count->next;
		}
		return count;
	}
	void print(){
		if (!is_empty()){
			node* last = new node;
			last = start;
			while (last->next != nullptr){
				printf("%d ", last->data);
				last = last->next;
			}
			printf("%d\n", last->data);
		}
	}
	inline node* operator[](int pos){
		return at(pos);
	}

private:
	int size;
};

#endif