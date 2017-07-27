#include <iostream>
#include "myUtils/log.hpp"
#include "math/myMath.hpp"
#include "myUtils/fileUtils.hpp"

// Graphics includes
#include "Graphics/window.cpp"
#include "Graphics/shader.cpp"
#include "Graphics/Buffers/buffer.cpp"
#include "Graphics/Buffers/indexBuffer.cpp"
#include "Graphics/Buffers/vertexArray.cpp"
#include "Graphics/simple2Drenderer.cpp"
#include "Graphics/renderable2D.hpp"

using namespace myMath;
using namespace Graphics;
using namespace myUtils;



int main()
{

        //Clear the log file
        LOG_CLEAR();

        // Generate A new window object
        Window window("Game Engine v0.1",1280, 720);
        window.init();



        mat4 ortho = mat4::orthographic(0.0f,16.0f,0.0f,9.0f,-1.0f,1.0f);


        Shader shader("shaders/basic.vert","shaders/basic.frag");
        shader.enable();

        // Intialize shader peramiters
        shader.setUniformMat4("pr_matrix",ortho);
        shader.setUniformMat4("ml_matrix",mat4::translation(vec3(4,3,0)));
        shader.setUniform2f("light_pos",vec2(0.0f,0.0f));
        shader.setUniform4f("color",vec4(2.0,2.0,2.0,1.0));


        Renderable2D sprite(vec3(0,0,0),vec2(5,5),vec4(1,0,1,0),shader);
        Renderable2D sprite1(vec3(5,5,0),vec2(2,5),vec4(1,0,0,0),shader);
        Renderable2D sprite2(vec3(5,0,0),vec2(2,2),vec4(0,1,0,0),shader);
        Simple2Drenderer renderer;


        LOG_B("Entering while loop");
        /* Loop until the user closes the window */
        while (window.isOpen())
        {

                window.clear();

                renderer.submit(&sprite);
                renderer.submit(&sprite1);
                renderer.submit(&sprite2);
                renderer.flush();

                vec2 mousePos = window.getMousePosGL();

                shader.setUniform2f("light_pos",mousePos);
                std::cout << "\rWindow: (" << window.getMousePosWindow().x << "," << window.getMousePosWindow().y <<
                        ") TransForm:(" << mousePos.x << "," << mousePos.y << ")          "<< std::flush;




                window.update();

        }

        // Close the window
        window.closeWindow();
        std::cout <<"\n";


        return 0;
}
