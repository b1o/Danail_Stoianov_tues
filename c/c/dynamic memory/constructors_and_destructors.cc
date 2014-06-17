#include <cstdio>
using namespace std;

class Foo {
    FILE* bar_;
public:
    Foo(const char* filename) :bar_(0) {
        bar_ = fopen(filename, "rw")
    }
};

int bar() {
    Foo foo("temp.txt");
    return 0;
}
