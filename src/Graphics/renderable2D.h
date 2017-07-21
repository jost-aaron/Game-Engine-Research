#pragma once

#include "Buffers/buffer.h"
#include "Buffers/indexBuffer.h"
#include "Buffers/vertexArray.h"

#include "../math/myMath.h"

#include "shader.h"

namespace Graphics {

class Renderable2D {

public:
myMath::vec3 m_Position;
myMath::vec2 m_Size;
myMath::vec4 m_Color;

vertexArray* m_VertexArray;
indexBuffer* m_IndexBuffer;

// Shader& m_Shader;
Shader& m_Shader;

Renderable2D(myMath::vec3 position, myMath::vec2 size, myMath::vec4 colors,Shader& shader)
        : m_Shader(shader),m_Position(position),m_Size(size),m_Color(colors) {

        m_VertexArray = new vertexArray();

        GLfloat verts[] = {
                0,0,0,
                0,m_Size.y,0,
                m_Size.x,m_Size.y,0,
                m_Size.x,0,0
        };



        GLfloat color[] = {
                m_Color.x,m_Color.y,m_Color.z,
                m_Color.x,m_Color.y,m_Color.z,
                m_Color.x,m_Color.y,m_Color.z,
                m_Color.x,m_Color.y,m_Color.z
        };


        m_VertexArray->addBuffer(new Buffer(verts,4*3,3),0);
        m_VertexArray->addBuffer(new Buffer(color,4*4,3),1);

        GLushort indicies[] = {0,1,2,2,3,0};

        m_IndexBuffer = new indexBuffer(indicies,6);

}

virtual ~Renderable2D(){
        delete m_VertexArray;
        delete m_IndexBuffer;
}

public:



// Inline accessor fuctions
inline const vertexArray* getVao() const {
        return m_VertexArray;
};
inline const indexBuffer* getIbo() const {
        return m_IndexBuffer;
};
inline const myMath::vec3& getPosition() const {
        return m_Position;
};
inline const myMath::vec2& getSize() const {
        return m_Size;
};
inline const myMath::vec4& getColor() const {
        return m_Color;
};
inline Shader& getShader() const {
        return m_Shader;
};



};


}
