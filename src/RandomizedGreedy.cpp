#include "include/RandomizedGreedy.hpp"

RandomizedGreedy::RandomizedGreedy(int maxWeight, int n, vector<int> weights, vector<int> profits)
{
    this->sortedProfitsByWeight.clear();
    for (int i = 0; i < weights.size(); i++)
    {
        double profitByWeight = (double)profits.at(i) / weights.at(i);
        this->sortedProfitsByWeight.push_back({i, profitByWeight});
        // cout << profitByWeight << "   ";
    }
    // cout << endl;

    sort(this->sortedProfitsByWeight.begin(), this->sortedProfitsByWeight.end(),
         [](auto &left, auto &right)
         { return left.second < right.second; });
}

RandomizedGreedy::~RandomizedGreedy() {}

vector<pair<int, double>> RandomizedGreedy::getSortedProfitsByWeight()
{
    return this->sortedProfitsByWeight;
}

int RandomizedGreedy::calculate()
{
    srand(time(NULL));
    return rand() % 2;
}