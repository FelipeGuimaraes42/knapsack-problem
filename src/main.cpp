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

    return 0;
}