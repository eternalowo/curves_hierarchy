#ifndef CURVES_FILLER_H_
#define CURVES_FILLER_H_

#include <vector>
#include <random>

#include <../circle/circle.h>
#include <../ellipse/ellipse.h>
#include <../helix/helix.h>

namespace curves {

enum CurveType {
    // curves types enumeration
    CIRCLE,
    ELLIPSE,
    HELIX
};

constexpr auto N = 100;           // objects in curves vector
constexpr auto value_min = 0.1;   // minimum that radiuses and step can be
constexpr auto value_max = 100.0; // maximum that radiuses and step can be

// function that fills vector (cur) with circles, ellipses and helixes
auto fill_vector_curves(std::vector<std::shared_ptr<Curve>>& cur) -> void;

} // namespace curves

#endif