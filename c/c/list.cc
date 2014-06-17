#include <iostream>
using namespace std;

template<typename T>
class List {
	struct Node {
		T data_;

		Node* prev_;
		Node* next_;

		Node(T val){
			data_=val;
		}

	};

	Node* head_;
	//Node* tail_;

public:

	List()
	:head_(new Node(0))
	{
		head_->next_ = head_->prev_ = head_;
	}

	~List(){
        while(!empty()) {
            pop_front();
        }
        delete head_;
	}

	bool empty() {
		return head_ == 0;
	}

	void push_front(T val){
		Node* new_elem = new Node(val);
		Node* tmp = head_->next_;

		new_elem-> prev_ = head_;
		new_elem-> next_ = tmp;

		head_->next_ = new_elem;
		tmp->prev_ = new_elem;
	}

	void push_back(T val){
		Node* new_elem = new Node(val);
		Node* tmp = head_->prev_;

		new_elem->next_ = head_;
		new_elem->prev_ = tmp;

		head_->prev_ = new_elem;
		tmp->next_ = new_elem;
	}

	T& front() {
		return head_->next_->data_;
	}

	T& back(){
		return head_->prev_->data_;
	}

	void pop_front(){
	    if(empty()){
            cout << "List empty" << endl;
	    }
        Node* front = head_->next_;
        Node* new_front = front->next_;

        head_->next_ = new_front;
        new_front->prev_ = head_;

        delete front;
	}

	void pop_back() {
        if(empty()) {
            cout << "list empty" << endl;
        }

        Node* back = head_->prev_;
        Node* new_back = back->prev_;

        new_back->next_ = head_;
        head_->prev_ = new_back;

        delete back;
	}

	class iterator {

		friend class List;

		Node* curr_elem_;

		iterator(Node* element):
			curr_elem_(element)
		{}

	public:

		T& operator*(){
			return curr_elem_->data_;
		}

		iterator& operator++() {
			curr_elem_=curr_elem_->next_;
			return *this;
		}



	};

	iterator begin(){
		return iterator(head_->next_);
	}

	iterator insert(iterator position, T val) {
		Node* new_elem = new Node(val);
		Node* tmp = position.curr_elem_;

		new_elem->next_ = tmp.next_;
		tmp.next_->prev_ = new_elem;

		tmp->next_ = new_elem;
		new_elem->prev_ = tmp;

		return iterator(new_elem);
	}

};

int main(){

	List<int> l1;

	std::cout << "Empty:" << l1.empty() << std::endl;

	l1.push_front(3);
	l1.push_front(2);
	l1.push_front(1);

    l1.push_back(4);
	cout << "back" << ":" << l1.back() << endl;
	cout << "front" << ":" << l1.front() << endl;

	l1.pop_back();
	cout << "back: " << l1.back() << endl;

	return 0;
}
