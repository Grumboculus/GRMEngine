#include "grm/gal/GraphicsContext.hpp"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace grm::gal {
  static GLFWwindow* s_Window = nullptr;

  bool GraphicsContext::Init(int width, int height, const char* title) {
    if (!glfwInit()) {
      std::cerr << "Failed to initalize GLFW" << std::endl;
      return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    s_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!s_Window) {
      std::cerr << "Failed to create window" << std::endl;
      glfwTerminate();
      return false;
    }

    glfwMakeContextCurrent(s_Window);

    int version = gladLoadGL((GLADloadfunc)glfwGetProcAddress);
    if (version == 0) {
      std::cerr << "Failed to initialize GLAD" << std::endl;
      return false;
    }

    return true;
  }

  void GraphicsContext::Shutdown() {
    if (s_Window) {
      glfwDestroyWindow(s_Window);
    }

    glfwTerminate();
  }

  void GraphicsContext::SwapBuffers() {
    glfwSwapBuffers(s_Window);
    glfwPollEvents();
  }

  bool GraphicsContext::ShouldClose() {
    return glfwWindowShouldClose(s_Window);
  }

  void GraphicsContext::Clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }
}