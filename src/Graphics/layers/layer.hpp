#pragma once
#include "../renderable2D.hpp"
#include "../renderer2D.hpp"
#include "../batchRenderer2D.hpp"
#include <vector>

namespace Graphics {

class Layer {

protected:
std::vector<Renderable2D*> m_Renderables;
Shader* m_Shader;
myMath::mat4 m_ProjectionMatrix;

protected:
Layer(Renderer2D* renderer,Shader* shader,myMath::mat4 projectionMatrix);
public:
  Renderer2D* m_Renderer;
virtual ~Layer();
virtual void add(Renderable2D* renderable);
virtual void render();
};
}
