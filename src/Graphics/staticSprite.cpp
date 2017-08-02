#include "staticSprite.hpp"


namespace Graphics {

// Constructor
StaticSprite::StaticSprite(float x,float y,float width,float height,const myMath::vec4& colors,Shader& shader)
        : Renderable2D(myMath::vec3(x,y,0),myMath::vec2(width,height),colors),m_Shader(shader){
        m_VertexArray = new vertexArray();

        GLfloat verts[] = {
                0,0,0,
                0,height,0,
                width,height,0,
                width,0,0
        };



        GLfloat color[] = {
                m_Color.x,m_Color.y,m_Color.z,
                m_Color.x,m_Color.y,m_Color.z,
                m_Color.x,m_Color.y,m_Color.z,
                m_Color.x,m_Color.y,m_Color.z
        };

        glCheckError();
        m_VertexArray->addBuffer(new Buffer(verts,4*3,3),0);
        glCheckError();

        m_VertexArray->addBuffer(new Buffer(color,4*4,3),1);
        glCheckError();

        GLuint indicies[] = {0,1,2,2,3,0};

        m_IndexBuffer = new indexBuffer(indicies,6);



}

// Destructor
StaticSprite::~StaticSprite(){
        delete m_VertexArray;
        delete m_IndexBuffer;
}

}
