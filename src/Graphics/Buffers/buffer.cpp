#include "buffer.hpp"
namespace Graphics {

Buffer::Buffer(GLfloat* data,GLuint count,GLuint componentCount){

// Set the number of components that are going to be in the buffer
        m_ComponentCount = componentCount;
        glCheckError();
        glGenBuffers(1,&m_BufferID);
        glCheckError();
        glBindBuffer(GL_ARRAY_BUFFER,m_BufferID);
        glCheckError();
        glBufferData(GL_ARRAY_BUFFER,count*sizeof(float),data,GL_STATIC_DRAW);
        glCheckError();
}

// Destructor for the buffer
Buffer::~Buffer(){
        glCheckError();
        glDeleteBuffers(1,&m_BufferID);
        glCheckError();
}

// Bind the buffer
void Buffer::bind() const {
        glCheckError();
        glBindBuffer(GL_ARRAY_BUFFER,m_BufferID);
        glCheckError();
}

// Unbind the buffer
void Buffer::unbind() const {
        glCheckError();
        glBindBuffer(GL_ARRAY_BUFFER,0);
        glCheckError();
}

}
