#include "Vec2.hpp"
#include <cmath>

namespace engine {
namespace math {

Vec2::Vec2() : x(0.0f), y(0.0f) {}

Vec2::Vec2(float xVal, float yVal) : x(xVal), y(yVal) {}

float Vec2::GetX() const { return x; }
float Vec2::GetY() const { return y; }

void Vec2::SetX(float xVal) { x = xVal; }
void Vec2::SetY(float yVal) { y = yVal; }
void Vec2::Set(float xVal, float yVal) { x = xVal; y = yVal; }

Vec2 Vec2::Normalize() const {
    if (Vec2::Length() == 0.0f) {
        return Vec2(0.0f, 0.0f);
    }

    return Vec2(x / magnitude, y / magnitude);
}

float Vec2::Length() const {
    return std::sqrt(x * x + y * y);
}

}
}