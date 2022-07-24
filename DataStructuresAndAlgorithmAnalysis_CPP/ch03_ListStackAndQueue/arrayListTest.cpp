#include <iostream>
#include "arrayList.h"

using namespace std;

void test01()
{
    ArrayList<int> arr1;
    ArrayList<int> arr2(10, 1);
    ArrayList<int> arr3(arr2);
    ArrayList<int> arr4;
    arr4 = arr3;

    arr1.print();
    arr2.print();
    arr3.print();
    arr4.print();
}

void test02()
{
    ArrayList<int> arr1;

    // cout << arr1.isEmpty() << endl;
    // cout << arr1.getSize() << endl;

    // arr1.reserve(10);
    // arr1.print();

    // arr1.resize(10);
    // arr1.print();

    for (int i = 0; i < 10; i++)
    {
        arr1.insert(i, i);
    }
    arr1.print();

    // cout << arr1[1] << endl;
    // cout << arr1.at(1) << endl;

    for (int i = 0; i < 5; i++)
    {
        arr1.erase(i);
    }
    arr1.print();

    // arr1.clear();
    // arr1.print();

    // cout << arr1.find(5) << endl;

    // arr1.modify(5, 0);
    // arr1.print();
}

int main()
{
    test01();
    // test02();

    return 0;
}