#include <iostream>
#include "linkedStack.h"

using namespace std;

const int N = 10;

void test01()
{
    LinkedStack<int> stack1;
    cout << stack1.isEmpty() << endl;

    for (int i = 0; i < N; i++)
    {
        stack1.push(i);
    }

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