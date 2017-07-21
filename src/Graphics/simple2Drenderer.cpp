#include "simple2Drenderer.h"

namespace Graphics {

// Add a renderable to the render queue
void Simple2Drenderer::submit(const Renderable2D* renderable){
        m_RendererQueue.push_back(renderable);
}

// Render all of the renderables in the queue
void Simple2Drenderer::flush(){



        // While there are still renderables in the render queue
        while (!m_RendererQueue.empty()) {

                // Grab the first renderable in the queue
                const Renderable2D* renderable = m_RendererQueue.front();

                // Bind its vertexArray buffer and indexBuffer to opengl
                renderable->getVao()->bind();
                renderable->getIbo()->bind();

                // Set the translation matrix of the shader to the current position of the renderable
                renderable->getShader().setUniformMat4("ml_matrix",myMath::mat4::translation(renderable->getPosition()));

                // Proform a draw call for all of the verticies
                glDrawElements(GL_TRIANGLES,renderable->getIbo()->getCount(),GL_UNSIGNED_SHORT,nullptr);

                // Unbind its vertexArray buffer and indexBuffer from opengl
                renderable->getVao()->unbind();
                renderable->getIbo()->unbind();


                // Remove the renderable from the front of the list we just rendered
                m_RendererQueue.pop_front();


        }
}


}
