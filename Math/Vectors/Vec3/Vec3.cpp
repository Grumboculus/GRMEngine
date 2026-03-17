#include "Vec3.hpp"
#include <cmath>
using namespace engine::math;

Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

Vec3::Vec3(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}

float Vec3::GetX() const { return x; }
float Vec3::GetY() const { return y; }
float Vec3::GetZ() const { return z; }

void Vec3::SetX(float xVal) { x = xVal; }
void Vec3::SetY(float yVal) { y = yVal; }
void Vec3::SetZ(float zVal) { z = zVal; }
void Vec3::Set(float xVal, float yVal, float zVal) { x = xVal; y = yVal; z = zVal;}

float Vec3::Length() const { 
    return std::sqrt(x * x + y * y + z * z); 
}

Vec3 Vec3::Normalized() const { 
    float len = Length();
    if (len > 0.0f) {
        return Vec3(x / len, y / len, z / len);
    }
    return Vec3(0.0f, 0.0f, 0.0f);
}

float Vec3::Dot(const Vec3& other) const {
    return 0.0f;
}

Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(this->GetX() + other.GetX(), this->GetY() + other.GetY(), this->GetZ() + other.GetZ());
}
