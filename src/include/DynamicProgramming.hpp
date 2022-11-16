#include <vector>

using namespace std;

class DynamicProgramming
{
private:
    /* data */
public:
    DynamicProgramming();
    ~DynamicProgramming();
    int calculate(int maxWeight, int n, vector<int> weights, vector<int> profits);
};