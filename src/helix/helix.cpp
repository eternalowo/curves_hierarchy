#include <helix.h>

namespace curves {

auto Helix::get_value(double t) const -> Point {
    return Point(_x_radius * cos(t), _y_radius * sin(t), t * _step / (2 * M_PI));
}

auto Helix::get_first_derivative(double t) const -> Point {
    return Point(-_x_radius * sin(t), _y_radius * cos(t), _step / (2 * M_PI));
}

} // namespace curves