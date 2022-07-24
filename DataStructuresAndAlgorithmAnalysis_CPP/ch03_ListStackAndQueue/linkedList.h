#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>

template <typename Object>
class LinkedList
{
private:
    struct Node
    {
        Object elem;
        Node *next;

        Node() : elem(0), next(nullptr) {}
        Node(const Object &obj) : elem(obj), next(nullptr) {}
        Node(const Object &obj, Node *next) : elem(obj), next(next) {}
    };
    Node *head;

public:
    LinkedList()
    {
        head = new Node();
    }

    LinkedList(const std::vector<Object> &v)
    {
        head = new Node();

        Node *tail = head;
        Node *currentNode = nullptr;
        for (int i = 0; i < v.size(); ++i)
        { // 尾插法建立单链表
            currentNode = new Node(v[i]);
            tail->next = currentNode;
            tail = currentNode;
        }
    }

    ~LinkedList()
    {
        clear();
        delete head;
        head = nullptr;
    }

    LinkedList(const LinkedList &list)
    {
        head = new Node();
        Node *currentNode = list.head->next;
        Node *tail = head;
        Node *newNode = nullptr;
        while (currentNode != nullptr)
        { // 尾插法复制单链表
            newNode = new Node(currentNode->elem);
            tail->next = newNode;
            tail = newNode;
            currentNode = currentNode->next;
        }
    }

    LinkedList &operator=(const LinkedList &list)
    {
        if (!isEmpty())
        {
            clear();
        }

        Node *currentNode = list.head->next;
        Node *tail = head;
        Node *newNode = nullptr;
        while (currentNode != nullptr)
        { // 尾插法复制单链表
            newNode = new Node(currentNode->elem);
            tail->next = newNode;
            tail = newNode;
            currentNode = currentNode->next;
        }

        return *this;
    }

    bool isEmpty() const
    {
        return head->next == nullptr;
    }

    int getSize() const
    {
        int count = 0;
        Node *currentNode = head->next;
        while (currentNode != nullptr)
        {
            ++count;
            currentNode = currentNode->next;
        }

        return count;
    }

    Node *getHead() const
    {
        return head;
    }

    Node *getFirst() const
    {
        return head->next;
    }

    Node *findPrev(const Object &obj) const
    {
        Node *currentNode = head;
        while (currentNode->next != nullptr && currentNode->next->elem != obj)
        {
            currentNode = currentNode->next;
        }

        return currentNode;
    }

    void insert(Node *currentNode, const Object &obj)
    {
        Node *newNode = new Node(obj);
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }

    void erase(const Object &obj)
    {
        Node *prevNode = findPrev(obj);
        if (prevNode->next != nullptr)
        {
            Node *tempNode = prevNode->next;
            prevNode->next = tempNode->next;
            delete tempNode;
        }
    }

    void clear()
    {
        Node *currentNode = nullptr;
        while (head->next != nullptr)
        {
            currentNode = head->next;
            head->next = head->next->next;
            delete currentNode;
        }
    }

    Node *find(const Object &obj) const
    {
        Node *currentNode = head->next;
        while (currentNode != nullptr && currentNode->elem != obj)
        {
            currentNode = currentNode->next;
        }

        return currentNode;
    }

    Object &at(int rank) const
    {
        if (rank < 1)
        {
            std::cout << "无效范围！" << std::endl;
            exit(0);
        }

        int count = 1;
        Node *currentNode = head->next;
        while (currentNode != nullptr && count < rank)
        {
            currentNode = currentNode->next;
            ++count;
        }

        if (currentNode == nullptr)
        {
            std::cout << "无效范围！" << std::endl;
            exit(0);
        }

        return currentNode->elem;
    }

    void print() const
    {
        Node *currentNode = head->next;
        while (currentNode != nullptr)
        {
            std::cout << currentNode->elem << " ";
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }
};

#endif