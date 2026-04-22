#include <iostream>
#include "./engine/include/grm/math/Utilities/Utils.hpp"
#include "./engine/include/grm/math/Vectors/Vec2/Vec2.hpp"

int main(int, char**){
    Vec2 NewVec = Vec2(5, 5);
    std::cout << NewVec.dot(Vec2(3,3));
    return 0;
}
