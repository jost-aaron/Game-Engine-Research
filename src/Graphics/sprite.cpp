#include "sprite.hpp"

namespace Graphics {

Sprite::Sprite(float x,float y,float width,float height,const myMath::vec4& color/*,Shader& shader*/)
        : Renderable2D(myMath::vec3(x,y,0),myMath::vec2(width,height),color)/*,m_Shader(shader)*/{


}

}
