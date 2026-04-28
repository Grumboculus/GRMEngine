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

    // Deconstructor
    ~Mat4() {
        delete data;
    }

    // $etters
    T get(int r, int c) const {
        return data[c * 4 + r]
    }

    void set(int r, int c, T value) {
        data[c * 4 + r] = value;
    }

    // Operators
    operator*(const Mat4& other) {
        
    }
};

#endif