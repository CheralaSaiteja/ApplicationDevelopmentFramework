// Contains glad.h
// should defined above averything
#include <Renderer.hpp>

// std
#include <stdio.h>
#include <stdlib.h>

// APP
#include <Object.hpp>
#include <TransMatrices.hpp>
#include <window.hpp>

// Handles
// window instance
Window &window = Window::GetInstace();
// Renderer instance
Renderer &renderer = Renderer::GetInstance();

// main
int main() {
  printf("Hello ADK\n");
  renderer.Init();
  renderer.setBgColor(vec4(1.0, 1.0, 1.0, 1.0));

  QObject simpleQuad;

  //   simpleQuad.VAO = renderer.createQObjectBuffer();

  //   simpleQuad.shader = renderer.createShader("src/shader/defaultFrag.glsl",
  //                                             "src/shader/defaultVert.glsl");

  CreateNewQObject(&simpleQuad, "Simple Object", 0.0f);

  while (window.checkWindowCloseStatus()) {

    // poll events
    window.pollEvents();

    // window update
    window.update();

    // clear background color to renmderer.bgcolor
    renderer.clearBackGround();

    // Draw
    RenderQObject(&simpleQuad);

    // // use shader
    // glUseProgram(simpleQuad.shader);

    // // pass data
    // glUniformMatrix4fv(
    //     glGetUniformLocation(simpleQuad.shader, "scale"), 1, GL_FALSE,
    //     value_ptr(GetScaleMatrix(window.ySize, window.xSize, 715, 150)));
    // glUniformMatrix4fv(
    //     glGetUniformLocation(simpleQuad.shader, "trans"), 1, GL_FALSE,
    //     value_ptr(GetTransformMatrix(window.ySize, window.xSize, 1200,
    //     365)));
    // glUniform1f(glGetUniformLocation(simpleQuad.shader, "zIndex"), 0.0);
    // // binding and drawing
    // glBindVertexArray(simpleQuad.VAO);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // glBindVertexArray(0);

    // swap window buffers
    window.swapBuffers();
  }

  return EXIT_SUCCESS;
}
