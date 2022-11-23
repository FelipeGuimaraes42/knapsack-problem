#include "include/VND.hpp"

VND::VND(int maxWeight, int n, vector<int> weights, vector<int> profits)
{
    this->n = n;
    this->maxWeight = maxWeight;
    this->profits = profits;
    this->weights = weights;
}

VND::~VND() {}

KPSolution VND::getInitialSolution()
{
    vector<bool> items;
    int solution = 0;
    int weight = 0;
    for (int i = 0; i < this->n; i++)
    {
        items.push_back(0);
    }

    return KPSolution(items, solution, weight);
}

KPSolution VND::getRandomSolution()
{
    vector<bool> items;
    int solution = 0;
    int weight = 0;

    for (int i = 0; i < this->n; i++)
    {
        int randomBool = rand() % 2;
        items.push_back(randomBool);
        int aux = weight + this->weights.at(i);

        if (randomBool && aux <= this->maxWeight)
        {
            solution += this->profits.at(i);
            weight = aux;
        }
    }

    return KPSolution(items, solution, weight);
}

int VND::getKnapsackSize(vector<bool> items)
{
    int profit = 0;
    int weight = 0;

    for (int i = 0; i < this->n; i++)
    {
        if (items.at(i))
        {
            profit += this->profits.at(i);
            weight += this->weights.at(i);
        }
    }

    return weight;
}

KPSolution VND::getAddOneDropOne(KPSolution bestSolution)
{
    KPSolution newSolution;
    double maxSolution = bestSolution.getValue();
    vector<bool> bestSolutionItems = bestSolution.getItems();
    bool isSolutionImproved = true;

    while (isSolutionImproved)
    {
        isSolutionImproved = false;
        for (int i = 0; i < this->n - 1; i++)
        {
            for (int j = i + 1; j < this->n; j++)
            {
                vector<bool> twoOptPoints, auxPoints;
                for (int k = 0; k < i; k++)
                {
                    twoOptPoints.push_back(bestSolution.getItems().at(k));
                }

                for (int k = i; k < j; k++)
                {
                    auxPoints.push_back(bestSolution.getItems().at(k));
                }

                reverse(auxPoints.begin(), auxPoints.end());

                for (int k = 0; k < auxPoints.size(); k++)
                {
                    twoOptPoints.push_back(auxPoints.at(k));
                }

                for (int k = j; k < this->n; k++)
                {
                    twoOptPoints.push_back(bestSolution.getItems().at(k));
                }

                double twoOptValue = getKnapsackSize(twoOptPoints);

                newSolution.setItems(twoOptPoints);
                newSolution.setValue(twoOptValue);

                if (newSolution.getValue() > maxSolution)
                {
                    bestSolution = newSolution;
                    maxSolution = bestSolution.getValue();

                    isSolutionImproved = true;
                }
            }
        }
    }
    return bestSolution;
}

/*
KPSolution VND::getAddTwoDropOne(KPSolution bestSolution)
{
    KPSolution newSolution;
    double minSolution = bestSolution.getValue();
    bool isSolutionImproved = true;
    int size = bestSolution.getItems().size();

    while (isSolutionImproved)
    {
        isSolutionImproved = false;

        for (int i = 0; i < size - 2; i++)
        {
            for (int j = i + 1; j < size - 1; j++)
            {
                for (int l = j + 1; l < size; l++)
                {
                    vector<pair<int, int>> a, b, c;
                    for (int k = 0; k < i; k++)
                    {
                        a.push_back(bestSolution.getItems().at(k));
                    }

                    for (int k = i; k < j; k++)
                    {
                        b.push_back(bestSolution.getItems().at(k));
                    }

                    for (int k = j; k < l; k++)
                    {
                        c.push_back(bestSolution.getItems().at(k));
                    }

                    reverse(b.begin(), b.end());
                    reverse(c.begin(), c.end());

                    for (pair<int, int> k : c)
                    {
                        a.push_back(k);
                    }

                    for (pair<int, int> k : b)
                    {
                        a.push_back(k);
                    }

                    for (int k = l; k < size; k++)
                    {
                        a.push_back(bestSolution.getItems().at(k));
                    }

                    double threeOptValue = getCycleSize(a);

                    newSolution.setPoints(a);
                    newSolution.setValue(threeOptValue);

                    if (newSolution.getValue() < minSolution)
                    {
                        bestSolution = newSolution;
                        minSolution = bestSolution.getValue();

                        isSolutionImproved = true;
                    }
                }
            }
        }
    }
    return bestSolution;
}
*/

int VND::calculate()
{
    KPSolution initialSolution = this->getRandomSolution();

    KPSolution solution(initialSolution.getItems(),
                        initialSolution.getValue(),
                        initialSolution.getWeight());
    int k = 0;
    double maxSolution = solution.getValue();

    while (k < MAX_TENTATIVES)
    {
        if (k == 0)
        {
            // solution = this->getAddOneDropOne(solution);
        }
        else
        {
            // solution = this->getAddTwoDropOne(solution);
        }

        if (solution.getValue() > maxSolution)
        {
            maxSolution = solution.getValue();
            k = 0;
        }
        else
        {
            k++;
        }
    }

    return solution.getValue();
}
