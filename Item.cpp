
#include "Item.h"
#include <string>

Item::Item(std::string s, double price) { mName = s; mPrice = price; }
std::string Item::getName() const { return mName; }
double Item::getPrice() const { return mPrice; }
void Item::setName(const std::string &s) { mName = s; }
void Item::setPrice(const double &price) { mPrice = price; }

Item::~Item(){}
