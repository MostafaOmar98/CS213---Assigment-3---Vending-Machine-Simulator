/*
 * Class that represents a stock of Items, these items could be food, drinks, ...
 */

#ifndef _STOCK_H
#define _STOCK_H
#include "Item.h"
#include <vector>

class Stock
{
protected:
    std::vector<Item*> mItem;
    std::vector<int> mCount;
    const int MAX_STOCK_SIZE, MAX_ITEM_COUNT;
public:
    // default constructor
    Stock();
    /*
     * Method addItem()
     * ---------------------
     * Takes a std::string and double value with default 0
     * ---------------------
     * If item with given name already exists in mItem it increases its billCount by 1, else it adds a new item with given name and price
     */
    void addItem(const std::string &name, double price = 0);
    /*
     * Method addNItems
     * -------------------------
     * takes a std::string and billCount default to 1 and double price with default 0
     * --------------------------
     * Repeats method addItem() for 'billCount' times
     */
    void addNItems(const std::string &name,int count = 1, double price = 0);
    /*
     * Method removeItem()
     * --------------------------
     * Takes itemName of std::string and billCount-int with default 1
     * -------------------
     * Decreases mCount of item with name 'name' by billCount, if modified mCount is less than or equal to 0 item is erased from stock
     */
    void removeItem(const std::string &name, int count = 1);
    /*
     * Method getItemPrice()
     * -------------------------
     * Takes item name of std::string
     * ------------------------
     * returns ItemPrice, -1 if Item is not found
     */
    double getItemPrice(const std::string &name) const;
    /*
     * Method getItemCount()
     * -------------------------
     * Takes item name of std::string
     * ------------------------
     * returns mCount of item with name 'name', 0 if Item is not found
     */
    double getItemCount(const std::string &name) const;

    void setItemPrice(const std::string &name, double price);
    /*
     * operator +=
     * ------------
     * adds item to stock
     */
    Stock operator+= (Item tempItem);
    // default destructor
    virtual ~Stock();
};


#endif //PROG_II_ASS3_TEAMTASK0_STOCK_H
