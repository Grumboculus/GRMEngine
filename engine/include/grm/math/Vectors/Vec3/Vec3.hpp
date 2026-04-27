#ifndef VEC3_HPP
#define VEC3_HPP

#include "../../Utilities/Utils.hpp"

template <typename T>

class Vec3 {
    private:
        
    public: 

        // Vars
        T x, y, z;

        // Constructors
        Vec3() : x(static_cast<T>(0)), y(static_cast<T>(0)), z(static_cast<T>(0)) {}
        Vec3(const T xVal, const T yVal, const T zVal) : x(xVal), y(yVal), z(zVal) {}

        // Length
        T length() const {
            T length = (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
            length = math::sqrt(length);
            return length;
        }

        T lengthSquared() const {
            return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
        }

        Vec3 normalized() const {
            T len = this->length();
            if (len == static_cast<T>(0)) {
                return Vec3();
            }

            T normalizedX = this->x / len;
            T normalizedY = this->y / len;
            T normalizedZ = this->z / len;
            return Vec3(normalizedX, normalizedY, normalizedZ);
        }

        void normalize() {
            T len = this->length();
            if (len == static_cast<T>(0)) {
                this->x = static_cast<T>(0);
                this->y = static_cast<T>(0);
                this->z = static_cast<T>(0);
                return;
            }

            T newX = this->x / len;
            T newY = this->y / len;
            T newZ = this->z / len;
            
            this->x = newX;
            this->y = newY;
            this->z = newZ;
            
            return;
        }

        // Vector Operations

        Vec3 cross(const Vec3& other) const {
            T crossX = (this->y * other.z) - (this->z * other.y);
            T crossY = (this->z * other.x) - (this->x * other.z);
            T crossZ = (this->x * other.y) - (this->y * other.x);
            return Vec3(crossX, crossY, crossZ);
        }

        T dot(const Vec3& other) const {
            return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
        }


        // Distance
        Vec3 displacement(const Vec3& other) const {
            T dx = this->x - other.x;
            T dy = this->y - other.y;
            T dz = this->z - other.z;
            return Vec3(dx, dy, dz);
        }

        T distance(const Vec3& other) const {
            return this->displacement(other).length();
        }

        T distanceSquared(const Vec3& other) const {
            return this->displacement(other).lengthSquared();
        }

        // Component
        void min(const Vec3& other) {
            this->x = math::min(this->x, other.x);
            this->y = math::min(this->y, other.y);
            this->z = math::min(this->z, other.z);
        }

        void max(const Vec3& other) {
            this->x = math::max(this->x, other.x);
            this->y = math::max(this->y, other.y);
            this->z = math::max(this->z, other.z);
        }

        void clamp(const Vec3& min, const Vec3& max) {
            this->x = math::clamp(this->x, min.x, max.x);
            this->y = math::clamp(this->y, min.y, max.y);
            this->z = math::clamp(this->z, min.z, max.z);
        }

        void abs() {
            this->x = math::abs(this->x);
            this->y = math::abs(this->y);
            this->z = math::abs(this->z);
        }

        // Operators
        Vec3 operator+(const Vec3& other) const {
            T newX = this->x + other.x;
            T newY = this->y + other.y;
            T newZ = this->z + other.z;
            return Vec3(newX, newY, newZ);
        }

        Vec3 operator-(const Vec3& other) const {
            T newX = this->x - other.x;
            T newY = this->y - other.y;
            T newZ = this->z - other.z;
            return Vec3(newX, newY, newZ);
        }
        
        Vec3 operator*(const Vec3& other) const {
            T newX = this->x * other.x;
            T newY = this->y * other.y;
            T newZ = this->z * other.z;
            return Vec3(newX, newY, newZ);
        }
        
        Vec3 operator*(const T scalar) const {
            T newX = this->x * scalar;
            T newY = this->y * scalar;
            T newZ = this->z * scalar;
            return Vec3(newX, newY, newZ);
        }

        Vec3 operator/(const Vec3& other) const {
            T newX = this->x / other.x;
            T newY = this->y / other.y;
            T newZ = this->z / other.z;
            return Vec3(newX, newY, newZ);
        }

        Vec3 operator/(const T scalar) const {
            T newX = this->x / scalar;
            T newY = this->y / scalar;
            T newZ = this->z / scalar;
            return Vec3(newX, newY, newZ);
        }

        bool operator==(const Vec3& other) const {
            if (this->x != other.x) {
                return false;
            }
            if (this->y != other.y) {
                return false;
            }
            if (this->z != other.z) {
                return false;
            }
            return true;
        }

        bool operator !=(const Vec3& other) const {
            return !(*this == other);
        }

        Vec3& operator=(const Vec3& other) const {
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;
            return *this;
        } 

        Vec3& operator+=(const Vec3& other) const {
            this->x = this->x + other.x;
            this->y = this->y + other.y;
            this->z = this->z + other.z;
            return *this;
        }

        Vec3& operator-=(const Vec3& other) const {
            this->x = this->x - other.x;
            this->y = this->y - other.y;
            this->z = this->z - other.z;
            return *this;
        }

       Vec3& operator*=(const Vec3& other) const {
            this->x = this->x * other.x;
            this->y = this->y * other.y;
            this->z = this->z * other.z;
            return *this;
        }
         
       Vec3& operator/=(const Vec3& other) const {
            this->x = this->x / other.x;
            this->y = this->y / other.y;
            this->z = this->z / other.z;
            return *this;
        }
         
};

#endif