#include <TransMatrices.hpp>

void printMatrix(mat4 _mat) {
  printf("%f\t%f\t%f\t%f\n"
         "%f\t%f\t%f\t%f\n"
         "%f\t%f\t%f\t%f\n"
         "%f\t%f\t%f\t%f\n",
         _mat[0][0], _mat[0][1], _mat[0][2], _mat[0][3], _mat[1][0], _mat[1][1],
         _mat[1][2], _mat[1][3], _mat[2][0], _mat[2][1], _mat[2][2], _mat[2][3],
         _mat[3][0], _mat[3][1], _mat[3][2], _mat[3][3]);
}

mat4 GetScaleMatrix(float _screenheight, float _screenwidth,
                    float _objectheight, float _objectwidth) {
  double hRation, wRation;
  hRation = (1 / (_screenheight / 2)) * (_objectheight);
  wRation = (1 / (_screenwidth / 2)) * (_objectwidth);
  // printf("%f : %f\n", wRation, hRation);
  return mat4(vec4(wRation, 0, 0, 0), vec4(0, hRation, 0, 0), vec4(0, 0, 1, 0),
              vec4(0, 0, 0, 1));
}

mat4 GetTransformMatrix(float _screenheight, float _screenwidth,
                        float _objectXPos, float _objectYPos) {
  double hRation, wRation;
  hRation = (_objectYPos - (_screenheight / 2)) / (_screenheight / 2);
  wRation = (_objectXPos - (_screenwidth / 2)) / (_screenwidth / 2);
  // printf("%f : %f\n", wRation, hRation);
  return mat4(vec4(1, 0, 0, wRation), vec4(0, 1, 0, hRation), vec4(0, 0, 1, 0),
              vec4(0, 0, 0, 1));
}
