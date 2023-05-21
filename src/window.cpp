#include "window.hpp"
#include "GLFW/glfw3.h"
#include <cstdint>

// window update
//
// Called every frame
// Updates window size variables, cursor position variables and checks if close
// key is pressed and if pressed set windowshouldclose to true
//
void Window::update() {
  updateCursorPosition();
  updateScreenSize();
  checkWindowShouldClose();
}

//
// returns instance of window class, works as a singleton
//
Window &Window::GetInstace() {
  static Window instance;
  return instance;
}

//
// updated cursor position variables
//
void Window::updateCursorPosition() {
  glfwGetCursorPos(winHandle, &xPos, &yPos);
}

//
// updates screen size variables
//
void Window::updateScreenSize() {
  glfwGetWindowSize(winHandle, &xSize, &ySize);
}

//
// creates window
//
void Window::_CreateWindow() {
  // Init GLFW
  glfwInit();

  // Set Hints
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create window
  winHandle = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
  if (winHandle == NULL) {
    perror("Failed to create window\n");
  }

  // set current context
  glfwMakeContextCurrent(winHandle);
}

// GLFW Abstractions
void Window::pollEvents() { glfwPollEvents(); }
void Window::swapBuffers() { glfwSwapBuffers(winHandle); }

// checks if window should be closed, used in main loop
uint8_t Window::checkWindowCloseStatus() {
  return !glfwWindowShouldClose(winHandle);
}

// check if close key is pressed and sets window should close to true
void Window::checkWindowShouldClose() {
  if (glfwGetKey(winHandle, closeKey) == GLFW_PRESS) {
    glfwSetWindowShouldClose(winHandle, true);
  }
}

// Constructor
Window::Window() { _CreateWindow(); }

// Destructor
Window::~Window() {
  glfwDestroyWindow(winHandle);
  glfwTerminate();
}