#ifndef MATH_HPP
#define MATH_HPP

namespace engine {
namespace math {

    /**
     * @brief Clamps a specific value between a minimum and a maximum.
     * 
     * @param Max The maximum limit.
     * @param Min The minimum limit.
     * @param X The value to clamp.
     * @return float The clamped value.
     */
    float Clamp(float Max, float Min, float X);

}
}

#endif