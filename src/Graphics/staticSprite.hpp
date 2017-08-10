#pragma once
#include "Buffers/buffer.hpp"
#include "Buffers/indexBuffer.hpp"
#include "Buffers/vertexArray.hpp"
#include "shader.hpp"
#include "renderable2D.hpp"

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
