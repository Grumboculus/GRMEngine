#include "math.hpp"

namespace engine {
namespace math {

    float Clamp(float Max, float Min, float x) {
        // Return max if the value exceeds it
        if (x > Max) {
            return x = Max;
        }

        // Return min if the value is below it
        if (x < Min) {
            return x = Min;
        }

        // Return the value itself if it sits within the range
        return x;
    }

}
}
