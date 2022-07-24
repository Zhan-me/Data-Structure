#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <iostream>
#include <climits>

template <typename Object>
class BinaryHeap
{
private:
    Object *elems; // 元素数组
    int size;
    int capacity;

public:
    BinaryHeap(int maxSize)
    {
        elems = new Object[maxSize + 1]; // 带有哨兵的数组
        size = 0;
        capacity = maxSize;
        elems[0] = INT_MIN; // 哨兵初始化为最小值
    }

    ~BinaryHeap()
    {
        delete[] elems;
        size = 0;
        capacity = 0;
    }

    BinaryHeap(const BinaryHeap &) = delete;
    BinaryHeap &operator=(const BinaryHeap &) = delete;

    void clear()
    {
        size = 0;
        elems[0] = INT_MIN;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    bool isFull() const
    {
        return size == capacity;
    }

    void insert(const Object &object)
    {
        if (isFull())
        {
            std::cout << "二叉堆已满！" << std::endl;
            return;
        }

        size++;
        int i;
        for (i = size; elems[i / 2] > object; i /= 2) // 空穴上滤
        {
            elems[i] = elems[i / 2];
        }
        elems[i] = object;
    }

    Object deleteMin()
    {
        if (isEmpty())
        {
            std::cout << "二叉堆为空！" << std::endl;
            return elems[0];
        }

        Object minElem = elems[1];
        Object lastElem = elems[size];
        size--;

        int child;
        int i;
        for (i = 1; i * 2 <= size; i = child)
        {
            // 选择最小的孩子
            child = i * 2;
            if (child != size && elems[child + 1] < elems[child])
            {
                child++;
            }

            // 空穴下滤
            if (lastElem > elems[child])
            {
                elems[i] = elems[child];
            }
            else
            {
                break;
            }
        }
        elems[i] = lastElem;

        return minElem;
    }

    Object findMin() const
    {
        if (isEmpty())
        {
            std::cout << "二叉堆为空！" << std::endl;
            return elems[0];
        }

        return elems[1];
    }

    void print() const
    {
        for (int i = 1; i <= size; i++)
        {
            std::cout << elems[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    void percolateDown(int index)
    {
        int child;
        Object temp;

        for (temp = elems[index]; index * 2 <= size; index = child)
        {
            // 选择最小的孩子
            child = index * 2;
            if (child != size && elems[child + 1] < elems[child]) // 右孩子的值小于左孩子
            {
                child++;
            }

            // 空穴下滤
            if (temp > elems[child])
            {
                elems[index] = elems[child];
            }
            else
            {
                break;
            }
        }
        elems[index] = temp;
    }
};

#endif