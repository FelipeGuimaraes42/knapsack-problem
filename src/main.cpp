#include <iostream>
#include <string>
#include <vector>
#include "include/combo.h"
#include "include/DynamicProgramming.hpp"
#include "include/InputFile.hpp"
#include "include/RandomizedGreedy.hpp"
#include "include/VND.hpp"

using namespace std;

int main(int argc, char **argv)
{
     srand(time(NULL));

     InputFile file(argv[1]);
     file.readFile();

     cout << "Knapasack Details\n"
          << " - Number Of Items: " << file.getNumberOfItems() << "\n"
          << " - Max Weight: " << file.getMaxWeight() << "\n"
          << endl;

     RandomizedGreedy rg(file.getMaxWeight(), file.getNumberOfItems(),
                         file.getWeights(), file.getProfits());

     int result = rg.calculate();

     cout << "Randomized Greedy\n - Profit: " << result << "\n "
          << endl;

     VND vnd(file.getMaxWeight(), file.getNumberOfItems(), file.getWeights(), file.getProfits());
     result = vnd.calculate();

     cout << "VND\n - Profit: " << result << endl;

     return 0;
}

// DynamicProgramming dp;
// int result = dp.calculate(file.getMaxWeight(), file.getNumberOfItems(),
//                           file.getWeights(), file.getProfits());

// cout << "Dynamic Programming\n"
//      << "Number of Items: " << file.getNumberOfItems() << "\n"
//      << "Knapsack Size: " << file.getMaxWeight() << "\n"
//      << "Profit: " << result << "\n"
//      << endl;