#pragma once

#include "renderable2D.h"
#include <GL/glew.h>
#include "../math/myMath.h"

namespace Graphics {

class Renderer2D {

protected:
virtual void submit(const Renderable2D* renderable) = 0;
virtual void flush() = 0;


};

}
