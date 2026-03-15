#include "Vec2.hpp"
#include <cmath>

namespace engine {
namespace math {

Vec2::Vec2() : x(0.0f), y(0.0f), magnitude(0.0f) {
    RecalculateMagnitude();
}

Vec2::Vec2(float xVal, float yVal) : x(xVal), y(yVal), magnitude(0.0f) {
    RecalculateMagnitude();
}

void Vec2::RecalculateMagnitude() { magnitude = std::sqrt(x * x + y * y); }

float Vec2::GetX() const { return x; }
float Vec2::GetY() const { return y; }
float Vec2::GetMagnitude() const { return magnitude; }

void Vec2::SetX(float xVal) { x = xVal; RecalculateMagnitude(); }
void Vec2::SetY(float yVal) { y = yVal; RecalculateMagnitude(); }
void Vec2::Set(float xVal, float yVal) { x = xVal; y = yVal; RecalculateMagnitude(); }

Vec2 Vec2::Normalize() const {
    if (magnitude == 0.0f) {
        return Vec2(0.0f, 0.0f);
    }

    return Vec2(x / magnitude, y / magnitude);
}

}
}