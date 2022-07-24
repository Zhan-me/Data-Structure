#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>

// 使用循环队列的方法
template <typename Object>
class ArrayQueue
{
private:
    Object *elem;
    int front; // front指向队头的前一位元素
    int rear;  // rear指向队尾元素
    int capacity;

public:
    ArrayQueue(int maxSize)
    {
        elem = new Object[maxSize];
        capacity = maxSize;
        clear();
    }

    ~ArrayQueue()
    {
        delete[] elem;
    }

    ArrayQueue(const ArrayQueue &) = delete;

    ArrayQueue &operator=(const ArrayQueue &) = delete;

    void clear()
    {
        front = rear = -1;
    }

    bool isEmpty() const
    {
        return rear == front;
    }

    bool isFull() const
    {
        return (rear + 1) % capacity == front; // 牺牲一个空间用来指示队满
    }

    void enqueue(const Object &obj)
    {
        if (isFull())
        {
            std::cout << "队满！" << std::endl;
            exit(0);
        }

        rear = (rear + 1) % capacity;
        elem[rear] = obj;
    }

    Object dequeue()
    {
        if (isEmpty())
        {
            std::cout << "队空！" << std::endl;
            exit(0);
        }

        front = (front + 1) % capacity;

        return elem[front];
    }

    Object getFront() const
    {
        if (isEmpty())
        {
            std::cout << "队空！" << std::endl;
            exit(0);
        }

        return elem[(front + 1) % capacity];
    }
};

#endif