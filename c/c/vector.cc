#include <iostream>

using namespace std;

template<typename T>
class Vector{

	int capacity_;
	int size_;
	T* buffer_;

	void ensure_capacity(int chunk) {

		if(size_ + chunk < capacity_)
			return;

		T* old_buffer = buffer_;

		capacity_+=chunk;

		buffer_ = new T[capacity_];

		for (int i = 0; i < chunk; ++i){
			buffer_[i] = old_buffer[i];		
		}
		cout << "called" << endl;
		delete [] old_buffer;
	}

public:

	Vector(int capacity):
		capacity_(capacity),
		size_(0),
		buffer_(new T[capacity_])
	{}

	bool empty(){
		return size_ == 0;
	}


	void push(T val){
		ensure_capacity(1);
		buffer_[size_++] = val;
	}
};

int main(){
	
	Vector<int> v1(10);
	cout << v1.empty() << endl;

	for (int i = 0; i < 10; ++i){
		v1.push(i);
	}

	return 0;
}