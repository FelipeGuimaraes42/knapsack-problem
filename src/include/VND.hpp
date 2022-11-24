#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <time.h>
#include <vector>
#include "KPSolution.hpp"

#define INF 0x3f3f3f3f
#define MAX_ATTEMPTS 3
#define MAX_ITERATIONS 1000

using namespace std;

class VND
{
private:
    int n;
    int maxWeight;
    vector<int> profits;
    vector<int> weights;

    KPSolution getEmptyKnapsack();
    KPSolution getRandomSolution();
    pair<int, int> getKnapsackDetails(vector<bool>);
    KPSolution getAddOneDropOne(KPSolution previousSolution);
    KPSolution getAddTwoDropOne(KPSolution previousSolution);
    KPSolution getDropTwoAddOne(KPSolution previousSolution);

public:
    VND(int maxWeight, int n, vector<int> weights, vector<int> profits);
    ~VND();
    int calculate();
};
