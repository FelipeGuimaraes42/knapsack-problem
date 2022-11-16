#include "include/InputFile.hpp"

InputFile::InputFile(string fileName)
{
    this->fileName = fileName;
}

InputFile::~InputFile() {}

void InputFile::printName()
{
    cout << " ____  __.                                          __     __________              ___.   .__                  \n"
         << "|    |/ _| ____ _____  ______  ___________    ____ |  | __ \\______   \\_______  ____\\_ |__ |  |   ____   _____  \n"
         << "|      <  /    \\\\__  \\ \\____ \\/  ___/\\__  \\ _/ ___\\|  |/ /  |     ___/\\_  __ \\/  _ \\| __ \\|  | _/ __ \\ /     \\ \n"
         << "|    |  \\|   |  \\/ __ \\|  |_> >___ \\  / __ \\\\  \\___|    <   |    |     |  | \\(  <_> ) \\_\\ \\  |_\\  ___/|  Y Y  \\\n"
         << "|____|__ \\___|  (____  /   __/____  >(____  /\\___  >__|_ \\  |____|     |__|   \\____/|___  /____/\\___  >__|_|  /\n"
         << "        \\/    \\/     \\/|__|       \\/      \\/     \\/     \\/                              \\/          \\/      \\/\n"
         << endl;
}

void InputFile::print()
{
    cout << this->numberOfItems << " " << this->maxWeight << endl;

    for (int i = 0; i < this->numberOfItems; i++)
    {
        cout << this->profits.at(i) << " " << this->weights.at(i) << endl;
    }
}

void InputFile::readFile()
{
    printName();
    this->profits.clear();
    this->weights.clear();

    ifstream file;
    file.open(this->fileName);
    string word;
    int profit, weight;

    file >> word;
    this->numberOfItems = stoi(word);

    file >> word;
    this->maxWeight = stoi(word);

    for (int i = 0; i < this->numberOfItems; i++)
    {
        file >> word;
        profit = stoi(word);
        file >> word;
        weight = stoi(word);

        this->profits.push_back(profit);
        this->weights.push_back(weight);
    }
    // print();
}

vector<int> InputFile::getProfits()
{
    return this->profits;
}

vector<int> InputFile::getWeights()
{
    return this->weights;
}

int InputFile::getNumberOfItems()
{
    return this->numberOfItems;
}

int InputFile::getMaxWeight()
{
    return this->maxWeight;
}