#include <iostream>
using namespace std;

class ListError {
    const char *const message_;
public:
    ListError(const char *const message = 0)
    : message_(message)
    {}

    const char *const get_message() const {
        return message_;
    }
};

class List {
    struct Node {
        Node* next_;
        Node* prev_;
        int data_;

        Node(int val) :
            next_(0), prev_(0), data_(val)
        {}
    };

    Node* head_;

public:

    class iterator {
        friend class List;

        List* list_;
        Node* current_;

        iterator(const List* l, Node* current)
            : list_(const_cast<List*>(l)),
              current_(current)
        {}
    public:

        bool has_next() const {
            return current_->next_!=list_->head_;
        }

        int next() {
            current_ = current_->next_;
            return current_->data_;
        }

        int get_data() const {
            if(current_ != list_->head_){
                return current_->data_;
            }
            throw ListError("iterator::get_data()...");
        }
    };

    bool empty() const {
        return head_==head_->next_;
    }

    List() : head_(new Node(0)) {
        head_->next_ = head_->prev_ = head_;
    }

    void push_front(int val) {
        Node* front = head_->next_;

        Node* ptr = new Node(val);

        head_->next_=ptr;
        ptr->prev_=head_;

        front->prev_=ptr;
        ptr->next_=front;
    }

    void push_back(int val) {
        Node* back = head_->prev_;

        Node* ptr = new Node(val);

        back->next_=ptr;
        ptr->prev_=back;

        head_->prev_=ptr;
        ptr->next_=head_;
    }

    int front() const {
        if(empty()){
            throw ListError("front(): list is empty");
        }
        return head_->next_->data_;
    }

    int back() const {
        if(empty()) {
            throw ListError("back(): list is empty");
        }
        return head_->prev_->data_;
    }

    void pop_front() {
        if(empty()) {
            throw ListError("pop_front(): list empty...");
        }
        Node* front = head_->next_;
        Node* new_front=front->next_;

        head_->next_=new_front;
        new_front->prev_=head_;

        delete front;
    }

    void pop_back() {
        if(empty()) {
            throw ListError("pop_back(): list empty...");
        }

        Node* back = head_->prev_;
        Node* new_back = back->prev_;

        new_back->next_ = head_;
        head_->prev_ = new_back;

        delete back;
    }

    ~List() {
        while(!empty()) {
            pop_front();
        }
        delete head_;
    }

};



int main(){
    List l;

    try {
        l.back();
    } catch(ListError ex) {
        cout << "ListError: " << ex.get_message() << endl;
    }

    try {
        l.front();
    } catch(ListError ex) {
        cout << "ListError: " << ex.get_message() << endl;
    }

    l.push_back(10);
    cout << l.back() << endl;

    l.push_back(20);
    cout << l.back() << endl;

    l.push_front(-10);
    cout << l.front() << endl;

    l.push_front(-20);
    cout << l.front() << endl;

    for(List::iterator it = l.get_iterator();
        it.has_next(); ){
            cout << it.next() << ", ";
    }
    cout << endl;

    return 0;
}
