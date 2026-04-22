#ifndef VEC3_HPP
#define VEC3_HPP

template <typename T>

class Vec3 {
    private:
        T x, y, z;
    public: 

        Vec3(const T xVal, const T yVal, const T zVal) void {
            x = xVal;
            y = yVal;
            z = zVal;

            return;
        }

        GetX() const T {
            return x;
        }

        GetY() const T {
            return y;
        }

        xyz() const T {
            return this.x, this.y, this.z;
        }

        
};

#endif