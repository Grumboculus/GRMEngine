#include <iostream>
#include <cstdlib>
#include "Math/Vectors/Vec2/Vec2.hpp"
#include "Table/Vector/Vector.hpp"

int main(){
    std::cout << "--- Testing engine::tables::Vector ---\n";
    engine::tables::Vector<int> myVec;

    std::cout << "Pushing numbers 10, 20, 30, 40, 50...\n";
    myVec.Push(10);
    myVec.Push(20);
    myVec.Push(30);
    myVec.Push(40);
    myVec.Push(50); // This should trigger the resize!
    
    std::cout << "Current size: " << myVec.Size() << "\n";
    std::cout << "Element at index 2: " << myVec.Get(2) << "\n";

    std::cout << "Popping the last element...\n";
    myVec.Pop();
    std::cout << "New size: " << myVec.Size() << "\n\n";

    std::cout << "Trying to get an out-of-bounds element:\n";
    try {
        myVec[100];
    }
    catch (const std::exception& e) {
        std::cout << "Caught an exception! Error message: " << e.what() << "\n";
    }

    std::cout << myVec[3];

    std::cout << "\n";
    system("pause");
    return 0;
}
