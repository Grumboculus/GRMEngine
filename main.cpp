#include <iostream>
#include <cstdlib>
#include "Math/Vectors/Vec2/Vec2.hpp"

int main(){
    engine::math::Vec2 NewVec2(5.0f, 6.0f);

    std::cout << NewVec2.GetMagnitude();

    system("pause");
}
