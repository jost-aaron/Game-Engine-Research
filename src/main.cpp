// Std includes
#include <iostream>

// Graphics includes
#include "Graphics/window.hpp"
#include "Graphics/shader.hpp"
#include "Graphics/simple2Drenderer.hpp"
#include "Graphics/staticSprite.hpp"
#include "Graphics/sprite.hpp"
#include "Graphics/batchRenderer2D.hpp"

#include "myUtils/fpsCounter.hpp"
#include "myUtils/myTimer.hpp"

// Other includes
#include "math/vector/vec2.hpp"
#include "math/vector/vec3.hpp"
#include "math/vector/vec4.hpp"

#include "Graphics/renderable2D.hpp"

#include "Graphics/layers/layer.hpp"
#include "Graphics/layers/tileLayer.hpp"

#include "Graphics/layers/group.hpp"

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

        mat4 transform1 = mat4::translation(vec3(0.0f,0.0f,0.0f));
        mat4 rotation1 = mat4::rotation(45.0f,vec3(0,0,1));
        mat4 answer = transform1*rotation1;

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

        for (float y=-9.0f; y < 9.0f; y+= 0.1) {
          for(float x=-16.0f; x < 16.0f; x+= 0.1) {
            layer.add(new Sprite(x,y,0.04f,0.04f,vec4(rand() % 1000 / 1000.0f,0,1,1)));
          }
        }
        mat4 transform = mat4::translation(vec3(0.0f,0.0f,0.0f)) * mat4::rotation(45.0f,vec3(0,0,1));

        // std::cout << "4x4 45deg rotation matrix" << '\n' << transform << std::endl;

        // layer.add(new Sprite(-4.0f,-4.0f,4.0f,4.0f,vec4(rand() % 1000 / 1000.0f,0,1,1)));



        // std::cout << transform << std::endl;
        // Group* group = new Group(transform);
        // group->add(new Sprite(0,0,6,3,vec4(1,1,1,1)));
        // group->add(new Sprite(0.5f,0.5f,5.0f,2.0f,vec4(1,0,1,1)));
        // layer.add(group);4x4

        // Fps timer
        myTimer t;

        float roatation_ammount = 0.0f;


        LOG_B("Entering while loop");
        /* Loop until the user closes the window */
        while (window.isOpen())
        {
                window.clear();

                if(roatation_ammount > 360.0f){
                  roatation_ammount = 0.0f;
                }

                roatation_ammount += 0.5;

                std::cout << "\r" << roatation_ammount << "                  "  << std::flush;


                vec2 mousePos = window.getMousePosGL();

                shader.enable();
                shader.setUniform2f("light_pos",mousePos);

                shader2.enable();
                shader2.setUniform2f("light_pos",mousePos);

                layer.m_Renderer->push(mat4::rotation(roatation_ammount,vec3(0,0,1)));
                layer.render();
                layer.m_Renderer->pop();

                // layer2.render();

                window.update();

                showFPS_GLFW(window,t.getFPS());

        }

        // Close the window
        window.closeWindow();
        std::cout <<"\n";


        return 0;
}
