#include <iostream>
#include <vector>
#include "linkedList.h"

using namespace std;

void test01()
{
    // LinkedList<int> list1;
    // list1.print();

    // vector<int> v = {0, 1, 2, 3, 4};
    // LinkedList<int> list2(v);
    // list2.print();

    LinkedList<int> list2({0, 1, 2, 3, 4});
    list2.print();

    // LinkedList<int> list3(list2);
    // list3.print();

    // LinkedList<int> list4;
    // list4 = list2;
    // list4.print();

    // cout << list2.isEmpty() << endl;

    // cout << list2.getSize() << endl;

    // cout << list2.getFirst()->elem << endl;

    // cout << list2.findPrev(3)->elem << endl;

    // list2.insert(list2.findPrev(3), 2);
    // list2.print();

    // list2.erase(2);
    // list2.print();

    // list2.clear();
    // list2.print();

    // cout << list2.find(3)->elem << endl;

    // cout << list2.at(3) << endl;
}

int main()
{
    test01();

    return 0;
}