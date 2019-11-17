#include "ComplexCube.hpp"
#include <array>

namespace GameObjects {
    Graphics::Mesh Cube::genComplexCubeMesh(float width, std::vector<float> colors) {
        
        ///TODO: finish this because it isnt done
        std::vector<float> vertices = {
            
            
            
            
            
            
        };

        Graphics::Mesh cubeMesh(vertices, complexCubeColors());
    }

    std::vector<float> complexCubeColors() {
        std::array<float, 3> color1 = {1,0,0}; //red
        std::array<float, 3> color2 = {0,1,0}; //green
        std::array<float, 3> color3 = {0,0,1}; //blue
        std::array<float, 3> color4 = color1; //red
        std::array<float, 3> color5 = color5; //green
        std::array<float, 3> color6 = color6; //blue
        
        std::array<std::array<float, 3>, 6> sixColors;

        std::vector<float> finalColors;
        //3 parts of each color, 4 vertexes per face, 6 faces = 72
        finalColors.resize(72);

        int i = 0;
        for(std::array<float, 3> color : sixColors) {
            //go through each color
            for(int k = 0; k<3; k++) {
                finalColors[i*3+k] = color[k];
            }
            i++;
        }

        return finalColors;
        
    }
}