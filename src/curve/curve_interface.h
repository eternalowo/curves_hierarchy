#ifndef CURVE_INTERFACE_H_
#define CURVE_INTERFACE_H_

#include <../point/point.h>

namespace curves {

class Curve {
    // Curve interface
    // (i assume that center is always is (0, 0, 0) point)
public:
    Curve(double x_radius, double y_radius, double step) 
    : _x_radius(x_radius), _y_radius(y_radius), _step(step) {}

    // returns C(t) value (point)
    virtual auto get_value(double t) const -> Point = 0;

    // returns C`(t) value (point)
    virtual auto get_first_derivative(double t) const -> Point = 0;

    inline auto get_x_radius() const -> double {
        return _x_radius;
    }

    inline auto get_y_radius() const -> double {
        return _y_radius;
    }

    inline auto get_step() const -> double {
        return _step;
    }

    virtual ~Curve() = default;

protected:
    double _x_radius;
    double _y_radius;
    double _step;
};

} // namespace curves

#endif