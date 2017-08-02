#pragma once
#include "../renderable2D.hpp"
#include "../batchRenderer2D.hpp"
#include <vector>

namespace Graphics {

class Layer {

protected:
Renderer2D* m_Renderer;
std::vector<Renderable2D*> m_Renderables;
Shader* m_Shader;
myMath::mat4 m_ProjectionMatrix;

protected:
Layer(Renderer2D* renderer,Shader* shader,myMath::mat4 projectionMatrix);
public:
virtual ~Layer();
virtual void add(Renderable2D* renderable);
virtual void render();
};
}
