#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "../myUtils/log.hpp"
#include "../math/myMath.hpp"


// Max sizes for keyboard input states and mouse button states
#define MAX_KEYBOARD_KEYS 1024
#define MAX_MOUSE_BUTTONS 32

// Set the version of glsl we want to use
#define GLSL_VERSION_MAJOR 1
#define GLSL_VERSION_MINOR 3


namespace Graphics {

// Window resize function prototype
void windowResize(GLFWwindow *,int, int);

// Input callback function prototypes
void key_callback(GLFWwindow*, int, int, int, int);
void mouse_button_callback(GLFWwindow*, int, int, int);
void mouse_position_callback(GLFWwindow*,double,double);

// Main window class
class Window {

public:

// Stuff for handeling input for the window
bool keyboardKeys[MAX_KEYBOARD_KEYS];
bool mouseButtons[MAX_MOUSE_BUTTONS];
double mouseX,mouseY;

// Variable for the window
GLFWwindow* window_obj;
// name of the window
std::string name;
bool isClosed;

// Window height information
int height;
int width;

// Class constructor and destructor
Window (std::string,int,int);
~Window ();

// Class member functions general
void init();
void closeWindow();
void update();
bool isOpen();
void clear();

// Get input states from class
bool isKeyPressed(unsigned int);
bool isMouseButtonPressed(unsigned int);
myMath::vec2 getMousePosWindow();
myMath::vec2 getMousePosGL();

};

}
