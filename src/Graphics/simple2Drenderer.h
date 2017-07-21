#pragma once
#include "renderable2D.h"
#include "renderer2D.h"
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
