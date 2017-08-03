
# DIRECTORY DEFINITIONS and large inlcudes
BUFFERS_DIR = Graphics/Buffers/
BUFFERS_INCLUDE = $(BUFFERS_DIR)buffer.hpp $(BUFFERS_DIR)indexBuffer.hpp $(BUFFERS_DIR)vertexArray.hpp
UTILS_DIR = myUtils/
LAYERS_DIR = Graphics/layers/
MATH_VEC_DIR = math/vector/
MATH_MAT_DIR = math/matrix/
MATH_INCLUDE = $(MATH_VEC_DIR)vec2.hpp $(MATH_VEC_DIR)vec3.hpp $(MATH_VEC_DIR)vec4.hpp $(MATH_MAT_DIR)mat4.hpp

# Set to -w as an initalizer
COMPILER_FLAGS = -w
ALL_OBJECT_NAMES = buffer.o indexBuffer.o vertexArray.o layer.o tileLayer.o batchRenderer2D.o shader.o simple2Drenderer.o sprite.o staticSprite.o window.o vec2.o vec3.o vec4.o mat4.o fileUtils.o

out: main.cpp $(ALL_OBJECT_NAMES)
	g++ -w $(COMPILER_FLAGS) main.cpp $(ALL_OBJECT_NAMES) -o out -lGL -lGLU -lGLEW -lglfw

clean:
	rm -rf *.o

cleanAll:
	rm -rf *.o

