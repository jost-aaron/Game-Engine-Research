#include "batchRenderer2D.hpp"

namespace Graphics {

// Constructor
BatchRenderer2D::BatchRenderer2D() {
        init();
}

// Destructor
BatchRenderer2D::~BatchRenderer2D(){
        // Delete the index buffer and delete the opengl version of it
        delete m_IBO;
        glDeleteBuffers(1,&m_VBO);
}

// Initalize the batch renderer
void BatchRenderer2D::init(){

        // Generate a new buffer for the vertices and colors in opengl
        // m_VBO and m_VAO are used by opengl to represent a location of the buffer
        glGenBuffers(1,&m_VBO);
        glGenVertexArrays(1,&m_VAO);

        // Bind the buffer and vertex array to opengl
        glBindBuffer(GL_ARRAY_BUFFER,m_VBO);
        glBindVertexArray(m_VAO);

        // Set its data properties in opengl
        glBufferData(GL_ARRAY_BUFFER,RENDERER_BUFFER_SIZE,NULL,GL_DYNAMIC_DRAW);

        // Enable the vertex attribute array for vertexs and colors in opengl
        glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
        glEnableVertexAttribArray(SHADER_COLOR_INDEX);

        // Set the peramiters of the vertex Buffers for the vertices and colors buffers
        glVertexAttribPointer(SHADER_VERTEX_INDEX,3,GL_FLOAT,GL_FALSE,RENDERER_VERTEX_SIZE,(const GLvoid*) 0);
                                  // Changed GL_FLOAT to GL_UNSIGNED_BYTE for new color optimization in VertexData struct
        glVertexAttribPointer(SHADER_COLOR_INDEX,4,GL_UNSIGNED_BYTE,GL_TRUE,RENDERER_VERTEX_SIZE,(const GLvoid*)offsetof(VertexData,VertexData::color));

        // glVertexAttribPointer(SHADER_COLOR_INDEX,4,GL_FLOAT,GL_FALSE,RENDERER_VERTEX_SIZE,(const GLvoid*) (3*sizeof(GLfloat)));

        // Unbind the buffer
        glBindBuffer(GL_ARRAY_BUFFER,0);

        // Generate a place to put the indeicies for the verticies
        GLuint indices[RENDERER_INDICIES_SIZE];

        // offset is used to generate the indices them selfs
        int offset = 0;

        // Generate all of the indices
        // i is used for accessing the indices[] offset generates the values at indices[i]
        for (int i = 0; i < RENDERER_INDICIES_SIZE; i+=6) {

                // First triangle vertices
                indices[ i ] = offset + 0;
                indices[i+1] = offset + 1;
                indices[i+2] = offset + 2;

                // Second triangle vertices
                indices[i+3] = offset + 2;
                indices[i+4] = offset + 3;
                indices[i+5] = offset + 0;

                offset += 4;
        }

        // Make an index buffer with the indices
        m_IBO = new indexBuffer(indices,RENDERER_INDICIES_SIZE);

        // Unbind the vertexArray from opengl
        glBindVertexArray(0);
}

// Tells the batch renderer to get the glMapBuffer ready to receive data
void BatchRenderer2D::begin(){
        // Bind the Vertex buffer into opengl
        glBindBuffer(GL_ARRAY_BUFFER,m_VBO);
        glCheckError();

        // Get the buffer opengl is working with and cast it to a VertexData class type so we can load data into it
        m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER,GL_WRITE_ONLY);


        // std::cout << "m_VBO: " << m_VBO << "\nm_VAO: " << m_VAO << std::endl;
        // std::cout << "Initalized m_Buffer: " << m_Buffer << std::endl;

        glCheckError();
}

// Submit a renderable to the batch renderer
void BatchRenderer2D::submit(const Renderable2D* renderable){

        // Get all of the information about the renderable
        const myMath::vec3& position = renderable->getPosition();
        const myMath::vec2& size = renderable->getSize();
        const myMath::vec4& color = renderable->getColor();

        int r = color.x * 255.0f;
        int g = color.y * 255.0f;
        int b = color.z * 255.0f;
        int a = color.w * 255.0f;

        unsigned int c = a << 24 | b << 16 | g << 8 | r;

        // m_Buffer++ will itterate the opengl mapBuffer to the next index
        // std::cout << "Adding Data to Maped Buffer:\n[ vertices , color ]\n";
        // Get the vertices and color of the first vertex
        m_Buffer->vertices = *m_TransformationBack * position;
        m_Buffer->color = c;
        // std::cout << "[ " << m_Buffer->vertices << " , " << m_Buffer->color << " ]\n";
        m_Buffer++;

        // Get the vertices and color of the second vertex
        m_Buffer->vertices =  *m_TransformationBack * myMath::vec3(position.x,position.y + size.y,position.z);
        m_Buffer->color = c;
      // std::cout << "[ " << m_Buffer->vertices << " , " << m_Buffer->color << " ]\n";
        m_Buffer++;

        // Get the vertices and color of the third vertex
        m_Buffer->vertices =  *m_TransformationBack * myMath::vec3(position.x + size.x,position.y + size.y,position.z);
        m_Buffer->color = c;
        // std::cout << "[ " << m_Buffer->vertices << " , " << m_Buffer->color << " ]\n";
        m_Buffer++;

        // Get the vertices and color of the forth vertex
        m_Buffer->vertices =  *m_TransformationBack *  myMath::vec3(position.x + size.x,position.y,position.z);
        m_Buffer->color = c;
        // std::cout << "[ " << m_Buffer->vertices << " , " << m_Buffer->color << " ]\n";
        m_Buffer++;

        // Since each renderable has 6 indicies ie [0+n,1+n,2+n,2+n,3+n,0+n] increment the count by 6
        m_IndexCount += 6;
}

// Tell the batch renderer that all of the renderables have been submitted
void BatchRenderer2D::end(){

        // Unbind the mapBuffer and arrayBuffer from opengl
        glUnmapBuffer(GL_ARRAY_BUFFER);
        glBindBuffer(GL_ARRAY_BUFFER,0);
}

// Render all of the renderables to the screen
void BatchRenderer2D::flush(){

        glCheckError();

        // Bind the vertexArray and indexBuffer to opengl
        glBindVertexArray(m_VAO);
        glCheckError();

        m_IBO->bind();
        glCheckError();

        // Draw all of the renderables onto the screen
        glDrawElements(GL_TRIANGLES,m_IndexCount,GL_UNSIGNED_INT,NULL);
        glCheckError();

        // Unbind the vertexArray and indexBuffer from opengl
        m_IBO->unbind();
        glCheckError();

        glBindVertexArray(0);
        glCheckError();

        // Reset the count of the number of indexs to 0
        m_IndexCount = 0;
}

}
