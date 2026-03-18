#include "application.hpp"
#include <raylib.h>
#include <iostream>
#include <Math/Vectors/Vec2/Vec2.hpp>

namespace engine {
namespace core {

    void application::Update(float dt) {

    }

    void application::Run() {
        const int screenWidth = 800;
        const int screenHeight = 450;

        InitWindow(screenWidth, screenHeight, "GRMEngine");

        engine::math::Vec2 PlayerPos((float)screenHeight/2,(float)screenHeight/2); 

        SetTargetFPS(60);

        while (!WindowShouldClose()) {
            // Input
                if (IsKeyDown(KEY_W)) {
                    std::cout << "Pressed W.";
                }

                if (IsKeyDown(KEY_A)) {
                    std::cout << "Pressed A.";
                }

                if (IsKeyDown(KEY_S)) {
                    std::cout << "Pressed S.";
                }

                if (IsKeyDown(KEY_D)) {
                    std::cout << "Pressed D.";
                }
                
            // Update
                Update(GetFrameTime());

            // Render
            BeginDrawing();
                ClearBackground(RAYWHITE);

                // Initialize Raylib's Vector2 struct using our engine's Vec2 data
                Vector2 rayPos = { PlayerPos.GetX(), PlayerPos.GetY() };
                Vector2 raySize = { 10.0f, 10.0f }; // Make it 10x10 so it's visible

                DrawRectangleV(rayPos, raySize, RED);
            EndDrawing();
        }
    }

}
}