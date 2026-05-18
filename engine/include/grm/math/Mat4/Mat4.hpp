#ifndef MAT4_HPP
#define MAT4_HPP

#include "../Vectors/Vec3/Vec3.hpp"
#include <iostream>

template <typename T>
struct Mat4 {
    T data[16];

    // Constructors
    Mat4() {
        for (int i = 0; i < 16; ++i) {
            data[i] = T(0);
        }
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

    // Translation
    static Mat4 translation(const Vec3<T>& translation) {
        Mat4 result = Mat4::identity();
        result.set(0, 3, translation.x);
        result.set(1, 3, translation.y);
        result.set(2, 3, translation.z);
        return result;
    }

    static Mat4 translationxyz(T x, T y, T z) {
        Mat4 result = Mat4::identity();
        result.set(0, 3, x);
        result.set(1, 3, y);
        result.set(2, 3, z);
        return result;
    }

    // Scale
    static Mat4 scale(const Vec3<T>& scale) {
        Mat4 result = Mat4::identity();
        result.set(0, 0, scale.x);
        result.set(1, 1, scale.y);
        result.set(2, 2, scale.z);
        return result;
    }

    static Mat4 scalexyz(T x, T y, T z) {
        Mat4 result = Mat4::identity();
        result.set(0, 0, x);
        result.set(1, 1, y);
        result.set(2, 2, z);
        return result;
    }

    // Rotation
    static Mat4 rotationX(T angleRAD) {
        Mat4 result = Mat4::identity();
        T cosAngle = math::cos(angleRAD);
        T sinAngle = math::sin(angleRAD);
        result.set(1, 1, cosAngle);
        result.set(1, 2, -sinAngle);
        result.set(2, 1, sinAngle);
        result.set(2, 2, cosAngle);
        return result;
    }
    
    // $etters
    T get(int r, int c) const {
        return data[c * 4 + r];
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

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Mat4<T>& mat) {
    os << "[ " << mat.get(0, 0) << " " << mat.get(0, 1) << " " << mat.get(0, 2) << " " << mat.get(0, 3) << " ]" << "\n"
    << "[ " << mat.get(1, 0) << " " << mat.get(1, 1) << " " << mat.get(1, 2) << " " << mat.get(1, 3) << " ]" << "\n"
    << "[ " << mat.get(2, 0) << " " << mat.get(2, 1) << " " << mat.get(2, 2) << " " << mat.get(2, 3) << " ]" << "\n"
    << "[ " << mat.get(3, 0) << " " << mat.get(3, 1) << " " << mat.get(3, 2) << " " << mat.get(3, 3) << " ]"
    << std::endl;
    return os;
}

#endif