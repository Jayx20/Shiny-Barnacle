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

        /*

        This was the OLD code that generated the array of floats you see below...
        but for some reason, it magically didn't work. It would produce that array of floats, and opengl would see it
        and it would just draw nothing

        I printed out the copy of the array, and copy pasted it below, and then it works fine. ?????????
        this occured on 11/19/19, i hope somebody finds this in 2020 and figures out why because i want to know. thank you.

        std::array<float, 3> color1 = {1.0f,0.0f,0.0f}; //red
        std::array<float, 3> color2 = {0.0f,1.0f,0.0f}; //green
        std::array<float, 3> color3 = {1,0,0}; //red
        std::array<float, 3> color4 = {0,1,0}; //green
        std::array<float, 3> color5 = {0,0,1}; //blue
        std::array<float, 3> color6 = {0,0,1}; //blue
        
        std::array<std::array<float, 3>, 6> sixColors{color1, color2, color3, color4, color5, color6};

        float finalColors[72];
        //3 parts of each color, 4 vertexes per face, 6 faces = 72
        
        for (int face = 0; face<6; face++) {
            std::array<float, 3> color = sixColors[face];
            //4 verts in a face
            for (int v = 0;  v<4; v++) {
                //face*12, (face+1)*12-1
                for(int i=0; i<3; i++) {
                    finalColors[face*12+v*3+i] = color[i];
                    printf("%f\n",color[i]);
                }
                printf("\n");
            }
        }

        return std::vector<float>(std::begin(finalColors),std::end(finalColors));
        */
        
        return std::vector<float> {
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,

            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,

            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,

            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,

            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,

            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f
        };
        
    }
}