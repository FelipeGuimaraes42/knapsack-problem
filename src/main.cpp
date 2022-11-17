#include <iostream>
#include <string>
#include <vector>
#include "include/combo.h"
#include "include/DynamicProgramming.hpp"
#include "include/InputFile.hpp"

using namespace std;

int main(int argc, char **argv)
{
    InputFile file(argv[1]);
    file.readFile();

    DynamicProgramming dp;
    int result = dp.calculate(file.getMaxWeight(), file.getNumberOfItems(),
                              file.getWeights(), file.getProfits());

    cout << "Number of Items: " << file.getNumberOfItems() << "\n"
         << "Knapsack Size: " << file.getMaxWeight() << "\n"
         << "Profit: " << result << endl;

    return 0;
}