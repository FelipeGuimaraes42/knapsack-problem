#include <vector>

using namespace std;

class KPSolution
{
private:
    vector<bool> items;
    int value;
    int weight;

public:
    KPSolution();
    KPSolution(vector<bool>, int, int);
    ~KPSolution();

    void setItems(vector<bool>);
    void setValue(int);
    void setWeight(int);

    vector<bool> getItems();
    int getValue();
    int getWeight();
};
