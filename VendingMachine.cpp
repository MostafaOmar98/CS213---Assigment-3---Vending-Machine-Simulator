#include "VendingMachine.h"
#include "Stock.h"
#include "Money.h"
#include <iostream>
VendingMachine::VendingMachine(){}
void VendingMachine::setVendingMachine()
{
    int stockSize;
    do
    {
        std::cout << "Number of items in stock (Max is " << MAX_STOCK_SIZE << "): ";
        std::cin >> stockSize;
    }
    while(stockSize > MAX_STOCK_SIZE);
    for (int i = 0; i < stockSize; ++i)
    {
        std::cout << "Enter item " << i + 1 << " name: ";
        std::string itemName;
        std::cin >> itemName;
        std::cout << "Enter item " << i + 1 << " price: ";
        double itemPrice;
        std::cin >> itemPrice;
        int itemCount;
        do
        {
            std::cout << "Enter item " << i + 1 << " count(Max is " << MAX_ITEM_COUNT << "): ";
            std::cin >> itemCount;
        }
        while(itemCount > MAX_ITEM_COUNT);
        addNItems(itemName, itemCount , itemPrice);
    }

    for (int i = 0; i < billValue.size(); ++i)
    {
        std::cout << "Enter count of bill of value " << billValue[i] << " (Max is 10): ";
        std::cin >> billCount[i];
    }
}

void VendingMachine::printMenu()
{
    std::cout << "0 - Exit\n";
    for (int i = 0; i < mItem.size(); ++i)
    {
        std::cout << i + 1 << " - ";
        std::cout << "There are " << mCount[i] << " units left of " << mItem[i]->getName() << " for " << mItem[i]->getPrice() << " each\n";
    }
}

void VendingMachine::runVendingMachine()
{
    int choice;
    do
    {
        do
        {
            std::cout << "What would you like to do now?\n"
                         "0 - Exit\n"
                         "1 - Print Menu\n";
            std::cin >> choice;
            if (choice == 1)
                printMenu();
            else if (choice == 0)
            {
                std::cout << "\nTerminating...\n"
                exit(0);
            }
        }
        while(choice != 0 && choice != 1);

        do
        {
            std::cout << "Enter your choice: ";
            std::cin >> choice;
        }
        while(choice > mItem.size());

        int itemIdx = choice - 1;

        do
        {
            std::cout << "Enter count: ";
            std::cin>>choice;
        }
        while(choice < 0 || choice > mCount[itemIdx]);
        double amountPaid;
        do{
            std::cout << "Enter Money: ";
            std::cin >> amountPaid;
        }
        while(amountPaid < choice * mItem[itemIdx]->getPrice());
        removeItem(mItem[itemIdx]->getName(), choice);
        giveChange(amountPaid - choice * mItem[itemIdx]->getPrice());
        checkTerminate();
    }
    while(choice != 0);
}
void VendingMachine:: checkTerminate()
{
    if (mItem.empty())
    {
        std::cout << "\nStock is empty\n"
                     "Terminating...\n";
        exit(0);
    }
}
VendingMachine::~VendingMachine(){}

