#include "Vec4.hpp"
using namespace engine::math;

// Default constructor, initializes to zero vector (with w set to 1)
Vec4::Vec4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}

// Parameterized constructor, sets x, y, z, and w directly
Vec4::Vec4(float xVal, float yVal, float zVal, float wVal) : x(xVal), y(yVal), z(zVal), w(wVal) {}

// Get X component safely as const
float Vec4::GetX() const { return x; }

// Get Y component safely as const
float Vec4::GetY() const { return y; }

// Get Z component safely as const
float Vec4::GetZ() const { return z; }

// Get W component safely as const
float Vec4::GetW() const { return w; }

// Set X to provided value
void Vec4::SetX(float xVal) { x = xVal; }

// Set Y to provided value
void Vec4::SetY(float yVal) { y = yVal; }

// Set Z to provided value
void Vec4::SetZ(float zVal) { z = zVal; }

// Set W to provided value
void Vec4::SetW(float wVal) { w = wVal; }

// Overloads the addition operator to return a new vector sum
Vec4 Vec4::operator+(const Vec4& other) const {
    return Vec4(x + other.GetX(), y + other.GetY(), z + other.GetZ(), w + other.GetW());
}

// Overloads the subtraction operator to return a new vector difference
Vec4 Vec4::operator-(const Vec4& other) const {
    return Vec4(x - other.GetX(), y - other.GetY(), z - other.GetZ(), w - other.GetW());
}
