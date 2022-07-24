#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>

const int EMPTY = -1;

template <typename Object>
class ArrayStack
{
private:
    Object *elem;
    int top;
    int capacity;

public:
    ArrayStack(int maxSize)
    {
        elem = new Object[maxSize];
        top = EMPTY;
        capacity = maxSize;
    }

    ~ArrayStack()
    {
        delete[] elem;
    }

    ArrayStack(const ArrayStack &stack) = delete;

    ArrayStack &operator=(const ArrayStack &stack) = delete;

    bool isEmpty() const
    {
        return top == EMPTY;
    }

    bool isFull() const
    {
        return top == capacity - 1;
    }

    void clear()
    {
        top = EMPTY;
    }

    void push(const Object &obj)
    {
        if (isFull())
        {
            std::cout << "栈满！" << std::endl;
            exit(0);
        }
        elem[++top] = obj;
    }

    Object pop()
    {
        if (isEmpty())
        {
            std::cout << "栈空！" << std::endl;
            exit(0);
        }
        return elem[top--];
    }

    Object getTop() const
    {
        if (isEmpty())
        {
            std::cout << "栈空！" << std::endl;
            exit(0);
        }
        return elem[top];
    }
};

#endif