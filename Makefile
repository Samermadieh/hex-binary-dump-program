#Name: Samer Madieh
#File Name: Makefile
#Description: Makefile to compile the dump.cpp file into an exe with the name dump

dump: dump.cpp
	gcc -o dump dump.cpp -lstdc++ -std=c++11
