#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GLFW/glfw3.h>
#include <cstdint>
#include <cstdio>
#include <glm/glm.hpp>

#define WIDTH 1280
#define HEIGHT 720
#define TITLE "ADK"
#define DEFAULT_EXIT_KEY GLFW_KEY_ESCAPE

using namespace glm;

class Window {
public:
  static Window &GetInstace();
  uint8_t checkWindowCloseStatus();

  void update();

  void swapBuffers();
  void pollEvents();
  ~Window();
  // objects
  double xPos, yPos;
  int xSize, ySize;

private:
  // objects
  GLFWwindow *winHandle;
  int closeKey = DEFAULT_EXIT_KEY;

  // Methods
  void checkWindowShouldClose();
  void updateCursorPosition();
  void updateScreenSize();
  void _CreateWindow();
  Window();
  Window(Window const &);
  void operator=(Window const &);
};

#endif
