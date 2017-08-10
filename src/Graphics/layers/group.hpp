#pragma once

#include "../renderable2D.hpp"

namespace Graphics {
class Group : public Renderable2D {

private:
std::vector<Renderable2D*> m_Renderables;
myMath::mat4 m_TransformationMatrix;

public:
Group(const myMath::mat4& transform);
void add(Renderable2D* renderable);
void submit(Renderer2D* renderer) const override;

};
}
