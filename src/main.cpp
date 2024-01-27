#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <iostream>

#include <omp.h>

#include "curves_filler.h"

int main() {
    std::vector<std::shared_ptr<curves::Curve>> curves_vector {};
    std::vector<std::shared_ptr<curves::Curve>> circles_vector {};

    // 1. filling vector with circles, ellipses and helixes
    curves::fill_vector_curves(curves_vector);

    // 2. printing C(t) and C'(t) for every object, where t = pi/4
    for (std::size_t i = 0; i < curves::N ; ++i) {
        std::cout << "Object #" << i + 1 << ":\n";
        std::cout << "    pi/4 value: " << curves_vector[i]->get_value(M_PI_4) << "\n";
        std::cout << "    pi/4 first derivative: " << curves_vector[i]->get_first_derivative(M_PI_4) << "\n";
    }

    // 3. filling second vector so it contains only circles (pointers to circles actually)
    for (const auto& elem : curves_vector) {
        if (auto circle = std::dynamic_pointer_cast<curves::Circle>(elem))
            circles_vector.emplace_back(std::move(circle));
    }

    // 4. sorting second vector by circles radius in ascending order
    std::sort(circles_vector.begin(), circles_vector.end(), 
        [](const std::shared_ptr<curves::Curve>& first,
           const std::shared_ptr<curves::Curve>& second) {
            return first->get_x_radius() < second->get_x_radius();
        });

    // 5. computing total sum of radiuses of circles using OpenMP
    double radiuses_sum = 0.0;
    #pragma omp parallel for reduction(+:radiuses_sum)
    for (int i = 0; i < circles_vector.size(); ++i) {
        radiuses_sum += circles_vector[i]->get_x_radius();
    }
    
    std::cout << "Circles radiuses sum: " << radiuses_sum;
  
    return 0;
}