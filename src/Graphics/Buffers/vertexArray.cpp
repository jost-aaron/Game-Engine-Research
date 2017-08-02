#include "vertexArray.hpp"


namespace Graphics {

// Class consturctor
vertexArray::vertexArray(){
        glGenVertexArrays(1,&m_ArrayID);

}

// Class destructor
vertexArray::~vertexArray(){
        // Delete all of the buffers
        for (int i=0; i<m_Buffers.size(); i++) {
                delete m_Buffers[i];
        }
        glCheckError();
        glDeleteVertexArrays(1,&m_ArrayID);
        glCheckError();
}

void vertexArray::addBuffer(Buffer* buffer,GLuint index){
        glCheckError();
        bind();
        glCheckError();
        buffer->bind();
        glCheckError();

        glEnableVertexAttribArray(index);
        glCheckError();
        glVertexAttribPointer(index,buffer->getComponentCount(),GL_FLOAT,GL_FALSE,0,0);
        glCheckError();


        buffer->unbind();
        glCheckError();
        unbind();
        glCheckError();
}

// Bind the vertexArray to opengl
void vertexArray::bind() const {
        glCheckError();
        glBindVertexArray(m_ArrayID);
        glCheckError();
}

// unBind the vertexArray to opengl
void vertexArray::unbind() const {
        glCheckError();
        glBindVertexArray(0);
        glCheckError();
}




}
