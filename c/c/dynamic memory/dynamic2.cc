#include <iostream>
using namespace std;

class Foo {
    int bar_;
public:
    Foo(void) : bar_(0) {}
    Foo(int v, int w): bar_(v + w) {}
    int get_bar() const {return bar_;}
};

int main() {
    Foo* ptr1 = new Foo;
    Foo* ptr2 = new Foo(21, 21);
    Foo* arr1 = new Foo[10];

    cout << "ptr1->get_bar(): " << ptr1->get_bar() << endl;
    cout << "ptr2->get_bar(): " << ptr2->get_bar() << endl;
    cout << "arr1->get_bar(): " << arr1->get_bar() << endl;
    delete ptr1;
    delete ptr2;
    delete [] arr1;
    return 0;
}
