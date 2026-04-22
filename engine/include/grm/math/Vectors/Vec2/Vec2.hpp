#ifndef VEC2_HPP
#define VEC2_HPP

#include "../../Utilities/Utils.hpp"
#include <concepts>

template <typename T>

class Vec2 {
    private:
        T x, y;
    public: 

        Vec2() : x(static_cast<T>(0)), y(static_cast<T>(0)) {}

        Vec2(const T xVal, const T yVal) : x(xVal), y(yVal) {}

        T GetX() const {
            return x;
        }

        T GetY() const {
            return y;
        }

        void SetX(T newX) {
            this->x = newX;
            return;
        }

        void SetY(T newY) {
            this->y = newY;
            return;
        }

        T dot(const Vec2& other) const {
            return (this->GetX() * other.GetX()) + (this->GetY() * other.GetY());
        }

        T length() const {
            T length = (this->x * this->x) + (this->y * this->y);
            length = math::sqrt(length);
            return length;
        }

        Vec2 normalized() const {
            T len = this->length();
            if (len == static_cast<T>(0)) {
                return Vec2();
            }

            T normalizedX = this->x / len;
            T normalizedY = this->y / len;
            return Vec2(normalizedX, normalizedY);
        }

        void normalize() {
            T len = this->length();
            if (len == static_cast<T>(0)) {
                this->x = static_cast<T>(0);
                this->y = static_cast<T>(0);
                return;
            }

            T newX = this->x / len;
            T newY = this->y / len;
            
            this->x = newX;
            this->y = newY;
            
            return;
        }

        Vec2 displacement(const Vec2& other) const {
            T dx = this->x - other.x;
            T dy = this->y - other.y;
            return Vec2(dx, dy);
        }

        T distance(const Vec2& other) const {
            return this->displacement(other).length();
        }

        // Operators

        Vec2 operator+(const Vec2& other) const {
            T newX = this->x + other.x;
            T newY = this->y + other.y;
            return Vec2(newX, newY);
        }

        Vec2 operator-(const Vec2& other) const {
            T newX = this->x - other.x;
            T newY = this->y - other.y;
            return Vec2(newX, newY);
        }

        Vec2 operator*(const Vec2& other) const {
            T newX = this->x * other.x;
            T newY = this->y * other.y;
            return Vec2(newX, newY);
        }

        Vec2 operator*(T scalar) const {
            return Vec2(this->x * scalar, this->y * scalar);
        }

        Vec2 operator/(const Vec2& other) const {
            T newX = this->x / other.x;
            T newY = this->y / other.y;
            return Vec2(newX, newY);
        }

        Vec2 operator/(T scalar) const {
            return Vec2(this->x / scalar, this->y / scalar);
        }

        bool operator==(const Vec2& other) const {
            if constexpr (std::floating_point<T>) {
                const T epsilon = math::EPSILON<T> * static_cast<T>(8);
                return math::abs(this->x - other.x) <= epsilon &&
                       math::abs(this->y - other.y) <= epsilon;
            }

            return this->x == other.x && this->y == other.y;
        }

        Vec2& operator=(const Vec2& other) {
            x = other.x;
            y = other.y;
            return *this;
        }

        Vec2& operator+=(const Vec2& other) {
            this->x = this->x + other.x;
            this->y = this->y + other.y;
            return *this;
        }

        Vec2& operator-=(const Vec2& other) {
            this->x = this->x - other.x;
            this->y = this->y - other.y;
            return *this;
        } 
        
        Vec2& operator*=(const Vec2& other) {
            this->x = this->x * other.x;
            this->y = this->y * other.y;
            return *this;
        } 

        Vec2& operator*=(T scalar) {
            this->x = this->x * scalar;
            this->y = this->y * scalar;
            return *this;
        }
        
        Vec2& operator/=(const Vec2& other) {
            this->x = this->x / other.x;
            this->y = this->y / other.y;
            return *this;
        }

        Vec2& operator/=(T scalar) {
            this->x = this->x / scalar;
            this->y = this->y / scalar;
            return *this;
        }
        
};

#endif