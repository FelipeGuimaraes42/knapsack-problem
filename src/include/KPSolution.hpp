#include <vector>

using namespace std;

class KPSolution
{
private:
    vector<int> items;
    int solutionValue;

public:
    KPSolution();
    KPSolution(vector<int>, int);
    ~KPSolution();

    void setItems(vector<int>);
    void setSolutionValue(int);

    vector<int> getItems();
    int getSolutionValue();
};
