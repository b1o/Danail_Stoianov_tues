#include <iostream>
#include <exception>

using namespace std;

class Stack {
    const static int size_ = 2;
    int data_[size_];
    int top_;
public:
    Stack(void)
        :top_(-1)
    {}

    void push(int v) {
        if(top_ >= (size_ -1)) {
            throw exception();
        }
        data_[++top_] = v;
    }

    int pop(void){
        if(top_ < 0) {
            throw exception();
        }
        return data_[top_--];
    }
};

int main(void) {
    Stack st;

    try {
        st.push(1);
        st.push(2);
        st.push(3);
    } catch(const exception &e) {
        cout << "exception() catched in push" << endl;
    }

    try {
        cout << st.pop() << endl;
        cout << st.pop() << endl;
        cout << st.pop() << endl;
    } catch(const exception &e) {
        cout << "exception() catched in pop" << endl;
    }
    return 0;
}

