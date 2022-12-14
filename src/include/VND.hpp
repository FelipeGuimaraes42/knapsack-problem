#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "KPSolution.hpp"

#define INF 0x3f3f3f3f
#define MAX_ATTEMPTS 6

using namespace std;

class VND
{
private:
    int n;
    int maxWeight;
    vector<int> profits;
    vector<int> weights;
    vector<pair<int, double>> profitsPerWeight;

    pair<int, int> getKnapsackDetails(vector<bool>);

    KPSolution getEmptyKnapsack();
    KPSolution getRandomSolution();

    KPSolution getAddOneDropNone(KPSolution previousSolution);
    KPSolution getAddOneDropOne(KPSolution previousSolution);
    KPSolution getAddTwoDropOne(KPSolution previousSolution);
    KPSolution getAddOneDropTwo(KPSolution previousSolution);
    KPSolution getAddOneDropOneByProfit(KPSolution previousSolution);
    KPSolution getAddOneDropTwoByProfit(KPSolution bestSolution);

public:
    VND(int maxWeight, int n, vector<int> weights, vector<int> profits);
    ~VND();
    KPSolution calculate();
};
