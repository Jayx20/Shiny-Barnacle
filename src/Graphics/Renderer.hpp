#pragma once

namespace Graphics {
    class Renderer {
        private:
            int window;
            int windowWidth;
            int windowHeight;

        public:
            Renderer();
            void init();
            void setWindowSize(int width, int height);

    };
}