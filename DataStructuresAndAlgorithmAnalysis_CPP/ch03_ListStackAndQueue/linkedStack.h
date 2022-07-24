#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>

template <typename Object>
class LinkedStack
{
private:
    struct Node
    {
        Object elem;
        Node *next;

        Node() : next(nullptr) {}
        Node(const Object &obj) : elem(obj), next(nullptr) {}
    };
    Node *head;

public:
    LinkedStack()
    {
        head = new Node();
    }

    ~LinkedStack()
    {
        clear();
        delete head;
        head = nullptr;
    }

    LinkedStack(const LinkedStack &) = delete;

    LinkedStack &operator=(const LinkedStack &) = delete;

    void clear()
    {
        while (head->next != nullptr)
        {
            Node *currentNode = head->next;
            head->next = currentNode->next;
            delete currentNode;
        }
    }

    bool isEmpty()
    {
        return head->next == nullptr;
    }

    void push(const Object &obj)
    {
        Node *currentNode = new Node(obj);
        currentNode->next = head->next;
        head->next = currentNode;
    }

    Object pop()
    {
        if (isEmpty())
        {
            std::cout << "栈空！" << std::endl;
            exit(0);
        }

        Object temp = head->next->elem;
        Node *currentNode = head->next;
        head->next = currentNode->next;
        delete currentNode;

        return temp;
    }

    Object getTop()
    {
        if (isEmpty())
        {
            std::cout << "栈空！" << std::endl;
            exit(0);
        }

        return head->next->elem;
    }
};

#endif