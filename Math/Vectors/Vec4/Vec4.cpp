#include "Vec4.hpp"
using namespace engine::math;

Vec4::Vec4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}

float Vec4::GetX() const { return x; }
float Vec4::GetY() const { return y; }
float Vec4::GetZ() const { return z; }
float Vec4::GetW() const { return w; }

void Vec4::SetX(float xVal) { x = xVal; }
void Vec4::SetY(float yVal) { y = yVal; }
void Vec4::SetZ(float zVal) { z = zVal; }
void Vec4::SetW(float wVal) { w = wVal; }

Vec4 Vec4::operator+(const Vec4& other) const {
    return Vec4(x + other.GetX(), y + other.GetY(), z + other.GetZ(), w + other.GetW());
}

Vec4 Vec4::operator-(const Vec4& other) const {
    return Vec4(x - other.GetX(), y - other.GetY(), z - other.GetZ(), w - other.GetW());
}