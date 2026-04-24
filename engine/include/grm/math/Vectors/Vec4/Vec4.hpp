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
        
};

#endif