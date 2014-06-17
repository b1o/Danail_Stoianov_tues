#include <iostream>
#include <exception>

using namespace std;

class Stack {
    const static int chunk_ = 2;
    int size_;
    int *data_;
    int top_;
public:
    Stack(void)
    : size_(chunk_),
      data_(new int [chunk_]),
      top_(-1)
    {}

    ~Stack(void) {
        delete [] data_;
    }

    int get_size() const {
        cout << "size is: " << size_ << endl;
    }

    void push(int v) {
        if(top_>=(size_-1)) {
            resize();
        }
        data_[++top_] = v;
    }

    int pop(void) {
        if(top_ < 0) {
            throw exception();
        }
        return data_[top_--];
    }


private:
    void resize(void) {
        cout << "Stack::resize() called..." << endl;
        int *temp = data_;
        data_ = new int [size_ + chunk_];
        for(int i = 0; i < size_; i++)
           data_[i] = temp[i];
        delete [] temp;
        size_ += chunk_;
        cout << "Stack::resize() new size is <" << size_ << ">..." << endl;
    }


};

int main(void){
    Stack st;
    st.push(9);
    st.push(2);

    try {
         st.get_size();
        cout << st.pop() << endl;
        cout << st.pop() << endl;
        cout << st.pop() << endl;
        cout << st.pop() << endl;
    } catch(const exception &e) {
        cout << "exception() catched in pop..." << endl;
    }

    return 0;

}
