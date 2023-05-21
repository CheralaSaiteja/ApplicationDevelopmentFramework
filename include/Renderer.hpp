#ifndef RENDERER_HPP
#define RENDERER_HPP
// GLAD
#include <glad/glad.h>
// GLM
#include <glm/glm.hpp>

using namespace glm;
class Renderer {
public:
  static Renderer &GetInstance();
  ~Renderer();
  void Init();
  void setBgColor(vec4 _color);
  vec4 getBgColor();
  void clearBackGround();

  unsigned int createShader(const char *frag_shader_path,
                            const char *vert_shader_path);
  unsigned int createQObjectBuffer();

private:
  // Objects
  vec4 bgColor = vec4(0);
  // Methods
  Renderer();
  Renderer(Renderer const &);
  void operator=(Renderer const &);
};

#endif