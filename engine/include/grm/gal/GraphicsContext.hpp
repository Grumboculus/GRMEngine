#pragma once

namespace grm::gal {
  
  class GraphicsContext {
    public:
      static bool Init(int width, int height, const char* title);
      static void Shutdown();

      static void SwapBuffers();
      static bool ShouldClose();

      static void Clear(float r, float g, float b, float a);
  };

}