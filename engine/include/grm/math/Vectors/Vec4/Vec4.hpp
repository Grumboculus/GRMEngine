#ifndef VEC4_HPP
#define VEC4_HPP

template <typename T>

class Vec4 {
    private:
        T x, y;
    public: 

        Vec4(const T xVal, const T yVal) void {
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