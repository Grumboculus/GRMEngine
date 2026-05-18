#include "grm/gal/GraphicsContext.hpp"

int main() {
    if (!grm::gal::GraphicsContext::Init(800, 600, "GRMEngine")) {
        return -1;
    }

    while (!grm::gal::GraphicsContext::ShouldClose()) {
        grm::gal::GraphicsContext::Clear(0.2f, 0.3f, 0.3f, 1.0f);
        
        // Render loop...

        grm::gal::GraphicsContext::SwapBuffers();
    }

    grm::gal::GraphicsContext::Shutdown();
    return 0;
}