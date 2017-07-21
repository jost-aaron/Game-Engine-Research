#pragma once
#include <vector>
#include <GL/glew.h>
#include "buffer.h"

namespace Graphics {

class vertexArray {

private:
GLuint m_ArrayID;
std::vector<Buffer*> m_Buffers;


public:
vertexArray ();
~vertexArray ();


void addBuffer(Buffer* buffer,GLuint index);
void bind() const;
void unbind() const;

};



}
