#include <iostream>
using namespace std;

class Point{
    double x_, y_;
public:
    Point(double x = 0, double y = 0)
        : x_(x), y_(y)
    {}

    double get_x() const {return x_;}
    double get_y() const {return y_;}

    Point operator-(void) const;
};

Point Point::operator-() const {
    Point result(-get_x(), -get_y());
    return result;
}

int main(void) {
    Point p1(1.0, 1.0), p2;
    p2 = -p1;
    cout << "p2=(" << p2.get_x() << ", " << p2.get_y() << ")" << endl;
    return 0;
}
