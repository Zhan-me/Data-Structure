#ifndef ARRAYHASH_H
#define ARRAYHASH_H

#include <iostream>
#include <cmath>

template <typename Object>
class HashTable
{
private:
    const int minCapacity = 5;

    enum KindOfEntry
    {
        Legitimate,
        Empty,
        Deleted
    };

    struct HashEntry
    {
        Object elem;
        KindOfEntry info;
    };

    HashEntry *cells; // 存放散列条目的数组
    int capacity;

public:
    HashTable(int tableSize)
    {
        init(tableSize);
    }

    ~HashTable()
    {
        delete[] cells;
        capacity = 0;
    }

    HashTable(const HashTable &) = delete;
    HashTable &operator=(const HashTable &) = delete;

    void init(int tableSize)
    {
        if (tableSize < minCapacity)
        {
            std::cout << "表大小太小了！" << std::endl;
            exit(0);
        }

        capacity = nextPrime(tableSize);
        cells = new HashEntry[capacity];

        clear();
    }

    void clear()
    {
        for (int i = 0; i < capacity; i++)
        {
            cells[i].info = Empty;
        }
    }

    int find(const Object &key) const
    {
        int collisionNum = 0;
        int index = hash(key);
        while (cells[index].info != Empty && cells[index].elem != key) // 可能需要 strcmp
        {
            collisionNum++;
            index += 2 * collisionNum - 1; // 平方探测公式：F(i) = F(i-1) + 2*i - 1
            index %= capacity;
        }

        return index;
    }

    void insert(const Object &key)
    {
        int index = find(key);
        if (cells[index].info != Legitimate) // 可以进行插入
        {
            cells[index].elem = key; // 可能需要 strcpy
            cells[index].info = Legitimate;
        }
    }

    void erase(const Object &key)
    {
        int index = find(key);
        if (cells[index].info == Legitimate) // 可以进行懒惰删除
        {
            cells[index].info = Deleted;
        }
    }

    Object at(int index) const
    {
        if (cells[index].info != Legitimate)
        {
            std::cout << "位置无效！" << std::endl;
            exit(0);
        }

        return cells[index].elem;
    }

    void rehash()
    {
        HashEntry *oldCells = cells;
        int oldCapacity = capacity;

        init(2 * oldCapacity);                // 获取新的扩容后的散列表
        for (int i = 0; i < oldCapacity; i++) // 将旧的合法条目插入到新表中
        {
            if (oldCells[i].info == Legitimate)
            {
                insert(oldCells[i].elem);
            }
        }
        delete[] oldCells;
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
};

#endif