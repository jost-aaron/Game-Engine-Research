clear

#Debug includes symbols for gdb debugging
g++ main.cpp -g -lGL -lGLU -lGLEW -lglfw -o out

# Relese Full optimization
# g++ main.cpp -O3 -lGL -lGLU -lGLEW -lglfw -o out

if [ $? -eq 0 ]; then
  # Run the executable
  ./out
fi
