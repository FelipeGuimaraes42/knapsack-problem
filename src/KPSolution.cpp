#include "include/KPSolution.hpp"

KPSolution::KPSolution() {}

KPSolution::KPSolution(vector<bool> items, int solution, int weight)
{
    this->items = items;
    this->value = solution;
    this->weight = weight;
}

KPSolution::~KPSolution() {}

void KPSolution::setItems(vector<bool> items)
{
    this->items = items;
}

void KPSolution::setValue(int solution)
{
    this->value = solution;
}

void KPSolution::setWeight(int weight)
{
    this->weight = weight;
}

vector<bool> KPSolution::getItems()
{
    return this->items;
}

int KPSolution::getValue()
{
    return this->value;
}

int KPSolution::getWeight()
{
    return this->weight;
}