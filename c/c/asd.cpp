#include <iostream>
#include <exception>
using namespace std;

template<typename T>
class List{
    struct Node {
        Node* next_;
        Node* prev_;

        T data_;

        Node(T val){
            data_ = val;
        }
    };

    Node* head_;

public:
    List():head_(new Node(0)){
        head_->next_ = head_->prev_ = head_;
    }

    ~List(){
        while(!empty()){
            pop_front();
        }
        delete head_;
    }

    bool empty(){
        return head_ == head_->next_;
    }

    T& front(){
        if(empty()){
            throw exception();
        }
        return head_->next_->data_;
    }

    T& back(){
        if(empty()){
            throw exception();
        }
        return head_->prev_->data_;
    }

    void push_front(T val){
        Node* front = head_->next_;
        Node* ptr = new Node(val);

        ptr->prev_ = head_;
        head_->next_ = ptr;

        ptr->next_ = front;
        front->prev_ = ptr;

    }

    void push_back(T val){
        Node* back = head_->prev_;
        Node* ptr = new Node(val);

        head_->prev_ = ptr;
        ptr->next_ = head_;

        back->next_ = ptr;
        ptr->prev_ = back;

    }

    void pop_back(){
        if(empty()){
            throw exception();
        }

        Node* back = head_->prev_;
        Node* new_back = back->prev_;

        head_->prev_ = new_back;
        new_back->next_ = head_;

        delete back;
    }

    void pop_front(){
        if(empty()){
            throw exception();
        }
        Node* front = head_->next_;
        Node* new_front = front->next_;

        head_->next_ = new_front;
        new_front->prev_ = head_;

        delete front;

    }

    void fag(){
        int a = 2;
        int b = *a;
        head_->next_ = a;
        cout << head_->next_;
    }
};

int main(){
    List<int> list;

    list.fag();
}
