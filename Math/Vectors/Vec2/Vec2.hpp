#ifndef VEC2_HPP
#define VEC2_HPP

namespace engine {
namespace math {

class Vec2 {
    private:
        float x, y, magnitude;

        void RecalculateMagnitude();

    public:
        Vec2();
        Vec2(float xVal, float yVal);

        float GetX() const;
        float GetY() const;
        float GetMagnitude() const;

        void SetX(float xVal);
        void SetY(float yVal);
        void Set(float xVal, float yVal);

        Vec2 Normalize() const;
    };

}
}

#endif