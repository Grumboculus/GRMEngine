#include <iostream>
#include <cstdlib>
// Include app
#include <Core/application/application.hpp>
// Include necessary headers for mathematical vectors and table data structures 
#include <Math/Vectors/Vec2/Vec2.hpp>
#include <Containers/Table/Vector/Vector.hpp>

/**
 * @brief The main entry point of the application.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main(){
    
    engine::core::application app;

    app.Run();

    return 0;
}

