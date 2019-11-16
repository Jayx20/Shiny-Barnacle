#pragma once
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include <vector>

#include <iostream>

std::vector<float> vectorsToFloats(std::vector<glm::vec3> vectors);

std::vector<float> vectorsToFloats(std::vector<glm::vec2> vectors);