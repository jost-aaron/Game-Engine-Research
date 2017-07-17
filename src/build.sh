clear

# Compile all the executable
g++ main.cpp -lGL -lGLU -lGLEW -lglfw -o out


if [ $? -eq 0 ]; then
  # Run the executable
  ./out
fi
