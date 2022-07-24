#ifndef LINKEDHASH_H
#define LINKEDHASH_H

#include <iostream>
#include <cmath>

template <typename Object>
class HashTable
{
private:
    const int minCapacity = 5;

    struct Node
    {
        Object elem;
        Node *next;

        Node() : next(nullptr) {}
        Node(Object object) : elem(object), next(nullptr) {}
    };

    Node *lists; // 存放链表头结点的数组
    int capacity;

public:
    HashTable(int tableSize)
    {
        if (tableSize < minCapacity)
        {
            std::cout << "表大小太小了！" << std::endl;
            exit(0);
        }

        capacity = nextPrime(tableSize);
        lists = new Node[capacity]; // 分配链表数组
    }

    ~HashTable()
    {
        clear();
        delete[] lists; // 删除头结点数组
        lists = nullptr;
        capacity = 0;
    }

    HashTable(const HashTable &) = delete;
    HashTable &operator=(const HashTable &) = delete;

    void clear()
    {
        Node *currentNode = nullptr;
        for (int i = 0; i < capacity; i++) // 删除所有结点链表
        {
            currentNode = lists[i].next;
            while (currentNode != nullptr) // 删除散列值为i的结点链表
            {
                lists[i].next = currentNode->next;
                delete currentNode;
                currentNode = lists[i].next;
            }
        }
    }

    Node *find(const Object &key) const
    {
        Node *currentNode = lists[hash(key)].next;
        while (currentNode != nullptr && currentNode->elem != key) // 可能需要 strcmp
        {
            currentNode = currentNode->next;
        }

        return currentNode;
    }

    void insert(const Object &key)
    {
        Node *position = find(key);
        if (position == nullptr) // 未找到 key
        {
            int index = hash(key);
            Node *newNode = new Node(key); // 可能需要 strcpy
            newNode->next = lists[index].next;
            lists[index].next = newNode;
        }
    }

    void erase(const Object &key)
    {
        Node *prevNode = findPrev(key, &lists[hash(key)]);
        if (prevNode->next != nullptr) // 前驱结点不是表尾节点
        {
            Node *currentNode = prevNode->next;
            prevNode->next = currentNode->next;
            delete currentNode;
        }
    }

    Object at(Node *position) const
    {
        if (position == nullptr)
        {
            std::cout << "位置无效！" << std::endl;
            exit(0);
        }

        return position->elem;
    }

private:
    int hash(const Object &key) const
    {
        return key % capacity;
    }

    bool isPrime(int num) const
    {
        if (num < 2)
        {
            return false;
        }

        int len = sqrt(num);
        for (int i = 2; i <= len; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int nextPrime(int num)
    {
        if (num < 2)
        {
            return 2;
        }

        while (!isPrime(num))
        {
            num++;
        }

        return num;
    }

    Node *findPrev(const Object &key, Node *list) const
    {
        Node *currentNode = list;
        while (currentNode->next != nullptr && currentNode->next->elem != key)
        {
            currentNode = currentNode->next;
        }

        return currentNode;
    }
};

#endif