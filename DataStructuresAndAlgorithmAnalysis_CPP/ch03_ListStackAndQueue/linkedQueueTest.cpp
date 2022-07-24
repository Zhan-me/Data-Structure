#include <iostream>
#include "linkedQueue.h"

using namespace std;

const int N = 10;

void test01()
{
    LinkedQueue<int> queue;

    for (int i = 0; i < N; i++)
    {
        queue.enqueue(i);
    }

    for (int i = 0; i < N; i++)
    {
        cout << queue.dequeue() << " ";
    }
    cout << endl;

    cout << queue.getFront() << endl;
}

int main()
{
    test01();

    return 0;
}