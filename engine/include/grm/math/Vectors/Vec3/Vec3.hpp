#ifndef VEC3_HPP
#define VEC3_HPP

template <typename T>

class Vec3 {
    private:
        
    public: 

        // Vars
        T x, y, z;

        // Constructors
        Vec3() : x(static_cast<T>(0)), y(static_cast<T>(0)), z(static_cast<T>(0)) {}
        Vec3(const T xVal, const T yVal, const T zVal) : x(xVal), y(yVal), z(zVal) {}

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
            else (this->y != other.y) {
                return false;
            }
            else (this->z != other.z) {
                return false;
            }
            }

            return true;
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