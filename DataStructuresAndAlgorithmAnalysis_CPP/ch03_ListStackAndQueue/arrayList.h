#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>

const int INCREMENT_SIZE = 10;
const int NOT_FOUND = -1;

template <typename Object>
class ArrayList
{
private:
    Object *elem;
    int size;
    int capacity;

public:
    ArrayList()
    {
        elem = nullptr;
        capacity = size = 0;
    }

    ArrayList(int n, const Object &obj)
    {
        elem = new Object[n];
        capacity = size = n;
        for (int i = 0; i < n; ++i)
        {
            elem[i] = obj;
        }
    }

    ~ArrayList()
    {
        delete[] elem;
        elem = nullptr;
        capacity = size = 0;
    }

    ArrayList(const ArrayList &list)
    {
        capacity = size = list.getSize();
        elem = new Object[size]; // 申请堆区内存空间，防止浅拷贝
        for (int i = 0; i < size; ++i)
        {
            elem[i] = list[i]; // list.elem[i]
        }
    }

    ArrayList &operator=(const ArrayList &list)
    {
        if (elem != nullptr)
        {
            delete[] elem; // 释放原有内存空间
        }
        capacity = size = list.getSize();
        elem = new Object[size]; // 申请堆区内存空间，防止浅拷贝
        for (int i = 0; i < size; ++i)
        {
            elem[i] = list[i]; // list.elem[i]
        }

        return *this;
    }

    Object &operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            std::cout << "数组越界！" << std::endl;
            exit(0);
        }
        return elem[index];
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    int getSize() const
    {
        return size;
    }

    void reserve(int newCapacity)
    {
        if (newCapacity > capacity)
        {
            Object *newElem = new Object[newCapacity];
            for (int i = 0; i < size; ++i)
            {
                newElem[i] = elem[i];
            }
            delete[] elem;
            elem = newElem;
            capacity = newCapacity;
        }
    }

    void resize(int newSize)
    {
        if (newSize <= capacity)
        {
            size = newSize;
        }
        else
        {
            reserve(newSize);
            for (int i = size; i < newSize; ++i)
            {
                elem[i] = 0; // 新增的元素初始化为0
            }
            size = newSize;
        }
    }

    void insert(int index, const Object &obj)
    {
        if (index < 0 || index > size || index > capacity) // 边界检查
        {
            std::cout << "无效位置！" << std::endl;
            exit(0);
        }
        else if (size == capacity) // 在容量空间的末尾插入时，空间已满进行扩容
        {
            int newCapacity = capacity + INCREMENT_SIZE;
            reserve(newCapacity);
        }
        for (int i = size - 1; i >= index; --i) // 待插入位置以后的元素从后往前依次后移一位
        {
            elem[i + 1] = elem[i];
        }
        elem[index] = obj;
        ++size;
    }

    void erase(int index)
    {
        if (index < 0 || index >= size) // 边界检查，附带检查元素是否为空
        {
            std::cout << "无效位置！" << std::endl;
            exit(0);
        }
        for (int i = index + 1; i <= size; ++i) // 待删除位置以后的元素从前往后依次前移一位
        {
            elem[i - 1] = elem[i];
        }
        --size;
    }

    void clear()
    {
        size = 0;
    }

    int find(const Object &obj)
    {
        for (int i = 0; i < size; ++i)
        {
            if (elem[i] == obj)
            {
                return i;
            }
        }

        return NOT_FOUND;
    }

    Object &at(int index) const
    {
        if (index < 0 || index >= size)
        {
            std::cout << "数组越界！" << std::endl;
            exit(0);
        }
        return elem[index];
    }

    void modify(int index, const Object &newObj)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "无效位置！" << std::endl;
            exit(0);
        }
        elem[index] = newObj;
    }

    void print() const
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << elem[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "size: " << size << std::endl;
        std::cout << "capacity: " << capacity << std::endl;
    }
};

#endif