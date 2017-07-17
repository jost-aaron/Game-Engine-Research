#pragma once
#include <GL/glew.h>

namespace Graphics {

class Buffer {
private:

GLuint m_BufferID;
GLuint m_ComponentCount;

public:

Buffer(GLfloat* data,GLuint count,GLuint componentCount);

void bind() const;
void unbind() const;

// Get the number of components
inline GLuint getComponentCount() const {return m_ComponentCount;};

};






}
