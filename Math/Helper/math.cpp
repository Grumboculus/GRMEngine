#include "math.hpp"

namespace engine {
namespace math {

    float Clamp(float Max, float Min, float x) {
        if (x > Max) {
            return x = Max;
        }

        if (x < Min) {
            return x = Min;
        }

        return x;
    }

    

}
}