
#include "gameVars.h"
#include <iostream>
#include "myUtils/log.h"
#include "math/myMath.h"
#include "myUtils/fileUtils.h"

// Graphics includes
#include "Graphics/window.cpp"
#include "Graphics/shader.cpp"
#include "Graphics/Buffers/buffer.cpp"
#include "Graphics/Buffers/indexBuffer.cpp"
#include "Graphics/Buffers/vertexArray.cpp"


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

        // glClearColor(0.0f,0.0f,0.0f,0.0f);

        // GLfloat verts[] = {
        //   0,0,0,
        //   16,0,0,
        //   0,9,0,
        //   0,9,0,
        //   16,9,0,
        //   16,0,0
        // };
        //
        // GLuint vbo;
        //
        // glGenBuffers(1,&vbo);
        // glBindBuffer(GL_ARRAY_BUFFER,vbo);
        // glBufferData(GL_ARRAY_BUFFER,sizeof(verts),verts,GL_STATIC_DRAW);
        // glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
        // glEnableVertexAttribArray(0);

        GLfloat verts[] = {
                0,0,0,
                0,3,0,
                8,3,0,
                8,0,0
        };

        GLushort indicies[] = {
                0,1,2,
                2,3,0
        };

        GLfloat colorsA[] = {
                1,0,1,1,
                1,0,1,1,
                1,0,1,1,
                1,0,1,1
        };

        GLfloat colorsB[] = {
                0.2f,0.3f,0.8f,1,
                0.2f,0.3f,0.8f,1,
                0.2f,0.3f,0.8f,1,
                0.2f,0.3f,0.8f,1
        };

        vertexArray sprite1,sprite2;

        indexBuffer ibo(indicies,6);

        sprite1.addBuffer(new Buffer(verts,4*3,3),0);
        sprite1.addBuffer(new Buffer(colorsA,4*4,4),1);
        sprite2.addBuffer(new Buffer(verts,4*3,3),0);
        sprite2.addBuffer(new Buffer(colorsB,4*4,4),1);



        Shader shader("shaders/basic.vert","shaders/basic.frag");
        shader.enable();

        mat4 ortho = mat4::orthographic(0.0f,16.0f,0.0f,9.0f,-1.0f,1.0f);
        // mat4 ortho = mat4::identity();

        shader.setUniformMat4("pr_matrix",ortho);
        shader.setUniformMat4("ml_matrix",mat4::translation(vec3(4,3,0)));
        shader.setUniform2f("light_pos",vec2(0.0f,0.0f));
        // Starting color
        shader.setUniform4f("color",vec4(2.0,2.0,2.0,1.0));


        LOG_B("Entering while loop");
        /* Loop until the user closes the window */
        while (window.isOpen())
        {

                window.clear();
                vec2 mousePos = window.getMousePosGL();

                shader.setUniform2f("light_pos",mousePos);
                std::cout << "\rWindow: (" << window.getMousePosWindow().x << "," << window.getMousePosWindow().y <<
                        ") TransForm:(" << mousePos.x << "," << mousePos.y << ")          "<< std::flush;

                sprite1.bind();
                ibo.bind();

                shader.setUniformMat4("ml_matrix",mat4::translation(vec3(4,3,0)));
                glDrawElements(GL_TRIANGLES,ibo.getCount(),GL_UNSIGNED_SHORT,0);
                ibo.bind();
                sprite1.unbind();

                sprite2.bind();
                ibo.bind();

                shader.setUniformMat4("ml_matrix",mat4::translation(vec3(0,0,0)));
                glDrawElements(GL_TRIANGLES,ibo.getCount(),GL_UNSIGNED_SHORT,0);

                ibo.bind();
                sprite2.unbind();



                window.update();

        }

        // Close the window
        window.closeWindow();
        std::cout <<"\n";


        return 0;
}
