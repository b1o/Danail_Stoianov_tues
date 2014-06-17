#include <iostream>
#include <exception>

using namespace std;

class Array {
    unsigned int size_;
    int* data_;
public:
    Array(unsigned int size = 10)
        : size_(size), data_(new int [size])
    {}

    ~Array(void) {
        delete [] data_;
    }

    int& operator[](unsigned int index) {
        if(index>=size_) {
            cerr << "index out of bounds..." << endl;
            throw exception();
        }
        return data_[index];
    }
    unsigned size() const {
        return size_;
    }
};

int main(void) {
    int c = 3;
    Array v(c);
    for(int i = 0; i < c; i++) {
        v[i] = i;
    }

    for(int i = 0; i < c; i++) {
        cout << "v[i] = " << v[i] << endl;
    }

    try {
        v[3] = 5;
    } catch(const exception &e) {
        cout << "exception catched..." << endl;
    }
    return 0;

}
