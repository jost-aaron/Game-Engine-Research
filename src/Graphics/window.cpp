#include "window.hpp"

namespace Graphics {

// Window class
Window::Window(std::string windowName,int windowHeight,int windowWidth) {

        height = windowHeight;
        width = windowWidth;
        name = windowName;
        isClosed = false;

        //Initialize glfw
        if (!glfwInit()) {
                LOG_B("glfwInti() Failed");
                exit(1);
        }

        // Initalize all of the keyboard key states to false
        for (int i=0; i < MAX_KEYBOARD_KEYS; i++) {
                keyboardKeys[i] = false;
        }

        // Initalize all of the mouse button states to false
        for (int i=0; i < MAX_MOUSE_BUTTONS; i++) {
                mouseButtons[i] = false;
        }


}

// Window destructor. Calls glfwTerminate() to close glfw
Window::~Window(){

        glfwTerminate();
}

// Intialize the window
void Window::init(){
        // Add some other information on the window title
        std::string nameFix_1 = name + " (" + std::to_string(width) + "x" + std::to_string(height) + ")";

        // Hack to get the name string to convert to char* array
        const char * nameFix = nameFix_1.c_str();

        // Manually set the GLSL version to 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLSL_VERSION_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLSL_VERSION_MINOR);
        //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwSwapInterval(VSYNC);

        // Make the window non resisable
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        window_obj = glfwCreateWindow( height,width, nameFix, NULL, NULL);

        // Check to see if the window was made
        if (!window_obj)
        {
                LOG_B("Error: the window failed to be made!");

                glfwTerminate();
                exit(1);
        }

        // Generate a context to the window
        glfwMakeContextCurrent(window_obj);

        // Set the callback functions
        glfwSetWindowUserPointer(window_obj,this);
        glfwSetWindowSizeCallback(window_obj,windowResize);
        glfwSetKeyCallback(window_obj, key_callback);
        glfwSetMouseButtonCallback(window_obj,mouse_button_callback);
        glfwSetCursorPosCallback(window_obj,mouse_position_callback);

        // Set the default backgound color of the window
        glClearColor(0.0f,0.0f,0.0f,0.0f);

        // Intialize GLEW and stuff
        if(glewInit() != GLEW_OK) {
                LOG_B("Error: GLEW did not initalize correctly!");
        }
}


// This function checks if the window is closed and returns it to whoever
bool Window::isOpen(){
        return !glfwWindowShouldClose(window_obj);
}

// Function to close the window
void Window::closeWindow(){
        isClosed = true;
}

// Update the window
void Window::update(){

        /* Render here */

        glCheckError();


        /* Poll for and process events */
        glfwPollEvents();

        // Get the size of the window and update the class dimensions
        glfwGetFramebufferSize(window_obj,&width,&height);

        /* Swap front and back buffers */
        glfwSwapBuffers(window_obj);

}

// Clear the window
void Window::clear(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

// This is the function we set to run when the window is resized
void windowResize(GLFWwindow * window_obj,int width, int height) {
        glViewport(0,0,width,height);
}

// -------------------------------------------------------------------------- //
//-----------------------KEYBOAD KEY DETECTION--------------------------------//
// -------------------------------------------------------------------------- //

// Check if a Keyboard key has been pressed
bool Window::isKeyPressed(unsigned int keycode){
        // make sure the keycode is not out of range
        if (keycode > MAX_KEYBOARD_KEYS) {
                LOG_B("ERROR: keycode out of range. Keyboard keycode: " + std::to_string(keycode));
                return false;
        }
        return keyboardKeys[keycode];
}
// Return the current state of a mouse button
bool Window::isMouseButtonPressed(unsigned int button){
        // make sure the button is not out of range
        if (button > MAX_MOUSE_BUTTONS) {
                LOG_B("ERROR: button out of range. Mouse Button: " + std::to_string(button));
                return false;
        }
        return mouseButtons[button];
}
// Return the position of the mouse as a array of 2 doubles
myMath::vec2 Window::getMousePosWindow(){
  //double out[2]{mouseX,mouseY};

  return myMath::vec2((float)mouseX,(float)mouseY);
}

// Return the position of the mouse as a array of 2 doubles
myMath::vec2 Window::getMousePosGL(){


  return myMath::vec2((float)(mouseX*32.0f/width - 16.0f),(float)(9.0f - mouseY*18.0f/height));
}

// -------------------------------- Callback Functions -------------------------------- //
// Callback function for when a keyboard key is pressed. Updates window class instance
void key_callback(GLFWwindow* window_obj, int key, int scancode, int action, int mods) {
        // Get a pointer to the current window
        Window* win  = (Window*)glfwGetWindowUserPointer(window_obj);
        // Access the key states array and if it is not GLFW_RELEASE set the state to true
        win->keyboardKeys[key] = action != GLFW_RELEASE;
}
// Callback function for when a mouse button is pressed. Updates window class instance
void mouse_button_callback(GLFWwindow* window_obj, int button, int action, int mods){
        // Get a pointer to the current window
        Window* win  = (Window*)glfwGetWindowUserPointer(window_obj);
        // Access the key states array and if it is not GLFW_RELEASE set the state to true
        win->mouseButtons[button] = action != GLFW_RELEASE;
}
// Callback function for when the poistion of the mouse changes. Updates window class instance
void mouse_position_callback(GLFWwindow* window_obj,double xpos,double ypos){
        Window* win  = (Window*)glfwGetWindowUserPointer(window_obj);
        win->mouseX = xpos;
        win->mouseY = ypos;
}



}
