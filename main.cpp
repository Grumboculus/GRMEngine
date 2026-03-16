#include <iostream>
#include <cstdlib>
#include "Math/Vectors/Vec2/Vec2.hpp"
#include "Table/Vector/Vector.hpp"

int main(){
    engine::tables::Vector<int> myVec;

    myVec.Push(10);

    std::cout << myVec[0];

    return 0;
}
