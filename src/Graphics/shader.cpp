#include "shader.hpp"

namespace Graphics {

Shader::Shader(const char* vertPath, const char* fragPath){

        m_vertPath = vertPath;
        m_fragPath = fragPath;
        m_program = load();
}

Shader::~Shader(){
        glDeleteProgram(m_program);
}

// Error checking helper method
static void checkForShaderError(GLuint shader,GLuint flag,bool isProgram,std::string errorMessage){

        GLint result;
        if (isProgram) {
                glGetProgramiv(shader,flag,&result);
        } else {
                glGetShaderiv(shader,flag,&result);
        }

        // If the compilation failed
        if(result == GL_FALSE) {
                GLint length;
                if (isProgram) {
                        glGetProgramiv(shader,GL_INFO_LOG_LENGTH,&length);
                        std::vector<char> error(length);
                        glGetProgramInfoLog(shader,length,&length,&error[0]);

                        std::cout << "Program failed to compile:\n" <<  &error[0] << "\n";
                        //glDeleteShader(shader);
                } else {
                        glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&length);
                        std::vector<char> error(length);
                        glGetShaderInfoLog(shader,length,&length,&error[0]);

                        std::cout << errorMessage <<  &error[0] << "\n";
                        glDeleteShader(shader);
                }
                exit(1);
        }
}

GLuint Shader::load(){

        GLuint program = glCreateProgram();
        GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

        std::string vert_src = read_file(m_vertPath);
        std::string frag_src = read_file(m_fragPath);

        const char* v = vert_src.c_str();
        const char* f = frag_src.c_str();

        // Compile vertex shader
        glShaderSource(vertex,1,&v,NULL);
        glCompileShader(vertex);
        GLint result;

        checkForShaderError(vertex,GL_COMPILE_STATUS,false,"Error: Vertex shader failed to compile!\n");

        // Compile fragment shader
        glShaderSource(fragment,1,&f,NULL);
        glCompileShader(fragment);

        checkForShaderError(fragment,GL_COMPILE_STATUS,false,"Fragment shader failed to compile:\n");

        glBindAttribLocation(program,0,"position");
        glBindAttribLocation(program,1,"color");

        glAttachShader(program,vertex);
        glAttachShader(program,fragment);

        glLinkProgram(program);
        checkForShaderError(program,GL_LINK_STATUS,true,"Error: Program failed to link");

        glValidateProgram(program);
        checkForShaderError(program,GL_VALIDATE_STATUS,true,"Error: Program failed to validate");

        glDeleteShader(vertex);
        glDeleteShader(fragment);

        return program;
}

// Enable the shader
void Shader::enable() const {
        // glCheckError();
        glUseProgram(m_program);
        // glCheckError();
}

// Disable the shader
void Shader::disable() const {
        // glCheckError();
        glUseProgram(0);
        // glCheckError();
}

// ---------------For Loading data into a shader program --------------//

// Get the loaction of the thing we want to load the data into
// TODO: Casch the locations of all the peramiters of the shaders
GLuint Shader::getUniformLocation(const GLchar* name){
        // glCheckError();
        return glGetUniformLocation(m_program,name);
        // glCheckError();
}

// Load a single float
void Shader::setUniform1f(const GLchar* name, const float value){
        // glCheckError();
        glUniform1f(getUniformLocation(name),value);
        // glCheckError();
}
// Load a single integer
void Shader::setUniform1i(const GLchar* name, const int value){
        // glCheckError();
        glUniform1i(getUniformLocation(name),value);
        // glCheckError();
}
// Load a vec2
void Shader::setUniform2f(const GLchar* name, const myMath::vec2& value){
        // glCheckError();
        glUniform2f(getUniformLocation(name),value.x,value.y);
        // glCheckError();
}
// Load a vec3
void Shader::setUniform3f(const GLchar* name, const myMath::vec3& value){
        // glCheckError();
        glUniform3f(getUniformLocation(name),value.x,value.y,value.z);
        // glCheckError();
}
// Load a vec4
void Shader::setUniform4f(const GLchar* name, const myMath::vec4& value){
        // glCheckError();
        glUniform4f(getUniformLocation(name),value.x,value.y,value.z,value.w);
        // glCheckError();
}
// Load a mat4
void Shader::setUniformMat4(const GLchar* name, const myMath::mat4& value){
        // glCheckError();
        glUniformMatrix4fv(getUniformLocation(name),1,GL_FALSE,value.elements);
        // glCheckError();
}



}
