#include "CubeMesh.hpp"
#include <array>

namespace Graphics {
    Graphics::Mesh CubeMesh::genCubeMesh(float width, std::vector<float> colors) {
        
        //there has to be a better way to do this...
        std::vector<float> vertices = {

        //Right
        width,  width,  width,
        width,  width, -width,
        width, -width,  width,
        width, -width, -width,

        //Back
        width,  width, -width,
        width, -width, -width,
        -width,  width, -width,
        -width, -width, -width,

        //Left
        -width,  width,  width,
        -width,  width, -width,
        -width, -width,  width,
        -width, -width, -width,

        //Front
        width,  width,  width,
        width, -width,  width,
        -width,  width,  width,
        -width, -width,  width,
        
        //Top
        width,  width,  width,
        width,  width, -width,
        -width,  width,  width,
        -width,  width, -width,

        //Bottom
        width, -width,  width,
        width, -width, -width,
        -width, -width,  width,
        -width, -width, -width

        };

        //0, 1, 2   1, 2, 3
        //4, 5, 6   5, 6, 7
        std::vector<unsigned int> indices;
        indices.resize(36); //36 = 2 triangles per face, 3 verts per triangle, 6 faces

        //6 faces
        for(unsigned int face; face<6; face++) {
            unsigned int start = face*6; //the first index of the face
            for(unsigned int t = 0; t<2; t++) {
                indices[start+t*3]   = face*4+t+0; //0, 1
                indices[start+t*3+1] = face*4+t+1; //1, 2
                indices[start+t*3+2] = face*4+t+2; //2, 3
            }
        }

        Graphics::Mesh cubeMesh(vertices, colors, std::vector<float>(), indices, GL_TRIANGLES);
        return cubeMesh;
    }

    std::vector<float> CubeMesh::cubeColors() {
        std::array<float, 3> color1 = {1,0,0}; //red
        std::array<float, 3> color2 = {0,1,0}; //green
        std::array<float, 3> color3 = {0,0,1}; //blue
        std::array<float, 3> color4 = color1; //red
        std::array<float, 3> color5 = color5; //green
        std::array<float, 3> color6 = color6; //blue
        
        std::array<std::array<float, 3>, 6> sixColors{color1, color2, color3, color4, color5, color6};

        std::vector<float> finalColors;
        //3 parts of each color, 4 vertexes per face, 6 faces = 72
        finalColors.resize(72);
        
        std::fill(finalColors.begin(), finalColors.end(), 0.5);

        std::fill(finalColors.begin()+0, finalColors.begin()+11, 0);
        std::fill(finalColors.begin()+12, finalColors.begin()+23, .2);
        std::fill(finalColors.begin()+24, finalColors.begin()+35, .4);
        std::fill(finalColors.begin()+36, finalColors.begin()+47, .6);
        std::fill(finalColors.begin()+48, finalColors.begin()+59, .8);
        std::fill(finalColors.begin()+60, finalColors.begin()+71, 1);

        /*
        for (int face = 0; face<6; face++) {
            std::array<float, 3> color = sixColors[face];
            //std::fill(finalColors.begin()+face*12, finalColors.begin()+((face+1)*12), color[]);
        }*/
        
       
       //ok
       /*
       for(int face = 0; face<6; face++) {
           std::array<float, 3> color = sixColors[face];
           //4 vertices in a face
           for(int v = 0; v<4; v++) {
               for(int i=0; i<3; i++) {
                   finalColors[face*6+v*4+i] = color[i];
                   printf("%f ",color[i]);
                }
           }
       }

        printf("\n");*/

        /*
        int i = 0;
        for(std::array<float, 3> color : sixColors) {
            //go through each color
            for(int k = 0; k<3; k++) {
                finalColors[i*3+k] = color[k];
            }
            i++;
        }
        */

        #ifdef DEBUG
        for(float color : finalColors) {
            printf("%f ", color);
        }
        #endif

        return finalColors;
        
    }
}