#include "indexBuffer.h"

namespace Graphics {

indexBuffer::indexBuffer(GLushort* data,GLuint count){

  // Set the number of components that are going to be in the buffer
  m_Count = count;

  glGenBuffers(1,&m_BufferID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_BufferID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(float),data,GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);


}

// Bind the buffer
void indexBuffer::bind() const{
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_BufferID);
}

// Unbind the buffer
void indexBuffer::unbind() const{
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

}
