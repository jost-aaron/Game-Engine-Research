#pragma once
#include "renderable2D.hpp"
#include "renderer2D.hpp"
#include <deque>

namespace Graphics {

// Simple2Drenderer derived from the Renderer2D
class Simple2Drenderer : public Renderer2D {

private:
// This is out render queue list
std::deque<const Renderable2D*> m_RendererQueue;

public:

void submit(const Renderable2D* renderable) override;
void flush() override;



};

}
