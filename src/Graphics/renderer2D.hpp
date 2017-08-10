#pragma once

#include <GL/glew.h>
#include <vector>

// Math includes
#include "../math/vector/vec2.hpp"
#include "../math/vector/vec3.hpp"
#include "../math/vector/vec4.hpp"
#include "../math/matrix/mat4.hpp"

// #include "renderable2D.hpp"

// #include "staticSprite.hpp"

namespace Graphics {

// Forward declared Renderable2D so it dosent have to be included
// Causing recursive including of the headers
class Renderable2D;
class StaticSprite;

class Renderer2D {

protected:

std::vector<myMath::mat4> m_TransformationStack;
const myMath::mat4* m_TransformationBack;

protected:
// Consturctor to add the identity matrix to the begining of the Transformation Stack
Renderer2D() {
        m_TransformationStack.push_back(myMath::mat4::identity());
        m_TransformationBack = &m_TransformationStack.back();
}

public:
void push(const myMath::mat4& matrix,bool override = false){
        if (override) {
                m_TransformationStack.push_back(matrix);
        } else {
                m_TransformationStack.push_back(m_TransformationStack.back()*matrix);
        }
        m_TransformationBack = &m_TransformationStack.back();

}

void pop(){
  // TODO: Add this to logging if we are trying to pop the identity matrix in the Stack
        if (m_TransformationStack.size() > 1) {
                m_TransformationStack.pop_back();
        }
        m_TransformationBack = &m_TransformationStack.back();
}

virtual void begin(){
}
virtual void submit(const Renderable2D* renderable) = 0;
virtual void submit(const StaticSprite* sprite) = 0;
virtual void end(){
}
virtual void flush() = 0;

};
}
