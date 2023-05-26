// std
#include <stdio.h>
#include <stdlib.h>

// APP
#include <QObject.hpp>

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

    // swap window buffers
    window.swapBuffers();
  }

  return EXIT_SUCCESS;
}