# Delete all of the precompiled Headers
	rm -rf Graphics/*.gch
	rm -rf $(BUFFERS_DIR)*.gch
	rm -rf $(LAYERS_DIR)*.gch
	rm -rf $(MATH_VEC_DIR)*.gch
	rm -rf $(MATH_MAT_DIR)*.gch
	rm -rf $(UTILS_DIR)*.gch

#---------------------------------------------
# -----BUFFERS @ Graphics/Buffers/------------
#---------------------------------------------
buffer.o: $(BUFFERS_DIR)buffer.cpp $(BUFFERS_DIR)buffer.hpp $(UTILS_DIR)glCheckError.hpp
	g++ -w $(COMPILER_FLAGS) -c $(BUFFERS_DIR)buffer.cpp $(BUFFERS_DIR)buffer.hpp $(UTILS_DIR)glCheckError.hpp

indexBuffer.o: $(BUFFERS_DIR)indexBuffer.cpp $(BUFFERS_DIR)indexBuffer.hpp $(UTILS_DIR)glCheckError.hpp
	g++ -w $(COMPILER_FLAGS) -c $(BUFFERS_DIR)indexBuffer.cpp $(BUFFERS_DIR)indexBuffer.hpp $(UTILS_DIR)glCheckError.hpp

vertexArray.o: $(BUFFERS_DIR)vertexArray.cpp $(BUFFERS_DIR)vertexArray.hpp $(BUFFERS_DIR)buffer.hpp
	g++ -w $(COMPILER_FLAGS) -c $(BUFFERS_DIR)vertexArray.cpp $(BUFFERS_DIR)vertexArray.hpp $(BUFFERS_DIR)buffer.hpp

#---------------------------------------------
# -----layers @ Graphics/layers/------------
#---------------------------------------------
layer.o: $(LAYERS_DIR)layer.cpp $(LAYERS_DIR)layer.hpp Graphics/renderable2D.hpp Graphics/batchRenderer2D.hpp
	g++ -w $(COMPILER_FLAGS) -c $(LAYERS_DIR)layer.cpp $(LAYERS_DIR)layer.hpp  Graphics/renderable2D.hpp Graphics/batchRenderer2D.hpp

tileLayer.o: $(LAYERS_DIR)tileLayer.cpp $(LAYERS_DIR)tileLayer.hpp $(LAYERS_DIR)layer.hpp
	g++ -w $(COMPILER_FLAGS) -c $(LAYERS_DIR)tileLayer.cpp $(LAYERS_DIR)tileLayer.hpp $(LAYERS_DIR)layer.hpp

#---------------------------------------------
# -----Graphics @ Graphics/-------------------
#---------------------------------------------
batchRenderer2D.o:  Graphics/batchRenderer2D.cpp Graphics/batchRenderer2D.hpp Graphics/renderer2D.hpp $(BUFFERS_DIR)vertexArray.hpp $(UTILS_DIR)glCheckError.hpp
	g++ -w $(COMPILER_FLAGS) -c Graphics/batchRenderer2D.cpp Graphics/batchRenderer2D.hpp Graphics/renderer2D.hpp $(BUFFERS_DIR)vertexArray.hpp $(UTILS_DIR)glCheckError.hpp

shader.o: Graphics/shader.cpp Graphics/shader.hpp $(UTILS_DIR)fileUtils.hpp $(MATH_INCLUDE)
	g++ -w $(COMPILER_FLAGS) -c Graphics/shader.cpp Graphics/shader.hpp $(UTILS_DIR)fileUtils.hpp $(MATH_INCLUDE)

simple2Drenderer.o: Graphics/simple2Drenderer.cpp Graphics/simple2Drenderer.hpp Graphics/renderable2D.hpp Graphics/renderer2D.hpp Graphics/staticSprite.hpp
	g++ -w $(COMPILER_FLAGS) -c Graphics/simple2Drenderer.cpp Graphics/simple2Drenderer.hpp Graphics/renderable2D.hpp Graphics/renderer2D.hpp Graphics/staticSprite.hpp

sprite.o: Graphics/sprite.cpp Graphics/sprite.hpp Graphics/renderable2D.hpp
	g++ -w $(COMPILER_FLAGS) -c Graphics/sprite.cpp Graphics/sprite.hpp Graphics/renderable2D.hpp

staticSprite.o: Graphics/staticSprite.cpp Graphics/staticSprite.hpp Graphics/renderable2D.hpp $(BUFFERS_INCLUDE)
	g++ -w $(COMPILER_FLAGS) -c Graphics/staticSprite.cpp Graphics/staticSprite.hpp Graphics/renderable2D.hpp $(BUFFERS_INCLUDE)

window.o: Graphics/window.cpp Graphics/window.hpp $(UTILS_DIR)fileUtils.hpp $(UTILS_DIR)glCheckError.hpp $(UTILS_DIR)log.hpp $(UTILS_DIR)myTimer.hpp $(UTILS_DIR)fpsCounter.hpp $(MATH_INCLUDE)
	g++ -w $(COMPILER_FLAGS) -c Graphics/window.cpp Graphics/window.hpp $(UTILS_DIR)fileUtils.hpp $(UTILS_DIR)glCheckError.hpp $(UTILS_DIR)log.hpp $(UTILS_DIR)myTimer.hpp $(UTILS_DIR)fpsCounter.hpp $(MATH_INCLUDE)


#---------------------------------------------
# -----MATH CLASSES @ MATH/-------------------
#---------------------------------------------

vec2.o:  $(MATH_VEC_DIR)vec2.cpp $(MATH_VEC_DIR)vec2.hpp
	g++ -w $(COMPILER_FLAGS) -c $(MATH_VEC_DIR)vec2.cpp $(MATH_VEC_DIR)vec2.hpp
vec3.o:  $(MATH_VEC_DIR)vec3.cpp $(MATH_VEC_DIR)vec3.hpp
	g++ -w $(COMPILER_FLAGS) -c $(MATH_VEC_DIR)vec3.cpp $(MATH_VEC_DIR)vec3.hpp
vec4.o:  $(MATH_VEC_DIR)vec4.cpp $(MATH_VEC_DIR)vec4.hpp
	g++ -w $(COMPILER_FLAGS) -c $(MATH_VEC_DIR)vec4.cpp $(MATH_VEC_DIR)vec4.hpp
mat4.o:  $(MATH_MAT_DIR)mat4.cpp $(MATH_INCLUDE)
	g++ -w $(COMPILER_FLAGS) -c $(MATH_MAT_DIR)mat4.cpp $(MATH_INCLUDE)

#---------------------------------------------
# -----Utils @ myUtils/-----------------------
#---------------------------------------------
fileUtils.o: $(UTILS_DIR)fileUtils.cpp $(UTILS_DIR)fileUtils.hpp
	g++ -w $(COMPILER_FLAGS) -c $(UTILS_DIR)fileUtils.cpp $(UTILS_DIR)fileUtils.hpp
