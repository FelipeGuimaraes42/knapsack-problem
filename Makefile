compile:
	cd src && g++ -o main main.cpp combo.cpp

run:
	cd src && ./main

all:
	cd src && g++ -o main main.cpp && ./main