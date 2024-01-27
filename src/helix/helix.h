#ifndef HELIX_H_
#define HELIX_H_

#define _USE_MATH_DEFINES
#include <cmath>

#include "curve_interface.h"

namespace curves {

class Helix : public Curve {
    // helix class, defined by its x_radius, y_radius and some step
    // that C(t) + {0, 0, step} = C(t + step)
public:
    Helix(double x_radius, double y_radius, double step) 
    : Curve(x_radius, y_radius, step) {}

    auto get_value(double t) const -> Point override;
    auto get_first_derivative(double t) const -> Point override;
};

} // namespace curves 

#endif