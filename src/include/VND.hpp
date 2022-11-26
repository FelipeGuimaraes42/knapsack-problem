#include <iostream>
#include <set>
#include <string>
#include <time.h>
#include <vector>
#include "KPSolution.hpp"

#define INF 0x3f3f3f3f
#define MAX_ATTEMPTS 8
#define MAX_ITERATIONS 100

using namespace std;

class VND
{
private:
    int n;
    int maxWeight;
    vector<int> profits;
    vector<int> weights;
    vector<double> profitsPerWeight;
    
    pair<int, int> getKnapsackDetails(vector<bool>);

    KPSolution getEmptyKnapsack();
    KPSolution getRandomSolution();
    
    KPSolution getAddOneDropNone(KPSolution previousSolution);
    KPSolution getAddOneDropOne(KPSolution previousSolution);
    KPSolution getAddTwoDropOne(KPSolution previousSolution);
    KPSolution getDropTwoAddOne(KPSolution previousSolution);

public:
    VND(int maxWeight, int n, vector<int> weights, vector<int> profits);
    ~VND();
    int calculate();
};
