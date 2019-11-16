#include "VectorUtil.hpp"

std::vector<float> vectorsToFloats(std::vector<glm::vec3> vectors) {
    std::vector<float> floats;
    int i = 0;
    floats.resize(vectors.size()*3);
    for (glm::vec3 vector : vectors) {
        floats[i] = vector.x;
        i++;
        floats[i] = vector.y;
        i++;
        floats[i] = vector.z;
        i++;
    }
    return floats;
}

std::vector<float> vectorsToFloats(std::vector<glm::vec2> vectors) {
    std::vector<float> floats;
    int i = 0;
    floats.resize(vectors.size()*2);
    for (glm::vec2 vector : vectors) {
        floats[i] = vector.x;
        i++;
        floats[i] = vector.y;
        i++;
    }
    return floats;
}