#include <iostream>
#include <cstdlib>

#include <Core/application/application.hpp>
#include <Math/Vectors/Vec2/Vec2.hpp>
#include <Containers/Table/Vector/Vector.hpp>

/**
 * @brief The main entry point of the application.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main(){
    
    engine::core::application app;

    engine::math::Vec2 player = app.InitPlayer();

    app.Run(player);

    return 0;
}

