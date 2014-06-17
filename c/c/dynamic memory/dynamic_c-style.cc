#include <cstdlib>

using namespace std;

class Foo {
    int bar_;
public:
    Foo(void) :bar_(0) {}
}

int main() {
    Foo* ptr = (Foo*)malloc(sizeof(Foo));
    //...
    free(ptr);
    return 0;
}
