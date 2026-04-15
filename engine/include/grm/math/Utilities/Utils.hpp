#ifndef UTILS_HPP
#define UTILS_HPP

#include <concepts>
#include <numbers>
#include <limits>

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

constexpr A clamp(A x, A min, A max) noexcept {
    if (x > max) x = max;
    else if (x < min) x = min;
    return x;
}

template <FloatingPoint F>
constexpr F floor(F x) noexcept {
    F returnedVal = std::floor(x);
    return returnedVal;
}

template <FloatingPoint F>
constexpr F ceil(F x) noexcept {
    F returnedVal = std::ceil(x);
    return returnedVal;
}

template <FloatingPoint F>
constexpr F trunc(F x) noexcept {
    F returnedVal = std::trunc(x);
    return returnedVal;
}

template <Arithmetic A>
constexpr A abs(A x) noexcept {
    A returnedVal = std::abs(x);
    return returnedVal;
}

#endif