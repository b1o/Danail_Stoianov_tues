#include <iostream>
#include <exception>
using namespace std;

template<typename T>
class Vector {
    const static int CHUNK_SIZE = 10;

    int size_;
    int capacity_;
    T* buffer_;

    void ensure_capacity (int count) {
        if(size_ + count <= capacity_) {
            return;
        }

        T* old_buffer = buffer_;
        capacity_ += (count/CHUNK_SIZE + 1) * CHUNK_SIZE;

        buffer_ = new T[capacity_];
        for(int i=0; i < size_; ++i) {
            buffer_[i] = old_buffer[i];
        }

        delete [] old_buffer;
    }

public:

    Vector (int capacity)
    : size_(0),
    capacity_(capacity),
    buffer_(new T [capacity_])
    {}

    Vector (int capacity, T init_val)
    : size_(capacity),
    capacity_(capacity),
    buffer_(new T [capacity_])
    {
        for (int i=0; i<capacity_; ++i) {
            buffer_[i] = init_val;
        }
    }

    ~Vector () {
        delete [] buffer_;
    }

    int size () const {
        return size_;
    }

    int capacity () const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }

    void clear() {
        size_ = 0;
    }

    void push_back(const T& el) {
        ensure_capacity(1);
        buffer_[size_++] = el;
    }

    void pop_back() {
        if (empty()) {
            throw std::exception();
        }

        size_--;
    }

    T& front() {
        if (empty()) {
            throw std::exception();
        }

        return buffer_[0];
    }

    const T& front() const {
        if (empty()) {
            throw std::exception();
        }

        return buffer_[0];
    }

    T& back() {
        if (empty()) {
            throw std::exception();
        }

        return buffer_[size_-1];
    }

    const T& back() const {
        if (empty()) {
            throw std::exception();
        }

        return buffer_[0];
    }

    T& operator [] (T el) {
        return buffer_[el];
    }

};

int main() {

    Vector<int> vyvy(5);

    for (int i=1; i < 15; i+=2) {
        vyvy.push_back(i);
    }

    cout << "Empty: " << boolalpha << vyvy.empty() << endl;
    cout << "Capacity: " << boolalpha << vyvy.capacity() << endl;
    cout << "Size: " << boolalpha << vyvy.size() << endl;
    cout << endl;

    for (int i=0; i < vyvy.size(); ++i) {
        cout << i << ": " << *(&(vyvy.front())+i) << endl;
    }
    cout << endl;

    vyvy.pop_back();

    cout << "Empty: " << boolalpha << vyvy.empty() << endl;
    cout << "Capacity: " << boolalpha << vyvy.capacity() << endl;
    cout << "Size: " << boolalpha << vyvy.size() << endl;
    cout << endl;

    for (int i=0; i < vyvy.size(); ++i) {
        cout << i << ": " << *(&(vyvy.front())+i) << endl;
    }
    cout << endl;

    cout << vyvy[3] << endl;

    // const Vector:
    /*
    const Vector<int> v(3,5); // const + second constructor
    // only const methods
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    cout << "empty: " << boolalpha << v.empty() << endl;
    cout << "front: " << v.front() << endl;
    cout << "back: " << v.back() << endl;
    */

    return 0;
}
