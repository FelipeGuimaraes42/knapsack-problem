# Knapsack Problem
### Test instances from http://artemisa.unicauca.edu.co/~johnyortega/instances_01_KP/
### Banner from https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Knapsack%20Problem

## About
In this project, we solve the NP-Complete Knapsack Problem using the metaheuristic Variable Neighborhood Descent (VND).
As the control heuristic, we are using Randomized Greedy.

## How to run
To run this project, you need to do three things:
- Compile;
- Choose a test file, inside src/test-cases directory;
- Run the executable.

To make this process simpler, we created a **Makefile**. In this Makefile, he already have some ready bash commands:
- make compile: compile all cpp files in an executable named **main**
- make run: execute the main file with a chosen test case, this command were created to be a easy way to test different scenarios
- make runLow: execute the compiled project with a lower sized knapsack
- make runLarge: execute the compiled project with a larger sized knapsack
- make all: make compile + make run
- make allLow: make compile + make runLow
- make allLarge: make compile + make runLarge

## Output
After running the project, it will print the results in the console.

It will first three things:
- Knapsack details;
- Randomized Greedy solution, profit and weight;
- VND solution, profit and weight.