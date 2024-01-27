#include "circle.h"

namespace curves {
    
    auto Circle::get_value(double t) const -> Point {
        return Point(_x_radius * cos(t), _x_radius * sin(t), 0.0);
    }

    auto Circle::get_first_derivative(double t) const -> Point {
        return Point(-_x_radius * sin(t), _x_radius * cos(t), 0.0);
    }

} // namespace curves