#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>

template <typename Object>
class LinkedQueue
{
private:
    struct Node
    {
        Object elem;
        Node *next;

        Node() : next(nullptr) {}
        Node(const Object &obj) : elem(obj), next(nullptr) {}
    };
    Node *front;
    Node *rear;

public:
    LinkedQueue()
    {
        front = rear = nullptr;
    }

    ~LinkedQueue()
    {
        clear();
        front = rear = nullptr;
    }

    LinkedQueue(const LinkedQueue &) = delete;

    LinkedQueue &operator=(const LinkedQueue &) = delete;

    void clear()
    {
        while (front != rear) // 队列中含有1个以上的元素时
        {
            Node *currentNode = front;
            front = front->next;
            delete currentNode;
        }

        if (!isEmpty()) // 队列中含有1个元素时
        {
            Node *currentNode = front;
            front = rear = nullptr;
            delete currentNode;
        }
    }

    bool isEmpty() const
    {
        if (front == nullptr && rear == nullptr)
        {
            return true;
        }

        return false;
    }

    void enqueue(const Object &obj)
    {
        Node *currentNode = new Node(obj);

        if (isEmpty())
        {
            front = rear = currentNode;
        }
        else
        {
            rear->next = currentNode;
            rear = currentNode;
        }
    }

    Object dequeue()
    {
        if (isEmpty())
        {
            std::cout << "队空！" << std::endl;
            exit(0);
        }

        Object ret;
        if (front != rear) // 队列中含有1个以上的元素时
        {
            Node *currentNode = front;
            ret = currentNode->elem;
            front = front->next;
            delete currentNode;
        }
        else
        {
            if (!isEmpty()) // 队列中含有1个元素时
            {
                Node *currentNode = front;
                ret = currentNode->elem;
                front = rear = nullptr;
                delete currentNode;
            }
        }

        return ret;
    }

    Object getFront() const
    {
        if (isEmpty())
        {
            std::cout << "队空！" << std::endl;
            exit(0);
        }

        return front->elem;
    }
};

#endif