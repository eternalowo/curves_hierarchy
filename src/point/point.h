#ifndef POINT_H_
#define POINT_H_

#include <iostream>

namespace curves {

class Point {
    // class that defines a 3D point 
public:
    Point(double x, double y, double z) : _x(x), _y(y), _z(z) {}
    
    friend auto operator<<(std::ostream& out, const Point& point) -> std::ostream& {
        out << "{" << point._x << " " << point._y << " " << point._z << "}";
        return out;
    }
    
private:
    double _x, _y, _z;
};

} // namespace curves

#endif POINT_H_