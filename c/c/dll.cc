#include <iostream>
#include <exception>
using namespace std;

template<typename T>
class List {
    struct Node{
        Node* next_;
        Node* prev_;
        T data_;

        Node(T val) {
            data_=val;
        }

    };

    Node* head_;

public:
    List() : head_(new Node(0)){
        head_->next_ = head_->prev_ =head_;
    }

    ~List() {
        while(!empty()){
            pop_front();
        }
        delete head_;
    }

    bool empty() const {
        return head_->next_ == head_;
    }

    T& front() const {
        if(empty()){
            throw exception();
        }
        return head_->next_->data_;
    }

    T& back() const {
        if(empty()) {
            throw exception();
        }
        return head_->prev_->data_;
    }

    void push_front(T val) {
        Node* front = head_->next_;
        Node* ptr = new Node(val);

        head_->next_ = ptr;
        ptr-> prev_ = head_;

        ptr->next_ = front;
        front->prev_ = ptr;
    }

    void push_back(T val) {
        Node* back = head_->prev_;
        Node* ptr = new Node(val);

        head_->prev_ = ptr;
        ptr->next_ = head_;

        back->next_ = ptr;
        ptr->prev_ = back;
    }

    void pop_front() {
        if(empty()) {
            throw exception();
        }
        Node* front = head_->next_;
        Node* new_front = front->next_;

        new_front->prev_ = head_;
        head_->next_ = new_front;

        delete front;
    }

    void pop_back() {
        if(empty()) {
            throw exception();
        }
        Node* back = head_->prev_;
        Node* new_back = back->prev_;

        new_back->next_ = head_;
        head_->prev_ = new_back;

        delete back;
    }
};


int main() {
    List<int> list;

    list.push_back(2);
    list.push_back(3);
    list.push_front(1);
    cout << "list1::front: " << list.front() << endl;
    cout << "list1::back: " << list.back() << endl;

    list.pop_back();
    cout << "list1::back: " << list.back() << endl;

    List <char*> list2;
    list2.push_back("asd");
    list2.push_back("asd");
    list2.push_front("sadsd");
    cout << "list2::front: " << list2.front() << endl;
    cout << "list2::back: " << list2.back() << endl;


    return 0;
}


