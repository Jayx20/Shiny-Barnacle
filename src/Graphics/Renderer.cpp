#include "Renderer.hpp"
#include <iostream>
#include <string>

const int DEFAULT_WINDOW_WIDTH = 640;
const int DEFAULT_WINDOW_HEIGHT = 480;

namespace Graphics {

    Renderer::Renderer() {
        windowWidth = DEFAULT_WINDOW_WIDTH;
        windowHeight = DEFAULT_WINDOW_HEIGHT;
    }

    void Renderer::setWindowSize(int width, int height) {
        windowWidth = width;
        windowHeight = height;
    }

    void Renderer::init() {
        std::cout << windowWidth << "x" << windowHeight << "\n";
    }
}