#include <iostream>
#include "linkedHash.h"

using namespace std;

void test01()
{
    HashTable<int> table(17);
    table.insert(3);
    table.insert(21);
    table.insert(15);
    table.insert(7);
    table.insert(33);

    cout << table.at(table.find(15)) << endl;

    table.erase(15);
    cout << table.at(table.find(15)) << endl;
}

int main()
{
    test01();

    return 0;
}