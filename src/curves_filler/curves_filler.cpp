#include "curves_filler.h"

namespace curves {

auto fill_vector_curves(std::vector<std::shared_ptr<Curve>>& cur) -> void {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real<double> values_dist(value_min, value_max);
    std::uniform_int_distribution<int> type_dist(0, 2);

    for (std::size_t i = 0; i < N; ++i) {
        auto type = static_cast<CurveType>(type_dist(gen));
        switch (type) {
            case CurveType::CIRCLE:
                cur.emplace_back(std::make_shared<Circle>(Circle(values_dist(gen))));
                break;
            case CurveType::ELLIPSE:
                cur.emplace_back(std::make_shared<Ellipse>(Ellipse(values_dist(gen), values_dist(gen))));
                break;
            case CurveType::HELIX:
                cur.emplace_back(std::make_shared<Helix>(Helix(values_dist(gen), values_dist(gen), values_dist(gen))));
                break;
            default:
                break;
        }
    }
}

} // namespace curves