// Std includes
#include <iostream>

// Graphics includes
#include "Graphics/window.cpp"
#include "Graphics/shader.cpp"
#include "Graphics/simple2Drenderer.cpp"
#include "Graphics/renderable2D.hpp"
#include "Graphics/staticSprite.cpp"
#include "Graphics/sprite.cpp"
#include "Graphics/batchRenderer2D.cpp"

#include "myUtils/fpsCounter.hpp"
#include "myUtils/myTimer.hpp"

// Other includes
#include "myUtils/include.hpp"
#include "math/include.hpp"
#include "Graphics/layers/layer.cpp"
#include "Graphics/layers/tileLayer.cpp"

#define VERSION "v0.1"
#define WINDOW_NAME "Game Engine " VERSION
#define WINDOW_RESOLUTION 1920,1080

using namespace myMath;
using namespace Graphics;
using namespace myUtils;

int main()
{

        //Clear the log file
        // LOG_CLEAR();

        // Generate A new window object
        Window window(WINDOW_NAME,WINDOW_RESOLUTION);
        window.init();

        mat4 ortho = mat4::orthographic(0.0f,16.0f,0.0f,9.0f,-1.0f,1.0f);

        Shader* s = new Shader("shaders/basic.vert","shaders/basic.frag");
        Shader* s2 = new Shader("shaders/basic.vert","shaders/basic.frag");

        Shader& shader = *s;
        Shader& shader2 = *s2;

        // Intialize shader peramiters
        shader.enable();
        shader.setUniform2f("light_pos",vec2(0.0f,0.0f));
        shader2.enable();
        shader2.setUniform2f("light_pos",vec2(0.0f,0.0f));


        TileLayer layer(&shader);
        // layer.add(new Sprite(-4.0f,-4.0f,4.0f,4.0f,vec4(rand() % 1000 / 1000.0f,0,1,1)));

        for (float y=-9.0f; y < 9.0f; y+= 0.1) {
          for(float x=-16.0f; x < 16.0f; x+= 0.1) {
            layer.add(new Sprite(x,y,0.04f,0.04f,vec4(rand() % 1000 / 1000.0f,0,1,1)));
          }
        }

        TileLayer layer2(&shader2);
        layer2.add(new Sprite(-1.0f,-1.0f,2.0f,2.0f,vec4(rand() % 1000 / 1000.0f,0,1,1)));



        // Fps timer
        myTimer t;

        LOG_B("Entering while loop");
        /* Loop until the user closes the window */
        while (window.isOpen())
        {
                window.clear();

                vec2 mousePos = window.getMousePosGL();

                shader.enable();
                shader.setUniform2f("light_pos",mousePos);

                shader2.enable();
                shader2.setUniform2f("light_pos",mousePos);


                layer.render();


                layer2.render();




                // std::cout << "Rendering sprite 1\n";


                // std::cout <<std::endl;





                // std::cout << "Rendering sprite 2\n";
                // layer2.render();

                window.update();

                showFPS_GLFW(window,t.getFPS());
                // std::cout << std::endl;

                //  break;

        }
        std::cin;
        // Close the window
        window.closeWindow();
        std::cout <<"\n";


        return 0;
}
