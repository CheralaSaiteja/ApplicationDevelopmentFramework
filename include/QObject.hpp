#ifndef OBJECT_HPP
#define OBJECT_HPP

// Renderer Header
// Always should be included firt
// Contains GLAD Header
#include <Renderer.hpp>
// Window
#include <TransMatrices.hpp>
#include <window.hpp>

#define MAX_QOBJECT_NAME_LENGTH 64

//
// QObject - Quad Object
//
struct QObject {
  char Name[MAX_QOBJECT_NAME_LENGTH];
  vec2 Position;
  vec2 Rotation;
  vec2 Scale;
  unsigned int VAO, shader;
  float zIndex;
};



void CreateNewQObject(QObject *_object, const char *_name, float _zindex);
void RenderQObject(QObject *_object);

#endif