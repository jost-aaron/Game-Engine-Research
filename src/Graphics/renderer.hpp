#pragma once

#include "Renderable2D.hpp"
#include <GL/glew.h>
#include "../math/myMath.hpp"

namespace Graphics {


class Renderer2D {
protected:

virtual void submit(const Renderable2D& renderable) = 0;
virtual void flush() = 0;



}

}
