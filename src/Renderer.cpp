#include "Renderer.hpp"
#include <stdio.h>

Renderer &Renderer::GetInstance() {
  static Renderer instance;
  return instance;
}

void Renderer::Init() { gladLoadGL(); }

void Renderer::setBgColor(vec4 _color) { bgColor = _color; }
vec4 Renderer::getBgColor() { return bgColor; }
Renderer::Renderer() { Init(); }
Renderer::~Renderer() {}
void Renderer::clearBackGround() {
  glClearColor(bgColor.r, bgColor.g, bgColor.b, bgColor.a);
  glClear(GL_COLOR_BUFFER_BIT);
}

void getFileSize(FILE *fd, long *size) {
  fseek(fd, 0L, SEEK_END);
  *size = ftell(fd);
  rewind(fd);
}
char *loadFile(const char *file_path) {
  FILE *fd = fopen(file_path, "r");
  if (fd == NULL) {
    perror("Failed to read file");
    return NULL;
  }
  long fSize = 0;
  getFileSize(fd, &fSize);
  if (fSize == 0) {
    perror("file is empty");
    fclose(fd);
    return NULL;
  }
  char *buffer = (char *)malloc(fSize + 1);
  if (buffer == NULL) {
    perror("failed to allocate");
    fclose(fd);
    return NULL;
  }
  fread(buffer, 1, fSize, fd);
  buffer[fSize] = '\0';

  return buffer;
}

unsigned int Renderer::createShader(const char *frag_shader_path,
                                    const char *vert_shader_path) {
  unsigned int shaderProgram, fragShader, vertShader;

  char *fragSource, *vertSource;
  int success;
  char infoLog[512];

  fragSource = loadFile(frag_shader_path);
  vertSource = loadFile(vert_shader_path);

  // vertex shader
  vertShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertShader, 1, &vertSource, NULL);
  glCompileShader(vertShader);

  glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
    printf("ERROR VERTEX SHADER\n%s\n", infoLog);
    return -1;
  }

  // fragment shader
  fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragShader, 1, &fragSource, NULL);
  glCompileShader(fragShader);

  glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
    printf("ERROR FRAGMENT SHADER\n%s\n", infoLog);
    return -1;
  }

  // shader program
  shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, vertShader);
  glAttachShader(shaderProgram, fragShader);
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    printf("ERROR SHADER PROGRAM\n%s\n", infoLog);
    return -1;
  }

  // delete shaders
  glDeleteShader(vertShader);
  glDeleteShader(fragShader);

  free(vertSource);
  free(fragSource);

  return shaderProgram;
}

// required Vertices and Indices Arrays
//
// for a quad(two triangles)
//
float QuadVertices[] = {
    0.5,  0.5,  // top right
    0.5,  -0.5, // bottom right
    -0.5, -0.5, // bottom left
    -0.5, 0.5   // top left
};
unsigned int QuadIndices[] = {
    // 0, 1, 3, // first triangle
    // 1, 2, 3  // second triangle
    2, 1, 0, 2, 0, 3};

unsigned int Renderer::createQObjectBuffer() {
  unsigned int VAO, VBO, EBO;
  // VAO
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  // VBO
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(QuadVertices), QuadVertices,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // EBO
  glGenBuffers(1, &EBO);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(QuadIndices), QuadIndices,
               GL_STATIC_DRAW);
  glBindVertexArray(0);
  return VAO;
}