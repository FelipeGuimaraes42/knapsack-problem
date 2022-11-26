#include "include/VND.hpp"

VND::VND(int maxWeight, int n, vector<int> weights, vector<int> profits)
{
    this->n = n;
    this->maxWeight = maxWeight;
    this->profits = profits;
    this->weights = weights;

    this->profitsPerWeight.clear();
    for (int i = 0; i < n; i++)
    {
        double ppw = (double)profits[i] / weights[i];
        this->profitsPerWeight.push_back({i, ppw});
    }
    sort(this->profitsPerWeight.begin(), this->profitsPerWeight.end(),
         [](auto &left, auto &right)
         { return left.second < right.second; });
}

VND::~VND() {}

KPSolution VND::getEmptyKnapsack()
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

pair<int, int> VND::getKnapsackDetails(vector<bool> items)
{
    int profit = 0;
    int weight = 0;

    for (int i = 0; i < this->n; i++)
    {
        if (items[i])
        {
            profit += this->profits[i];
            weight += this->weights[i];
        }
    }

    return {profit, weight};
}

KPSolution VND::getRandomSolution()
{
    vector<bool> items;
    int solution;
    int weight;
    set<int> differentPicks;

    do
    {
        solution = 0;
        weight = 0;
        differentPicks.clear();

        for (int i = 0; i < this->n; i++)
        {
            int randomBool = rand() % 2;
            differentPicks.insert(randomBool * i);
            int aux = weight + this->weights[i];

            if (randomBool && aux <= this->maxWeight)
            {
                items.push_back(1);
                solution += this->profits[i];
                weight = aux;
            }
            else
            {
                items.push_back(0);
            }
        }

    } while (differentPicks.size() < this->n / 3);

    return KPSolution(items, solution, weight);
}

KPSolution VND::getAddOneDropNone(KPSolution bestSolution)
{
    KPSolution newBestSolution(bestSolution);

    bool isSolutionImproved = true;
    int i = this->n;
    while (i > 0)
    {
        vector<bool> newItemsPick = newBestSolution.getItems();

        do
        {
            i--;
        } while (i > 0 && newItemsPick.at(this->profitsPerWeight.at(i).first));

        newItemsPick.at(i) = true;

        pair<int, int> knapsackDetails = getKnapsackDetails(newItemsPick);

        if (knapsackDetails.first > newBestSolution.getValue() && knapsackDetails.second <= this->maxWeight)
        {
            newBestSolution.setItems(newItemsPick);
            newBestSolution.setValue(knapsackDetails.first);
            newBestSolution.setWeight(knapsackDetails.second);
            isSolutionImproved = true;
        }
    }

    return newBestSolution;
}

KPSolution VND::getAddOneDropOne(KPSolution bestSolution)
{
    KPSolution newBestSolution(bestSolution);
    int i = 0;

    while (i < this->n)
    {
        i++;
        vector<bool> newItemsPick = newBestSolution.getItems();
        int rand1, rand2;

        do
        {
            rand1 = rand() % this->n;
            rand2 = rand() % this->n;
        } while (newItemsPick.at(rand1) == newItemsPick.at(rand2));

        bool aux = newItemsPick.at(rand1);
        newItemsPick.at(rand1) = newItemsPick.at(rand2);
        newItemsPick.at(rand2) = aux;

        pair<int, int> knapsackDetails = getKnapsackDetails(newItemsPick);

        if (knapsackDetails.first > newBestSolution.getValue() && knapsackDetails.second <= this->maxWeight)
        {
            newBestSolution.setItems(newItemsPick);
            newBestSolution.setValue(knapsackDetails.first);
            newBestSolution.setWeight(knapsackDetails.second);
        }
    }

    return newBestSolution;
}

KPSolution VND::getAddTwoDropOne(KPSolution bestSolution)
{
    KPSolution newBestSolution(bestSolution);
    int i = 0;

    while (i < this->n)
    {
        i++;
        int not1, not2, yes;
        while (true)
        {
            not1 = rand() % this->n;
            if (!newBestSolution.getItems().at(not1))
            {
                break;
            }
        }
        while (true)
        {
            not2 = rand() % this->n;
            if (!newBestSolution.getItems().at(not2) && not2 != not1)
            {
                break;
            }
        }
        while (true)
        {
            yes = rand() % this->n;
            if (newBestSolution.getItems().at(yes))
            {
                break;
            }
        }

        vector<bool> newItemsPick = newBestSolution.getItems();
        newItemsPick.at(not1) = true;
        newItemsPick.at(not2) = true;
        newItemsPick.at(yes) = false;

        pair<int, int> knapsackDetails = getKnapsackDetails(newItemsPick);

        if (knapsackDetails.first > newBestSolution.getValue() && knapsackDetails.second <= this->maxWeight)
        {
            newBestSolution.setItems(newItemsPick);
            newBestSolution.setValue(knapsackDetails.first);
            newBestSolution.setWeight(knapsackDetails.second);
        }
    }

    return newBestSolution;
}

KPSolution VND::getAddOneDropTwo(KPSolution bestSolution)
{
    KPSolution newBestSolution(bestSolution);
    int i = 0;

    while (i < this->n)
    {
        i++;
        int yes1, yes2, no;

        while (true)
        {
            yes1 = rand() % this->n;
            if (newBestSolution.getItems().at(yes1))
            {
                break;
            }
        }
        while (true)
        {
            yes2 = rand() % this->n;
            if (newBestSolution.getItems().at(yes2) && yes2 != yes1)
            {
                break;
            }
        }
        while (true)
        {
            no = rand() % this->n;
            if (!newBestSolution.getItems().at(no))
            {
                break;
            }
        }

        vector<bool> newItemsPick = newBestSolution.getItems();
        newItemsPick.at(yes1) = false;
        newItemsPick.at(yes2) = false;
        newItemsPick.at(no) = true;

        pair<int, int> knapsackDetails = getKnapsackDetails(newItemsPick);

        if (knapsackDetails.first > newBestSolution.getValue() && knapsackDetails.second <= this->maxWeight)
        {
            newBestSolution.setItems(newItemsPick);
            newBestSolution.setValue(knapsackDetails.first);
            newBestSolution.setWeight(knapsackDetails.second);
        }
    }

    return newBestSolution;
}

