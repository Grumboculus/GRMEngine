#ifndef VEC2_HPP
#define VEC2_HPP

#include "../../Utilities/Utils.hpp"

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
           T x =  this->x / this->length();
           T y = this->y / this->length();
           return Vec2(x, y);
        }

        void normalize() {
            T newX = this->x / this->length();
            T newY = this->y / this->length();
            
            this->x = newX;
            this->y = newY;
            
            return;
        }

        Vec2 distance(const Vec2& other) {

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

        Vec2 operator/(const Vec2& other) const {
            T newX = this->x / other.x;
            T newY = this->y / other.y;
            return Vec2(newX, newY);
        }

        bool operator==(const Vec2& other) const {
            if (this->x != other.x) {
                return false;
            }

            if (this->y != other.y) {
                return false;
            }

            return true;
        }

        Vec2& operator=(const Vec2& other) {
            x = other.x;
            y = other.y;
            return *this;
        }
};

#endif