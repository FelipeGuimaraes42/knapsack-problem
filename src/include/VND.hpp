#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <time.h>
#include <vector>
#include "KPSolution.hpp"

#define INF 0x3f3f3f3f
#define MAX_ATTEMPTS 2
#define MAX_ITERATIONS 10000

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
    pair<int, int> getKnapsackDetails(vector<bool>);
    KPSolution getAddOneDropOne(KPSolution previousSolution);
    KPSolution getAddTwoDropOne(KPSolution previousSolution);

public:
    VND(int maxWeight, int n, vector<int> weights, vector<int> profits);
    ~VND();
    int calculate();
};
