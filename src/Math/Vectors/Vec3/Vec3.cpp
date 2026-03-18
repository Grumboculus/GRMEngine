#include "Vec3.hpp"
#include <cmath>
using namespace engine::math;

// Default constructor, initializes to zero vector
Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

// Parameterized constructor, sets x, y, and z directly
Vec3::Vec3(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}

// Getters for individual components
float Vec3::GetX() const { return x; }
float Vec3::GetY() const { return y; }
float Vec3::GetZ() const { return z; }

// Setters for individual components
void Vec3::SetX(float xVal) { x = xVal; }
void Vec3::SetY(float yVal) { y = yVal; }
void Vec3::SetZ(float zVal) { z = zVal; }

// Sets all components simultaneously
void Vec3::Set(float xVal, float yVal, float zVal) { x = xVal; y = yVal; z = zVal;}

// Calculates the magnitude of the 3D vector using Pythagoras' theorem
float Vec3::Length() const { 
    return std::sqrt(x * x + y * y + z * z); 
}

// Returns a normalized copy of the vector
Vec3 Vec3::Normalized() const { 
    float len = Length(); // Calculate magnitude
    // Prevent division by zero if the magnitude is positive
    if (len > 0.0f) {
        return Vec3(x / len, y / len, z / len); // Return scaled vector
    }
    // Return a zero vector if length is zero
    return Vec3(0.0f, 0.0f, 0.0f);
}

// Performs a dot product between two vectors (currently missing implementation)
float Vec3::Dot(const Vec3& other) const {
    return 0.0f;
}

// Overloads the addition operator to return a new vector sum
Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(this->GetX() + other.GetX(), this->GetY() + other.GetY(), this->GetZ() + other.GetZ());
}
