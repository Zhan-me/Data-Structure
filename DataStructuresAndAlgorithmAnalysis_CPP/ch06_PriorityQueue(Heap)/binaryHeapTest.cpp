#include <iostream>
#include "binaryHeap.h"

using namespace std;

void test01()
{
    const int N = 10;
    BinaryHeap<int> heap(N);

    for (int i = N - 1; i >= 0; i--)
    {
        heap.insert(i);
    }
    heap.print();

    cout << "最小值：" << heap.findMin() << endl;

    heap.deleteMin();
    heap.print();
}

int main()
{
    test01();

    return 0;
}