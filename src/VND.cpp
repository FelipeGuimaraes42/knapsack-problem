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
    for (int i = 0; i < this->n; i++)
    {
        items.push_back(0);
    }

    return KPSolution(items, solution);
}

/* double VND::getEuclideanDistance(const pair<int, int> xiYi, const pair<int, int> xjYj)
{
    double xd = xiYi.first - xjYj.first;
    double yd = xiYi.second - xjYj.second;
    return floor(sqrt(xd * xd + yd * yd));
}

double VND::getPseudoEuclideanDistance(const pair<int, int> xiYi, const pair<int, int> xjYj)
{
    double xd = xiYi.first - xjYj.first;
    double yd = xiYi.second - xjYj.second;
    double rij = sqrt((xd * xd + yd * yd) / 10.0);
    double tij = floor(rij);

    if (tij < rij)
    {
        return tij + 1.0;
    }
    return tij;
}

KPSolution VND::getConstructiveSolution()
{
    srand(time(0));
    int n = this->points.size();

    bool visitedCities[n] = {false};

    int first = rand() % n;
    visitedCities[first] = true;

    int u = first;

    double solutionValue = 0;

    vector<pair<int, int>> solutionPoints;

    while (true)
    {
        solutionPoints.push_back(this->points.at(u));
        bool run = false;
        for (int i = 0; i < n; i++)
        {
            if (visitedCities[i] == false)
            {
                run = true;
            }
        }
        if (!run)
        {
            break;
        }

        int distance = INF;
        int vertice = -1;

        for (int v = 0; v < n; v++)
        {
            if (!visitedCities[v])
            {
                double currentDistance;
                if (this->weightType == "EUC_2D")
                {
                    currentDistance = getEuclideanDistance(this->points[u], this->points[v]);
                }
                else
                {
                    currentDistance = getPseudoEuclideanDistance(this->points[u], this->points[v]);
                }

                if (currentDistance < distance)
                {
                    vertice = v;
                    distance = currentDistance;
                }
            }
        }

        visitedCities[vertice] = true;
        solutionValue += distance;
        u = vertice;
    }

    solutionValue += (this->weightType == "EUC_2D" ? getEuclideanDistance(this->points[first], this->points[u]) : getPseudoEuclideanDistance(this->points[first], this->points[u]));

    KPSolution solution(solutionValue, solutionPoints);

    return solution;
}

double VND::getCycleSize(vector<pair<int, int>> points)
{
    int size = points.size();
    double cycleSize = 0;

    for (int i = 0; i < points.size() - 1; i++)
    {
        if (this->weightType == "EUC_2D")
        {
            cycleSize += getEuclideanDistance(points.at(i), points.at(i + 1));
        }
        else
        {
            cycleSize += getPseudoEuclideanDistance(points.at(i), points.at(i + 1));
        }
    }

    if (this->weightType == "EUC_2D")
    {
        cycleSize += getEuclideanDistance(points.at(size - 1), points.at(0));
    }
    else
    {
        cycleSize += getPseudoEuclideanDistance(points.at(size - 1), points.at(0));
    }

    return cycleSize;
}
*/

/* KPSolution VND::getTwoOptSolution(KPSolution bestSolution)
{
    KPSolution newSolution;
    double minSolution = bestSolution.getSolutionValue();
    bool isSolutionImproved = true;

    while (isSolutionImproved)
    {
        isSolutionImproved = false;
        int size = bestSolution.getItems().size();

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                vector<pair<int, int>> twoOptPoints, auxPoints;
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

                for (int k = j; k < size; k++)
                {
                    twoOptPoints.push_back(bestSolution.getItems().at(k));
                }

                double twoOptValue = getCycleSize(twoOptPoints);

                newSolution.setPoints(twoOptPoints);
                newSolution.setValue(twoOptValue);

                if (newSolution.getSolutionValue() < minSolution)
                {
                    bestSolution = newSolution;
                    minSolution = bestSolution.getSolutionValue();

                    isSolutionImproved = true;
                }
            }
        }
    }
    return bestSolution;
}

KPSolution VND::getThreeOptSolution(KPSolution bestSolution)
{
    KPSolution newSolution;
    double minSolution = bestSolution.getSolutionValue();
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

                    if (newSolution.getSolutionValue() < minSolution)
                    {
                        bestSolution = newSolution;
                        minSolution = bestSolution.getSolutionValue();

                        isSolutionImproved = true;
                    }
                }
            }
        }
    }
    return bestSolution;
}

KPSolution VND::getFourOptSolution(KPSolution bestSolution)
{
    KPSolution newSolution;
    double minSolution = bestSolution.getSolutionValue();
    bool isSolutionImproved = true;
    int size = bestSolution.getItems().size();

    while (isSolutionImproved)
    {
        isSolutionImproved = false;

        for (int i = 0; i < size - 3; i++)
        {
            for (int j = i + 1; j < size - 2; j++)
            {
                for (int l = j + 1; l < size - 1; l++)
                {
                    for (int m = l + 1; m < size; m++)
                    {
                        vector<pair<int, int>> a, b, c, d;
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

                        for (int k = l; k < m; k++)
                        {
                            d.push_back(bestSolution.getItems().at(k));
                        }

                        reverse(b.begin(), b.end());
                        reverse(c.begin(), c.end());
                        reverse(d.begin(), d.end());

                        for (pair<int, int> k : d)
                        {
                            a.push_back(k);
                        }

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

                        double fourOptValue = getCycleSize(a);

                        newSolution.setPoints(a);
                        newSolution.setValue(fourOptValue);

                        if (newSolution.getSolutionValue() < minSolution)
                        {
                            bestSolution = newSolution;
                            minSolution = bestSolution.getSolutionValue();

                            isSolutionImproved = true;
                        }
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
    KPSolution initialSolution = this->getInitialSolution();

    KPSolution solution(initialSolution.getItems(), initialSolution.getSolutionValue());
    int k = 0;
    double minSolution = solution.getSolutionValue();

    /*while (k < MAX_TENTATIVES)
        {
            if (k == 0)
            {
                solution = this->getTwoOptSolution(solution);
            }
            else if (k == 1)
            {
                solution = this->getThreeOptSolution(solution);
            }
            else
            {
                solution = this->getFourOptSolution(solution);
            }

            if (solution.getSolutionValue() < minSolution)
            {
                minSolution = solution.getSolutionValue();
                k = 0;
            }
            else
            {
                k++;
            }
        }
    */

    return solution.getSolutionValue();
}
