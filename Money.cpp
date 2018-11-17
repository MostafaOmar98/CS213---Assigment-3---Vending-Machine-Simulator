#include "Money.h"
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <iostream>

Money::Money(): EPS(1e-9)
{
    billValue = {0.5, 1, 5, 10, 20};
    billCount.resize(billValue.size());
}
int Money::doubleCompare (double a, double b) const
{
    if (fabs(a - b) <= EPS)
        return 0;
    else if (a > b)
        return -1;
    return 1;
}

int Money::getBillCount(double bill) const
{
    for (int i = 0; i < billValue.size(); ++i)
    {
        if (doubleCompare(billValue[i], bill) == 0)
            return billCount[i];
    }
    return 0;
}
void Money::IncreaseBillCount(double bill, int count)
{
    for (int i = 0; i < billValue.size(); ++i)
    {
        if (doubleCompare(billValue[i], bill) == 0)
            billCount[i] += count;
    }

}
void Money::decreaseBillCount(double bill, int count)
{
    for (int i = 0; i < billValue.size(); ++i)
    {
        if (doubleCompare(billValue[i], bill) == 0)
        {
            assert(billCount[i] >= count);
            billCount[i] -= count;
        }
    }
}
std::vector<int> Money::giveChange(double Change)
{
    std::vector<int> resultChange;
    for (int i = (int)billValue.size() - 1; i >= 0; --i)
    {
        int tempCount = 0;
        while(doubleCompare(Change, billValue[i]) <= 0 && billCount[i] > 0) // Change >= billValue[i]
        {
            Change -= billValue[i];
            Change += EPS;
            billCount[i]--;
            ++tempCount;
        }
        resultChange.push_back(tempCount);
    }
    std::reverse(resultChange.begin(), resultChange.end());
    if (doubleCompare(Change, 0.5) == -1)
    {
        std::cout << "\nNo enough change\n"
                "Terminating...\n";
        exit(0);
    }
    for (int i = 0; i < resultChange.size(); ++i)
    {
        std::cout << resultChange[i] << " bills of value " << billValue[i] << '\n';
    }
    return resultChange;
}
Money::~Money(){}