#include "application.hpp"
#include <raylib.h>
#include <iostream>
#include <Math/Vectors/Vec2/Vec2.hpp>

namespace engine {
namespace core {

    void application::Update(float dt) {

    }

    engine::math::Vec2 application::InitPlayer() {
        engine::math::Vec2 PlayerPos((float) 400.0f, (float) 225.0f);

        return PlayerPos;
    }

    void application::Run(engine::math::Vec2 Player) {
        const int screenWidth = 800;
        const int screenHeight = 450;

        InitWindow(screenWidth, screenHeight, "GRMEngine");

        SetTargetFPS(60);

        while (!WindowShouldClose()) {
            // Input
                float dt = GetFrameTime();

                if (IsKeyDown(KEY_W)) {
                    Player.SetY(Player.GetY() - 200.0f * dt);
                }

                if (IsKeyDown(KEY_A)) {
                    Player.SetX(Player.GetX() - 200.0f * dt);
                }

                if (IsKeyDown(KEY_S)) {
                    Player.SetY(Player.GetY() + 200.0f * dt);
                }

                if (IsKeyDown(KEY_D)) {
                    Player.SetX(Player.GetX() + 200.0f * dt);
                }
                
            // Update
                Update(GetFrameTime());

            // Render
            BeginDrawing();
                ClearBackground(RAYWHITE);

                // Initialize Raylib's Vector2 struct using our engine's Vec2 data
                Vector2 rayPos = { Player.GetX(), Player.GetY() };
                Vector2 raySize = { 10.0f, 10.0f }; // Make it 10x10 so it's visible

                DrawRectangleV(rayPos, raySize, RED);
            EndDrawing();
        }
    }

}
}