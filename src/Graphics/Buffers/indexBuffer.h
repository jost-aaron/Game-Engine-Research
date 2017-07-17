#pragma once
#include "indexBuffer.h"

namespace Graphics {


  class indexBuffer {
  private:

  GLuint m_BufferID;
  GLuint m_Count;

  public:

  indexBuffer(GLushort* data,GLuint count);

  void bind() const;
  void unbind() const;


  // Get the number of components
  inline GLuint getCount() const {return m_Count;};

  };


}
