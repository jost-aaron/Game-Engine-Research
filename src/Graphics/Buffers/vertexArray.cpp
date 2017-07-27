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
}

void vertexArray::addBuffer(Buffer* buffer,GLuint index){
  bind();
  buffer->bind();

  glEnableVertexAttribArray(index);
  glVertexAttribPointer(index,buffer->getComponentCount(),GL_FLOAT,GL_FALSE,0,0);


  buffer->unbind();
  unbind();
}

// Bind the vertexArray to opengl
void vertexArray::bind() const {
  glBindVertexArray(m_ArrayID);
}

// unBind the vertexArray to opengl
void vertexArray::unbind() const {
  glBindVertexArray(0);
}




}
