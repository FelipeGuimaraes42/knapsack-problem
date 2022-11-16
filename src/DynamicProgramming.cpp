#include "include/DynamicProgramming.hpp"

DynamicProgramming::DynamicProgramming(/* args */) {}

DynamicProgramming::~DynamicProgramming() {}

int DynamicProgramming::calculate(int maxWeight, int n, vector<int> weights, vector<int> profits)
{
    int wt;
    int K[n + 1][maxWeight + 1];
    for (int i = 0; i <= n; i++)
    {
        for (wt = 0; wt <= maxWeight; wt++)
        {
            if (i == 0 || wt == 0)
                K[i][wt] = 0;
            else if (weights[i - 1] <= wt)
                K[i][wt] = max(profits[i - 1] + K[i - 1][wt - weights[i - 1]], K[i - 1][wt]);
            else
                K[i][wt] = K[i - 1][wt];
        }
    }
    return K[n][maxWeight];
}