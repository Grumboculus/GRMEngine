#ifndef VEC3_HPP
#define VEC3_HPP

template <typename T>

class Vec3 {
    private:
        T x, y;
    public: 

        Vec3(const T xVal, const T yVal) void {
            x = xVal;
            y = yVal;

            return;
        }

        GetX() const T {
            return x;
        }

        GetY() const T {
            return y;
        }

        xy() const T {
            return x, y;
        }

        
};

#endif