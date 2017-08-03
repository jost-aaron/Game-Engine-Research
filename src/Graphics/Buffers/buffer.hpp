#pragma once
#include <GL/glew.h>
#include "../../myUtils/glCheckError.hpp"

namespace Graphics {

class Buffer {
private:

GLuint m_BufferID;
GLuint m_ComponentCount;

public:

Buffer(GLfloat* data,GLuint count,GLuint componentCount);
~Buffer();

void bind() const;
void unbind() const;

// Get the number of components
inline GLuint getComponentCount() const {return m_ComponentCount;};

};






}
