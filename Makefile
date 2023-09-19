all:
	g++ main.cpp src/*.cpp -std=c++17 -lsfml-graphics -lsfml-system -lsfml-window -o terminal