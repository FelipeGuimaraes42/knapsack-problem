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
    cout << this->header.first << " " << this->header.second << endl;

    for (int i = 0; i < this->items.size(); i++)
    {
        cout << this->items.at(i).first << " " << this->items.at(i).second << endl;
    }
}

void InputFile::readFile()
{
    printName();
    this->items.clear();

    ifstream file;
    file.open(this->fileName);
    string word;
    int profit, weight;

    file >> word;
    int numberOfItems = stoi(word);

    file >> word;
    int maxWeight = stoi(word);

    this->header = {numberOfItems, maxWeight};

    while (file >> word && word != "EOF")
    {
        profit = stoi(word);
        file >> word;
        weight = stoi(word);
        if (profit > 0 && weight > 0)
        {
            this->items.push_back({profit, weight});
        }
    }
    // print();
}

vector<pair<int, int>> InputFile::getItems()
{
    return this->items;
}
pair<int, int> InputFile::getHeader()
{
    return this->header;
}