compile:
	cd src && g++ -o main main.cpp InputFile.cpp DynamicProgramming.cpp

run:
	cd src && ./main test-cases/low-dimensional/f1_l-d_kp_10_269

all:
	cd src && g++ -o main main.cpp InputFile.cpp DynamicProgramming.cpp && ./main test-cases/low-dimensional/f1_l-d_kp_10_269

allLow:
	cd src && g++ -o main main.cpp InputFile.cpp DynamicProgramming.cpp && ./main test-cases/low-dimensional/f1_l-d_kp_10_269

allLarge:
	cd src && g++ -o main main.cpp InputFile.cpp DynamicProgramming.cpp && ./main test-cases/large_scale/knapPI_1_100_1000_1
