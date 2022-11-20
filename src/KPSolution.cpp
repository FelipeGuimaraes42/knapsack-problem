#include "include/KPSolution.hpp"

KPSolution::KPSolution() {}

KPSolution::KPSolution(vector<bool> items, int solution)
{
    this->items = items;
    this->solutionValue = solution;
}

KPSolution::~KPSolution()
{
}

void KPSolution::setItems(vector<bool> items)
{
    this->items = items;
}

void KPSolution::setSolutionValue(int solution)
{
    this->solutionValue = solution;
}

vector<bool> KPSolution::getItems()
{
    return this->items;
}

int KPSolution::getSolutionValue()
{
    return this->solutionValue;
}