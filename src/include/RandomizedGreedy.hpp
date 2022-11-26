#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "KPSolution.hpp"

using namespace std;

class RandomizedGreedy
{
private:
    int n;
    int maxWeight;
    vector<int> profits;
    vector<int> weights;
    vector<pair<int, double>> sortedProfitsByWeight;
    void removeItem(int position);

public:
    RandomizedGreedy(int maxWeight, int n, vector<int> weights, vector<int> profits);
    ~RandomizedGreedy();

    KPSolution calculate();
    vector<pair<int, double>> getSortedProfitsByWeight();
};