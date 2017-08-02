#include "tileLayer.hpp"

namespace Graphics {

TileLayer::TileLayer(Shader* shader)
        : Layer(new BatchRenderer2D(),shader,myMath::mat4::orthographic(-16.0f,16.0f,-9.0f,9.0f,-1.0f,1.0f)) {

}

TileLayer::~TileLayer(){


}
}
