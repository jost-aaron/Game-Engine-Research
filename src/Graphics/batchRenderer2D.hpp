#pragma once
// #include "renderable2D.hpp"
#include <cstddef>
#include "renderer2D.hpp"
#include "Buffers/vertexArray.hpp"
#include "../myUtils/glCheckError.hpp"


namespace Graphics {

class BatchRenderer2D : public Renderer2D {

// Attributes of the batch renderer
#define RENDERER_MAX_SPRITES 60000
#define RENDERER_VERTEX_SIZE sizeof(VertexData)
#define RENDERER_SPRITE_SIZE RENDERER_VERTEX_SIZE *4
#define RENDERER_BUFFER_SIZE RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICIES_SIZE RENDERER_MAX_SPRITES * 6

// Set the indexs of the vertex and color data in the vertex buffer
#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX 1

private:
indexBuffer* m_IBO;
GLsizei m_IndexCount;
GLuint m_VAO;
GLuint m_VBO;
VertexData* m_Buffer;

public:
BatchRenderer2D();
~BatchRenderer2D();
void begin() override;
void submit(const Renderable2D* renderable) override;
void submit(const StaticSprite* sprite) override{};
void end() override;
void flush() override;

private:
void init();

};
}
