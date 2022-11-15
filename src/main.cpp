#include <iostream>
#include <string>
#include <vector>
#include "include/combo.h"
#include "include/InputFile.hpp"

using namespace std;

int main(int argc, char **argv)
{
    InputFile file(argv[1]);
    file.readFile();

    int numOfItems = file.getHeader().first;
    int maxWeight = file.getHeader().second;
    vector<pair<int, int>> items = file.getItems();

    return 0;
}