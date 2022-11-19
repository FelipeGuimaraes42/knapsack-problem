#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class RandomizedGreedy
{
private:
    vector<pair<int, double>> sortedProfitsByWeight;

public:
    RandomizedGreedy(int maxWeight, int n, vector<int> weights, vector<int> profits);
    ~RandomizedGreedy();

    int calculate();
    vector<pair<int, double>> getSortedProfitsByWeight();
};