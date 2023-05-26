// Header
#include <QObject.hpp>
#include <cstring>
Renderer &oRenderer = Renderer::GetInstance();
Window &oWindow = Window::GetInstace();

void CreateNewQObject(QObject *_object, const char *_name, float _zindex) {
  // set name
  strcpy(_object->Name, _name);

  // create buffer handle
  _object->VAO = oRenderer.createQObjectBuffer();

  // set defaults
  _object->Position = vec2(0);
  _object->Scale = vec2(1);
  _object->zIndex = _zindex;

  // assign shader
  _object->shader = oRenderer.createShader("src/shader/default.frag",
                                           "src/shader/default.vert");
}
void RenderQObject(QObject *_object) {
  // use shader
  glUseProgram(_object->shader);

  // pass data
  glUniformMatrix4fv(
      glGetUniformLocation(_object->shader, "scale"), 1, GL_FALSE,
      value_ptr(GetScaleMatrix(oWindow.ySize, oWindow.xSize, 715, 150)));
  glUniformMatrix4fv(
      glGetUniformLocation(_object->shader, "trans"), 1, GL_FALSE,
      value_ptr(GetTransformMatrix(oWindow.ySize, oWindow.xSize, 1200, 365)));
  glUniform1f(glGetUniformLocation(_object->shader, "zIndex"), 0.0);
  // binding and drawing
  glBindVertexArray(_object->VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}