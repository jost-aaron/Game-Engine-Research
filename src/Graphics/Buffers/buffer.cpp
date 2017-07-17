#include "buffer.h"
namespace Graphics {

Buffer::Buffer(GLfloat* data,GLuint count,GLuint componentCount){

// Set the number of components that are going to be in the buffer
        m_ComponentCount = componentCount;

        glGenBuffers(1,&m_BufferID);
        glBindBuffer(GL_ARRAY_BUFFER,m_BufferID);
        glBufferData(GL_ARRAY_BUFFER,count*sizeof(float),data,GL_STATIC_DRAW);


}

// Bind the buffer
void Buffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER,m_BufferID);
}

// Unbind the buffer
void Buffer::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER,0);
}

}