KPSolution VND::getAddOneDropOneByProfit(KPSolution bestSolution)
{
    KPSolution newBestSolution(bestSolution);
    int i = n - 1;

    while (i >= 0)
    {
        vector<bool> newItemsPick = newBestSolution.getItems();
        int random, valuable;

        do
        {
            valuable = this->profitsPerWeight[i].first;
            i--;
        } while (newItemsPick.at(valuable) && i >= 0);

        do
        {
            random = rand() % this->n;
        } while (!newItemsPick.at(random) && random == valuable);

        newItemsPick.at(random) = false;
        newItemsPick.at(valuable) = true;

        pair<int, int> knapsackDetails = getKnapsackDetails(newItemsPick);

        if (knapsackDetails.first > newBestSolution.getValue() && knapsackDetails.second <= this->maxWeight)
        {
            newBestSolution.setItems(newItemsPick);
            newBestSolution.setValue(knapsackDetails.first);
            newBestSolution.setWeight(knapsackDetails.second);
        }
    }

    return newBestSolution;
}

KPSolution VND::getAddOneDropTwoByProfit(KPSolution bestSolution)
{
    KPSolution newBestSolution(bestSolution);
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < this->n)
    {
        vector<bool> newItemsPick = newBestSolution.getItems();
        int notValuable1, notValuable2, valuable;

        do
        {
            valuable = this->profitsPerWeight[i].first;
            i--;
        } while (newItemsPick.at(valuable) && i >= 0);

        do
        {
            notValuable1 = this->profitsPerWeight[j].first;
            j++;
        } while (!newItemsPick.at(notValuable1) && notValuable1 == valuable);

        do
        {
            notValuable2 = this->profitsPerWeight[j].first;
            j++;
        } while (!newItemsPick.at(notValuable2) && notValuable1 == notValuable2);

        newItemsPick.at(notValuable1) = false;
        newItemsPick.at(notValuable2) = false;
        newItemsPick.at(valuable) = true;

        pair<int, int> knapsackDetails = getKnapsackDetails(newItemsPick);

        if (knapsackDetails.first > newBestSolution.getValue() && knapsackDetails.second <= this->maxWeight)
        {
            newBestSolution.setItems(newItemsPick);
            newBestSolution.setValue(knapsackDetails.first);
            newBestSolution.setWeight(knapsackDetails.second);
        }
    }

    return newBestSolution;
}

KPSolution VND::calculate()
{
    KPSolution actualSolution = this->getRandomSolution();

    KPSolution bestSolution(actualSolution);
    int k = 0;

    while (k < MAX_ATTEMPTS)
    {
        if (k == 0)
        {
            actualSolution = this->getAddOneDropOne(actualSolution);
        }
        else if (k == 1)
        {
            actualSolution = this->getAddTwoDropOne(actualSolution);
        }
        else if (k == 2)
        {
            actualSolution = this->getAddOneDropTwo(actualSolution);
        }
        else if (k == 3)
        {
            actualSolution = this->getAddOneDropOneByProfit(actualSolution);
        }
        else if (k == 4)
        {
            actualSolution = this->getAddOneDropTwoByProfit(actualSolution);
        }
        else
        {
            actualSolution = this->getAddOneDropNone(actualSolution);
        }

        if (actualSolution.getValue() > bestSolution.getValue())
        {
            bestSolution = actualSolution;
            k = 0;
        }
        else
        {
            k++;
        }
    }

    return bestSolution;
}

// cout << bestSolution.getValue() << " " << bestSolution.getWeight() << endl;
// for (bool item : bestSolution.getItems())
// {
//     cout << item << " ";
// }
// cout << endl;
// cout << getKnapsackDetails(bestSolution.getItems()).first << endl;

// if (k == 0)
// {
//     actualSolution = this->getAddOneDropNone(actualSolution);
// }
// else if (k == 1)
// {
//     actualSolution = this->getAddOneDropOne(actualSolution);
// }
// else if (k == 2)
// {
//     actualSolution = this->getAddTwoDropOne(actualSolution);
// }
// else if (k == 3)
// {
//     actualSolution = this->getDropTwoAddOne(actualSolution);
// }
// else
// {
//     actualSolution = this->getAddOneDropOneByProfit(actualSolution);
// }

// KPSolution VND::getAddOneDropNone(KPSolution bestSolution)
// {
//     KPSolution newBestSolution(bestSolution);

//     bool isSolutionImproved = true;
//     int i = 0;
//     while (isSolutionImproved || i < MAX_ITERATIONS)
//     {
//         i++;
//         isSolutionImproved = false;
//         int random;

//         vector<bool> newItemsPick = newBestSolution.getItems();

//         do
//         {
//             random = rand() % this->n;
//         } while (newItemsPick.at(random));

//         newItemsPick.at(random) = true;

//         pair<int, int> knapsackDetails = getKnapsackDetails(newItemsPick);

//         if (knapsackDetails.first > newBestSolution.getValue() && knapsackDetails.second <= this->maxWeight)
//         {
//             newBestSolution.setItems(newItemsPick);
//             newBestSolution.setValue(knapsackDetails.first);
//             newBestSolution.setWeight(knapsackDetails.second);
//             isSolutionImproved = true;
//         }
//     }

//     return newBestSolution;
// }
