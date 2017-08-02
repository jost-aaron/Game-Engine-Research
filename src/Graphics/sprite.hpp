#pragma once

#include "renderable2D.hpp"

namespace Graphics {

class Sprite : public Renderable2D {

private:



public:
Sprite(float x,float y,float width,float height,const myMath::vec4& color/*,Shader& shader*/);


};
}
