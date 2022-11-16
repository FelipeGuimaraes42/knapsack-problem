#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class InputFile
{
private:
    string fileName;
    int numberOfItems;
    int maxWeight;
    vector<int> profits;
    vector<int> weights;

    void print();
    void printName();

public:
    InputFile(string fileName);
    ~InputFile();
    void readFile();

    vector<int> getProfits();
    vector<int> getWeights();
    int getNumberOfItems();
    int getMaxWeight();
};