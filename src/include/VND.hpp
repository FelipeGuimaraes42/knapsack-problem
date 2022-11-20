#include <algorithm>
#include <cmath>
#include <string>
#include <time.h>
#include <vector>
#include "KPSolution.hpp"

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

    KPSolution getConstructiveSolution();
    KPSolution getTwoOptSolution(KPSolution previousSolution);
    KPSolution getThreeOptSolution(KPSolution previousSolution);
    KPSolution getFourOptSolution(KPSolution previousSolution);

public:
    VND(vector<pair<int, int>> points, string weightType);
    ~VND();
    double tsp();
};
