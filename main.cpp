#include <iomanip>
#include <iostream>
#include "MyHashtable.h"

void testMyHashTable();

int main()
{
    testMyHashTable();
    return 0;
}

void testMyHashTable()
{
    auto menu = Hashtable::MyHashtable<std::string, float>(6);
    menu.add("Pizza", 9.99f);
    menu.add("Burger", 5.99f);
    menu.add("Fries", 2.99f);
    menu.add("Soda", 1.99f);
    menu.add("Salad", 4.99f);
    menu.add("Steak", 12.99f);

    std::cout << menu.toString();
    std::cout << "Count: " << menu.getCount();
    std::cout << " Buckets: " + menu.bucketCount;
    int pos = std::to_string(menu["Burger"]).find('.');
    std::cout << "Price of Burger: " << std::to_string(menu["Burger"]).substr(0, pos + 3);
}
