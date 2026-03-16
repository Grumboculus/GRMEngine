#ifndef Vec4.hpp
#define VEC4_HPP

namespace engine {
namespace math {
    
    class Vec4 {
        private:
            float x, y, z;
            int w;

        public:
            Vec4();
            Vec4(float xVal, float yVal, float zVal, int wVal);

            float GetX() const;
            float GetY() const;
            float GetZ() const;
            int GetW() const;
    };

}
}

#endif