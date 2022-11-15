#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class InputFile
{
private:
    string fileName;
    vector<pair<int, int>> items;
    pair<int, int> header;
    void print();
    void printName();

public:
    InputFile(string fileName);
    ~InputFile();
    void readFile();

    vector<pair<int, int>> getItems();
    pair<int, int> getHeader();
};