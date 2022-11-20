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

    // double getEuclideanDistance(const pair<int, int> xiYi, const pair<int, int> xjYj);
    // double getPseudoEuclideanDistance(const pair<int, int> xiYi, const pair<int, int> xjYj);
    // double getCycleSize(vector<pair<int, int>> points);
    // KPSolution getConstructiveSolution();
    
    KPSolution getValue(vector<bool>);

    KPSolution getInitialSolution();
    KPSolution getRandomSolution();
    KPSolution getTwoOptSolution(KPSolution previousSolution);
    KPSolution getThreeOptSolution(KPSolution previousSolution);
    KPSolution getFourOptSolution(KPSolution previousSolution);

public:
    VND(int maxWeight, int n, vector<int> weights, vector<int> profits);
    ~VND();
    int calculate();
};
