#pragma once

#include "renderable2D.hpp"
#include "Buffers/include.hpp"

namespace Graphics {

class StaticSprite : public Renderable2D {

private:

vertexArray* m_VertexArray;
indexBuffer* m_IndexBuffer;
Shader& m_Shader;


public:
StaticSprite(float x,float y,float width,float height,const myMath::vec4& color,Shader& shader);
~StaticSprite();

// Inline accessor functions
inline const vertexArray* getVao() const {
        return m_VertexArray;
};
inline const indexBuffer* getIbo() const {
        return m_IndexBuffer;
};
inline Shader& getShader() const {
        return m_Shader;
};
};
}
