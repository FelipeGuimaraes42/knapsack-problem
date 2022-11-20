#include "include/KPSolution.hpp"

KPSolution::KPSolution(vector<int> items, int solution)
{
    this->items = items;
    this->solutionValue = solution;
}

KPSolution::~KPSolution()
{
}

void KPSolution::setItems(vector<int> items)
{
    this->items = items;
}

void KPSolution::setSolutionValue(int solution)
{
    this->solutionValue = solution;
}

vector<int> KPSolution::getItems()
{
    return this->items;
}

int KPSolution::getSolutionValue()
{
    return this->solutionValue;
}