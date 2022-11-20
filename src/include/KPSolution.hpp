#include <vector>

using namespace std;

class KPSolution
{
private:
    vector<bool> items;
    int solutionValue;

public:
    KPSolution();
    KPSolution(vector<bool>, int);
    ~KPSolution();

    void setItems(vector<bool>);
    void setSolutionValue(int);

    vector<bool> getItems();
    int getSolutionValue();
};
