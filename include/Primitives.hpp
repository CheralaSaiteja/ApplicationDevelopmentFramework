#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include <glm/glm.hpp>

using namespace glm;

struct Quad {
  vec3 p0 = vec3(-1, -1, 0.0);
  vec3 p1 = vec3(1, -1, 0.0);
  vec3 p2 = vec3(1, 1, 0.0);
  vec3 p3 = vec3(-1, 1, 0.0);
};

#endif