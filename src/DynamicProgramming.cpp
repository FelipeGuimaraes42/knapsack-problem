#include "include/DynamicProgramming.hpp"

DynamicProgramming::DynamicProgramming(/* args */) {}

DynamicProgramming::~DynamicProgramming() {}

int DynamicProgramming::calculate(int maxWeight, int n, vector<int> weights, vector<int> profits)
{
    vector<vector<int>> K(n + 1, vector<int>(maxWeight + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (weights[i - 1] <= j)
                K[i][j] = max(profits[i - 1] + K[i - 1][j - weights[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }
    return K[n][maxWeight];
}