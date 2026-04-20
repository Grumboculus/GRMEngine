#ifndef VEC2_HPP
#define VEC2_HPP

template <typename T>

class Vec2 {
    private:
        T x, y;
    public: 

        void Vec2() { return Vec2<T>(static_assert<T>(1), static_assert<T>(1)) }

        Vec2(const T xVal, const T yVal) void {
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

        void SetX(T newX) {
            this.x = newX;
            return;
        }

        void SetY(T newY) {
            this.y = newY;
            return;
        }
};

#endif