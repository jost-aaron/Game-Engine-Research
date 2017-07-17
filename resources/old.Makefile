build: main.cpp window.o
	g++ main.cpp window.o -I ./myUtils/ -I ./Graphics/ -lglfw -lGL -o out.exe

window.o: ./Graphics/window.cpp
	g++ -c ./Graphics/window.cpp -I ./myUtils/ -o window.o

clean:
	rm -rf *.o
