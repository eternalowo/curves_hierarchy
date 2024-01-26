#include <ellipse.h>

namespace curves {

auto Ellipse::get_value(double t) const -> Point {
    return Point(_x_radius * cos(t), _y_radius * sin(t), 0.0);
}

auto Ellipse::get_first_derivative(double t) const -> Point {
    return Point(-_x_radius * sin(t), _y_radius * cos(t), 0.0);
}

} // namespace curves