#pragma once

#include <GL/glew.h>
#include "../myUtils/fileUtils.h"
#include <vector>
#include "../math/myMath.h"


namespace Graphics {

class Shader {

private:
public:
GLuint m_program;
GLuint load();

// Vertex shader path and fragment shader path to file
const char* m_vertPath;
const char* m_fragPath;

public:
Shader(const char* vertPath, const char* fragPath);
~Shader();

void enable() const;
void disable() const;

// For loading stuff into shaders
void setUniform1f(const GLchar* name, const float value);
void setUniform1i(const GLchar* name, const int value);
void setUniform2f(const GLchar* name, const myMath::vec2& value);
void setUniform3f(const GLchar* name, const myMath::vec3& value);
void setUniform4f(const GLchar* name, const myMath::vec4& value);
void setUniformMat4(const GLchar* name, const myMath::mat4& value);

GLuint getUniformLocation(const GLchar* name);



};


}
