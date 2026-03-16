#ifndef VEC3_HPP
#define VEC3_HPP

namespace engine {
namespace math {

    class Vec3 {
        private: 
            float x, y, z;
        public: 
            Vec3();
            Vec3(float xVal, float yVal, float zVal);

            float GetX() const;
            float GetY() const;
            float GetZ() const;

            void SetX(float xVal);
            void SetY(float yVal);
            void SetZ(float zVal);
            void Set(float xVal, float yVal, float zVal);

            float Length() const;

            Vec3 Normalized() const;

            float Dot(const Vec3& other) const;
    };

}
}

#endif