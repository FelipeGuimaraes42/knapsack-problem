compile:
	cd src && g++ -std=c++17 -o main main.cpp InputFile.cpp DynamicProgramming.cpp RandomizedGreedy.cpp VND.cpp KPSolution.cpp

run:
	cd src && ./main test-cases/low-dimensional/f1_l-d_kp_10_269

all:
	cd src && g++ -std=c++17 -o main main.cpp InputFile.cpp DynamicProgramming.cpp RandomizedGreedy.cpp VND.cpp KPSolution.cpp && ./main test-cases/low-dimensional/f1_l-d_kp_10_269

allLow:
	cd src && g++ -std=c++17 -o main main.cpp InputFile.cpp DynamicProgramming.cpp RandomizedGreedy.cpp VND.cpp KPSolution.cpp && ./main test-cases/low-dimensional/f1_l-d_kp_10_269

allLarge:
	cd src && g++ -std=c++17 -o main main.cpp InputFile.cpp DynamicProgramming.cpp RandomizedGreedy.cpp VND.cpp KPSolution.cpp && ./main test-cases/large_scale/knapPI_1_10000_1000_1
