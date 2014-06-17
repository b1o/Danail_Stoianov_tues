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

    Point operator+(const Point& p) const;
};

Point Point::operator+(const Point& p) const {
    Point result(get_x() + p.get_x(),
                 get_y() + p.get_y());
    return result;
}

int main(void) {
    Point p1(1.0, 1.0), p2(2.0, 2.0), p3;

    p3 = p1 + p2;
    cout << "p3=(" << p3.get_x() << ", " << p3.get_y() << ")" << endl;
    return 0;

}
