#pragma once

#include "/Buffers/buffer.h"
#include "/Buffers/indexBuffer.h"
#include "/Buffers/vertexArray.h"

#include "../math/myMath.h"

namespace Graphics {

class Renderable2D {

protected:
myMath::vec3 m_Position;
myMath::vec2 m_Size;
myMath::vec3 m_Color;

vertexArray* m_VertexArray;
indexBuffer* m_IndexBuffer;

Renderable2D(myMath::vec3 position, myMath::vec2 size, myMath::color) {

        m_Position = position;
        m_Size = size;
        m_Color = color;

        m_VertexArray = new vertexArray();

        GLushort verts[] = {
          0,0,0,
          0,m_Position.y,0,
          m_Position.x,m_Position.y,0,
          m_Position.x,0,0
        };

        GLushort color[] = {
          color.x,color.y,color.z,
          color.x,color.y,color.z,
          color.x,color.y,color.z,
          color.x,color.y,color.z
        }

        m_VertexArray->addBuffer(new Buffer(verts,4*3,3),0);
        m_VertexArray->addBuffer(new Buffer(color,4*4,4),1);

        GLushort indicies[] = {0,1,2,2,3,0};

        m_IndexBuffer = new indexBuffer(indicies,6);

}

virtual ~Renderable2D(){
  delete m_VertexArray;
  delete m_IndexBuffer;
}

inline const myMath::vec3& getPosition(){return m_Position;};
inline const myMath::vec2& getSize(){return m_Size;};
inline const myMath::vec4& getColor(){return m_Color;};



}


}
