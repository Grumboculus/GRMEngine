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
        Vec4(const T xVal, const T yVal, const T zVal, const int wVal) : x(xVal), y(yVal), z(zVal), w(wVal) {}

        Vec4() : x(static_cast<T>(0)), y(static_cast<T>(0)), z(static_cast<T>(0)), w(0) {}

        // Length
        T length() const {
            T length = (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
            length = math::sqrt(length);
            return length;
        }

        T lengthSquared() const {
            return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
        }

        T normalized() const {
            T len = this->length();
            if (len == static_cast<T>(0)) {
                return Vec4();
            }

            T normalizedX = this->x / len;
            T normalizedY = this->y / len;
            T normalizedZ = this->z / len;
            return Vec4(normalizedX, normalizedY, normalizedZ, this->w);
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
};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Vec4<T>& vec) {
    os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
    return os;
}

#endif