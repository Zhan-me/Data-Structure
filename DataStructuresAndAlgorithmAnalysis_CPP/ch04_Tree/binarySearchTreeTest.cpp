#include <iostream>
#include "binarySearchTree.h"

using namespace std;

void test01()
{
    const int N = 10;

    BinarySearchTree<int> tree;

    for (int i = 0; i < N; i++)
    {
        tree.insert(i);
    }

    // cout << tree.find(3)->elem << endl;
    // cout << tree.findMin()->elem << endl;
    // cout << tree.findMax()->elem << endl;

    tree.print();

    tree.erase(3);
    cout << "\n删除后：" << endl;
    tree.print();
}

int main()
{
    test01();

    return 0;
}