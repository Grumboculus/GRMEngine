#ifndef MAT4_HPP
#define MAT4_HPP

template <typename T>
struct Mat4 {
    T data[16];

    // Constructors
    Mat4() {
        for (int i = 0; i < 16; ++i) {
            data[i] = T(0);
        }
    }

    static Mat4 translate(T x, T y, T z) {
        Mat4 result = identity();
        result.set(0, 3, x);
        result.set(1, 3, y);
        result.set(2, 3, z);
        return result;
    }


    static Mat4 identity() {
        Mat4 result;
        result.set(0, 0, T(1));
        result.set(1, 1, T(1));
        result.set(2, 2, T(1));
        result.set(3, 3, T(1));
        return result;
    }

    // Deconstructor
    ~Mat4() {
        
    }

    // $etters
    T get(int r, int c) const {
        return data[c * 4 + r]
    }

    void set(int r, int c, T value) {
        data[c * 4 + r] = value;
    }

    // Operators
    Mat4 operator*(const Mat4& other) const {
        Mat4 result;

        for (int r = 0; r < 4; ++r) {
            for (int c = 0; c < 4; ++c) {
                T sum = T(0);
                for (int k = 0; k < 4; ++k) {
                    sum += get(r, k) * other.get(k, c);
                }
                result.set(r, c, sum);
            }
        }

        return result;
    }
};

#endif