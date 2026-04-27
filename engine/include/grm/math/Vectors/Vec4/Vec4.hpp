#ifndef VEC4_HPP
#define VEC4_HPP

template <typename T>

class Vec4 {
    private:

    public: 
        // Variables
        T x, y, z;
        int w;

        // Constructors
        Vec4(const T xVal, const T yVal, const T zVal, const int wVal) const : x(xVal), y(yVal), z(zVal), w(wVal) {}

        Vec4() const : x(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), 0) {}



        // Operators
        Vec4 operator+(const Vec4& other) const {
            T newX = this->x + other.x;
            T newY = this->y + other.y;
            T newZ = this->z + other.z;
            return Vec4(newX, newY, newZ, this->w);
        }

        Vec4 operator-(const Vec4& other) const {
            T newX = this->x - other.x;
            T newY = this->y - other.y;
            T newZ = this->z - other.z;
            return Vec4(newX, newY, newZ, this->w);
        }

        Vec4 operator*(const Vec4& other) const {
            T newX = this->x * other.x;
            T newY = this->y * other.y;
            T newZ = this->z * other.z;
            return Vec4(newX, newY, newZ, this->w);
        }

        Vec4 operator*(T scalar) const {
            T newX = this->x * scalar;
            T newY = this->y * scalar;
            T newZ = this->z * scalar;
            return Vec4(newX, newY, newZ, this->w);
        }

        Vec4 operator/(const Vec4& other) const {
            T newX = this->x / other.x;
            T newY = this->y / other.y;
            T newZ = this->z / other.z;
            return Vec4(newX, newY, newZ, this->w);
        }
        
        Vec4 operator/(T scalar) const {
            T newX = this->x / scalar;
            T newY = this->y / scalar;
            T newZ = this->z / scalar;
            return Vec4(newX, newY, newZ, this->w);
        }

        bool operator==(const Vec4& other) const {
            if (this->x != other.x) {
                return false;
            }
            if (this->y != other.y) {
                return false;
            }
            if (this->z != other.z) {
                return false;
            }
            if (this->w != other.w) {
                return false;
            }
            return true;
        }

        bool operator !=(const Vec4& other) const {
            return !(*this == other);
        }

#endif