#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "curve_interface.h"

namespace curves {
    
class Circle : public Curve {
    // circle class, defined by its radius
public:
    Circle(double radius) : Curve(radius, 0.0, 0.0) {}
    
    auto get_value(double t) const -> Point override;
    auto get_first_derivative(double t) const -> Point override;
};

} // namespace curves

#endif