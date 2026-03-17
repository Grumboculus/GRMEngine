#include <iostream>
#include <cstdlib>

// Include necessary headers for mathematical vectors and table data structures
#include "Math/Vectors/Vec2/Vec2.hpp"
#include "Table/Vector/Vector.hpp"

/**
 * @brief The main entry point of the application.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main(){
    // Create a generic vector of integers
    engine::tables::Vector<int> myVec;

    // Push an element onto the vector
    myVec.Push(10);

    // Output the first element
    std::cout << myVec[0];

    return 0;
}

