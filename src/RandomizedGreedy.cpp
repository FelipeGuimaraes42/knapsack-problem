#include "include/RandomizedGreedy.hpp"

RandomizedGreedy::RandomizedGreedy(int maxWeight, int n, vector<int> weights, vector<int> profits)
{
    this->n = n;
    this->maxWeight = maxWeight;
    this->profits = profits;
    this->weights = weights;

    this->sortedProfitsByWeight.clear();
    for (int i = 0; i < weights.size(); i++)
    {
        double profitByWeight = (double)profits.at(i) / weights.at(i);
        this->sortedProfitsByWeight.push_back({i, profitByWeight});
    }

    sort(this->sortedProfitsByWeight.begin(), this->sortedProfitsByWeight.end(),
         [](auto &left, auto &right)
         { return left.second < right.second; });
}

RandomizedGreedy::~RandomizedGreedy() {}

vector<pair<int, double>> RandomizedGreedy::getSortedProfitsByWeight()
{
    return this->sortedProfitsByWeight;
}

void RandomizedGreedy::removeItem(int position)
{
    vector<pair<int, double>>::iterator it = this->sortedProfitsByWeight.begin();
    advance(it, position);
    this->sortedProfitsByWeight.erase(it);
}

KPSolution RandomizedGreedy::calculate()
{
    int result = 0;
    int weight = 0;
    int n = this->n - 1;

    while (n > 0)
    {
        int index = n - rand() % 2;
        int sourceIndex = this->sortedProfitsByWeight.at(index).first;
        int aux = weight + this->weights.at(sourceIndex);

        if (aux <= this->maxWeight)
        {
            result += this->profits.at(sourceIndex);
            weight = aux;
        }

        removeItem(index);
        n--;
    }

    int aux = weight + this->weights.at(this->sortedProfitsByWeight.at(0).first);

    if (aux <= this->maxWeight)
    {
        weight = aux;
        result += this->profits.at(this->sortedProfitsByWeight.at(0).first);
    }

    KPSolution solution;
    solution.setValue(result);
    solution.setWeight(weight);

    return solution;
}