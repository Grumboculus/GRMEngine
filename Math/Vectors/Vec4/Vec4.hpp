#ifndef Vec4.hpp
#define VEC4_HPP

namespace engine {
namespace math {
    
    class Vec4 {
        private:
            float x, y, z, w;

        public:
            Vec4();
            Vec4(float xVal, float yVal, float zVal, float wVal);

            float GetX() const;
            float GetY() const;
            float GetZ() const;
            float GetW() const;

            void SetX(float xVal);
            void SetY(float yVal);
            void SetZ(float zVal);
            void SetW(float wVal);

            Vec4 operator+(const Vec4& other) const;
            Vec4 operator-(const Vec4& other) const;
    };

}
}

#endif