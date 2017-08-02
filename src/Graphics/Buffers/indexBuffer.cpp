#include "indexBuffer.hpp"

namespace Graphics {

// Constructor for indexBuffer
indexBuffer::indexBuffer(GLuint* data,GLuint count){
        // Set the number of components that are going to be in the buffer
        m_Count = count;

        glGenBuffers(1,&m_BufferID);
        glCheckError();
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_BufferID);
        glCheckError();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(float),data,GL_STATIC_DRAW);
        glCheckError();
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
        glCheckError();
}

// Destructor for the index buffer
indexBuffer::~indexBuffer(){
        glCheckError();
        glDeleteBuffers(1,&m_BufferID);
        glCheckError();
}

// Bind the buffer
void indexBuffer::bind() const {
        glCheckError();
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_BufferID);
        glCheckError();
}

// Unbind the buffer
void indexBuffer::unbind() const {
        glCheckError();
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
        glCheckError();
}

}
