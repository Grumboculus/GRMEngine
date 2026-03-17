#include "Vec2.hpp"
#include <cmath>

namespace engine {
namespace math {

// Default constructor, initializes to zero vector
Vec2::Vec2() : x(0.0f), y(0.0f) {}

// Parameterized constructor, sets x and y directly
Vec2::Vec2(float xVal, float yVal) : x(xVal), y(yVal) {}

// Getters for individual components
float Vec2::GetX() const { return x; }
float Vec2::GetY() const { return y; }

// Setters for individual components
void Vec2::SetX(float xVal) { x = xVal; }
void Vec2::SetY(float yVal) { y = yVal; }

// Sets both components simultaneously
void Vec2::Set(float xVal, float yVal) { x = xVal; y = yVal; }

// Returns a normalized copy of the vector
Vec2 Vec2::Normalize() const {
    // Prevent division by zero if the length is zero
    if (Vec2::Length() == 0.0f) {
        return Vec2(0.0f, 0.0f);
    }

    // Return the scaled components
    return Vec2(x / magnitude, y / magnitude);
}

// Calculates the magnitude of the vector using Pythagoras' theorem
float Vec2::Length() const {
    return std::sqrt(x * x + y * y);
}

// Overloads the addition operator to return a new vector sum
Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(this->GetX() + other.GetX(), this->GetY() + other.GetY());
}

// Overloads the subtraction operator to return a new vector difference
Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2(this->GetX() - other.GetX(), this->GetY() - other.GetY());
}

}
}
