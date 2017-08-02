#include "simple2Drenderer.hpp"

namespace Graphics {

// // Add a sprite to the render queue
void Simple2Drenderer::submit(const StaticSprite* sprite){
        m_RendererQueue.push_back(sprite);
}


// Render all of the sprites in the queue
void Simple2Drenderer::flush(){

        // While there are still sprites in the render queue
        while (!m_RendererQueue.empty()) {

                // Grab the first sprite in the queue
                const StaticSprite* sprite = m_RendererQueue.front();
                glCheckError();

                // Bind its vertexArray buffer and indexBuffer to opengl
                sprite->getVao()->bind();
                glCheckError();
                sprite->getIbo()->bind();
                glCheckError();

                // Set the translation matrix of the shader to the current position of the sprite
                sprite->getShader().setUniformMat4("ml_matrix",myMath::mat4::translation(sprite->getPosition()));

                glCheckError();
                // Proform a draw call for all of the verticies
                // glDrawElements(GL_TRIANGLES,sprite->getIbo()->getCount(),GL_UNSIGNED_INT,nullptr);
                glDrawElements(GL_TRIANGLES,sprite->getIbo()->getCount(),GL_UNSIGNED_INT,NULL);
                glCheckError();

                // Unbind its vertexArray buffer and indexBuffer from opengl
                sprite->getVao()->unbind();
                sprite->getIbo()->unbind();


                // Remove the sprite from the front of the list we just rendered
                m_RendererQueue.pop_front();


        }
}


}
