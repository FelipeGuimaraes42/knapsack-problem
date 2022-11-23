#include <algorithm>
#include <cmath>
#include <string>
#include <time.h>
#include <vector>
#include "KPSolution.hpp"

#define INF 0x3f3f3f3f
#define MAX_TENTATIVES 2

using namespace std;

class VND
{
private:
    int n;
    int maxWeight;
    vector<int> profits;
    vector<int> weights;

    KPSolution getInitialSolution();
    KPSolution getRandomSolution();
    int getKnapsackSize(vector<bool>);
    KPSolution getAddOneDropOne(KPSolution previousSolution);
    KPSolution getAddTwoDropOne(KPSolution previousSolution);

public:
    VND(int maxWeight, int n, vector<int> weights, vector<int> profits);
    ~VND();
    int calculate();
};
