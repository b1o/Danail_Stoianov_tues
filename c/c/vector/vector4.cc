#include <iostream>
#include <exception>

using namespace std;

class Array {
    int* data_;
    unsigned int size_;
public:
    Array(unsigned int size = 10)
        : size_(size), data_(new int[size])
    {}
    ~Array(void) {
        delete[] data_;
    }

    int& element(unsigned int index) {
        if(index >= size_) {
            cerr << "index ot of bounds.." << endl;
            throw exception();
        }
        return data_[index];
    }
    unsigned size() const {
        return size_;
    }
};

int main(void) {
    Array v(5);
    for(int i = 0; i < 5; i++){
        v.element(i) = i;
    }

    for(int i = 0; i < 5; i++) {
        cout << "v[i] = " << v.element(i) << endl;
    }
    return 0;
}

