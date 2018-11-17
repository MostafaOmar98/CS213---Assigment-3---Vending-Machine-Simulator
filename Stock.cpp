#include "Stock.h"
#include <string>
#include <vector>

Stock::Stock():MAX_STOCK_SIZE(10), MAX_ITEM_COUNT(10) {}
void Stock::addItem(const std::string &name, double price)
{
    bool found = false;
    for (int i = 0; i < mItem.size(); ++i)
    {
        if (mItem[i]->getName() == name)
        {
            mCount[i]++;
            found = true;
            break;
        }
    }
    if (!found)
    {
        Item* tempItemPtr = new Item(name, price);
        mItem.push_back(tempItemPtr);
        mCount.push_back(1);
    }
}

void Stock::addNItems(const std::string &name,int count, double price)
{
    while(count--)
        addItem(name, price);
}
void Stock::removeItem(const std::string &name, int count)
{
    for (int i = 0; i < mItem.size(); ++i)
    {
        if (mItem[i]->getName() == name)
        {
            mCount[i] -= count;
            if (mCount[i] <= 0)
            {
                mItem.erase(mItem.begin() + i);
                mCount.erase(mCount.begin() + i);
            }
            break;
        }
    }
}
double Stock::getItemPrice(const std::string &name) const
{
    for (int i = 0; i < mItem.size(); ++i)
    {
        if (mItem[i]->getName() == name)
        {
            return mItem[i]->getPrice();
        }
    }
    return -1;
}
double Stock::getItemCount(const std::string &name) const
{
    bool found = false;
    for (int i = 0; i < mItem.size(); ++i)
    {
        if (mItem[i]->getName() == name)
        {
            return mCount[i];
        }
    }
    return 0;

}

Stock Stock::operator+= (Item tempItem)
{
    addItem(tempItem.getName());
}

Stock::~Stock() {
    for (int i = 0; i < mItem.size(); ++i)
    {
        delete mItem[i];
    }
}