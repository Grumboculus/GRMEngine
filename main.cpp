#include <iostream>
#include "./engine/include/grm/math/Utilities/Utils.hpp"
#include "./engine/include/grm/math/Vectors/Vec2/Vec2.hpp"
#include "./engine/include/grm/math/Vectors/Vec3/Vec3.hpp"
#include "./engine/include/grm/math/Vectors/Vec4/Vec4.hpp"
#include "./engine/include/grm/math/Mat4/Mat4.hpp"

int main(int, char**){
    Mat4 NewMat4 = Mat4<float>();

    Mat4 TranslationMat4 = NewMat4.translationxyz(1, 2, 3);

    std::cout << TranslationMat4;

    return 0;
}
