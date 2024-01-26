#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include <../curve/curve_interface.h>

namespace curves {

class Ellipse : public Curve {
    // ellipse class, defined by its x_radius and y_radius
public:
    Ellipse(double x_radius, double y_radius) : Curve(x_radius, y_radius, 0.0) {}

    auto get_value(double t) const -> Point override;
    auto get_first_derivative(double t) const -> Point override;
};

} // namespace curves

#endif 