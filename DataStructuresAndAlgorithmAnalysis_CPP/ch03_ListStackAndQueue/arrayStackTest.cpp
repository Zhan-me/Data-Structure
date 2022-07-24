#include <iostream>
#include "arrayStack.h"

using namespace std;

const int N = 10;

void test01()
{
    ArrayStack<int> stack1(N);
    cout << stack1.isEmpty() << endl;

    for (int i = 0; i < N; i++)
    {
        stack1.push(i);
    }
    cout << stack1.isFull() << endl;

    for (int i = 0; i < N; i++)
    {
        cout << stack1.pop() << " ";
    }
    cout << endl;

    cout << stack1.getTop() << endl;
}

int main()
{
    test01();

    return 0;
}