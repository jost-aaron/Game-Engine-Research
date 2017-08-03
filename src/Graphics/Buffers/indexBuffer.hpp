#pragma once
#include <GL/glew.h>
#include "../../myUtils/glCheckError.hpp"

namespace Graphics {


class indexBuffer {
private:

GLuint m_BufferID;
GLuint m_Count;

public:

indexBuffer(GLuint* data,GLuint count);
~indexBuffer();

void bind() const;
void unbind() const;


// Get the number of components
inline GLuint getCount() const {
        return m_Count;
};

};


}
