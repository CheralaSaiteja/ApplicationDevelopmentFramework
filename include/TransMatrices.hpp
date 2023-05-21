#ifndef TRANSMATRICES_HPP
#define TRANSMATRICES_HPP

#include <stdio.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
using namespace glm;

mat4 GetScaleMatrix(float _screenheight, float _screenwidth,
                    float _objectheight, float _objectwidth);

mat4 GetTransformMatrix(float _screenheight, float _screenwidth,
                        float _objectXPos, float _objectYPos);

void printMatrix(mat4 _mat);

#endif