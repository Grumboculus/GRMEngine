#ifndef UTILS_HPP
#define UTILS_HPP

#include <cmath>
#include <concepts>
#include <numbers>
#include <limits>

namespace math {

template <typename A>
concept FloatingPoint = std::floating_point<A>;
template <typename A>
concept Arithmetic = std::integral<A> || std::floating_point<A>;


// CONSTANTS

template <FloatingPoint F>
inline constexpr F PI = std::numbers::pi_v<F>;

template <FloatingPoint F>
inline constexpr F E = std::numbers::e_v<F>;

template <FloatingPoint F>
inline constexpr F TAU = 2 * std::numbers::pi_v<F>;

template <FloatingPoint F>
inline constexpr F INF = std::numeric_limits<F>::infinity();

template <FloatingPoint F>
inline constexpr F EPSILON = std::numeric_limits<F>::epsilon();

template <Arithmetic A>

inline constexpr A clamp(A x, A min, A max) noexcept {
    if (x > max) x = max;
    else if (x < min) x = min;
    return x;
}

template <FloatingPoint F>

inline constexpr F floor(F x) noexcept {
    F returnedVal = std::floor(x);
    return returnedVal;
}

template <FloatingPoint F>

inline constexpr F ceil(F x) noexcept {
    F returnedVal = std::ceil(x);
    return returnedVal;
}

template <FloatingPoint F>

inline constexpr F trunc(F x) noexcept {
    F returnedVal = std::trunc(x);
    return returnedVal;
}

template <Arithmetic A>

inline constexpr A abs(A x) noexcept {
    A returnedVal = std::abs(x);
    return returnedVal;
}

template <Arithmetic A>

inline constexpr A pow(A x, int power) noexcept {
    if (power == 0) { return static_cast<A>(1); }
    if (power < 0) {
        if constexpr (FloatingPoint<A>) {
            return static_cast<A>(1) / pow(x, -power);
        } else {
            return static_cast<A>(0);
        }
    }

    A result = static_cast<A>(1);
    for (int i = 0; i < power; ++i) {
        result *= x;
    }

    return result;
}

template <Arithmetic A>

inline constexpr A min(A x, A min) noexcept {
    if (x < min) { x = min; }
    return x;
}

template <Arithmetic A>

inline constexpr A max(A x, A max) noexcept {
    if (x > max) { x = max; }
    return x;
}

template <Arithmetic A>

inline constexpr int sign(A x) noexcept {
    if (x < 0) {
        return -1;
    }

    if (x == 0) {
        return 0;
    }

    return 1;
}

template <Arithmetic A>

inline constexpr A cbrt(A x) noexcept {
    A calculatedValue = std::cbrt(x);
    return calculatedValue;
}

template <FloatingPoint F>

inline constexpr F lerp(F a, F b, F t) noexcept {
    F value = a + (b - a) * t;
    return value;
}

template <FloatingPoint F>

inline constexpr F inverseLerp(F a, F b, F value) noexcept {
    F result = (value - a) / (b - a);
    return result;
}

template <FloatingPoint F>

inline constexpr F remap(F value, F inMin, F inMax, F outMin, F outMax) noexcept {
    F out = outMin + (value - inMin) * (outMax - outMin) / (inMax - inMin);
    return out;
}

template <FloatingPoint F>

inline constexpr F smoothstep(F edge0, F edge1, F x) noexcept {
    x = clamp((x - edge0) / (edge1 - edge0), static_cast<F>(0.0), static_cast<F>(1.0));
    return x * x * (3.0 - 2.0 * x);
}

template <Arithmetic A>

inline constexpr A sqrt(A x) noexcept {
    A result = std::sqrt(x);
    return result;
}

template <Arithmetic A>

inline constexpr A sin(A x) noexcept {
    A result = std::sin<A>(x);
    return result;
}

template <Arithmetic A>

inline constexpr A cos(A x) noexcept {
    A result = std::cos<A>(x);
    return result;
}

template <Arithmetic A>

inline constexpr A tan(A x) noexcept {
    A result = std::tan<A>(x);
    return result;
}

}

#endif