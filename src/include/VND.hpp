#include <algorithm>
#include <cmath>
#include <string>
#include <time.h>
#include <vector>

#include "TSPSolution.hpp"

#define INF 0x3f3f3f3f
#define MAX_TENTATIVES 3

using namespace std;

class VND
{
private:
    vector<pair<int, int>> points;
    string weightType;

    double getEuclideanDistance(const pair<int, int> xiYi, const pair<int, int> xjYj);
    double getPseudoEuclideanDistance(const pair<int, int> xiYi, const pair<int, int> xjYj);
    double getCycleSize(vector<pair<int, int>> points);

    TSPSolution getConstructiveSolution();
    TSPSolution getTwoOptSolution(TSPSolution previousSolution);
    TSPSolution getThreeOptSolution(TSPSolution previousSolution);
    TSPSolution getFourOptSolution(TSPSolution previousSolution);

public:
    VND(vector<pair<int, int>> points, string weightType);
    ~VND();
    double tsp();
};
