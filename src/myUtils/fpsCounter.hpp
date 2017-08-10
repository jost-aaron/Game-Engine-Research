#ifndef FPS_COUTER_INCLUDED
#define FPS_COUTER_INCLUDED

#include "../Graphics/window.hpp"
#include "myTimer.hpp"
#include <sstream>

static double lastTime = 0;
static int numberFrames = 0;



// Show the fps in the title bar of the window
void showFPS_GLFW(Graphics::Window& windowIn,double fps)
{
        // Settings for formating the’ was not declared in this scope
        #define NUM_SPACES_1 2
        #define NUM_SPACES_2 90

        std::stringstream ss;

        ss << windowIn.name;

        // Add in the spaces for part 1
        for (int i=0; i<NUM_SPACES_1; i++) {
                ss << " ";
        }

        ss << " " << " (" << windowIn.width <<  "x" << windowIn.height << ")";

        // Add in the spaces for part 2
        for (int i=0; i<NUM_SPACES_2; i++) {
                ss << " ";
        }
        ss << " [" << (int)fps << " fps]";

        glfwSetWindowTitle(windowIn.window_obj, ss.str().c_str());

}

#endif
