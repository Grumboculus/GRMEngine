#include <iostream>
#include "./engine/include/grm/math/Utilities/Utils.hpp"
#include "./engine/include/grm/math/Vectors/Vec2/Vec2.hpp"
#include "./engine/include/grm/math/Vectors/Vec3/Vec3.hpp"
#include "./engine/include/grm/math/Vectors/Vec4/Vec4.hpp"

int main(int, char**){
    Vec2 NewVec = Vec2(3, 4);
    std::cout << NewVec.length() << std::endl;

    Vec3 Vector3Created = Vec3<float>(30, 30, 30);
    Vec3 answer = Vector3Created.cross(Vec3<float>(30.1, 14.3, 16.01));

    std::cout << answer << std::endl;

    //std::cout << answer.x() << ", " << answer.y() << ", " << answer.z() << std::endl;
    std::cout << Vector3Created << std::endl;

    Vec4 NewVec4 = Vec4<float>(4.0f, 6.0f, 7.0f, 0);

    std::cout << NewVec4;


    return 0;
}
