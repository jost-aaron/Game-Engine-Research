#pragma once

// Buffer stuff
#include "Buffers/buffer.hpp"
#include "Buffers/indexBuffer.hpp"
#include "Buffers/vertexArray.hpp"

// Math stuff
#include "../math/vector/vec2.hpp"
#include "../math/vector/vec3.hpp"
#include "../math/vector/vec4.hpp"
#include "../math/matrix/mat4.hpp"

#include "renderer2D.hpp"

#include "shader.hpp"

namespace Graphics {

class Renderer2D;

// A renderable2Ds vertex data
struct VertexData {
        myMath::vec3 vertices;
        // myMath::vec4 color;
        unsigned int color;
};

// Class for a renderable2D object
class Renderable2D {

public:
myMath::vec3 m_Position;
myMath::vec2 m_Size;
myMath::vec4 m_Color;

protected:
Renderable2D(){};


public:
Renderable2D(myMath::vec3 position, myMath::vec2 size, myMath::vec4 colors)
        : m_Position(position),m_Size(size),m_Color(colors) {
}

virtual ~Renderable2D(){
}


virtual void submit(Renderer2D* renderer) const {
        renderer->submit(this);
}

public:

inline const myMath::vec3& getPosition() const {
        return m_Position;
};
inline const myMath::vec2& getSize() const {
        return m_Size;
};
inline const myMath::vec4& getColor() const {
        return m_Color;
};

};

}
