#include <iostream>
#include <exception>

using namespace std;

template<typename T>
class Vector {
    friend class iterator;

    const static int CHUNK_SIZE = 10;

    int capacity_;
    int size_;
    T* buffer_;

    void ensure_capacity(int count) {
        if(size_ + count <= capacity_){
            return;
        }

        T* old_buffer = buffer_;
        capacity_ += (count/CHUNK_SIZE + 1) * CHUNK_SIZE;
        cout << "ensure capacity called: " << capacity_ << endl;
        buffer_ = new T[capacity_];

        for(int i = 0; i < size_; ++i){
            buffer_[i] = old_buffer[i];
        }
    delete [] old_buffer;
    }

public:

    Vector(int capacity)
        :   capacity_(capacity),
            size_(0),
            buffer_(new T[capacity_])
    {}

    ~Vector(){
        delete [] buffer_;
    }

    int size() const {
        return size_;
    }

    bool empty(){
        return size_==0;
    }

    void clear() {
        size_ = 0;
    }

    int capacity() const {
        return capacity_;
    }

    void push_back(const T& val) {
        ensure_capacity(1);

        buffer_[size_++] = val;
    }

    void pop_back() {
        if(empty()){
            throw std::exception();
        }

        size_--;
    }

    T& front(){
        if(empty()){
            throw std::exception();
        }
        return buffer_[0];
    }

    const T& front() const {
        if(empty()){
            throw std::exception();
        }
        return buffer_[0];
    }

    T& back(){
        if(empty()){
            throw std::exception();
        }

        return buffer_[size_-1];
    }

    const T& back() const {
        if(empty()){
            throw std::exception();
        }

        return buffer_[size_-1];
    }

    class iterator{
        friend class Vector;

        Vector& v_;
        int pos_;

        iterator(Vector& v, int pos)
        : v_(v),
          pos_(pos)
        {}
    public:

        iterator operator++(){
            if(pos_ >= v_.size()){
                return;
            }
            pos_++;
        }

        bool operator==(const iterator& other)  const {
            return pos_ == other.pos_;
        }

        bool operator!=(const iterator& other) const {
            return !operator == (other);
        }

        T& operator*(){
            return v_.buffer_[pos_];
        }

    };

    iterator begin() {
        return iterator(*this, 0);
    }

    iterator end(){
        return iterator(*this, size_);
    }

    T& operator[](int index){
        return buffer_[index];

    }

    T& at(int index) {
        if(index > 0 && index < size_) {
            return buffer_[index];
        }
        throw std::exception();
    }

};

int main(){
    Vector<int> v(5);
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }


    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

